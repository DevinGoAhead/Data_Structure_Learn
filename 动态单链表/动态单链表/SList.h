#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;//对链表节点中的数据类型进行重定义，便于批量更改链表数据类型

typedef struct SListNode
{
	SLDataType data;//节点中存放的数据
	struct SListNode* next_node;//节点中存放的指向下一个节点的指针
}SLNode;

SLNode* SListBuyNode(SLDataType data);//申请一个节点
SLNode* SListFind(SLNode* pp_head, SLDataType data);//查询
void SListPushFront(SLNode** pList, SLDataType data);//头插
void SListPushBack(SLNode** pp_head, SLDataType data);//尾插
void SListInsertBefore(SLNode** pp_head, SLDataType data_dest, SLDataType data_src);//指定位置之前插入
void SListInsertAfter(SLNode* pp_head, SLDataType data_dest, SLDataType data_src);//指定位置之后插入
void SListPopFront(SLNode** pp_head);//头删
void SListPopBack(SLNode** pp_head);//尾删
void SListErase(SLNode** pp_head, SLDataType data_dest);//指定位置删除
void SListPrintf(SLNode* pp_head);//打印
void SListDestroy(SLNode** pp_head);//销毁链表