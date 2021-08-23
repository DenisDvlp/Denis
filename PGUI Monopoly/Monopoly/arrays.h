#pragma once

//�������� �������

//�������� �������������� �������
int* CreateIntArray(int size);
int** CreateIntArray(int rows, int cols);
int*** CreateIntArray(int depth, int rows, int cols);
//�������� ������������� �������
double* CreateDoubleArray(int size);
double** CreateDoubleArray(int rows, int cols);
double*** CreateDoubleArray(int depth, int rows, int cols);
//�������� ������� ��������
char* CreateCharArray(int size);
char** CreateCharArray(int rows, int cols);
char*** CreateCharArray(int depth, int rows, int cols);

//�������� �������

//�������� �������������� �������
void DeleteArray(int *array);
void DeleteArray(int **array, int rows);
void DeleteArray(int ***array, int depth, int rows);
//�������� ������������� �������
void DeleteArray(double *array);
void DeleteArray(double **array, int rows);
void DeleteArray(double ***array, int depth, int rows);
//�������� ����������� �������
void DeleteArray(char *array);
void DeleteArray(char **array, int rows);
void DeleteArray(char ***array, int depth, int rows);

//����� �������

//����� �������������� �������
void ShowArray(int *array, int size);
void ShowArray(int **array, int rows, int cols);
void ShowArray(int ***array, int depth, int rows, int cols);
//����� ������������� �������
void ShowArray(double *array, int size);
void ShowArray(double **array, int rows, int cols);
void ShowArray(double ***array, int depth, int rows, int cols);
//����� ����������� �������
void ShowArray(char *array, int size);
void ShowArray(char **array, int rows, int cols);
void ShowArray(char ***array, int depth, int rows, int cols);
//����� �����
void ShowString(char *array);
void ShowStrings(char **array, int rows);
void ShowStrings(char ***array, int depth, int rows);

//������������� �������

//������������� ������� ���������� ���������� �� ���������
//��������������
void InitRandomArray(int *array, int size, int from, int to);
void InitRandomArray(int **array, int rows, int cols, int from, int to);
void InitRandomArray(int ***array, int depth, int rows, int cols, int from, int to);
//�������������
void InitRandomArray(double *array, int size, double from, double to);
void InitRandomArray(double **array, int rows, int cols, double from, double to);
void InitRandomArray(double ***array, int depth, int rows, int cols, double from, double to);
//�����������
void InitRandomArray(char *array, int size, char from, char to);
void InitRandomArray(char **array, int rows, int cols, char from, char to);
void InitRandomArray(char ***array, int depth, int rows, int cols, char from, char to);
//������������� ������� ���������� ���������� �� �������
//��������������
void InitRandomArrayFromAlphabet(int *array, int size, int *alphabet, int asize);
void InitRandomArrayFromAlphabet(int **array, int rows, int cols, int *alphabet, int asize);
void InitRandomArrayFromAlphabet(int ***array, int depth, int rows, int cols, int *alphabet, int asize);
//�������������
void InitRandomArrayFromAlphabet(double *array, int size, double *alphabet, int asize);
void InitRandomArrayFromAlphabet(double **array, int rows, int cols, double *alphabet, int asize);
void InitRandomArrayFromAlphabet(double ***array, int depth, int rows, int cols, double *alphabet, int asize);
//�����������
void InitRandomArrayFromAlphabet(char *array, int size, char *alphabet, int asize);
void InitRandomArrayFromAlphabet(char **array, int rows, int cols, char *alphabet, int asize);
void InitRandomArrayFromAlphabet(char ***array, int depth, int rows, int cols, char *alphabet, int asize);
//���������� ����� ������� ���������
//��������������
void FillSubArray(int *array, int start, int count, int value);
void FillSubArray(int **array, int startRow, int startCol, int rowCount, int colCount, int value);
void FillSubArray(int ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, int value);
//�������������
void FillSubArray(double *array, int start, int count, double value);
void FillSubArray(double **array, int startRow, int startCol, int rowCount, int colCount, double value);
void FillSubArray(double ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, double value);
//�����������
void FillSubArray(char *array, int start, int count, char value);
void FillSubArray(char **array, int startRow, int startCol, int rowCount, int colCount, char value);
void FillSubArray(char ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, char value);
//���������� ������� ���������
//��������������
void FillArray(int *array, int size, int value);
void FillArray(int **array, int rows, int cols, int value);
void FillArray(int ***array, int depth, int rows, int cols, int value);
//�������������
void FillArray(double *array, int size, double value);
void FillArray(double **array, int rows, int cols, double value);
void FillArray(double ***array, int depth, int rows, int cols, double value);
//�����������
void FillArray(char *array, int size, char value);
void FillArray(char **array, int rows, int cols, char value);
void FillArray(char ***array, int depth, int rows, int cols, char value);

