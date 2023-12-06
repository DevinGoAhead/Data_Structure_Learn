#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

Test1()
{
	//测试空的情况
	Heap hp;
	int a[] = {17,28,102,33,66,99,20,0,15,47,53,12,23,25,42,12,16,18,77,55};
	int sz = sizeof(a) / sizeof(int);//元素个数
	
	HeapInitial(&hp);//初始化
	
	//创建堆
	printf("创建堆\n");
	for(int i=0;i<sz;i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	//删除结点（堆头）
	printf("删除根结点\n");
	HeapPopPos(&hp,0);
	HeapPrint(&hp);

	printf("删除根结点\n");
	HeapPopPos(&hp, 12);
	HeapPrint(&hp);

	//堆排序（升序）
	printf("堆排序（升序）\n");
	HeapSort(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);//销毁
}

Test2()
{
	Heap hp;
	HeapInitial(&hp);//初始化
	int i;
	//创建一个1~1000的随机数数组
	int arr[1000] = {0};
	for (i = 0; i < 1000; i++)
	{
		arr[i] = rand()%1000 + 1;
		//printf("%d ", arr[i]);
		//Sleep(200);
	}
	HeapTopMin(&hp,arr,1000,10);
	HeapPrint(&hp);
}

int main()
{
	/*Test1();*/
	srand((unsigned int)time(NULL));
	Test2;
}
