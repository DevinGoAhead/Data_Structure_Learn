#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

Test1()
{
	Queue q;
	QueueInitial(&q);//��ʼ��
	
	//���
	printf("���\n");
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueBack(&q));//��ȡ��β����
	printf("\n");
	printf("%d ", QueueFront(&q));//��ȡ��β����
	printf("\n");
	QueuePrint(&q);

	//����
	printf("����\n");
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);
	printf("%d ", QueueEmpty(&q));//�ж϶����Ƿ�Ϊ��
	printf("\n");
	QueuePop(&q);
	printf("%d ", QueueEmpty(&q));//�ж϶����Ƿ�Ϊ��
	printf("\n");


	//���
	printf("���\n");
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	printf("%d ", QueueSize(&q));//��ȡ������������
	printf("\n");
	QueuePrint(&q);
}

int main()
{
	Test1();
}