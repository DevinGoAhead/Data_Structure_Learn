#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void Test1()
{
	LN* p_head = NULL;
	ListInitial(&p_head);//初始化
	
	//尾插
	printf("尾插\n");
	ListPushBack(p_head, 1);
	ListPushBack(p_head, 2);
	ListPushBack(p_head, 3);
	ListPushBack(p_head, 4);
	ListPrint(p_head);

	//首插
	printf("首插\n");
	ListPushFront(p_head, 5);
	ListPushFront(p_head, 6);
	ListPushFront(p_head, 7);
	ListPushFront(p_head, 8);
	ListPrint(p_head);

	//尾删
	printf("尾删\n");
	ListPopBack(p_head);
	ListPopBack(p_head);
	ListPopBack(p_head);
	ListPrint(p_head);

	//头删
	printf("头删\n");
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPrint(p_head);

	//指定位置插入
	printf("指定位置之后插入\n");
	ListInsert(p_head, 1, 11);
	ListInsert(p_head, 11, 2);
	ListInsert(p_head, 2, 22);
	ListInsert(p_head, 4, 3);
	ListPrint(p_head);

	//指定位置之后删除
	printf("指定位置删除\n");
	ListErase(p_head, 1);
	ListErase(p_head, 4);
	ListErase(p_head, 22);
	ListErase(p_head, 2);
	ListErase(p_head, 11);
	ListErase(p_head, 11);
	ListPrint(p_head);

	////清除链表
	//printf("清除链表\n");
	//ClearList(p_head);
	//ListPrint(p_head);

	//清除链表
	printf("销毁链表\n");
	DestroyList(&p_head);
	ListPrint(p_head);
}

int main()
{
	Test1();
}