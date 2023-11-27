#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//��ʼ��
void StackInitial(SK * ps)
{
	////˼·һ����ʼ��ʱ�������ڴ�
	//ps->_p=malloc(capacity_initial * sizeof(SKDataType));
	//memset((ps, capacity_initial * sizeof(SKDataType),0));//��ʼ��Ϊ0
	//ps->top = 0;
	//ps->capacity = capacity_initial;
	
	//˼·������ʼ��ʱ�������ڴ棬������ʱ�ٲ���
	ps->_p = NULL;
	ps->top = ps->capacity = 0;
}

//��ջ-��ʵ��β�壬���ｫ�Ҳ���Ϊջ����
void StackPush(SK* ps,SKDataType data)
{
	/*assert(ps);*/
	if (ps->top >= ps->capacity)
	{
		ps->capacity = ps->capacity==0 ? capacity_initial : ps->capacity * 2;//�ж���Ҫ���ٿռ�Ĵ�С����0���򿪱�Ĭ���ڴ��С������0����ǰ��������
		SKDataType *p_temp = malloc(ps->capacity * sizeof(SKDataType));
		if (p_temp == NULL)
			perror("�ڴ濪��ʧ��");
		else
		{
			ps->_p = p_temp;
			memset(ps->_p + ps->top, (ps->capacity - ps->top) * sizeof(SKDataType), 0);//���¿��ٵĿռ��ʼ��Ϊ0���ò���ѡ,�Ǳ���
		}
	}
	ps->_p[ps->top] = data;
	ps->top++;
}

//��ջ-��ʵ��βɾ
void StackPop(SK* ps)
{
	assert(ps);
	assert(ps->top);
	ps->_p[ps->top - 1] = 0;//����ĩβ��ʵ��ջ��ֵ-1���ò���ѡ���Ǳ���
	ps->top--;
}

//��ȡջ��λ��/����
int StackTop(SK* ps)
{
	assert(ps);
	return ps->top;
	//return ps->_p[ps->top - 1];//��ȡջ������
}

//�ж�ջ�Ƿ�Ϊ�գ�0��ʾ�գ�1��ʾ�ǿ�
int StackEmpty(SK* ps)
{
	int isEmpty = ps->top == 0 ? 0 : 1;
	return isEmpty;
}

//��ӡ
void StackPrint(SK* ps)
{
	assert(ps);
	if (ps->top == 0)
		printf("ջΪ�գ����κ�����");
	int cur = 0;
	while (cur < ps->top)
	{
		printf("%d ", ps->_p[cur]);
		cur++;
	}
	printf("\n");
}

//����ջ
void StackDestroy(SK* ps)
{
	ps->capacity = 0;
	ps->top = 0;
	free(ps->_p);
	ps->_p = NULL;
}