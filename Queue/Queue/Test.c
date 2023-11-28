#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

Test1()
{
	Queue q;
	QueueInitial(&q);//初始化
	
	//入队
	printf("入队\n");
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueBack(&q));//获取队尾数据
	printf("\n");
	printf("%d ", QueueFront(&q));//获取队尾数据
	printf("\n");
	QueuePrint(&q);

	//出队
	printf("出队\n");
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);
	printf("%d ", QueueEmpty(&q));//判断队列是否为空
	printf("\n");
	QueuePop(&q);
	printf("%d ", QueueEmpty(&q));//判断队列是否为空
	printf("\n");


	//入队
	printf("入队\n");
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	printf("%d ", QueueSize(&q));//获取队列数据数量
	printf("\n");
	QueuePrint(&q);
}

int main()
{
	Test1();
}