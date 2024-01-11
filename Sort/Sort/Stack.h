#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SKDataType;

#define  capacity_initial 5
#define nSubFile 10//���鲢�����У�ÿ���ָ��ļ��е�������

typedef struct Stack
{
	SKDataType* _p;
	int top;
	int capacity;
}Stack,SK; 

//����
void StackInitial(SK* ps);//ջ��ʼ��
void StackPush(SK* ps, SKDataType data);//��ջ
void StackPop(SK* ps);//��ջ
int StackTop(SK* ps);//��ȡջ��λ��
int StackEmpty(SK* ps);//�ж�ջ�Ƿ�Ϊ��
void StackPrint(SK* ps);//��ӡջ
void StackDestroy(SK* ps);//����
