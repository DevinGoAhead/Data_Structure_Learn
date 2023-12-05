#pragma once

typedef int HPDataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct Heap
{
	HPDataType* pa;
	int capacity;
	int size;
}Heap;

//����
void HeapSwap(HPDataType* pa_1, HPDataType* pa_2);// ����
void HeapAdjustDown(Heap* pHp, int i,int sz);// ���µ����㷨
void HeapAdjustUp(Heap* pHp, int i);//���ϵ����㷨
void HeapInitial(Heap* pHp, HPDataType* arr, int sz);//�ѳ�ʼ��+������
void HeapSort(Heap* pHp);//������
int HeapFind(Heap* pHp, HPDataType posNum);//�Ѳ���
void HeapPopBack(Heap* pHp);//β���ɾ��
void HeapPopPos(Heap* pHp, HPDataType posNum);//�������ɾ��
void HeapPush(Heap* pHp, HPDataType posNum);//������
HPDataType HeapTop(Heap* pHp);//���ضѶ�Ԫ��
HPDataType HeapBack(Heap* pHp);//���ض�βԪ��
void HeapPrint(Heap* pHp);//�Ѵ�ӡ
void HeapDestroy(Heap* pHp);//������
