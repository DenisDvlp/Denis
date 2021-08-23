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
//����������� �������

//��������� �������� �������

//���������� ��������
//�������� ��������
//������������ ��������
//������� �������
//������� �������