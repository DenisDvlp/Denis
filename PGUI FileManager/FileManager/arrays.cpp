/*
1. �������� ������� (1, 2, 3 - ������)
	1.1 �������������
	1.2 ������������
	1.3 ����������
2. �������� ������� (1, 2, 3 - ������)
	2.1 �������������
	2.2 ������������
	2.3 ����������
3. ����� ������� (1, 2, 3 - ������)
	3.1 �������������
	3.2 ������������
	3.3 ����������
	3.4 ������
4. ������������� ������� ���������� ���������� (1, 2, 3 - ������)
	4.1 � ���������
		4.1.1 �������������
		4.1.2 ������������
		4.1.3 ����������
	4.2 �� �������
		4.2.1 �������������
		4.2.2 ������������
		4.2.3 ����������
	4.3 ��������� ����� ���������
		4.3.1 �������������
		4.3.2 ������������
		4.3.3 ����������
	4.4 ���� ������ ����� ���������
		4.4.1 �������������
		4.4.2 ������������
		4.4.3 ����������
5. ����� ����������/���������� ����������
6. ��������� ���������� ��������
7. ����� ��������
	7.1 �������� ����� �������
	7.2 ����������� �������
8. ��������� �������� �������
	8.1 ���������� ��������
	8.2 �������� ��������
	8.3 ������������ ��������
	8.4 ������� �������
	8.5 ������� �������
*/
#include <iostream>
#include <cstring>
#include "arrays.h"

using namespace std;

//�������� �������

//�������� �������������� �������
int* CreateIntArray(int size) {
	if (size <= 0)
		return NULL;
	return new int[size];
}

//�������� ����������� �������������� �������
int** CreateIntArray(int rows, int cols) {
	if (rows <= 0 || cols <= 0)
		return NULL;
	int **array = new int*[rows];
	for (int i = 0; i < rows; i++)
		array[i] = CreateIntArray(cols);
	return array;
}

//�������� ���������� �������������� �������
int*** CreateIntArray(int depth, int rows, int cols) {
	if (depth <= 0 || rows <= 0 || cols <= 0)
		return NULL;
	int ***array = new int**[depth];
	for (int i = 0; i < depth; i++)
		array[i] = CreateIntArray(rows, cols);
	return array;
}

//�������� ������������� �������
double* CreateDoubleArray(int size) {
	if (size <= 0)
		return NULL;
	return new double[size];
}

//�������� ����������� ������������� �������
double** CreateDoubleArray(int rows, int cols) {
	if (rows <= 0 || cols <= 0)
		return NULL;
	double **array = new double*[rows];
	for (int i = 0; i < rows; i++)
		array[i] = CreateDoubleArray(cols);
	return array;
}

//�������� ���������� ������������� �������
double*** CreateDoubleArray(int depth, int rows, int cols) {
	if (depth <= 0 || rows <= 0 || cols <= 0)
		return NULL;
	double ***array = new double**[depth];
	for (int i = 0; i < depth; i++)
		array[i] = CreateDoubleArray(rows, cols);
	return array;
}

//�������� ����������� �������
char* CreateCharArray(int size) {
	if (size <= 0)
		return NULL;
	return new char[size];
}

//�������� ����������� ����������� �������
char** CreateCharArray(int rows, int cols) {
	if (rows <= 0 || cols <= 0)
		return NULL;
	char **array = new char*[rows];
	for (int i = 0; i < rows; i++)
		array[i] = CreateCharArray(cols);
	return array;
}

//�������� ���������� ����������� �������
char*** CreateCharArray(int depth, int rows, int cols) {
	if (depth <= 0 || rows <= 0 || cols <= 0)
		return NULL;
	char ***array = new char**[depth];
	for (int i = 0; i < depth; i++)
		array[i] = CreateCharArray(rows, cols);
	return array;
}

//�������� �������

//�������� �������������� �������
void DeleteArray(int *array) {
	delete[] array;
}

//�������� ����������� �������������� �������
void DeleteArray(int **array, int rows) {
	for (int i = 0; i < rows; i++)
		DeleteArray(array[i]);
	DeleteArray((int*)array);
}

//�������� ���������� �������������� �������
void DeleteArray(int ***array, int depth, int rows) {
	for (int i = 0; i < depth; i++)
		DeleteArray(array[i], rows);
	DeleteArray((int*)array);
}

