#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

Test1()
{
	//���Կյ����
	Heap hp;
	int a[] = {17,28,102,33,66,99,20,0,15,47,53,12,23,25,42,12,16,18,77,55};
	int sz = sizeof(a) / sizeof(int);//Ԫ�ظ���
	
	HeapInitial(&hp);//��ʼ��
	
	//������
	printf("������\n");
	for(int i=0;i<sz;i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	//ɾ����㣨��ͷ��
	printf("ɾ�������\n");
	HeapPopPos(&hp,0);
	HeapPrint(&hp);

	printf("ɾ�������\n");
	HeapPopPos(&hp, 12);
	HeapPrint(&hp);

	//����������
	printf("����������\n");
	HeapSort(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);//����
}

Test2()
{
	Heap hp;
	HeapInitial(&hp);//��ʼ��
	int i;
	//����һ��1~1000�����������
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
