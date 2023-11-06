#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_CAPACITY 4//p_arr�ĳ�ʼ��������capacity�ĳ�ʼֵ

typedef int SLDataType;//����Ҫ������������ʱ��ֱ�ӵ���typedef�Ϳ���

typedef struct SeqList
{
	SLDataType* p_arr;//��̬����ָ��
	int size;//������Ԫ������
	int capacity;//��������
}SL;

//��������
void SeqListInitil(SL* p_SL);//˳����ʼ��
void CheckCapacity(SL* p_SL);//˳����ʼ����̬�����ڴ���

void SeqListPushBack(SL* p_SL, SLDataType s);//��̬����β��
void SeqListPushFront(SL* p_SL, SLDataType s);//��̬�����ײ�
void SeqListPushPos(SL* p_SL, SLDataType s, int pos);//��̬����ָ��λ�ò���

void SeqListPopBack(SL* p_SL);//��̬����βɾ
void SeqListPopFront(SL* p_SL);//��̬������ɾ
void SeqListPopPos(SL* p_SL, int pos);//��̬����ָ��λ��ɾ��

void SeqListPrintf(SL* p_SL);//��ӡ˳���
