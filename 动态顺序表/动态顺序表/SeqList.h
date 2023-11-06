#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_CAPACITY 4//p_arr的初始容量，即capacity的初始值

typedef int SLDataType;//当需要调整数组类型时，直接调整typedef就可以

typedef struct SeqList
{
	SLDataType* p_arr;//动态数组指针
	int size;//数组内元素数量
	int capacity;//数组容量
}SL;

//函数声明
void SeqListInitil(SL* p_SL);//顺序表初始化
void CheckCapacity(SL* p_SL);//顺序表初始化动态数组内存检查

void SeqListPushBack(SL* p_SL, SLDataType s);//动态数组尾插
void SeqListPushFront(SL* p_SL, SLDataType s);//动态数组首插
void SeqListPushPos(SL* p_SL, SLDataType s, int pos);//动态数组指定位置插入

void SeqListPopBack(SL* p_SL);//动态数组尾删
void SeqListPopFront(SL* p_SL);//动态数组首删
void SeqListPopPos(SL* p_SL, int pos);//动态数组指定位置删除

void SeqListPrintf(SL* p_SL);//打印顺序表