//�������� ������������� �������
void DeleteArray(double *array) {
	delete[] array;
}

//�������� ����������� ������������� �������
void DeleteArray(double **array, int rows) {
	for (int i = 0; i < rows; i++)
		DeleteArray(array[i]);
	DeleteArray((double*)array);
}

//�������� ���������� ������������� �������
void DeleteArray(double ***array, int depth, int rows) {
	for (int i = 0; i < depth; i++)
		DeleteArray(array[i], rows);
	DeleteArray((double*)array);
}

//�������� ����������� �������
void DeleteArray(char *array) {
	delete[] array;
}

//�������� ����������� ����������� �������
void DeleteArray(char **array, int rows) {
	for (int i = 0; i < rows; i++)
		DeleteArray(array[i]);
	DeleteArray((char*)array);
}

//�������� ���������� ����������� �������
void DeleteArray(char ***array, int depth, int rows) {
	for (int i = 0; i < depth; i++)
		DeleteArray(array[i], rows);
	DeleteArray((char*)array);
}

//����� �������

//����� �������������� �������
void ShowArray(int *array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

//����� ����������� �������������� �������
void ShowArray(int **array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		ShowArray(array[i], cols);
		cout << endl;
	}
}

//����� ���������� �������������� �������
void ShowArray(int ***array, int depth, int rows, int cols) {
	for (int i = 0; i < depth; i++) {
		ShowArray(array[i], rows, cols);
		cout << endl;
	}
}

//����� ������������� �������
void ShowArray(double *array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

//����� ����������� ������������� �������
void ShowArray(double **array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		ShowArray(array[i], cols);
		cout << endl;
	}
}

//����� ���������� ������������� �������
void ShowArray(double ***array, int depth, int rows, int cols) {
	for (int i = 0; i < depth; i++) {
		ShowArray(array[i], rows, cols);
		cout << endl;
	}
}

//����� ����������� �������
void ShowArray(char *array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

//����� ����������� ����������� �������
void ShowArray(char **array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		ShowArray(array[i], cols);
		cout << endl;
	}
}

//����� ���������� ����������� �������
void ShowArray(char ***array, int depth, int rows, int cols) {
	for (int i = 0; i < depth; i++) {
		ShowArray(array[i], rows, cols);
		cout << endl;
	}
}

//����� ������
void ShowString(char *array) {
	cout << array;
}

//����� ������� �����
void ShowStrings(char **array, int rows) {
	for (int i = 0; i < rows; i++) {
		ShowString(array[i]);
		cout << endl;
	}
}

//����� ����������� ������� �����
void ShowStrings(char ***array, int depth, int rows) {
	for (int i = 0; i < depth; i++) {
		ShowStrings(array[i], rows);
		cout << endl;
	}
}

//������������� �������

//������������� �������������� ������� ���������� ����������
void InitRandomArray(int *array, int size, int from, int to) {
	for (int i = 0; i < size; i++)
		array[i] = GetRand(from, to);
}

//������������� ����������� �������������� ������� ���������� ����������
void InitRandomArray(int **array, int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
		InitRandomArray(array[i], cols, from, to);
}

//������������� ���������� �������������� ������� ���������� ����������
void InitRandomArray(int ***array, int depth, int rows, int cols, int from, int to) {
	for (int i = 0; i < depth; i++)
		InitRandomArray(array[i], rows, cols, from, to);
}

//������������� ������������� ������� ���������� ����������
void InitRandomArray(double *array, int size, double from, double to) {
	for (int i = 0; i < size; i++)
		array[i] = GetRand(from, to);
}

//������������� ����������� ������������� ������� ���������� ����������
void InitRandomArray(double **array, int rows, int cols, double from, double to) {
	for (int i = 0; i < rows; i++)
		InitRandomArray(array[i], cols, from, to);
}

//������������� ���������� ������������� ������� ���������� ����������
void InitRandomArray(double ***array, int depth, int rows, int cols, double from, double to) {
	for (int i = 0; i < depth; i++)
		InitRandomArray(array[i], rows, cols, from, to);
}

//������������� ����������� ������� ���������� ����������
void InitRandomArray(char *array, int size, char from, char to) {
	for (int i = 0; i < size; i++)
		array[i] = GetRand(from, to);
}

