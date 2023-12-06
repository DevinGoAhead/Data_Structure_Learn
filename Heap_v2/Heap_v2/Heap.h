#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>

typedef int HPDataType;
#define capacityInitial 5

typedef struct Heap
{
	HPDataType* pa;
	int capacity;
	int size;
}Heap;

//����
void HeapSwap(HPDataType* pa_1, HPDataType* pa_2);// ����
void HeapAdjustDown(HPDataType* pa, int parent,int numEnd);// ���µ����㷨
void HeapAdjustUp(HPDataType* pa, int child);//���ϵ����㷨
void HeapInitial(Heap* pHp);//�ѳ�ʼ��+������
void HeapSort(Heap* pHp);//������
int HeapFind(Heap* pHp, HPDataType posNum);//�Ѳ���
void HeapPopBack(Heap* pHp);//β���ɾ��
void HeapPopPos(Heap* pHp, HPDataType posNum);//�������ɾ��
void HeapPush(Heap* pHp, HPDataType posNum);//������
HPDataType HeapTop(Heap* pHp);//���ضѶ�Ԫ��
HPDataType HeapBack(Heap* pHp);//���ض�βԪ��
void HeapTopMin(Heap* pHp, HPDataType* arr, int sz, int k);//�ҳ������е�ǰk����Сֵ
void HeapPrint(Heap* pHp);//�Ѵ�ӡ
void HeapDestroy(Heap* pHp);//������
