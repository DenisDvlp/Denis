#include "Interface.h"

void Interface::Init(Color menuColor, Color submenuColor, Color aActionColor) {
	root = new Item;
	root->Init("", menuColor, ITEM_NONE);
	root->AddSubitem("Show cook book", menuColor, ITEM_SHOW);
	root->AddSubitem("Add recipe", menuColor, ITEM_ADD);
	root->GetSubitem(1)->AddSubitem("Back", submenuColor, ITEM_BACK);
	root->GetSubitem(1)->AddSubitem("Cold dish", submenuColor, ITEM_COLD);
	root->GetSubitem(1)->AddSubitem("Warm dish", submenuColor, ITEM_WARM);
	root->AddSubitem("Remove recipe", menuColor, ITEM_DELETE);
	root->AddSubitem("Save to file", menuColor, ITEM_SAVE);
	root->AddSubitem("Load from file", menuColor, ITEM_LOAD);
	root->AddSubitem("Exit", menuColor, ITEM_EXIT);
	root->SetChoosen(true);
	localRoot = root;
	actionColor = aActionColor;
}

void Interface::Run() {
	//����� ����
	int id = 0;
	root->Show();
	do {
		id = WaitInputWithDialog();
		//����� ����
		system("cls");
		root->Show();
		//����������� ���� � ����������
		Execute(id);
	} while (id != ITEM_EXIT);
	//��������� ������ ������� �� ���������
	SetDefaultConsoleColors();
	cout << endl;
	system("pause");
}

//�������� ����� � ��������
int Interface::WaitInputWithDialog() {
	//����� ������� ������������ � ���, ��� ��� ������
	ShowText("\nChoose item:", localRoot->GetSubitem(0)->GetColor(), BLACK);
	//����������� ���� � ����������
	char input[255];
	cin >> input;
	int itemNumber = atoi(input);
	//���������� ID ��������� ������
	int id = ITEM_NONE;
	if (itemNumber > 0 && itemNumber <= localRoot->GetItemCount())
		id = localRoot->GetSubitem(itemNumber - 1)->GetId();
	else
		id = localRoot->GetId();
	//������� ��������� �� ���� ������� ������ ���������
	localRoot->SetChoosen(false);
	//�������� ��������
	localRoot->SetChoosen(true);
	//�������� ���������
	localRoot->SetChoosenById(id, true);
	return id;
}

//���������� ��������
void Interface::Execute(int id) {
	int index;
	char input[255] = { 0 };
	FILE *file = nullptr;
	switch (id) {
	case ITEM_NONE:
		break;
	case ITEM_SHOW:
		ShowText("\nITEM_SHOW\n", actionColor, BLACK);
		break;
	case ITEM_ADD:
		localRoot = root->FindItemById(ITEM_ADD);
		break;
	case ITEM_BACK:
		localRoot = root;
		root->SetChoosen(false);
		//�������� ��������
		root->SetChoosen(true);
		system("cls");
		root->Show();
		break;
	case ITEM_COLD:
	case ITEM_WARM:
		ShowText("\nITEM_COLDITEM_WARM\n", actionColor, BLACK);
		break;
	case ITEM_DELETE:
		ShowText("\nITEM_DELETE\n", actionColor, BLACK);
		break;
	case ITEM_SAVE:
		ShowText("\nITEM_SAVE\n", actionColor, BLACK);
		break;
	case ITEM_LOAD:
		ShowText("\nITEM_LOAD\n", actionColor, BLACK);
		break;
	case ITEM_EXIT:
		ShowText("\ITEM_EXIT\n", actionColor, BLACK);
		break;
	}
}