//������������� ����������� ����������� ������� ���������� ����������
void InitRandomArray(char **array, int rows, int cols, char from, char to) {
	for (int i = 0; i < rows; i++)
		InitRandomArray(array[i], cols, from, to);
}

//������������� ���������� ����������� ������� ���������� ����������
void InitRandomArray(char ***array, int depth, int rows, int cols, char from, char to) {
	for (int i = 0; i < depth; i++)
		InitRandomArray(array[i], rows, cols, from, to);
}

//������������� �������������� ������� ���������� �� ������
void InitRandomArrayFromAlphabet(int *array, int size, int *alphabet, int asize) {
	for (int i = 0; i < size; i++)
		array[i] = GetRandFromArray(alphabet, asize);
}

//������������� ����������� �������������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(int **array, int rows, int cols, int *alphabet, int asize) {
	for (int i = 0; i < rows; i++)
		InitRandomArrayFromAlphabet(array[i], cols, alphabet, asize);
}

//������������� ���������� �������������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(int ***array, int depth, int rows, int cols, int *alphabet, int asize) {
	for (int i = 0; i < depth; i++)
		InitRandomArrayFromAlphabet(array[i], rows, cols, alphabet, asize);
}

//������������� ������������� ������� ���������� �� ������
void InitRandomArrayFromAlphabet(double *array, int size, double *alphabet, int asize) {
	for (int i = 0; i < size; i++)
		array[i] = GetRandFromArray(alphabet, asize);
}

//������������� ����������� ������������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(double **array, int rows, int cols, double *alphabet, int asize) {
	for (int i = 0; i < rows; i++)
		InitRandomArrayFromAlphabet(array[i], cols, alphabet, asize);
}

//������������� ���������� ������������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(double ***array, int depth, int rows, int cols, double *alphabet, int asize) {
	for (int i = 0; i < depth; i++)
		InitRandomArrayFromAlphabet(array[i], rows, cols, alphabet, asize);
}

//������������� ����������� ������� ���������� �� ������
void InitRandomArrayFromAlphabet(char *array, int size, char *alphabet, int asize) {
	for (int i = 0; i < size; i++)
		array[i] = GetRandFromArray(alphabet, asize);
}

//������������� ����������� ����������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(char **array, int rows, int cols, char *alphabet, int asize) {
	for (int i = 0; i < rows; i++)
		InitRandomArrayFromAlphabet(array[i], cols, alphabet, asize);
}

//������������� ���������� ����������� ������� ���������� ����������
void InitRandomArrayFromAlphabet(char ***array, int depth, int rows, int cols, char *alphabet, int asize) {
	for (int i = 0; i < depth; i++)
		InitRandomArrayFromAlphabet(array[i], rows, cols, alphabet, asize);
}

//���������� ����� �������������� ������� ���������
void FillSubArray(int *array, int start, int count, int value) {
	int size = start + count;
	for (int i = start; i < size; i++)
		array[i] = value;
}

//���������� ����� ����������� �������������� ������� ���������
void FillSubArray(int **array, int startRow, int startCol, int rowCount, int colCount, int value) {
	int size = startRow + rowCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startCol, colCount, value);
}

//���������� ����� ���������� �������������� ������� ���������
void FillSubArray(int ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, int value) {
	int size = startDepth + depthCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startRow, startCol, rowCount, colCount, value);
}

//���������� ����� ������������� ������� ���������
void FillSubArray(double *array, int start, int count, double value) {
	int size = start + count;
	for (int i = start; i < size; i++)
		array[i] = value;
}

//���������� ����� ����������� ������������� ������� ���������
void FillSubArray(double **array, int startRow, int startCol, int rowCount, int colCount, double value) {
	int size = startRow + rowCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startCol, colCount, value);
}

//���������� ����� ���������� ������������� ������� ���������
void FillSubArray(double ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, double value) {
	int size = startDepth + depthCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startRow, startCol, rowCount, colCount, value);
}

//���������� ����� ����������� ������� ���������
void FillSubArray(char *array, int start, int count, char value) {
	int size = start + count;
	for (int i = start; i < size; i++)
		array[i] = value;
}

//���������� ����� ����������� ����������� ������� ���������
void FillSubArray(char **array, int startRow, int startCol, int rowCount, int colCount, char value) {
	int size = startRow + rowCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startCol, colCount, value);
}

