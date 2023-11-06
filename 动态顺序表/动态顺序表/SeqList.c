#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//初始化动态数组
void SeqListInitil(SL* p_SL)
{
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
	if (p_SL->size >= p_SL->capacity)
	{
		SLDataType* p_a = realloc(p_SL->p_arr, (size_t)2 * DEFAULT_CAPACITY * sizeof(SLDataType));//size_t强转，否则会报错“在被分配到更广的类型之前，子表达式可益出”
		if(p_a==NULL)
			perror("内存开辟失败");//也可以暴力一点，直接exist(-1)退出
		else
		{
			p_SL->p_arr = p_a;
			p_SL->capacity += 2 * DEFAULT_CAPACITY;
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
void SeqListPushPos(SL* p_SL, SLDataType s,int pos)//SeqListInsert
{
	CheckCapacity(p_SL);
	memmove((p_SL->p_arr + pos), (p_SL->p_arr + pos - 1), (size_t)(p_SL->size - pos+1) * sizeof(SLDataType));
	p_SL->p_arr[pos - 1] = s;
	p_SL->size++;
}

//动态数组尾删
void SeqListPopBack(SL* p_SL)
{
	//p_SL->p_arr[p_SL->size-1] = 0;//这一步必要性不大，根据需要选择是否使用
	p_SL->size--;
}

//动态数组首删
void SeqListPopFront(SL* p_SL)
{
	memmove(p_SL->p_arr, (p_SL->p_arr + 1), p_SL->size * sizeof(SLDataType));
	//p_SL->p_arr[p_SL->size-1] = 0;//这一步必要性不大，根据需要选可以省略
	p_SL->size--;
}

//动态数组指定位置删除
void SeqListPopPos(SL* p_SL, int pos)//SeqListErase
{
	memmove((p_SL->p_arr + pos-1), (p_SL->p_arr + pos), (size_t)(p_SL->size - pos) * sizeof(SLDataType));
	//p_SL->p_arr[p_SL->size-1] = 0;//这一步必要性不大，根据需要选可以省略
	p_SL->size--;
}

//打印动态数组内容
void SeqListPrintf(SL* p_SL)
{
	int i;
	for (i = 0; i < p_SL->size;i++)
		printf("p_arr[%d] = %d\n", i, p_SL->p_arr[i]);
	printf("size = %d\n",p_SL->size);
	printf("capacity = %d\n", p_SL->capacity);
}

//销毁顺序表
void SeqListDestroy(SL* p_SL)
{
	free(p_SL);
	p_SL->p_arr = NULL;
	p_SL->size = 0;
	p_SL->capacity = 0;
}