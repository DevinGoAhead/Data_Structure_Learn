#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

int main()
{
	SLNode *pList=NULL;
	//ͷ��
	printf("\nͷ��\n");
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrintf(pList);
	
	//β��
	printf("\nβ��\n");
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPushBack(&pList, 8);
	SListPrintf(pList);

	//ָ��λ��֮�����
	printf("\nָ��λ��֮�����\n");
	SListInsertAfter(pList, 1, 11);
	SListInsertAfter(pList, 6, 66);
	SListInsertAfter(pList, 8, 88);
	SListInsertAfter(pList, 9, 99);
	SListPrintf(pList);

	//ָ��λ��֮ǰ����
	printf("\nָ��λ��֮ǰ����\n");
	SListInsertBefore(&pList, 1, 0);
	SListInsertBefore(&pList, 66, 60);
	SListInsertBefore(&pList, 88, 80);
	SListInsertAfter(pList, 9, 99);
	SListPrintf(pList);

	//ͷɾ
	printf("\nͷɾ\n");
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrintf(pList);

	//βɾ
	printf("\nβɾ\n");
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrintf(pList);

	//ָ��λ��ɾ��
	printf("\nָ��λ��ɾ��\n");
	SListErase(&pList, 6);
	SListErase(&pList, 0);
	SListErase(&pList, 8);
	SListErase(&pList, 9);
	SListPrintf(pList);

	//����
	SListDestroy(&pList);
	return 0;
}