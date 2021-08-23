#include "interface.h"
#include "coremanager.h"
#include <time.h>
#include <iostream>

struct GlobalInterface {
	Display display;
	Dialog *dialog;
	Window *window;
	Core *core;
} gInterface = { 0 };

void Run();
void CreateScene();
bool ConfirmExitWithDialog(void(*Refresh)(), Window *window, Dialog *dialog);
void ToParentViewList(ViewList *viewList);
void BuildViewList(ViewList *viewList);
void ChangeViewList(ViewList *viewList);
void DeleteCurrentFile(ViewList *viewList);
void CopyCurrentFile(ViewList *viewList);
void MoveCurrentFile(ViewList *viewList);
void CreateNewFile(ViewList *viewList);
File* GetCurrentFile(ViewList *viewList);

Interface CreateInterface() {
	CreateScene();
	srand(time(NULL));
	Interface interface;
	interface.Run = Run;
	return interface;
}

void CreateScene() {
	short width = 109;
	short height = 30;

	gInterface.window = CreateWindow();
	SetSize(gInterface.window, width, height);

	gInterface.dialog = CreateDialog();
	gInterface.dialog->body->backgroundColor = COLOR_DARKPURPLE;
	gInterface.dialog->body->contentColor = COLOR_PURPLE;
	SetSize(gInterface.dialog, 50, 12);
	gInterface.dialog->body->visible = false;

	gInterface.display = CreateDisplay(width, height, 14, COLOR_GRAY);
	Object *parent = gInterface.display.mainParent;
	SetParent(gInterface.window->body, parent);
	SetParent(gInterface.dialog->body, gInterface.window->body);

	gInterface.core = CreateCore();
	BuildViewList(gInterface.window->leftList);
	BuildViewList(gInterface.window->rigthList);
}

void DestroyInterface() {
	DestroyWindow(gInterface.window);
	DestroyDisplay();
}

void Run() {
	Core *core = gInterface.core;
	Dialog *dialog = gInterface.dialog;
	Window *window = gInterface.window;
	ViewList *left = window->leftList;
	ViewList *right = window->rigthList;
	ViewList *current = 0;
	void(*Refresh)() = gInterface.display.Refresh;

	current = left;
	SetFocused(current, true);

	SetContent(dialog->message,
		"esc - �������� ���������/����\n"
		"home/end/pgup/pgdown/up/down - \n����������� �� ������\n"
		"tab - ������������ ����� ��������\n"
		"enter/backspace - ��������� �� ������\n"
		"�����: ����� ������, ������ 28��11, "
		"������ 2016");
	SetButtons(dialog, "����������");
	ShowDialog(Refresh, dialog);

	Files *files = 0;
	int answer = 0;
	while (true) {
		answer = KeyHandler(Refresh, current, DispatcheViewList);
		switch (answer) {
		case ANSWER_VIEWLIST_EXIT:
			if (ConfirmExitWithDialog(Refresh, window, dialog)) return;
			break;
		case ANSWER_VIEWLIST_CHANGE:
			SetFocused(current, false);
			current = (current == left) ? right : left;
			if (current == left)
				F.SetCurrentDir(core->leftPath);
			else
				F.SetCurrentDir(core->rightPath);
			SetFocused(current, true);
			break;
		case ANSWER_VIEWLIST_REFRESH:
			BuildViewList(left);
			BuildViewList(right);
			break;
		case ANSWER_VIEWLIST_TOPARENT:
			ToParentViewList(current);
			break;
		case ANSWER_VIEWLIST_SELECT:
			ChangeViewList(current);
			break;
		case ANSWER_VIEWLIST_DELETE:
			DeleteCurrentFile(current);
			break;
		case ANSWER_VIEWLIST_COPY:
			CopyCurrentFile(current);
			break;
		case ANSWER_VIEWLIST_MOVE:
			MoveCurrentFile(current);
			break;
		case ANSWER_VIEWLIST_CREATE:
			CreateNewFile(current);
			break;
		}
	}
}

bool ConfirmExitWithDialog(void(*Refresh)(), Window *window, Dialog *dialog) {
	SetContent(dialog->message, "�� ������������� ������\n �����?");
	SetButtons(dialog, "��", "���");
	if (ShowDialog(Refresh, dialog) == ANSWER_DIALOG_FIRST) {
		window->body->visible = false;
		Refresh();
		return true;
	}
	return false;
}

File* GetCurrentFile(ViewList *viewList) {
	int index = viewList->stringList->selected;
	if (0 == index) return 0;
	if (viewList == gInterface.window->leftList)
		return gInterface.core->leftFiles->list[index - 1];
	else
		return gInterface.core->rightFiles->list[index - 1];
}


void ToParentViewList(ViewList *viewList) {
	Core *core = gInterface.core;
	Window *window = gInterface.window;
	if (viewList == window->leftList) {
		S.Destroy(core->leftPath);
		core->leftPath = F.SetParentDir();
	}
	else {
		S.Destroy(core->rightPath);
		core->rightPath = F.SetParentDir();
	}
	BuildViewList(viewList);
}

