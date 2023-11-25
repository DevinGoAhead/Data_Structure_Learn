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

//声明
LN* ListFind(LN* p_head, LTDataType data);//查询
LN* ListBuyNode(LTDataType data);//申请新节点
void ListInitial(LN **pp_head);//初始化
void ListPushBack(LN* p_head, LTDataType data);//尾插
void ListPushFront(LN* p_head, LTDataType data);//首插
void ListInsert(LN* p_head, LTDataType data_dest, LTDataType data_src);//指定位置之后插入
void ListPopBack(LN* p_head);//尾删
void ListPopFront(LN* p_head);//头删
void ListErase(LN* p_head, LTDataType data);//指定位置删除
void ListPrint(LN* p_head);//打印