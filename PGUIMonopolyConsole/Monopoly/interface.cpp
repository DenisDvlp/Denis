#include "interface.h"
#include <time.h>

struct GlobalInterface {
	Display display;
	Board *board;
	Infopanel *infopanel;
	Dialog *dialog;
	Core *core;
} gInterface = { 0 };

void Run();
void CreateScene();
bool ConfirmExitWithDialog(void(*Refresh)(), Board *board, Dialog *dialog);
void PlayerTurn(void(*Refresh)(), Board *board, Infopanel *infopanel, Dialog *dialog, Core *core);
void AssociateInfopanelType(Infopanel *infopanel, Core *core);


Interface CreateInterface() {
	CreateScene();
	srand(time(NULL));
	Interface interface;
	interface.Run = Run;
	return interface;
}

void CreateScene() {
	//������� �������������� ������
	gInterface.infopanel = CreateInfopanel();
	gInterface.infopanel->dialog->body->visible = false;
	SetSize(gInterface.infopanel, 50, 20);

	//������� ������
	gInterface.dialog = CreateDialog();
	gInterface.dialog->body->visible = false;
	SetSize(gInterface.dialog, 45, 10);

	//������� ������� ����
	gInterface.board = CreateBoard();
	SetCardSize(gInterface.board, 16, 8);

	//������� ������� ��� ������ �� �����
	gInterface.display = CreateDisplay(gInterface.board->body->width, gInterface.board->body->height, 14, COLOR_GRAY);
	Object *parent = gInterface.display.mainParent;
	SetParent(gInterface.board->body, parent);
	SetParent(gInterface.infopanel->dialog->body, parent);
	SetParent(gInterface.dialog->body, parent);

	//������� ������� ������
	gInterface.core = CreateCore();
	for (int i = 0; i < gInterface.core->gamecardCount; i++) {
		Card *card = gInterface.board->cards[i];
		Gamecard *gamecard = gInterface.core->gamecards[i];
		InitCard(card, gamecard->name, gamecard->cost, gamecard->cardType, gamecard->colorCaption, gamecard->colorCard);
	}
	//������ ������ �������
	SetPlayerBalance(gInterface.board, 0, gInterface.core->startMoney);
	SetPlayerBalance(gInterface.board, 1, gInterface.core->startMoney);
	//�������� ������, ������� ����� ������ ������
	SetActivePlayer(gInterface.board, gInterface.core->currentPlayerIndex);
}

void DestroyInterface() {
	DestroyDialog(gInterface.dialog);
	DestroyInfopanel(gInterface.infopanel);
	DestroyBoard(gInterface.board);
	DestroyDisplay();
	DestroyCore(gInterface.core);
}

void Run() {
	Board *board = gInterface.board;
	Infopanel *infopanel = gInterface.infopanel;
	Dialog *dialog = gInterface.dialog;
	Core *core = gInterface.core;
	void(*Refresh)() = gInterface.display.Refresh;

	int answer = 0;
	while (true) {
		answer = KeyHandler(Refresh, board, DispatcherBoard);
		switch (answer) {
		case ANSWER_BOARD_EXIT:
			if (ConfirmExitWithDialog(Refresh, board, dialog)) return;
			break;
		case ANSWER_BOARD_THROW:
			PlayerTurn(Refresh, board, infopanel, dialog, core);
			break;
		}
	}
}

bool ConfirmExitWithDialog(void(*Refresh)(), Board *board, Dialog *dialog) {
	SetContent(dialog->message, "�� ������������� ������\n �����?");
	SetButtons(dialog, "��", "���");
	if (ShowDialog(Refresh, dialog) == ANSWER_DIALOG_FIRST) {
		board->body->visible = false;
		Refresh();
		return true;
	}
	return false;
}

