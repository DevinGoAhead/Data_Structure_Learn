#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void Test1()
{
	LN* p_head = NULL;
	ListInitial(&p_head);//��ʼ��
	
	//β��
	printf("β��\n");
	ListPushBack(p_head, 1);
	ListPushBack(p_head, 2);
	ListPushBack(p_head, 3);
	ListPushBack(p_head, 4);
	ListPrint(p_head);

	//�ײ�
	printf("�ײ�\n");
	ListPushFront(p_head, 5);
	ListPushFront(p_head, 6);
	ListPushFront(p_head, 7);
	ListPushFront(p_head, 8);
	ListPrint(p_head);

	//βɾ
	printf("βɾ\n");
	ListPopBack(p_head);
	ListPopBack(p_head);
	ListPopBack(p_head);
	ListPrint(p_head);

	//ͷɾ
	printf("ͷɾ\n");
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPopFront(p_head);
	ListPrint(p_head);

	//ָ��λ�ò���
	printf("ָ��λ��֮�����\n");
	ListInsert(p_head, 1, 11);
	ListInsert(p_head, 11, 2);
	ListInsert(p_head, 2, 22);
	ListInsert(p_head, 4, 3);
	ListPrint(p_head);

	//ָ��λ��֮��ɾ��
	printf("ָ��λ��ɾ��\n");
	ListErase(p_head, 1);
	ListErase(p_head, 4);
	ListErase(p_head, 22);
	ListErase(p_head, 2);
	ListErase(p_head, 11);
	ListErase(p_head, 11);
	ListPrint(p_head);

	////�������
	//printf("�������\n");
	//ClearList(p_head);
	//ListPrint(p_head);

	//�������
	printf("��������\n");
	DestroyList(&p_head);
	ListPrint(p_head);
}

int main()
{
	Test1();
}