void ChangeViewList(ViewList *viewList) {
	Core *core = gInterface.core;
	Window *window = gInterface.window;
	Dialog *dialog = gInterface.dialog;
	void(*Refresh)() = gInterface.display.Refresh;
	File *file = GetCurrentFile(viewList);
	if (!file)
		ToParentViewList(viewList);
	else {
		if (file->isDir) {
			if (viewList == window->leftList) {
				S.Destroy(core->leftPath);
				core->leftPath = F.SetCurrentDir(file->name);
			}
			else {
				S.Destroy(core->rightPath);
				core->rightPath = F.SetCurrentDir(file->name);
			}
			BuildViewList(viewList);
		}
		else {
			SetContent(dialog->message, file->name);
			SetButtons(dialog, "��");
			ShowDialog(Refresh, dialog);
		}
	}
}

void BuildViewList(ViewList *viewList) {
	Core *core = gInterface.core;
	Window *window = gInterface.window;
	Files *files = 0;
	ViewList *list = 0;
	Object *fullPath = 0;
	char *path = 0;
	char *currentDir = F.GetCurrentDir();
	//�������������, ��������� ������� ����� � ������������ � ������� ������
	if (viewList == window->leftList) {
		F.SetCurrentDir(core->leftPath);
		files = core->leftFiles;
		list = window->leftList;
		BuildFiles(core, CORE_LEFT);
		SetContent(window->leftPath, core->leftPath);
		path = core->leftPath;
		fullPath = window->leftPath;
	}
	else {
		F.SetCurrentDir(core->rightPath);
		files = core->rightFiles;
		list = window->rigthList;
		BuildFiles(core, CORE_RIGHT);
		path = core->rightPath;
		fullPath = window->rightPath;
	}
	//�������� ������
	//���� �� ����������, �� ������� ��������� ...
	if (S.Length(path) > fullPath->width) {
		char *sub = S.Substring(path, S.Length(path) - fullPath->width + 3, S.Length(path));
		path = S.ConcatTwoStrings("...", sub);
		SetContent(fullPath, path);
		S.Destroy(sub);
		S.Destroy(path);
		SetHorizontalAlign(fullPath, ALIGN_RIGHT);
	}
	else {
		SetContent(fullPath, path);
		SetHorizontalAlign(fullPath, ALIGN_LEFT);
	}
	//�������� ������ ����� � ������
	Strings *all = SS.Create();
	SS.Add(all, "<<<<");
	for (int i = 0; i < files->count; i++) {
		char *tmp = files->list[i]->name;
		if (files->list[i]->isDir)
			tmp = S.ConcatStrings(3, "[", tmp, "]");
		else
			tmp = S.ConcatTwoStrings("  ", tmp);
		SS.Add(all, tmp);
		S.Destroy(tmp);
	}
	//��������� ������ �� ������
	InitWithStrings(list->stringList, all);
	SS.Destroy(all);
	SetSelected(list->stringList, 0);
	//��������� ������� ����� �� �����
	F.SetCurrentDir(currentDir);
	S.Destroy(currentDir);
}
void DeleteCurrentFile(ViewList *viewList) {
	Dialog *dialog = gInterface.dialog;
	void(*Refresh)() = gInterface.display.Refresh;
	File *file = GetCurrentFile(viewList);
	if (!file) return;
	char *message = 0;
	//���������� ����� ��� ����
	if (file->isDir)
		message = S.ConcatStrings(3, "�� ������������� ������ �������\n����� \"",
			file->name,"\" � �� ����������?");
	else
		message = S.ConcatStrings(3, "�� ������������� ������ �������\n���� \"",
			file->name, "\"?");
	SetContent(dialog->message, message);
	SetButtons(dialog, "�������", "������");
	if (ShowDialog(Refresh, dialog) == ANSWER_DIALOG_FIRST) {
		//��������
		if (file->isDir)
			F.DeleteDir(file->name, true);
		else
			F.DeleteFile(file->name);
		//���������� ������� �� ������
		BuildViewList(gInterface.window->leftList);
		BuildViewList(gInterface.window->rigthList);
	}
	S.Destroy(message);
}

