#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define initialCapacity 5

typedef struct Heap
{
	int* pData;
	int size;
	int capacity;
}Heap;

void InsertSort(int* arr, int sz);//ֱ�Ӳ�������
void ShellSort(int* arr, int sz);//ϣ������
void SelectSort(int* arr, int sz);//ֱ��ѡ������
void HeapSort(int* arr, int sz);//������
void BubbleSort(int* arr, int sz);//ð������
void QuickSort(int* arr, int begin, int end);//��������
void QuickSortNonR(int* arr, int begin, int end);//��������-�ǵݹ�
void  MergeSort(int* arr, int begin, int end);//�鲢����
void MergeSortNonR(int* arr, int sz);//�鲢����-�ǵݹ�
void MergeSortFile(char* fileName);//���鲢����
void Print(int* arr, int sz);//��ӡ