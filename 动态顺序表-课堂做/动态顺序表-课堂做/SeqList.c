#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//初始化动态数组
void SeqListInitil(SL* p_SL)
{
	assert(p_SL);
	p_SL->p_arr=calloc(DEFAULT_CAPACITY, sizeof(SLDataType));//为结构体成员p_arr指向的内存开辟初始空间
	if (p_SL->p_arr == NULL)
		perror("内存开辟失败");//也可以暴力一点，直接exist(-1)退出
	else
		memset(p_SL->p_arr, 0, 4 * sizeof(SLDataType));//事实上，不去初始化开辟的空间也是被允许的
	p_SL->capacity = DEFAULT_CAPACITY;
	p_SL->size = 0;
}

//容量检查
void CheckCapacity(SL* p_SL)
{
	assert(p_SL);
	if (p_SL->size >= p_SL->capacity)
	{
		SLDataType* p_a = realloc(p_SL->p_arr, (size_t)2*p_SL->capacity*sizeof(SLDataType));//size_t强转，否则会报错“在被分配到更广的类型之前，子表达式可益出”
		if(p_a==NULL)
			perror("内存开辟失败");//也可以暴力一点，直接exist(-1)退出
		else
		{
			p_SL->p_arr = p_a;
			p_SL->capacity *=2;
		}
	}
}

//动态数组尾端插入
void SeqListPushBack(SL* p_SL,SLDataType s)
{
	CheckCapacity(p_SL);
	p_SL->p_arr[p_SL->size] = s;
	p_SL->size++;
}

//动态数组首端插入
void SeqListPushFront(SL* p_SL, SLDataType s)
{
	CheckCapacity(p_SL);
	memmove((p_SL->p_arr + 1), p_SL->p_arr, p_SL->size * sizeof(SLDataType));
	p_SL->p_arr[0] = s;
	p_SL->size++;
}

//动态数组指定位置插入
void SeqListPushInsert(SL* p_SL, SLDataType s,int pos)//这里的pos指的是以0为起始值的数
{
	CheckCapacity(p_SL);
	
	assert(pos >= 0);//当pos==0时，效果相等于首插
	assert(pos <= p_SL->size);//当pos==size时，效果相等于尾插
	
	int end = p_SL->size - 1;
	while (end >= pos)
	{
		p_SL->p_arr[end + 1] = p_SL->p_arr[end];
		end--;
	}
	
	p_SL->p_arr[pos] = s;
	p_SL->size++;
}

//动态数组尾删
void SeqListPopBack(SL* p_SL)
{
	assert(p_SL);
	//p_SL->p_arr[p_SL->size-1] = 0;//这一步必要性不大，根据需要选择是否使用
	p_SL->size--;
}

//动态数组首删
void SeqListPopFront(SL* p_SL)
{
	SeqListErase(p_SL, 0);//这里可以重新写，也可以直接调用SeqListErase，原则上，本节所有操作都可以直接调用Insert和Erase来完成
}

//动态数组指定位置删除
void SeqListErase(SL* p_SL, int pos)
{
	assert(p_SL);
	assert(pos >= 0);//当pos==0时，效果相等于首删
	assert(pos < p_SL->size);//当pos==size-1时，效果相等于尾删
	
	while (pos < p_SL->size-1)
	{
		p_SL->p_arr[pos] = p_SL->p_arr[pos + 1];
		pos++;
	}
	
	//p_SL->p_arr[p_SL->size-1] = 0;//这一步必要性不大，根据需要选可以省略
	p_SL->size--;
}

//打印动态数组内容
void SeqListPrintf(SL* p_SL)
{
	assert(p_SL);
	int i;
	for (i = 0; i < p_SL->size;i++)
		printf("p_arr[%d] = %d\n", i, p_SL->p_arr[i]);
	printf("size = %d\n",p_SL->size);
	printf("capacity = %d\n", p_SL->capacity);
}

//销毁顺序表
void SeqListDestroy(SL* p_SL)
{
	assert(p_SL);
	free(p_SL->p_arr);
	p_SL->p_arr = NULL;
	p_SL->size = 0;
	p_SL->capacity = 0;
}