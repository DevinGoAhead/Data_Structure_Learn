#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

Test1()
{
	SK s;
	StackInitial(&s);//��ʼ��
	
	//��ջ
	printf("��ջ\n");
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPrint(&s);

	//��ջ
	printf("��ջ\n");
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);
	//StackPop(&s);
	StackPrint(&s);

	//��ȡջ��
	printf("��ȡջ��\n");
	int top=StackTop(&s);
	printf("%d\n", top);
    
	//�ж�ջ�Ƿ�Ϊ��
	printf("�ж�ջ�Ƿ�Ϊ��\n");
	int bool= StackEmpty(&s);
	printf("%d\n",bool);

	StackDestroy(&s);//����
}

int main()
{
	Test1();
}
