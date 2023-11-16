#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

int main()
{
	SLNode *pList=NULL;
	//头插
	printf("\n头插\n");
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrintf(pList);
	
	//尾插
	printf("\n尾插\n");
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPushBack(&pList, 8);
	SListPrintf(pList);

	//指定位置之后插入
	printf("\n指定位置之后插入\n");
	SListInsertAfter(pList, 1, 11);
	SListInsertAfter(pList, 6, 66);
	SListInsertAfter(pList, 8, 88);
	SListInsertAfter(pList, 9, 99);
	SListPrintf(pList);

	//指定位置之前插入
	printf("\n指定位置之前插入\n");
	SListInsertBefore(&pList, 1, 0);
	SListInsertBefore(&pList, 66, 60);
	SListInsertBefore(&pList, 88, 80);
	SListInsertAfter(pList, 9, 99);
	SListPrintf(pList);

	//头删
	printf("\n头删\n");
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrintf(pList);

	//尾删
	printf("\n尾删\n");
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrintf(pList);

	//指定位置删除
	printf("\n指定位置删除\n");
	SListErase(&pList, 6);
	SListErase(&pList, 0);
	SListErase(&pList, 8);
	SListErase(&pList, 9);
	SListPrintf(pList);

	//销毁
	SListDestroy(&pList);
	return 0;
}