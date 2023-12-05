#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

Test1()
{
	//测试空的情况
	Heap hp;
	int a[] = {17,28,102,33,66,99,20,0,15,47,53,12,23,25,42,12,16,18,77,55};
	int sz = sizeof(a) / sizeof(int);//元素个数
	
	printf("初始化\n");
	HeapInitial(&hp,a,sz);//初始化
	HeapPrint(&hp);//打印
	
	printf("删除堆尾元素\n");
	HeapPopBack(&hp);//删除队尾元素
	printf("新的堆尾元素:%d\n",HeapBack(&hp));

	printf("删除其他元素\n");
	HeapPopPos(&hp,0);//以删除队顶元素为例
	printf("新的堆顶元素:%d\n", HeapTop(&hp));

	printf("再次删除其他元素\n");
	HeapPopPos(&hp, 12);//以删除队顶元素为例
	printf("新的堆顶元素:%d\n", HeapTop(&hp));

	printf("再次删除其他元素\n");
	HeapPopPos(&hp, 12);//以删除队顶元素为例
	printf("新的堆顶元素:%d\n", HeapTop(&hp));

	printf("插入数据\n");
	HeapPush(&hp,99);
	HeapPrint(&hp);//打印
	
	printf("插入数据\n");
	HeapPush(&hp, 6);
	HeapPrint(&hp);//打印

	printf("排序\n");
	HeapSort(&hp);//堆排序
	HeapPrint(&hp);//打印

	HeapDestroy(&hp);//销毁
}

int main()
{
	Test1();
}
