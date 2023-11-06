#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//��ʼ����̬����
void SeqListInitil(SL* p_SL)
{
	p_SL->p_arr=calloc(DEFAULT_CAPACITY, sizeof(SLDataType));//Ϊ�ṹ���Աp_arrָ����ڴ濪�ٳ�ʼ�ռ�
	if (p_SL->p_arr == NULL)
		perror("�ڴ濪��ʧ��");//Ҳ���Ա���һ�㣬ֱ��exist(-1)�˳�
	else
		memset(p_SL->p_arr, 0, 4 * sizeof(SLDataType));//��ʵ�ϣ���ȥ��ʼ�����ٵĿռ�Ҳ�Ǳ������
	p_SL->capacity = DEFAULT_CAPACITY;
	p_SL->size = 0;
}

//�������
void CheckCapacity(SL* p_SL)
{
	if (p_SL->size >= p_SL->capacity)
	{
		SLDataType* p_a = realloc(p_SL->p_arr, (size_t)2 * DEFAULT_CAPACITY * sizeof(SLDataType));//size_tǿת������ᱨ���ڱ����䵽���������֮ǰ���ӱ��ʽ�������
		if(p_a==NULL)
			perror("�ڴ濪��ʧ��");//Ҳ���Ա���һ�㣬ֱ��exist(-1)�˳�
		else
		{
			p_SL->p_arr = p_a;
			p_SL->capacity += 2 * DEFAULT_CAPACITY;
		}
	}
}

//��̬����β�˲���
void SeqListPushBack(SL* p_SL,SLDataType s)
{
	CheckCapacity(p_SL);
	p_SL->p_arr[p_SL->size] = s;
	p_SL->size++;
}

//��̬�����׶˲���
void SeqListPushFront(SL* p_SL, SLDataType s)
{
	CheckCapacity(p_SL);
	memmove((p_SL->p_arr + 1), p_SL->p_arr, p_SL->size * sizeof(SLDataType));
	p_SL->p_arr[0] = s;
	p_SL->size++;
}

//��̬����ָ��λ�ò���
void SeqListPushPos(SL* p_SL, SLDataType s,int pos)//SeqListInsert
{
	CheckCapacity(p_SL);
	memmove((p_SL->p_arr + pos), (p_SL->p_arr + pos - 1), (size_t)(p_SL->size - pos+1) * sizeof(SLDataType));
	p_SL->p_arr[pos - 1] = s;
	p_SL->size++;
}

//��̬����βɾ
void SeqListPopBack(SL* p_SL)
{
	//p_SL->p_arr[p_SL->size-1] = 0;//��һ����Ҫ�Բ��󣬸�����Ҫѡ���Ƿ�ʹ��
	p_SL->size--;
}

//��̬������ɾ
void SeqListPopFront(SL* p_SL)
{
	memmove(p_SL->p_arr, (p_SL->p_arr + 1), p_SL->size * sizeof(SLDataType));
	//p_SL->p_arr[p_SL->size-1] = 0;//��һ����Ҫ�Բ��󣬸�����Ҫѡ����ʡ��
	p_SL->size--;
}

//��̬����ָ��λ��ɾ��
void SeqListPopPos(SL* p_SL, int pos)//SeqListErase
{
	memmove((p_SL->p_arr + pos-1), (p_SL->p_arr + pos), (size_t)(p_SL->size - pos) * sizeof(SLDataType));
	//p_SL->p_arr[p_SL->size-1] = 0;//��һ����Ҫ�Բ��󣬸�����Ҫѡ����ʡ��
	p_SL->size--;
}

//��ӡ��̬��������
void SeqListPrintf(SL* p_SL)
{
	int i;
	for (i = 0; i < p_SL->size;i++)
		printf("p_arr[%d] = %d\n", i, p_SL->p_arr[i]);
	printf("size = %d\n",p_SL->size);
	printf("capacity = %d\n", p_SL->capacity);
}

//����˳���
void SeqListDestroy(SL* p_SL)
{
	free(p_SL);
	p_SL->p_arr = NULL;
	p_SL->size = 0;
	p_SL->capacity = 0;
}