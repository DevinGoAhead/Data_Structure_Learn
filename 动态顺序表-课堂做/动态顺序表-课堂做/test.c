#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//����
int main()
{
	SL SL1;
	SeqListInitil(&SL1);//��ʼ��
	
	//β��
	SeqListPushBack(&SL1, 6);
	SeqListPushBack(&SL1, 7);
	SeqListPushBack(&SL1, 8);
	SeqListPushBack(&SL1, 9);
	
	SeqListPrintf(&SL1);
	printf("--------------\n");

	//�ײ�
	SeqListPushFront(&SL1, 1);
	SeqListPushFront(&SL1, 2);
	SeqListPushFront(&SL1, 3);
	SeqListPushFront(&SL1, 4);
	SeqListPushFront(&SL1, 5);
	
	SeqListPrintf(&SL1);
	printf("--------------\n");

	//ָ��λ�ò���
	SeqListPushInsert(&SL1, 55, 5);
	SeqListPushInsert(&SL1, 66, 6);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//βɾ
	SeqListPopBack(&SL1);
	SeqListPopBack(&SL1);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//��ɾ
	SeqListPopFront(&SL1);
	SeqListPopFront(&SL1);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//ָ��λ��ɾ��
	SeqListErase(&SL1, 5);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//����˳���
	SeqListDestroy(&SL1);

	return 0;
}