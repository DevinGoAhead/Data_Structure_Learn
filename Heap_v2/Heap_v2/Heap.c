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
void HeapAdjustDown(HPDataType *pa,int parent,int numEnd)//numEnd表示向下调整的终点
{
	int maxChild = 2 * parent + 1;//假设两个子结点中左子结点为较大者
	while (maxChild < numEnd)
	{
		//如果两个子结点中右子结点为较大者
		if (maxChild + 1 < numEnd && pa[maxChild + 1] > pa[maxChild])//while中对maxChild进行了判断，但maxChild + 1仍然可能越界
			maxChild++;
		//如果子结点 > 父结点，则向下调整
		if (pa[maxChild] > pa[parent])
		{
			HeapSwap(&pa[maxChild], &pa[parent]);//交换

			parent = maxChild;//将原来的子结点作为新的父结点，继续向下调整
			maxChild = 2 * parent + 1;//假设两个子结点中左子结点为较大者
		}
		else//父结点不大于子结点，说明该子树已经是大堆，不需要继续调整
			break;
	}
}

//向上调整算法
void HeapAdjustUp(HPDataType* pa,int child)
{
	int parent = (child - 1) / 2;
	while (child >0)
	{
		//如果子结点 > 父结点，则向上调整
		if (pa[child] > pa[parent])
		{
			HeapSwap(&pa[child], &pa[parent]);//交换
			child = parent;//将原来的子结点作为父结点
			parent= (child - 1) / 2;//计算新的父结点的下标
		}
		else//子结点不大于父结点，说明该子树已经是大堆，不需要继续调整
			break;
	}
}

/*v1中采用了在初始化中创建堆的思路
但是v2采用了全新的思路，初始化仅仅是初始化堆的一些结构体成员，并不构建堆
而是在push的过程中一边push一边调整堆*/
void HeapInitial(Heap* pHp)
{
	assert(pHp);
	//初始化堆的一些成员
	pHp->capacity = 0;
	pHp->size = 0;
	pHp->pa = NULL;
}

//插入结点（同样是插入在尾部，插在根部会破坏堆结构）
void HeapPush(Heap* pHp, HPDataType data)
{
	if (pHp->size >= pHp->capacity)
	{
		pHp->capacity = pHp->capacity == 0 ? capacityInitial : pHp->capacity * 2;
		HPDataType* pDataTemp = realloc(pHp->pa, (size_t)pHp->capacity * sizeof(HPDataType));
		if (pDataTemp == NULL)
			perror("开辟内存失败");
		else
			pHp->pa = pDataTemp;
	}
	pHp->pa[pHp->size] = data;//将data放入堆尾
	pHp->size++;
	HeapAdjustUp(pHp->pa, pHp->size - 1);//每插入一次，就执行一次向上调整，保证插入之前的结构为堆结构
}

//堆排序(升序，但排序完将不再是大堆，而是转换为一个完全升序的小堆)
void HeapSort(Heap* pHp)
{
	assert(pHp);
	assert(pHp->size>0);
	int numEnd = pHp->size;
	while(numEnd >0)
	{
		HeapSwap(&(pHp->pa[numEnd-1]), &(pHp->pa[0]));//首尾交换，将最小值放在数组尾部
		HeapAdjustDown(pHp->pa, 0, numEnd-1);//根结点以下仍然保持了小堆的特点，但是根结点不满足要求，因此重新想象调整
		numEnd--;//不考虑最尾部的最小值，对次小值做同样的操作
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
	del之后仍然保持了大堆的结构，不受影响
	最后自del位置开始依次向上执行向下调整算法*/

	HeapSwap(&(pHp->pa[del]), &(pHp->pa[pHp->size - 1]));//交换
	HeapPopBack(pHp);//删除新的尾节点
	
	//自del位置开始依次向上执行向下调整算法
	int i;
	for (i = del; i >= 0; i--)//
		HeapAdjustDown(pHp->pa, i,pHp->size);//调用向下调整算法
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

void HeapTopMin(Heap* pHp, HPDataType* arr, int sz, int k)
{
	int i;
	//取前k个数构成大堆
	for (i = 0; i < k; i++)
	{
		HeapPush(pHp, arr[i]);
	}
	//依次取第k个数之后的数与堆顶数进行比较
	for (i = k; i < sz; i++)
	{
		if (arr[i] <pHp->pa[0])
		{
			pHp->pa[0] = arr[i];
			HeapAdjustDown(pHp->pa, 0, k);
		}
	}
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