void PlayerTurn(void(*Refresh)(), Board *board, Infopanel *infopanel, Dialog *dialog, Core *core) {
	//��������� �������� �������� ������
	short first = board->bones[0]->number;
	short second = board->bones[1]->number;
	short sum = first + second;
	//������
	short playerIndex = core->currentPlayerIndex; // ������ ��������� ������
	short competitorIndex = (playerIndex + 1) % core->playerCount; // ������ ���������
	Player *player = core->players[playerIndex]; // �������� �����
	Player *competitor = core->players[competitorIndex]; // ��������
	//�����
	short nextCardIndex = (player->currentCard + sum) % 24; // ������ �������� �����
	Gamecard *currentCard = core->gamecards[nextCardIndex];
	//����� �����, ���� ����� � ������ - ������ �� �����
	if (first == second) {
		if (player->jailCount) {
			SetContent(dialog->message, "����� �����!\n ��� �������������!");
			SetButtons(dialog, "�������");
			ShowDialog(Refresh, dialog);
		}
		player->jailCount = 0;
	}
	//��������� ������, �� ����� �� �� � ������
	if (player->jailCount) {
		SetContent(dialog->message, "�� �� ��� ������ � ������.\n��������� ��� ���������� ������.");
		SetButtons(dialog, "����");
		ShowDialog(Refresh, dialog);
		player->jailCount--;
		core->currentPlayerIndex = competitorIndex;
		SetActivePlayer(board, competitorIndex);
		return;
	}
	//�������� ����� �� ����
	ChipMovement(Refresh, board, board->chip[playerIndex], player->currentCard, sum);
	//��������, ������ �� ����� �����
	if (nextCardIndex < player->currentCard) {
		player->balance += core->lapMoney; //������ �� �����
		char *money = IntToStr(core->lapMoney);
		char *text = ConcatStrings(3, "����� ����!\n�������� ", money, "!");
		SetContent(dialog->message, text);
		DeleteArray(money);
		DeleteArray(text);
		SetButtons(dialog, "�������");
		ShowDialog(Refresh, dialog);
		ChangeBalance(Refresh, board, playerIndex, player->balance - core->lapMoney, player->balance);
	}
	player->currentCard = nextCardIndex;
	//������������� �������������� ������
	InitCard(infopanel->card, board->cards[nextCardIndex]);
	AssociateInfopanelType(infopanel, core);
	//����� ������
	int answer = ShowInfopanel(Refresh, infopanel);
	int rent = 0;
	char *number = 0;
	char *text = 0;
	switch (answer) {
	case ANSWER_INFOPANEL_ACCEPT:
		switch (currentCard->type) {
		case GAMECARD_COMMON:
		case GAMECARD_PRIVATE:
			if (!currentCard->owner) {
				if (player->balance - currentCard->cost >= 0) {
					player->balance -= core->gamecards[nextCardIndex]->cost;
					AddCard(player, core->gamecards[nextCardIndex]);
					SetContent(dialog->message, "����������� � �������� ������ �������!");
					SetButtons(dialog, "�������");
					ShowDialog(Refresh, dialog);
					ChangeBalance(Refresh, board, playerIndex, player->balance + currentCard->cost, player->balance);
				}
			}
			else {
				if (player != currentCard->owner)
					if (player->balance - currentCard->cost / 10 >= 0) {
						rent = currentCard->cost / 10;
						number = IntToStr(rent);
						text = ConcatStrings(2, "��� ������ ���������� �� ", number);
						SetContent(dialog->message, text);
						DeleteArray(text);
						DeleteArray(number);
						SetButtons(dialog, "��");
						ShowDialog(Refresh, dialog);
						ChangeBalance(Refresh, board, playerIndex, player->balance, player->balance - rent);
						ChangeBalance(Refresh, board, competitorIndex, competitor->balance, competitor->balance + rent);
						player->balance -= rent;
						competitor->balance += rent;
					}
					else {
						SetContent(dialog->message, "�� ���������!");
						SetButtons(dialog, "��");
						ShowDialog(Refresh, dialog);
						board->body->visible = false;
						Refresh();
						return;
					}
			}
			break;
		case GAMECARD_MINUS10:
			rent = (player->balance / 10 > currentCard->cost) ? currentCard->cost : player->balance / 10;
			number = IntToStr(rent);
			text = ConcatStrings(2, "��� ������ ���������� �� ", number);
			SetContent(dialog->message, text);
			DeleteArray(text);
			DeleteArray(number);
			SetButtons(dialog, "��");
			ShowDialog(Refresh, dialog);
			ChangeBalance(Refresh, board, playerIndex, player->balance, player->balance - rent);
			player->balance -= rent;
			break;
		case GAMECARD_PLUS10:
			rent = (player->balance / 10 > currentCard->cost) ? currentCard->cost : player->balance / 10;
			number = IntToStr(rent);
			text = ConcatStrings(2, "��� ������ ���������� �� ", number);
			SetContent(dialog->message, text);
			DeleteArray(text);
			DeleteArray(number);
			SetButtons(dialog, "��");
			ShowDialog(Refresh, dialog);
			ChangeBalance(Refresh, board, playerIndex, player->balance, player->balance + rent);
			player->balance += rent;
			break;
		case GAMECARD_START:
			rent = core->lapMoney;
			number = IntToStr(rent);
			text = ConcatStrings(2, "�������� �������������� ", number);
			SetContent(dialog->message, text);
			DeleteArray(text);
			DeleteArray(number);
			SetButtons(dialog, "�������");
			ShowDialog(Refresh, dialog);
			ChangeBalance(Refresh, board, playerIndex, player->balance, player->balance + rent);
			player->balance += rent;
		case GAMECARD_JAIL:
			player->jailCount = 2;
			break;
		}
		break;
	case ANSWER_INFOPANEL_DENY:
		break;
	case ANSWER_INFOPANEL_EXIT:
		break;
	}
	//�������� ����
	SetContent(dialog->message, "��������� ��� ���������� ������");
	SetButtons(dialog, "��");
	ShowDialog(Refresh, dialog);
	//�������� ������, ������� ����� ������
	core->currentPlayerIndex = competitorIndex;
	SetActivePlayer(board, competitorIndex);
}