//���������� ����� ���������� ����������� ������� ���������
void FillSubArray(char ***array, int startDepth, int startRow, int startCol, int depthCount, int rowCount, int colCount, char value) {
	int size = startDepth + depthCount;
	for (int i = startRow; i < size; i++)
		FillSubArray(array[i], startRow, startCol, rowCount, colCount, value);
}

//���������� �������������� ������� ���������
void FillArray(int *array, int size, int value) {
	FillSubArray(array, 0, size, value);
}

//���������� ����������� �������������� ������� ���������
void FillArray(int **array, int rows, int cols, int value) {
	FillSubArray(array, 0, 0, rows, cols, value);
}

//���������� ���������� �������������� ������� ���������
void FillArray(int ***array, int depth, int rows, int cols, int value) {
	FillSubArray(array, 0, 0, 0, depth, rows, cols, value);
}

//���������� ������������� ������� ���������
void FillArray(double *array, int size, double value) {
	FillSubArray(array, 0, size, value);
}

//���������� ����������� ������������� ������� ���������
void FillArray(double **array, int rows, int cols, double value) {
	FillSubArray(array, 0, 0, rows, cols, value);
}

//���������� ���������� ������������� ������� ���������
void FillArray(double ***array, int depth, int rows, int cols, double value) {
	FillSubArray(array, 0, 0, 0, depth, rows, cols, value);
}

//���������� ����������� ������� ���������
void FillArray(char *array, int size, char value) {
	FillSubArray(array, 0, size, value);
}

//���������� ����������� ����������� ������� ���������
void FillArray(char **array, int rows, int cols, char value) {
	FillSubArray(array, 0, 0, rows, cols, value);
}

//���������� ���������� ����������� ������� ���������
void FillArray(char ***array, int depth, int rows, int cols, char value) {
	FillSubArray(array, 0, 0, 0, depth, rows, cols, value);
}

//����� ����������/���������� ����������

//����� ���������� ����������
void Exchange(int &first, int &second) {
	int tmp = first;
	first = second;
	second = tmp;
}

//����� ���������� ����������
void Exchange(double &first, double &second) {
	double tmp = first;
	first = second;
	second = tmp;
}

//����� ���������� ����������
void Exchange(char &first, char &second) {
	char tmp = first;
	first = second;
	second = tmp;
}

//����� ���������� ����������
void Exchange(void* &first, void* &second) {
	void *tmp = first;
	first = second;
	second = tmp;
}

//����� ���������� ����������
void Exchange(int* &first, int* &second) {
	Exchange((void*&)first, (void*&)second);
}

//����� ���������� ����������
void Exchange(int** &first, int** &second) {
	Exchange((void*&)first, (void*&)second);
}

//����� ���������� ����������
void Exchange(double* &first, double* &second) {
	Exchange((void*&)first, (void*&)second);
}

//����� ���������� ����������
void Exchange(double** &first, double** &second) {
	Exchange((void*&)first, (void*&)second);
}

//����� ���������� ����������
void Exchange(char* &first, char* &second) {
	Exchange((void*&)first, (void*&)second);
}

//����� ���������� ����������
void Exchange(char** &first, char** &second) {
	Exchange((void*&)first, (void*&)second);
}

//��������� ���������� ��������

//��������� ������������� ����� � ���������
int GetRand(int from, int to) {
	if (to < from)
		Exchange(from, to);
	return rand() % (to - from + 1) + from;
}

//��������� ������������ ����� � ���������
double GetRand(double from, double to) {
	if (to < from)
		Exchange(from, to);
	return rand() % (int)(to - from + 1) + from + rand() % 100 * 0.01;
}

//��������� ������ � ���������
char GetRand(char from, char to) {
	if (to < from)
		Exchange(from, to);
	return rand() % (to - from + 1) + from;
}

//��������� ����� ����� �� �������
int GetRandFromArray(int *array, int size) {
	if (size <= 0)
		return 0;
	return array[rand() % size];
}

//��������� ������������ ����� �� �������
double GetRandFromArray(double *array, int size) {
	if (size <= 0)
		return 0;
	return array[rand() % size];
}

//��������� ������ �� �������
char GetRandFromArray(char *array, int size) {
	if (size <= 0)
		return 0;
	return array[rand() % size];
}


//����� ��������

//�������� ����� �������

//�������� ����� ������� �������������
int* CreateCopyArray(int *array, int size) {
	return CreateCopySubArray(array, size, 0, size - 1);
}

