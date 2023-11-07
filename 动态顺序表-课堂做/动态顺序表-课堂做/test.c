#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//测试
int main()
{
	SL SL1;
	SeqListInitil(&SL1);//初始化
	
	//尾插
	SeqListPushBack(&SL1, 6);
	SeqListPushBack(&SL1, 7);
	SeqListPushBack(&SL1, 8);
	SeqListPushBack(&SL1, 9);
	
	SeqListPrintf(&SL1);
	printf("--------------\n");

	//首插
	SeqListPushFront(&SL1, 1);
	SeqListPushFront(&SL1, 2);
	SeqListPushFront(&SL1, 3);
	SeqListPushFront(&SL1, 4);
	SeqListPushFront(&SL1, 5);
	
	SeqListPrintf(&SL1);
	printf("--------------\n");

	//指定位置插入
	SeqListPushInsert(&SL1, 55, 5);
	SeqListPushInsert(&SL1, 66, 6);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//尾删
	SeqListPopBack(&SL1);
	SeqListPopBack(&SL1);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//首删
	SeqListPopFront(&SL1);
	SeqListPopFront(&SL1);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//指定位置删除
	SeqListErase(&SL1, 5);

	SeqListPrintf(&SL1);
	printf("--------------\n");

	//销毁顺序表
	SeqListDestroy(&SL1);

	return 0;
}