void AssociateInfopanelType(Infopanel *infopanel, Core *core) {
	Player *player = core->players[core->currentPlayerIndex]; // �������� �����
	Gamecard *currentCard = core->gamecards[player->currentCard];
	char *number = 0;
	char *text = 0;
	switch (currentCard->type) {
	case GAMECARD_PLUS10:
		SetInfopanelInfo(infopanel, "���������", core->plusminus[0], "��������", 0);
		break;
	case GAMECARD_MINUS10:
		SetInfopanelInfo(infopanel, "�����", core->plusminus[1], "��������", 0);
		break;
	case GAMECARD_INFO:
		SetInfopanelInfo(infopanel, "���������", core->info[0], "��", 0);
		break;
	case GAMECARD_BONUS:
		SetInfopanelInfo(infopanel, "�����", core->bonus[0], "��", 0);
		break;
	case GAMECARD_JAIL:
		SetInfopanelInfo(infopanel, "������", "���������� ���������.\n����������� 2 ����.", "��", 0);
		break;
	case GAMECARD_REST:
		SetInfopanelInfo(infopanel, "�����", "�� ����������� �� ������!", "��", 0);
		break;
	case GAMECARD_START:
		number = IntToStr(core->lapMoney);
		text = ConcatStrings(2, "�� ������ ���� � ������ �� �����!\n�������� �������������� ", number);
		SetInfopanelInfo(infopanel, "�����", text, "��������", 0);
		DeleteArray(text);
		DeleteArray(number);
		break;
	case GAMECARD_COMMON:
	case GAMECARD_PRIVATE:
		if (!currentCard->owner) {
			if (player->balance - currentCard->cost >= 0)
				SetInfopanelInfo(infopanel, "������", "��� ��������� �����������\n �� ������������ �������������.", "������", "����������");
			else
				SetInfopanelInfo(infopanel, "������", "��� ��������� �����������\n �� ������������ �������������.\n� ��� �� ������� �������.", "����������", 0);
		}
		else {
			if (player == currentCard->owner)
				SetInfopanelInfo(infopanel, "������", "��� ���� �������������.\n������ ���������.", "������", 0);
			else
			if (player->balance - currentCard->cost / 10 >= 0) {
				number = IntToStr(currentCard->cost / 10);
				text = ConcatStrings(2, "�� ������ �������� ������\n� ������� ", number);
				SetInfopanelInfo(infopanel, "������", text, "��������", 0);
				DeleteArray(text);
				DeleteArray(number);
			}else
				SetInfopanelInfo(infopanel, "������", "�� ������ �������� ������.\n� ��� �� ������� �������.\n�� �������!", "�������", 0);
		}
		break;
	}
}