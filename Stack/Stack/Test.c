#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

Test1()
{
	SK s;
	StackInitial(&s);//初始化
	
	//入栈
	printf("入栈\n");
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPrint(&s);

	//出栈
	printf("出栈\n");
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);
	//StackPop(&s);
	StackPrint(&s);

	//获取栈顶
	printf("获取栈顶\n");
	int top=StackTop(&s);
	printf("%d\n", top);
    
	//判断栈是否为空
	printf("判断栈是否为空\n");
	int bool= StackEmpty(&s);
	printf("%d\n",bool);

	StackDestroy(&s);//销毁
}

int main()
{
	Test1();
}