//�������� ����� ������� ������������� 2�
int** CreateCopyArray(int **array, int rows, int cols) {
	return CreateCopySubArray(array, rows, cols, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ������� ������������� 3�
int*** CreateCopyArray(int ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	return CreateCopySubArray(array, depth, rows, cols, 0, depth - 1, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ������� �������������
double* CreateCopyArray(double *array, int size) {
	return CreateCopySubArray(array, size, 0, size - 1);
}

//�������� ����� ������� ������������� 2�
double** CreateCopyArray(double **array, int rows, int cols) {
	return CreateCopySubArray(array, rows, cols, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ������� ������������� 3�
double*** CreateCopyArray(double ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	return CreateCopySubArray(array, depth, rows, cols, 0, depth - 1, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ������� �����������
char* CreateCopyArray(char *array, int size) {
	return CreateCopySubArray(array, size, 0, size - 1);
}

//�������� ����� ������� ����������� 2�
char** CreateCopyArray(char **array, int rows, int cols) {
	return CreateCopySubArray(array, rows, cols, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ������� ����������� 3�
char*** CreateCopyArray(char ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	return CreateCopySubArray(array, depth, rows, cols, 0, depth - 1, 0, rows - 1, 0, cols - 1);
}

//�������� ����� ���������� �������������
int* CreateCopySubArray(int *array, int size, int from, int to) {
	int newSize = to - from + 1;
	int *copy = CreateIntArray(newSize);
	CopySubArray(copy, newSize, 0, array, size, from, newSize);
	return copy;
}

//�������� ����� ���������� ������������� 2�
int** CreateCopySubArray(int **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol) {
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	int **copy = CreateIntArray(newRows, newCols);
	CopySubArray(copy, newRows, newCols, 0, 0,
		array, rows, cols, fromRow, fromCol, newRows, newCols);
	return copy;
}

//�������� ����� ���������� ������������� 3�
int*** CreateCopySubArray(int ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	int newDepth = toDepth - fromDepth + 1;
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	int ***copy = CreateIntArray(newDepth, newRows, newCols);
	CopySubArray(copy, newDepth, newRows, newCols, 0, 0, 0,
		array, depth, rows, cols, fromDepth, fromRow, fromCol, newDepth, newRows, newCols);
	return copy;
}

//�������� ����� ���������� �������������
double* CreateCopySubArray(double *array, int size, int from, int to) {
	int newSize = to - from + 1;
	double *copy = CreateDoubleArray(newSize);
	CopySubArray(copy, newSize, 0, array, size, from, newSize);
	return copy;
}

//�������� ����� ���������� ������������� 2�
double** CreateCopySubArray(double **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol) {
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	double **copy = CreateDoubleArray(newRows, newCols);
	CopySubArray(copy, newRows, newCols, 0, 0,
		array, rows, cols, fromRow, fromCol, newRows, newCols);
	return copy;
}

//�������� ����� ���������� ������������� 3�
double*** CreateCopySubArray(double ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	int newDepth = toDepth - fromDepth + 1;
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	double ***copy = CreateDoubleArray(newDepth, newRows, newCols);
	CopySubArray(copy, newDepth, newRows, newCols, 0, 0, 0,
		array, depth, rows, cols, fromDepth, fromRow, fromCol, newDepth, newRows, newCols);
	return copy;
}

//�������� ����� ���������� �����������
char* CreateCopySubArray(char *array, int size, int from, int to) {
	int newSize = to - from + 1;
	char *copy = CreateCharArray(newSize);
	CopySubArray(copy, newSize, 0, array, size, from, newSize);
	return copy;
}

//�������� ����� ���������� ����������� 2�
char** CreateCopySubArray(char **array, int rows, int cols,
	int fromRow, int toRow, int fromCol, int toCol) {
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	char **copy = CreateCharArray(newRows, newCols);
	CopySubArray(copy, newRows, newCols, 0, 0,
		array, rows, cols, fromRow, fromCol, newRows, newCols);
	return copy;
}

//�������� ����� ���������� ����������� 3�
char*** CreateCopySubArray(char ***array, int depth, int rows, int cols,
	int fromDepth, int toDepth, int fromRow, int toRow, int fromCol, int toCol) {
	int newDepth = toDepth - fromDepth + 1;
	int newRows = toRow - fromRow + 1;
	int newCols = toCol - fromCol + 1;
	char ***copy = CreateCharArray(newDepth, newRows, newCols);
	CopySubArray(copy, newDepth, newRows, newCols, 0, 0, 0,
		array, depth, rows, cols, fromDepth, fromRow, fromCol, newDepth, newRows, newCols);
	return copy;
}

//����������� �������

//����������� ����� ������� � ������ ������ �������������
void CopySubArray(
	int *dest, int destSize, int destOffset,
	int *src, int srcSize, int srcOffset,
	int count) {
	if (destOffset < 0) destOffset = 0;
	if (destOffset > destSize - 1) destOffset = destSize - 1;
	if (srcOffset < 0) srcOffset = 0;
	if (srcOffset > srcSize - 1) srcOffset = srcSize - 1;
	if (count > destSize - destOffset) count = destSize - destOffset;
	if (count > srcSize - srcOffset) count = srcSize - srcOffset;
	for (int i = 0, d = destOffset, s = srcOffset; i < count; i++, d++, s++)
		dest[d] = src[s];
}

//����������� ����� ������� � ������ ������ ������������� 2�
void CopySubArray(
	int **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	int **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols) {
	if (destOffsetRow < 0) destOffsetRow = 0;
	if (destOffsetRow > destRows - 1) destOffsetRow = destRows - 1;
	if (srcOffsetRow < 0) srcOffsetRow = 0;
	if (srcOffsetRow > srcRows - 1) srcOffsetRow = srcRows - 1;
	if (countRows > destRows - destOffsetRow) countRows = destRows - destOffsetRow;
	if (countRows > srcRows - srcOffsetRow) countRows = srcRows - srcOffsetRow;
	for (int i = 0, d = destOffsetRow, s = srcOffsetRow; i < countRows; i++, d++, s++)
		CopySubArray(dest[d], destCols, destOffsetCol, src[s], srcCols, srcOffsetCol, countCols);
}

//����������� ����� ������� � ������ ������ ������������� 3�
void CopySubArray(
	int ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	int ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols) {
	if (destOffsetDepth < 0) destOffsetDepth = 0;
	if (destOffsetDepth > destDepth - 1) destOffsetDepth = destDepth - 1;
	if (srcOffsetDepth < 0) srcOffsetDepth = 0;
	if (srcOffsetDepth > srcDepth - 1) srcOffsetDepth = srcDepth - 1;
	if (countDepth > destDepth - destOffsetDepth) countDepth = destDepth - destOffsetDepth;
	if (countDepth > srcDepth - srcOffsetDepth) countDepth = srcDepth - srcOffsetDepth;
	for (int i = 0, d = destOffsetDepth, s = srcOffsetDepth; i < countDepth; i++, d++, s++)
		CopySubArray(dest[d], destRows, destCols, destOffsetRow, destOffsetCol,
			src[s], srcRows, srcCols, srcOffsetRow, srcOffsetCol,
			countRows, countCols);
}

//����������� ����� ������� � ������ ������ �������������
void CopySubArray(
	double *dest, int destSize, int destOffset,
	double *src, int srcSize, int srcOffset,
	int count) {
	if (destOffset < 0) destOffset = 0;
	if (destOffset > destSize - 1) destOffset = destSize - 1;
	if (srcOffset < 0) srcOffset = 0;
	if (srcOffset > srcSize - 1) srcOffset = srcSize - 1;
	if (count > destSize - destOffset) count = destSize - destOffset;
	if (count > srcSize - srcOffset) count = srcSize - srcOffset;
	for (int i = 0, d = destOffset, s = srcOffset; i < count; i++, d++, s++)
		dest[d] = src[s];
}

//����������� ����� ������� � ������ ������ ������������� 2�
void CopySubArray(
	double **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	double **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols) {
	if (destOffsetRow < 0) destOffsetRow = 0;
	if (destOffsetRow > destRows - 1) destOffsetRow = destRows - 1;
	if (srcOffsetRow < 0) srcOffsetRow = 0;
	if (srcOffsetRow > srcRows - 1) srcOffsetRow = srcRows - 1;
	if (countRows > destRows - destOffsetRow) countRows = destRows - destOffsetRow;
	if (countRows > srcRows - srcOffsetRow) countRows = srcRows - srcOffsetRow;
	for (int i = 0, d = destOffsetRow, s = srcOffsetRow; i < countRows; i++, d++, s++)
		CopySubArray(dest[d], destCols, destOffsetCol, src[s], srcCols, srcOffsetCol, countCols);
}

//����������� ����� ������� � ������ ������ ������������� 3�
void CopySubArray(
	double ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	double ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols) {
	if (destOffsetDepth < 0) destOffsetDepth = 0;
	if (destOffsetDepth > destDepth - 1) destOffsetDepth = destDepth - 1;
	if (srcOffsetDepth < 0) srcOffsetDepth = 0;
	if (srcOffsetDepth > srcDepth - 1) srcOffsetDepth = srcDepth - 1;
	if (countDepth > destDepth - destOffsetDepth) countDepth = destDepth - destOffsetDepth;
	if (countDepth > srcDepth - srcOffsetDepth) countDepth = srcDepth - srcOffsetDepth;
	for (int i = 0, d = destOffsetDepth, s = srcOffsetDepth; i < countDepth; i++, d++, s++)
		CopySubArray(dest[d], destRows, destCols, destOffsetRow, destOffsetCol,
			src[s], srcRows, srcCols, srcOffsetRow, srcOffsetCol,
			countRows, countCols);
}

//����������� ����� ������� � ������ ������ �����������
void CopySubArray(
	char *dest, int destSize, int destOffset,
	char *src, int srcSize, int srcOffset,
	int count) {
	if (destOffset < 0) destOffset = 0;
	if (destOffset > destSize - 1) destOffset = destSize - 1;
	if (srcOffset < 0) srcOffset = 0;
	if (srcOffset > srcSize - 1) srcOffset = srcSize - 1;
	if (count > destSize - destOffset) count = destSize - destOffset;
	if (count > srcSize - srcOffset) count = srcSize - srcOffset;
	for (int i = 0, d = destOffset, s = srcOffset; i < count; i++, d++, s++)
		dest[d] = src[s];
}

//����������� ����� ������� � ������ ������ ����������� 2�
void CopySubArray(
	char **dest, int destRows, int destCols, int destOffsetRow, int destOffsetCol,
	char **src, int srcRows, int srcCols, int srcOffsetRow, int srcOffsetCol,
	int countRows, int countCols) {
	if (destOffsetRow < 0) destOffsetRow = 0;
	if (destOffsetRow > destRows - 1) destOffsetRow = destRows - 1;
	if (srcOffsetRow < 0) srcOffsetRow = 0;
	if (srcOffsetRow > srcRows - 1) srcOffsetRow = srcRows - 1;
	if (countRows > destRows - destOffsetRow) countRows = destRows - destOffsetRow;
	if (countRows > srcRows - srcOffsetRow) countRows = srcRows - srcOffsetRow;
	for (int i = 0, d = destOffsetRow, s = srcOffsetRow; i < countRows; i++, d++, s++)
		CopySubArray(dest[d], destCols, destOffsetCol, src[s], srcCols, srcOffsetCol, countCols);
}

//����������� ����� ������� � ������ ������ ����������� 3�
void CopySubArray(
	char ***dest, int destDepth, int destRows, int destCols, int destOffsetDepth, int destOffsetRow, int destOffsetCol,
	char ***src, int srcDepth, int srcRows, int srcCols, int srcOffsetDepth, int srcOffsetRow, int srcOffsetCol,
	int countDepth, int countRows, int countCols) {
	if (destOffsetDepth < 0) destOffsetDepth = 0;
	if (destOffsetDepth > destDepth - 1) destOffsetDepth = destDepth - 1;
	if (srcOffsetDepth < 0) srcOffsetDepth = 0;
	if (srcOffsetDepth > srcDepth - 1) srcOffsetDepth = srcDepth - 1;
	if (countDepth > destDepth - destOffsetDepth) countDepth = destDepth - destOffsetDepth;
	if (countDepth > srcDepth - srcOffsetDepth) countDepth = srcDepth - srcOffsetDepth;
	for (int i = 0, d = destOffsetDepth, s = srcOffsetDepth; i < countDepth; i++, d++, s++)
		CopySubArray(dest[d], destRows, destCols, destOffsetRow, destOffsetCol,
			src[s], srcRows, srcCols, srcOffsetRow, srcOffsetCol,
			countRows, countCols);
}

//��������� �������� �������

//���������� ��������
//�������� ��������
//������������ ��������
//������� �������
//������� �������