//����� ����������/���������� ����������

void Exchange(int &first, int &second);
void Exchange(double &first, double &second);
void Exchange(char &first, char &second);
void Exchange(void* &first, void* &second);
void Exchange(int* &first, int* &second);
void Exchange(int** &first, int** &second);
void Exchange(double* &first, double* &second);
void Exchange(double** &first, double** &second);
void Exchange(char* &first, char* &second);
void Exchange(char** &first, char** &second);

//��������� ���������� ��������

//��������� �������� � ���������
int GetRand(int from, int to);
double GetRand(double from, double to);
char GetRand(char from, char to);
//��������� �������� �� �������
int GetRandFromArray(int *array, int size);
double GetRandFromArray(double *array, int size);
char GetRandFromArray(char *array, int size);


//����� ��������

//�������� ����� ���������� �������������
int* CreateCopySubArray(int *array, int size, int from, int to);
//�������� ����� ���������� ������������� 2�
int** CreateCopySubArray(int **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ���������� ������������� 3�
int*** CreateCopySubArray(int ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ���������� �������������
double* CreateCopySubArray(double *array, int size, int from, int to);
//�������� ����� ���������� ������������� 2�
double** CreateCopySubArray(double **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ���������� ������������� 3�
double*** CreateCopySubArray(double ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ���������� �����������
char* CreateCopySubArray(char *array, int size, int from, int to);
//�������� ����� ���������� ����������� 2�
char** CreateCopySubArray(char **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ���������� ����������� 3�
char*** CreateCopySubArray(char ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);

//�������� ����� ������� �������������
int* CreateCopyArray(int *array, int size);
//�������� ����� ������� ������������� 2�
int** CreateCopyArray(int **array, int rows, int cols);
//�������� ����� ������� ������������� 3�
int*** CreateCopyArray(int ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ������� �������������
double* CreateCopyArray(double *array, int size);
//�������� ����� ������� ������������� 2�
double** CreateCopyArray(double **array, int rows, int cols);
//�������� ����� ������� ������������� 3�
double*** CreateCopyArray(double ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);
//�������� ����� ������� �����������
char* CreateCopyArray(char *array, int size);
//�������� ����� ������� ����������� 2�
char** CreateCopyArray(char **array, int rows, int cols);
//�������� ����� ������� ����������� 3�
char*** CreateCopyArray(char ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol);

//����������� �������

//����������� ����� ������� � ������ ������ �������������
void CopySubArray(
	int *dest, int destSize, int destOffset,
	int *src, int srcSize, int srcOffset,
	int count);
//����������� ����� ������� � ������ ������ ������������� 2�
void CopySubArray(
	int **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	int **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols);
//����������� ����� ������� � ������ ������ ������������� 3�
void CopySubArray(
	int ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	int ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols);
//����������� ����� ������� � ������ ������ �������������
void CopySubArray(
	double *dest, int destSize, int destOffset,
	double *src, int srcSize, int srcOffset,
	int count);
//����������� ����� ������� � ������ ������ ������������� 2�
void CopySubArray(
	double **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	double **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols);
//����������� ����� ������� � ������ ������ ������������� 3�
void CopySubArray(
	double ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	double ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols);
//����������� ����� ������� � ������ ������ �����������
void CopySubArray(
	char *dest, int destSize, int destOffset,
	char *src, int srcSize, int srcOffset,
	int count);
//����������� ����� ������� � ������ ������ ����������� 2�
void CopySubArray(
	char **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	char **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols);
//����������� ����� ������� � ������ ������ ����������� 3�
void CopySubArray(
	char ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	char ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols);
