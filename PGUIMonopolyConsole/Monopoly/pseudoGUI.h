#pragma once

enum GraphicChar {
	CHAR_FULL = -37,
	CHAR_FULL_TOP = -33,
	CHAR_FULL_BOT = -36,

	CHAR_STICK_VERT = -77,
	CHAR_STICK_HOR = -60,
	CHAR_STICK_TOP_LEFT = -38,
	CHAR_STICK_TOP_RIGHT = -65,
	CHAR_STICK_BOT_LEFT = -64,
	CHAR_STICK_BOT_RIGHT = -39,

	CHAR_DSTICK_VERT = -70,
	CHAR_DSTICK_HOR = -51,
	CHAR_DSTICK_TOP_LEFT = -55,
	CHAR_DSTICK_TOP_RIGHT = -69,
	CHAR_DSTICK_BOT_LEFT = -56,
	CHAR_DSTICK_BOT_RIGHT = -68,

	CHAR_FILL_LIGHT = -80,
	CHAR_FILL_MEDIUM = -79,
	CHAR_FILL_DARK = -78
};

enum Color {
	COLOR_BLACK,
	COLOR_DARKBLUE,
	COLOR_DARKGREEN,
	COLOR_DARKCYAN,
	COLOR_DARKRED,
	COLOR_DARKPURPLE,
	COLOR_DARKYELLOW,
	COLOR_GRAY,
	COLOR_DARKGRAY,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_CYAN,
	COLOR_RED,
	COLOR_PURPLE,
	COLOR_YELLOW,
	COLOR_WHITE
};

enum StrokeType {
	STROKE_NONE,
	STROKE_BOLD,
	STROKE_SEMIBOLD,
	STROKE_THIN,
};

enum Align {
	ALIGN_TOP = 0,
	ALIGN_LEFT = 0,
	ALIGN_CENTER = 1,
	ALIGN_BOTTOM = 2,
	ALIGN_RIGHT = 2
};

//������, ������� �������������� �� ������
struct Object {
	short x, y; //���������� ��������
	short width, height; //���������� ����� ������� SetSize
	Color contentColor, backgroundColor; //���������� ��������
	char *content; //���������� ����� ������� SetContent
	char fill; //���������� ����� ������� SetFilling
	StrokeType stroke; //���������� ����� ������� SetStroke
	Align contentHorizAlign, contentVertAlign;
	bool autosize; //���������� ����� ������� SetAutisize
	bool visible; //���������� ��������
	bool transparent; //���������� ��������
	bool clip; //���������� ��������
	char **body; //�� ����������
	unsigned short childrenCount; //�� ����������
	Object **children; //�� ����������
	Object *parent; //���������� ����� ������� SetParent
};

//���������� �������
Object* CreateObject();
void DestroyObject(Object *object);
void SetParent(Object *object, Object *parent);
void SetSize(Object *object, short width, short height);
void SetStroke(Object *object, StrokeType strokeType);
void SetHorizontalAlign(Object *object, Align align);
void SetVerticalAlign(Object *object, Align align);
void SetFilling(Object *object, char filling);
void SetContent(Object *object, char *content);
void SetAutosize(Object *object, bool autosize);
int GetAbsoluteX(Object *object);
int GetAbsoluteY(Object *object);

//�������� �� ������ ������
struct Display {
	Object *mainParent; //������� ������, ������� �������� ������������ ��� ����
	short width, height;
	void (*Refresh)();
	void (*Clear)();
};

Display CreateDisplay(short  width, short  height, unsigned char pixelSize, Color color);
void DestroyDisplay();