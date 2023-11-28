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

//����
void QueueInitial(Queue* pq);//���г�ʼ��
void QueuePush(Queue* pq, QDataType data);//���
void QueuePop(Queue* pq);//����
int QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
QDataType QueueFront(Queue* pq);//��ȡ��������
QDataType QueueBack(Queue* pq);//��ȡ��β����
int QueueSize(Queue* pq);//��ȡ�������ݸ���
void QueuePrint(Queue* pq);//��ӡ
void QueueDestroy(Queue* pq);//���ٶ���

