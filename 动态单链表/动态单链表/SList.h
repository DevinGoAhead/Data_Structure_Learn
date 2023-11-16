#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;//������ڵ��е��������ͽ����ض��壬������������������������

typedef struct SListNode
{
	SLDataType data;//�ڵ��д�ŵ�����
	struct SListNode* next_node;//�ڵ��д�ŵ�ָ����һ���ڵ��ָ��
}SLNode;

SLNode* SListBuyNode(SLDataType data);//����һ���ڵ�
SLNode* SListFind(SLNode* pp_head, SLDataType data);//��ѯ
void SListPushFront(SLNode** pList, SLDataType data);//ͷ��
void SListPushBack(SLNode** pp_head, SLDataType data);//β��
void SListInsertBefore(SLNode** pp_head, SLDataType data_dest, SLDataType data_src);//ָ��λ��֮ǰ����
void SListInsertAfter(SLNode* pp_head, SLDataType data_dest, SLDataType data_src);//ָ��λ��֮�����
void SListPopFront(SLNode** pp_head);//ͷɾ
void SListPopBack(SLNode** pp_head);//βɾ
void SListErase(SLNode** pp_head, SLDataType data_dest);//ָ��λ��ɾ��
void SListPrintf(SLNode* pp_head);//��ӡ
void SListDestroy(SLNode** pp_head);//��������