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

//声明
void HeapSwap(HPDataType* pa_1, HPDataType* pa_2);// 交换
void HeapAdjustDown(Heap* pHp, int i,int sz);// 向下调整算法
void HeapAdjustUp(Heap* pHp, int i);//向上调整算法
void HeapInitial(Heap* pHp, HPDataType* arr, int sz);//堆初始化+构建堆
void HeapSort(Heap* pHp);//堆排序
int HeapFind(Heap* pHp, HPDataType posNum);//堆查找
void HeapPopBack(Heap* pHp);//尾结点删除
void HeapPopPos(Heap* pHp, HPDataType posNum);//其他结点删除
void HeapPush(Heap* pHp, HPDataType posNum);//插入结点
HPDataType HeapTop(Heap* pHp);//返回堆顶元素
HPDataType HeapBack(Heap* pHp);//返回堆尾元素
void HeapPrint(Heap* pHp);//堆打印
void HeapDestroy(Heap* pHp);//堆销毁
