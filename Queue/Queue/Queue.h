#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//声明
void QueueInitial(Queue* pq);//队列初始化
void QueuePush(Queue* pq, QDataType data);//入队
void QueuePop(Queue* pq);//出队
int QueueEmpty(Queue* pq);//判断队列是否为空
QDataType QueueFront(Queue* pq);//获取队首数据
QDataType QueueBack(Queue* pq);//获取队尾数据
int QueueSize(Queue* pq);//获取队列数据个数
void QueuePrint(Queue* pq);//打印
void QueueDestroy(Queue* pq);//销毁队列

