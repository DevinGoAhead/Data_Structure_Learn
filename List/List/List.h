#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LN;

//����
LN* ListFind(LN* p_head, LTDataType data);//��ѯ
LN* ListBuyNode(LTDataType data);//�����½ڵ�
void ListInitial(LN **pp_head);//��ʼ��
void ListPushBack(LN* p_head, LTDataType data);//β��
void ListPushFront(LN* p_head, LTDataType data);//�ײ�
void ListInsert(LN* p_head, LTDataType data_dest, LTDataType data_src);//ָ��λ��֮�����
void ListPopBack(LN* p_head);//βɾ
void ListPopFront(LN* p_head);//ͷɾ
void ListErase(LN* p_head, LTDataType data);//ָ��λ��ɾ��
void ListPrint(LN* p_head);//��ӡ