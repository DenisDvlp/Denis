#include "gamecore.h"

Core* CreateCore() {
	Core *core = new Core;
	core->currentPlayerIndex = 0;
	core->startMoney = 12000;
	core->lapMoney = 6000;
	core->bonus[0] = "����� 1";
	core->bonus[1] = "����� 1";
	core->bonus[2] = "����� 1";
	core->bonus[3] = "����� 1";
	core->bonus[4] = "����� 1";
	core->info[0] = "��������� 1";
	core->info[1] = "��������� 1";
	core->info[2] = "��������� 1";
	core->info[3] = "��������� 1";
	core->info[4] = "��������� 1";
	core->plusminus[0] = "�����������!\n��� ������ ����� �� 10 ���������!";
	core->plusminus[1] = "��������!\n�������� ����� ����������!";
	Gamecard **list = core->gamecards;
	for (int i = 0; i < core->gamecardCount; i++)
		list[i] = CreateGamecard();
	InitGamecard(list[0], "�����", 0, COLOR_BLACK, COLOR_WHITE, GAMECARD_START, CARD_INFO);
	InitGamecard(list[1], "�����\n�������", 1000, COLOR_WHITE, COLOR_PURPLE, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[2], "�������\n����", 1000, COLOR_WHITE, COLOR_PURPLE, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[3], "+10% �������\n�� �� �����", 10000, COLOR_WHITE, COLOR_DARKYELLOW, GAMECARD_PLUS10, CARD_INFO);
	InitGamecard(list[4], "�����", 2000, COLOR_BLACK, COLOR_GREEN, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[5], "��������", 3000, COLOR_BLACK, COLOR_GREEN, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[6], "�����", 0, COLOR_WHITE, COLOR_DARKCYAN, GAMECARD_REST, CARD_INFO);
	InitGamecard(list[7], "�����+", 0, COLOR_WHITE, COLOR_DARKBLUE, GAMECARD_BONUS, CARD_INFO);
	InitGamecard(list[8], "������������\n�����������", 5000, COLOR_WHITE, COLOR_BLUE, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[9], "�������\n�����������", 5000, COLOR_WHITE, COLOR_BLUE, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[10], "�����������\n�������", 7000, COLOR_WHITE, COLOR_BLUE, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[11], "��������������", 10000, COLOR_WHITE, COLOR_DARKPURPLE, GAMECARD_COMMON, CARD_INFO);
	InitGamecard(list[12], "������", 0, COLOR_WHITE, COLOR_BLACK, GAMECARD_JAIL, CARD_INFO);
	InitGamecard(list[13], "�����", 9000, COLOR_BLACK, COLOR_YELLOW, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[14], "���������", 10000, COLOR_BLACK, COLOR_YELLOW, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[15], "-10% �������\n�� �� �����", 10000, COLOR_WHITE, COLOR_DARKYELLOW, GAMECARD_MINUS10, CARD_INFO);
	InitGamecard(list[16], "���������\n�����", 14000, COLOR_BLACK, COLOR_CYAN, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[17], "��������\n��������", 18000, COLOR_BLACK, COLOR_CYAN, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[18], "�����", 0, COLOR_WHITE, COLOR_DARKCYAN, GAMECARD_REST, CARD_INFO);
	InitGamecard(list[19], "���������", 0, COLOR_WHITE, COLOR_DARKBLUE, GAMECARD_INFO, CARD_INFO);
	InitGamecard(list[20], "google", 25000, COLOR_WHITE, COLOR_RED, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[21], "microsoft", 30000, COLOR_WHITE, COLOR_RED, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[22], "apple", 35000, COLOR_WHITE, COLOR_RED, GAMECARD_PRIVATE, CARD_CLASSIC);
	InitGamecard(list[23], "���������", 10000, COLOR_WHITE, COLOR_DARKPURPLE, GAMECARD_COMMON, CARD_INFO);

	for (int i = 0; i < core->playerCount; i++) {
		core->players[i] = CreatePlayer();
		InitPlayer(core->players[i], 0, 12000);
	}

	return core;
}

void DestroyCore(Core *&core) {
	for (int i = 0; i < core->gamecardCount; i++)
		delete[] core->gamecards[i];
	delete[] core->players[0];
	delete[] core->players[1];
	delete[] core;
	core = 0;
}