void CopyCurrentFile(ViewList *viewList) {
	Dialog *dialog = gInterface.dialog;
	void(*Refresh)() = gInterface.display.Refresh;
	File *file = GetCurrentFile(viewList);
	if (!file) return;
	char *message = 0;
	//���������� ����� ��� ����
	if (file->isDir)
		message = S.ConcatStrings(3, "�� ������������� ������ �����������\n����� \"",
			file->name, "\" � �� ����������?");
	else
		message = S.ConcatStrings(3, "�� ������������� ������ �����������\n���� \"",
			file->name, "\"?");
	SetContent(dialog->message, message);
	SetButtons(dialog, "����������", "������");
	if (ShowDialog(Refresh, dialog) == ANSWER_DIALOG_FIRST) {
		//�������� ������ ���� �����
		char *srcPath = 0;
		char *dstPath = 0;
		if (viewList == gInterface.window->leftList) {
			dstPath = gInterface.core->rightPath;
			srcPath = gInterface.core->leftPath;
		}
		else {
			dstPath = gInterface.core->leftPath;
			srcPath = gInterface.core->rightPath;
		}
		char *fullSrcPath = S.ConcatStrings(3, srcPath, "/", file->name);
		char *fullDstPath = 0;
		//���� �������� � �� �� �����, �� ��������� � ����� ������� (copy)
		if (!S.Compare(dstPath, srcPath, false))
			fullDstPath = S.ConcatTwoStrings(file->name, "(copy)");
		else
			fullDstPath = S.Copy(file->name);
		//�����������
		F.SetCurrentDir(dstPath);
		if (file->isDir)
			F.CopyDir(fullSrcPath, fullDstPath);
		else
			F.CopyFile(fullSrcPath, fullDstPath);
		F.SetCurrentDir(srcPath);
		//���������� ������� �� ������
		BuildViewList(gInterface.window->leftList);
		BuildViewList(gInterface.window->rigthList);
		S.Destroy(fullSrcPath);
		S.Destroy(fullDstPath);
	}
	S.Destroy(message);
}

void MoveCurrentFile(ViewList *viewList) {
	Dialog *dialog = gInterface.dialog;
	void(*Refresh)() = gInterface.display.Refresh;
	File *file = GetCurrentFile(viewList);
	if (!file) return;
	char *message = 0;
	//���������� ����� ��� ����
	if (file->isDir)
		message = S.ConcatStrings(3, "�� ������������� ������ �����������\n����� \"",
			file->name, "\" � �� ����������?");
	else
		message = S.ConcatStrings(3, "�� ������������� ������ �����������\n���� \"",
			file->name, "\"?");
	SetContent(dialog->message, message);
	SetButtons(dialog, "�����������", "������");
	if (ShowDialog(Refresh, dialog) == ANSWER_DIALOG_FIRST) {
		//�������� ������ ���� �����
		char *srcPath = 0;
		char *dstPath = 0;
		if (viewList == gInterface.window->leftList) {
			dstPath = gInterface.core->rightPath;
			srcPath = gInterface.core->leftPath;
		}
		else {
			dstPath = gInterface.core->leftPath;
			srcPath = gInterface.core->rightPath;
		}
		char *fullSrcPath = S.ConcatStrings(3, srcPath, "/", file->name);
		char *fullDstPath = S.Copy(file->name);
		//���� ���������� � �� �� �����, �� ������ ����������� ���
		if (!S.Compare(dstPath, srcPath, false)) {
			S.Destroy(fullSrcPath);
			S.Destroy(fullDstPath);
			S.Destroy(message);
			return;
		}
		//����������� �����������, ���� ����� ���������� �������� ��������
		if (0 == S.IndexOf(dstPath, srcPath, 0)) {
			S.Destroy(fullSrcPath);
			S.Destroy(fullDstPath);
			S.Destroy(message);
			SetContent(dialog->message, "����������� � �������� ����� ���������!");
			SetButtons(dialog, "��");
			ShowDialog(Refresh, dialog);
			return;
		}
		//�����������
		F.SetCurrentDir(dstPath);
		if (file->isDir)
			F.MoveDir(fullSrcPath, fullDstPath);
		else
			F.MoveFile(fullSrcPath, fullDstPath);
		F.SetCurrentDir(srcPath);
		//���������� ������� �� ������
		BuildViewList(gInterface.window->leftList);
		BuildViewList(gInterface.window->rigthList);
		S.Destroy(fullSrcPath);
		S.Destroy(fullDstPath);
	}
	S.Destroy(message);
}

void CreateNewFile(ViewList *viewList) {
	Dialog *dialog = gInterface.dialog;
	void(*Refresh)() = gInterface.display.Refresh;
	SetContent(dialog->message, "�������� ������ ��������");
	SetButtons(dialog, "�����", "����", "������");
	int answer = ShowDialog(Refresh, dialog);
	if (answer == ANSWER_DIALOG_FIRST) {
		char *name = S.Copy("new folder");
		int i = 2;
		while (F.FileExists(name)) {
			char *number = S.IntToString(i++);
			char *tmp = S.ConcatStrings(3, "new folder(", number, ")");
			S.Destroy(name);
			name = tmp;
			S.Destroy(number);
		}
		F.MakeDir(name);
		//���������� ������� �� ������
		BuildViewList(gInterface.window->leftList);
		BuildViewList(gInterface.window->rigthList);
	} else
	if (answer == ANSWER_DIALOG_SECOND) {
		char *name = S.Copy("new file.txt");
		int i = 2;
		while (F.FileExists(name)) {
			char *number = S.IntToString(i++);
			char *tmp = S.ConcatStrings(3, "new file(", number, ").txt");
			S.Destroy(name);
			name = tmp;
			S.Destroy(number);
		}
		F.MakeFile(name);
		//���������� ������� �� ������
		BuildViewList(gInterface.window->leftList);
		BuildViewList(gInterface.window->rigthList);
	}
}