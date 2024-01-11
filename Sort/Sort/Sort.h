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

void InsertSort(int* arr, int sz);//÷±Ω”≤Â»Î≈≈–Ú
void ShellSort(int* arr, int sz);//œ£∂˚≈≈–Ú
void SelectSort(int* arr, int sz);//÷±Ω”—°‘Ò≈≈–Ú
void HeapSort(int* arr, int sz);//∂—≈≈–Ú
void BubbleSort(int* arr, int sz);//√∞≈›≈≈–Ú
void QuickSort(int* arr, int begin, int end);//øÏÀŸ≈≈–Ú
void QuickSortNonR(int* arr, int begin, int end);//øÏÀŸ≈≈–Ú-∑«µ›πÈ
void  MergeSort(int* arr, int begin, int end);//πÈ≤¢≈≈–Ú
void MergeSortNonR(int* arr, int sz);//πÈ≤¢≈≈–Ú-∑«µ›πÈ
void MergeSortFile(char* fileName);//Õ‚¥ÊπÈ≤¢≈≈–Ú
void Print(int* arr, int sz);//¥Ú”°