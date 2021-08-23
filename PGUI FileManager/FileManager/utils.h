#pragma once

struct Strings;
struct StringFunctions;
struct StringsFunctions;
struct FileFunctions;

extern StringFunctions S;
extern StringsFunctions SS;
extern FileFunctions F;

// !!!�� ���� ������� �� ���������� �������� ���������!!!

///������

char* CreateString(int length);
void DestroyString(char *&string);
int LengthString(char *string);
bool IsEmptyString(char *string);
char* CopyString(char *string);
char* ConcatStrings(int count, char *string1, ...);
char* ConcatTwoStrings(char *string1, char *string2);
char* StringFromStrings(Strings *strings, char *delim);
int CompareStrings(char *first, char *second, bool caseSensitive);
int IndexOfChar(char *string, char character, int start);
int IndexOfString(char *string, char *substring, int start);
int LastIndexOfChar(char *string, char character);
int LastIndexOfString(char *string, char *substring);
bool ContainsChar(char *string, char character, int start);
bool ContainsString(char *string, char *substring, int start);
char* Substring(char *string, int start, int end);
char* Replace(char *string, char *target, char *replacement, int start);
char* ToUpper(char *string);
char* ToLower(char *string);
char* CharToString(char character);
char* IntToString(int number);
char* DoubleToString(double number);

struct StringFunctions {
	//������ ������, ���� ����� ������ ������ 1, �� ������ ������ ������
	char*(*Create)(int length);
	//������ ����� ������
	char*(*Copy)(char *string);
	//������ ������, �������� ������ ����� ���������� ������� delim
	char*(*CreateFrom)(Strings *strings, char *delim);
	//�������� ������ (���������� ������)
	void(*Destroy)(char *&string);
	//�������� ����� ������
	int(*Length)(char *string);
	//����� �� ������
	bool(*IsEmpty)(char *string);
	//������ ��������� �� ������ ���������� �� start �� end ������������
	char*(*Substring)(char *string, int start, int end);
	//������ ������, ���������� ������
	char*(*ConcatStrings)(int count, char *string1, ...);
	//������ ������, ���������� ��� ������
	char*(*ConcatTwoStrings)(char *string1, char *string2);
	//���������� ��� ������, ������ ����� - 0, ������ > ������ - >0, ������ < ������ - <0
	//caseSensitive ��������/��������� ����������� ��������
	int(*Compare)(char *first, char *second, bool caseSensitive);
	//���������� ������ ������� ��������� ������, ���� ������� ��� -1
	int(*IndexOf)(char *string, char *substring, int start);
	//���������� ������ ������� ��������� �������, ���� ������� ��� -1
	int(*IndexOfChar)(char *string, char character, int start);
	//���������� ������ ���������� ��������� ������, ���� ������� ��� -1
	int(*LastIndexOf)(char *string, char *substring);
	//���������� ������ ���������� ��������� �������, ���� ������� ��� -1
	int(*LastIndexOfChar)(char *string, char character);
	//�������� �� ������ ���������
	bool(*Contains)(char *string, char *substring, int start);
	//�������� �� ������ ������
	bool(*ContainsChar)(char *string, char character, int start);
	//������ ������, ������� ��������� ������ ����������
	char*(*Replace)(char *string, char *target, char *replacement, int start);
	//������ ������, ������� � � �������� ��������
	char*(*ToUpper)(char *string);
	//������ ������, ������� � � ������� ��������
	char*(*ToLower)(char *string);
	//������ ������, ���������� ������������ � ������
	char*(*DoubleToString)(double number);
	//������ ������, ���������� ����� � ������
	char*(*IntToString)(int number);
	//������ ������, ���������� ������ � ������
	char*(*CharToString)(char character);
};

///������

struct Strings {
	char **items;
	int count;
};

Strings* CreateStrings();
Strings* Substrings(Strings *strings, int start, int end);
Strings* StringsFromString(char *string, char *delims);
Strings* LoadFromFile(char *filepath);
void SaveToFile(Strings *strings, char *filepath);
void DestroyStrings(Strings *&strings);
int LengthOfAllStrings(Strings *strings);
int CountStrings(Strings *strings);
void AddString(Strings *strings, char *string);
void AddStrings(Strings *strings, Strings *strs);
void DeleteString(Strings *strings, int index);
void DeleteStrings(Strings *strings, int start, int count);
void InsertString(Strings *strings, char *string, int index);
void InsertStrings(Strings *strings, Strings *strs, int start);
int IndexOf(Strings *strings, char *string, int start, bool caseSensitive);
void SortStrings(Strings *strings, bool reverse);
void ClearStrings(Strings *strings);
void ExchangeStrings(Strings *strings, int firstIndex, int secondIndex);

