#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//交换
void HeapSwap(HPDataType* pa_1, HPDataType* pa_2)
{
	HPDataType dataTemp;
	dataTemp = *pa_1;
	*pa_1 = *pa_2;
	*pa_2 = dataTemp;
}

//向下调整算法（时间复杂度O(logn +1)）
void HeapAdjustDown(Heap* pHp,int i,int sz)
{
	int parent = i;
	int minChild = 2 * parent + 1;//假设两个子结点中左子结点为较小者
	while (minChild < sz)
	{
		//如果两个子结点中右子结点为较小者
		if (minChild + 1 < sz && pHp->pa[minChild + 1] < pHp->pa[minChild])//while中对minChild进行了判断，但minChild + 1仍然可能越界
			minChild++;
		//如果父结点 < 子结点，则向下调整
		if (pHp->pa[minChild] < pHp->pa[parent])
		{
			HeapSwap(&(pHp->pa[minChild]), &(pHp->pa[parent]));//交换

			parent = minChild;//将原来的子结点作为新的父结点，继续向下调整
			minChild = 2 * parent + 1;//假设两个子结点中左子结点为较小者
		}
		else//父结点不小于子结点，说明该子树已经是小堆，不需要继续调整
			break;
	}
}

//向上调整算法
void HeapAdjustUp(Heap *pHp,int i)
{
	int child = i;
	int parent = (child - 1) / 2;
	while (child >0)
	{
		//如果子结点 < 父结点，则向上调整
		if (pHp->pa[child] < pHp->pa[parent])
		{
			HeapSwap(&(pHp->pa[child]), &(pHp->pa[parent]));//交换
			child = parent;//将原来的子结点作为父结点
			parent= (child - 1) / 2;//计算新的父结点的下标
		}
		else//子结点不小于父结点，说明该子树已经是小堆，不需要继续调整
			break;
	}
}

//初始化（时间复杂度O(n)(已考虑向下调整算法)）
void HeapInitial(Heap* pHp, HPDataType* arr, int sz)
{
	assert(pHp);
	assert(arr);
	assert(sz>0);
	//初始化堆的一些成员
	pHp->capacity = sz;
	pHp->size = sz;
	pHp->pa = NULL;
	//开辟内存并将源数组拷贝到开辟的内存中
	HPDataType* pDataTemp = malloc((size_t)pHp->capacity * sizeof(HPDataType));//开辟与源数组元素个数对应空间
	if (pDataTemp == NULL)
		perror("开辟内存失败");
	else
		pHp->pa = pDataTemp;
	memmove(pHp->pa, arr, (size_t)sz * sizeof(HPDataType));//将源数组中的元素拷贝至开辟的内存中

	//构建堆
	int i;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)//sz-1为数组的尾标值，(sz - 1 - 1) / 2 是最后一个结点的父结点，即最后一个非父结点
		HeapAdjustDown(pHp,i,pHp->size);//调用向下调整算法
}

//堆排序(降序，但排序完将不再是小堆，而是转换为一个完全降序的大堆)
void HeapSort(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	int tail = pHp->size-1;
	while(tail>0)
	{
		HeapSwap(&(pHp->pa[tail]), &(pHp->pa[0]));//首尾交换，将最小值放在数组尾部
		HeapAdjustDown(pHp, 0,tail);//根结点以下仍然保持了小堆的特点，但是根结点不满足要求，因此重新想象调整
		tail--;//不考虑最尾部的最小值，对次小值做同样的操作
	}
}

//堆查找,返回元素的下标值
int HeapFind(Heap* pHp, HPDataType posNum)
{
	return 0;
}

//尾结点删除
void HeapPopBack(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	pHp->size--;
}

//其他结点删除
void HeapPopPos(Heap* pHp,HPDataType posNum)
{
	assert(pHp);
	assert(pHp->size > 0);
	int del = HeapFind(pHp,posNum);//要删除的目标值的下标
	
	/*只有删除尾结点不会破坏堆结构，删除首结点或其他任意结点，整个堆的结构会被破坏，从而需要很复杂的操作来恢复堆
	因此，采取将删除的节点与尾结点交换，然后删除新的尾节点
	del之后仍然保持了小堆的结构，不受影响
	最后自del位置开始依次向上执行向下调整算法*/

	HeapSwap(&(pHp->pa[del]), &(pHp->pa[pHp->size - 1]));//交换
	HeapPopBack(pHp);//删除新的尾节点
	
	//自del位置开始依次向上执行向下调整算法
	int i;
	for (i = del; i >= 0; i--)//
		HeapAdjustDown(pHp, i,pHp->size);//调用向下调整算法
}

//插入结点（同样是插入在尾部，插在根部会破坏堆结构）
void HeapPush(Heap* pHp, HPDataType posNum)
{
	if (pHp->size >= pHp->capacity)
	{
		HPDataType* pDataTemp = realloc(pHp->pa,(size_t)pHp->capacity*2*sizeof(HPDataType));
		if (pDataTemp == NULL)
			perror("开辟内存失败");
		else
			pHp->pa = pDataTemp;
	}
	pHp->pa[pHp->size] = posNum;//将posNum放入堆尾
	pHp->size++;
	int i = pHp->size-1;
	HeapAdjustUp(pHp,i);
}

//返回堆顶元素
HPDataType HeapTop(Heap *pHp)
{
	assert(pHp);
	assert(pHp->size >0);
	return pHp->pa[0];
}
//返回堆尾元素
HPDataType HeapBack(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size > 0);
	return pHp->pa[pHp->size-1];
}

//堆打印
void HeapPrint(Heap* pHp)
{
	int i;
	for (i = 0; i < pHp->size; i++)
	{
		printf("%d ",pHp->pa[i]);
	}
	printf("\n");
}

//堆销毁
void HeapDestroy(Heap* pHp)
{
	free(pHp->pa);
	pHp->capacity = 0;
	pHp->size = 0;
}