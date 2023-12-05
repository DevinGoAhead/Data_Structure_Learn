#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//����
void HeapSwap(HPDataType* pa_1, HPDataType* pa_2)
{
	HPDataType dataTemp;
	dataTemp = *pa_1;
	*pa_1 = *pa_2;
	*pa_2 = dataTemp;
}

//���µ����㷨��ʱ�临�Ӷ�O(logn +1)��
void HeapAdjustDown(Heap* pHp,int i,int sz)
{
	int parent = i;
	int minChild = 2 * parent + 1;//���������ӽ�������ӽ��Ϊ��С��
	while (minChild < sz)
	{
		//��������ӽ�������ӽ��Ϊ��С��
		if (minChild + 1 < sz && pHp->pa[minChild + 1] < pHp->pa[minChild])//while�ж�minChild�������жϣ���minChild + 1��Ȼ����Խ��
			minChild++;
		//�������� < �ӽ�㣬�����µ���
		if (pHp->pa[minChild] < pHp->pa[parent])
		{
			HeapSwap(&(pHp->pa[minChild]), &(pHp->pa[parent]));//����

			parent = minChild;//��ԭ�����ӽ����Ϊ�µĸ���㣬�������µ���
			minChild = 2 * parent + 1;//���������ӽ�������ӽ��Ϊ��С��
		}
		else//����㲻С���ӽ�㣬˵���������Ѿ���С�ѣ�����Ҫ��������
			break;
	}
}

//���ϵ����㷨
void HeapAdjustUp(Heap *pHp,int i)
{
	int child = i;
	int parent = (child - 1) / 2;
	while (child >0)
	{
		//����ӽ�� < ����㣬�����ϵ���
		if (pHp->pa[child] < pHp->pa[parent])
		{
			HeapSwap(&(pHp->pa[child]), &(pHp->pa[parent]));//����
			child = parent;//��ԭ�����ӽ����Ϊ�����
			parent= (child - 1) / 2;//�����µĸ������±�
		}
		else//�ӽ�㲻С�ڸ���㣬˵���������Ѿ���С�ѣ�����Ҫ��������
			break;
	}
}

//��ʼ����ʱ�临�Ӷ�O(n)(�ѿ������µ����㷨)��
void HeapInitial(Heap* pHp, HPDataType* arr, int sz)
{
	assert(pHp);
	assert(arr);
	assert(sz>0);
	//��ʼ���ѵ�һЩ��Ա
	pHp->capacity = sz;
	pHp->size = sz;
	pHp->pa = NULL;
	//�����ڴ沢��Դ���鿽�������ٵ��ڴ���
	HPDataType* pDataTemp = malloc((size_t)pHp->capacity * sizeof(HPDataType));//������Դ����Ԫ�ظ�����Ӧ�ռ�
	if (pDataTemp == NULL)
		perror("�����ڴ�ʧ��");
	else
		pHp->pa = pDataTemp;
	memmove(pHp->pa, arr, (size_t)sz * sizeof(HPDataType));//��Դ�����е�Ԫ�ؿ��������ٵ��ڴ���

	//������
	int i;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)//sz-1Ϊ�����β��ֵ��(sz - 1 - 1) / 2 �����һ�����ĸ���㣬�����һ���Ǹ����
		HeapAdjustDown(pHp,i,pHp->size);//�������µ����㷨
}

//������(���򣬵������꽫������С�ѣ�����ת��Ϊһ����ȫ����Ĵ��)
void HeapSort(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	int tail = pHp->size-1;
	while(tail>0)
	{
		HeapSwap(&(pHp->pa[tail]), &(pHp->pa[0]));//��β����������Сֵ��������β��
		HeapAdjustDown(pHp, 0,tail);//�����������Ȼ������С�ѵ��ص㣬���Ǹ���㲻����Ҫ����������������
		tail--;//��������β������Сֵ���Դ�Сֵ��ͬ���Ĳ���
	}
}

//�Ѳ���,����Ԫ�ص��±�ֵ
int HeapFind(Heap* pHp, HPDataType posNum)
{
	return 0;
}

//β���ɾ��
void HeapPopBack(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	pHp->size--;
}

//�������ɾ��
void HeapPopPos(Heap* pHp,HPDataType posNum)
{
	assert(pHp);
	assert(pHp->size > 0);
	int del = HeapFind(pHp,posNum);//Ҫɾ����Ŀ��ֵ���±�
	
	/*ֻ��ɾ��β��㲻���ƻ��ѽṹ��ɾ���׽������������㣬�����ѵĽṹ�ᱻ�ƻ����Ӷ���Ҫ�ܸ��ӵĲ������ָ���
	��ˣ���ȡ��ɾ���Ľڵ���β��㽻����Ȼ��ɾ���µ�β�ڵ�
	del֮����Ȼ������С�ѵĽṹ������Ӱ��
	�����delλ�ÿ�ʼ��������ִ�����µ����㷨*/

	HeapSwap(&(pHp->pa[del]), &(pHp->pa[pHp->size - 1]));//����
	HeapPopBack(pHp);//ɾ���µ�β�ڵ�
	
	//��delλ�ÿ�ʼ��������ִ�����µ����㷨
	int i;
	for (i = del; i >= 0; i--)//
		HeapAdjustDown(pHp, i,pHp->size);//�������µ����㷨
}

//�����㣨ͬ���ǲ�����β�������ڸ������ƻ��ѽṹ��
void HeapPush(Heap* pHp, HPDataType posNum)
{
	if (pHp->size >= pHp->capacity)
	{
		HPDataType* pDataTemp = realloc(pHp->pa,(size_t)pHp->capacity*2*sizeof(HPDataType));
		if (pDataTemp == NULL)
			perror("�����ڴ�ʧ��");
		else
			pHp->pa = pDataTemp;
	}
	pHp->pa[pHp->size] = posNum;//��posNum�����β
	pHp->size++;
	int i = pHp->size-1;
	HeapAdjustUp(pHp,i);
}

//���ضѶ�Ԫ��
HPDataType HeapTop(Heap *pHp)
{
	assert(pHp);
	assert(pHp->size >0);
	return pHp->pa[0];
}
//���ض�βԪ��
HPDataType HeapBack(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size > 0);
	return pHp->pa[pHp->size-1];
}

//�Ѵ�ӡ
void HeapPrint(Heap* pHp)
{
	int i;
	for (i = 0; i < pHp->size; i++)
	{
		printf("%d ",pHp->pa[i]);
	}
	printf("\n");
}

//������
void HeapDestroy(Heap* pHp)
{
	free(pHp->pa);
	pHp->capacity = 0;
	pHp->size = 0;
}