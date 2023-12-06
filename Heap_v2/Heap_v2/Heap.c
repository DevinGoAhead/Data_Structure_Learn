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
void HeapAdjustDown(HPDataType *pa,int parent,int numEnd)//numEnd��ʾ���µ������յ�
{
	int maxChild = 2 * parent + 1;//���������ӽ�������ӽ��Ϊ�ϴ���
	while (maxChild < numEnd)
	{
		//��������ӽ�������ӽ��Ϊ�ϴ���
		if (maxChild + 1 < numEnd && pa[maxChild + 1] > pa[maxChild])//while�ж�maxChild�������жϣ���maxChild + 1��Ȼ����Խ��
			maxChild++;
		//����ӽ�� > ����㣬�����µ���
		if (pa[maxChild] > pa[parent])
		{
			HeapSwap(&pa[maxChild], &pa[parent]);//����

			parent = maxChild;//��ԭ�����ӽ����Ϊ�µĸ���㣬�������µ���
			maxChild = 2 * parent + 1;//���������ӽ�������ӽ��Ϊ�ϴ���
		}
		else//����㲻�����ӽ�㣬˵���������Ѿ��Ǵ�ѣ�����Ҫ��������
			break;
	}
}

//���ϵ����㷨
void HeapAdjustUp(HPDataType* pa,int child)
{
	int parent = (child - 1) / 2;
	while (child >0)
	{
		//����ӽ�� > ����㣬�����ϵ���
		if (pa[child] > pa[parent])
		{
			HeapSwap(&pa[child], &pa[parent]);//����
			child = parent;//��ԭ�����ӽ����Ϊ�����
			parent= (child - 1) / 2;//�����µĸ������±�
		}
		else//�ӽ�㲻���ڸ���㣬˵���������Ѿ��Ǵ�ѣ�����Ҫ��������
			break;
	}
}

/*v1�в������ڳ�ʼ���д����ѵ�˼·
����v2������ȫ�µ�˼·����ʼ�������ǳ�ʼ���ѵ�һЩ�ṹ���Ա������������
������push�Ĺ�����һ��pushһ�ߵ�����*/
void HeapInitial(Heap* pHp)
{
	assert(pHp);
	//��ʼ���ѵ�һЩ��Ա
	pHp->capacity = 0;
	pHp->size = 0;
	pHp->pa = NULL;
}

//�����㣨ͬ���ǲ�����β�������ڸ������ƻ��ѽṹ��
void HeapPush(Heap* pHp, HPDataType data)
{
	if (pHp->size >= pHp->capacity)
	{
		pHp->capacity = pHp->capacity == 0 ? capacityInitial : pHp->capacity * 2;
		HPDataType* pDataTemp = realloc(pHp->pa, (size_t)pHp->capacity * sizeof(HPDataType));
		if (pDataTemp == NULL)
			perror("�����ڴ�ʧ��");
		else
			pHp->pa = pDataTemp;
	}
	pHp->pa[pHp->size] = data;//��data�����β
	pHp->size++;
	HeapAdjustUp(pHp->pa, pHp->size - 1);//ÿ����һ�Σ���ִ��һ�����ϵ�������֤����֮ǰ�ĽṹΪ�ѽṹ
}

//������(���򣬵������꽫�����Ǵ�ѣ�����ת��Ϊһ����ȫ�����С��)
void HeapSort(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	int numEnd = pHp->size;
	while(numEnd >0)
	{
		HeapSwap(&(pHp->pa[numEnd-1]), &(pHp->pa[0]));//��β����������Сֵ��������β��
		HeapAdjustDown(pHp->pa, 0, numEnd-1);//�����������Ȼ������С�ѵ��ص㣬���Ǹ���㲻����Ҫ����������������
		numEnd--;//��������β������Сֵ���Դ�Сֵ��ͬ���Ĳ���
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
	del֮����Ȼ�����˴�ѵĽṹ������Ӱ��
	�����delλ�ÿ�ʼ��������ִ�����µ����㷨*/

	HeapSwap(&(pHp->pa[del]), &(pHp->pa[pHp->size - 1]));//����
	HeapPopBack(pHp);//ɾ���µ�β�ڵ�
	
	//��delλ�ÿ�ʼ��������ִ�����µ����㷨
	int i;
	for (i = del; i >= 0; i--)//
		HeapAdjustDown(pHp->pa, i,pHp->size);//�������µ����㷨
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

void HeapTopMin(Heap* pHp, HPDataType* arr, int sz, int k)
{
	int i;
	//ȡǰk�������ɴ��
	for (i = 0; i < k; i++)
	{
		HeapPush(pHp, arr[i]);
	}
	//����ȡ��k����֮�������Ѷ������бȽ�
	for (i = k; i < sz; i++)
	{
		if (arr[i] <pHp->pa[0])
		{
			pHp->pa[0] = arr[i];
			HeapAdjustDown(pHp->pa, 0, k);
		}
	}
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