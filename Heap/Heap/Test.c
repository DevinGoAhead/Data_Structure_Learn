#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

Test1()
{
	//���Կյ����
	Heap hp;
	int a[] = {17,28,102,33,66,99,20,0,15,47,53,12,23,25,42,12,16,18,77,55};
	int sz = sizeof(a) / sizeof(int);//Ԫ�ظ���
	
	printf("��ʼ��\n");
	HeapInitial(&hp,a,sz);//��ʼ��
	HeapPrint(&hp);//��ӡ
	
	printf("ɾ����βԪ��\n");
	HeapPopBack(&hp);//ɾ����βԪ��
	printf("�µĶ�βԪ��:%d\n",HeapBack(&hp));

	printf("ɾ������Ԫ��\n");
	HeapPopPos(&hp,0);//��ɾ���Ӷ�Ԫ��Ϊ��
	printf("�µĶѶ�Ԫ��:%d\n", HeapTop(&hp));

	printf("�ٴ�ɾ������Ԫ��\n");
	HeapPopPos(&hp, 12);//��ɾ���Ӷ�Ԫ��Ϊ��
	printf("�µĶѶ�Ԫ��:%d\n", HeapTop(&hp));

	printf("�ٴ�ɾ������Ԫ��\n");
	HeapPopPos(&hp, 12);//��ɾ���Ӷ�Ԫ��Ϊ��
	printf("�µĶѶ�Ԫ��:%d\n", HeapTop(&hp));

	printf("��������\n");
	HeapPush(&hp,99);
	HeapPrint(&hp);//��ӡ
	
	printf("��������\n");
	HeapPush(&hp, 6);
	HeapPrint(&hp);//��ӡ

	printf("����\n");
	HeapSort(&hp);//������
	HeapPrint(&hp);//��ӡ

	HeapDestroy(&hp);//����
}

int main()
{
	Test1();
}