struct StringsFunctions {
	//������ ������ ������
	Strings*(*Create)();
	//������ ������ �� ������, �������� � ������������� (����������� �����������)
	Strings*(*SplitString)(char *string, char *delims);
	//������ ��������� �� ������ ����� ���������� �� start �� end ������������
	Strings*(*Substrings)(Strings *strings, int start, int end);
	//�������� ����� �� �����
	Strings*(*LoadFromFile)(char *filepath);
	//���������� � ����
	void(*SaveToFile)(Strings *strings, char *filepath);
	//�������� ������ (���������� ������)
	void(*Destroy)(Strings *&strings);
	//����� ����� �����
	int(*LengthOfAll)(Strings *strings);
	//���������� �����
	int(*Count)(Strings *strings);
	//�������� ������ � ������
	void(*Add)(Strings *strings, char *str);
	//�������� ������ � ������
	void(*AddStrings)(Strings *strings, Strings *strs);
	//�������� ������ � ������
	void(*Insert)(Strings *strings, char *string, int index);
	//�������� ������ � ������
	void(*InsertStrings)(Strings *strings, Strings *strs, int start);
	//������� ������ �� ������
	void(*Delete)(Strings *strings, int index);
	//������� ������ �� ������
	void(*DeleteStrings)(Strings *strings, int start, int end);
	//����� ������ ��������� ������ � ������, ���������� -1 ���� ������ �� �������
	int(*IndexOf)(Strings *strings, char *string, int start, bool caseSensitive);
	//������������� ������, reverse - ��������� �� ��������/�����������
	void(*Sort)(Strings *strings, bool reverse);
	//������� ������ (������� ��� ������ � ������)
	void(*Clear)(Strings *strings);
	//�������� ������� ��� ������ � ������
	void(*Exchange)(Strings *strings, int firstIndex, int secondIndex);
};

//����

Strings* DirList(char *dirpath, char *filter);
Strings* FileList(char *dirpath, char *filter);
long long DirSize(char *dirpath, bool recursive);
long long FileSize(char *filepath);
bool FileExists(char *filepath);
void DeleteDir(char *dirpath, bool recursive);
void DeleteFile(char *filepath);
void CopyDir(char *dirsrc, char *dirdst);
void CopyFile(char *filesrc, char *filedst);
void MoveDir(char *dirsrc, char *dirdst);
void MoveFile(char *filesrc, char *filedst);
char* GetCurrentDir();
char* SetCurrentDir(char *dirpath);
char* SetParentDir();
char* SetRootDir();
char* GetFileNameFromPath(char *path);
char* GetDirFromPath(char *path);
void MakeDir(char *dirpath);
void MakeFile(char *filepath);

struct FileFunctions {
	//������ ����� �� ������� �����
	Strings*(*DirList)(char *dirpath, char *filter);
	//������ ������ �� ������� �����
	Strings*(*FileList)(char *dirpath, char *filter);
	//������ �����
	long long(*DirSize)(char *dirpath, bool recursive);
	//������ �����
	long long(*FileSize)(char *filepath);
	//���������� �� ����
	bool(*FileExists)(char *filepath);
	//������� �����
	void(*DeleteDir)(char *dirpath, bool recursive);
	//������� ����
	void(*DeleteFile)(char *filepath);
	//���������� �����
	void(*CopyDir)(char *dirsrc, char *dirdst);
	//���������� ����
	void(*CopyFile)(char *filesrc, char *filedst);
	//����������� �����
	void(*MoveDir)(char *dirsrc, char *dirdst);
	//����������� ����
	void(*MoveFile)(char *filesrc, char *filedst);
	//������� �����
	char*(*GetCurrentDir)();
	//������������� � �����
	char*(*SetCurrentDir)(char *dirpath);
	//������������� � ������������ �����
	char*(*SetParentDir)();
	//������������� � �������� �����
	char*(*SetRootDir)();
	//������� ��� ����� �� ����
	char*(*GetFileNameFromPath)(char *path);
	//������� ����� �� ����
	char*(*GetDirFromPath)(char *path);
	//������� �����
	void(*MakeDir)(char *dirpath);
	//������� ����
	void(*MakeFile)(char *filepath);
};

bool IsEqual(const char *first, const char *second);
int GetLength(const char *string);
void CopyString(char *&dst, char *src);
void AddString(char **&stringList, unsigned count, char *string);
void AddCopyString(char **&stringList, unsigned count, char *string);
char** GetStringsFromText(char *text, const char *delims, int &count);
char* GetTextFromStrings(char **strings, int count, const char *delim = 0);
char* CreateCharArray(int size);
char** CreateCharArray(int height, int width);
char* IntToStr(int number);
void DeleteArray(char *&array);
void DeleteArray(char **&array);
void DeleteArray(char *&array);
void DeleteArray(char **&array, int count);