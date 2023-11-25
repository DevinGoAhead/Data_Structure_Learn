#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//��ѯ���ݵĵ�ַ
LN* ListFind(LN *p_head,LTDataType data)
{
	assert(p_head);
	if (p_head->next == p_head)
		printf("����Ϊ�գ����κ�����\n");
	LN* cur = p_head->next;//��Ȼ��ʹ��curҲ�ǿ��Եģ����Ƕ���cur�����Ӵ���Ŀɶ���
	while (cur !=p_head )
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//�����½ڵ�
LN* ListBuyNode(LTDataType data)
{
	LN* new_node = malloc(sizeof(LN));
	if (new_node == NULL)//�ж��ڴ��Ƿ񿪱ٳɹ�
	{
		perror("�ڵ�����ʧ��");
	}
	else
	{
		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	return new_node;
}

//��ʼ��
void ListInitial(LN** pp_head)
{
	*pp_head = ListBuyNode(0);//�½��ƽڵ�/�ڱ��ڵ�/ͷ�ڵ�
	(*pp_head)->prev = *pp_head;//��ֻ��ͷ�ڵ�ʱ����prev��next��ָ���Լ�
	(*pp_head)->next = *pp_head;
}

//β��
void ListPushBack(LN* p_head,LTDataType data)//ͨ��������������0����Ч�ڵ���߷�0����Ч�ڵ㣬������Ҫ�ı�ͷ���ָ�룬���һ��ָ��
{
	assert(p_head);
	//ͨ��������������0����Ч�ڵ���߷�0����Ч�ڵ㣬β��Ĳ�����һ������˲���Ҫ�����
	LN *new_node=ListBuyNode(data);//�����½ڵ㲢��data�Ž�ȥ
	LN *tail = p_head->prev;//�ҵ������β�ڵ�
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = p_head;//�µ�β�ڵ��next��ָ��ͷ���
	p_head->prev = new_node;//ͷ�ڵ��prev��ָ���µ�β�ڵ�
}

//�ײ�
void ListPushFront(LN* p_head, LTDataType data)//һ��ָ�룬ԭ��ͬβ��
{
	assert(p_head);
	//ͨ��������������0����Ч�ڵ���߷�0����Ч�ڵ㣬�ײ�Ĳ�����һ������˲���Ҫ�����
	LN* new_node = ListBuyNode(data);//�����½ڵ㲢��data�Ž�ȥ
	LN* first = p_head->next;//�ҵ�������׽ڵ�
	first->prev = new_node;
	new_node->next = first;
	new_node->prev = p_head;//�µ��׽ڵ��prev��ָ��ͷ���
	p_head->next = new_node;//ͷ�ڵ��next��ָ���µ��׽ڵ�
}

//ָ��λ��֮�����
void ListInsert(LN* p_head, LTDataType data_dest, LTDataType data_src)
{
	LN* pos = ListFind(p_head, data_dest);
	if (pos == NULL)
		printf("δ��ѯ��������\n");
	else
	{
		LN* new_node = ListBuyNode(data_src);//�����½ڵ㲢��data_src�Ž�ȥ
		LN* next = pos->next;//�ҵ�pos֮��Ľڵ�
		pos->next = new_node;
		new_node->prev = pos;
		new_node->next = next;
		next->prev = new_node;
	}
}

//βɾ
void ListPopBack(LN* p_head)//����Ҫ�ı�ͷ���ָ�룬���һ��ָ��
{
	assert(p_head);
	assert(p_head->next != p_head);//��0����Ч�ڵ�ʱ���Ͳ�����ɾ���ˣ������ɾ��ͷ��㣬�ƻ�����ṹ
	LN* tail = p_head->prev;//�ҵ������β�ڵ�
	LN* prev = tail->prev;//�ҵ�����ĵ����ڶ����ڵ�
	prev->next = p_head;//����ĵ����ڶ����ڵ��next��Ҫָ��ͷ���
	p_head->prev = prev;//ͷ����prev��Ҫָ������ĵ����ڶ����ڵ㣬�����µ�β�ڵ�
	free(tail);//�ͷ������β�ڵ��ڴ�
}

//��ɾ
void ListPopFront(LN* p_head)//����Ҫ�ı�ͷ���ָ�룬���һ��ָ��
{
	assert(p_head);
	assert(p_head->next != p_head);//��0����Ч�ڵ�ʱ���Ͳ�����ɾ���ˣ������ɾ��ͷ��㣬�ƻ�����ṹ
	LN* first = p_head->next;//�ҵ�������׽ڵ�
	LN* second = first->next;//�ҵ�����ĵڶ����ڵ�
	second->prev = p_head;//����ĵڶ����ڵ��prev��Ҫָ��ͷ���
	p_head->next = second;//ͷ����next��Ҫָ������ĵڶ����ڵ㣬�����µ�ͷ�ڵ�
	free(first);//�ͷ������ͷ�ڵ��ڴ�
}

//ָ��λ��ɾ��
void ListErase(LN* p_head, LTDataType data)
{
	LN* pos = ListFind(p_head, data);
	if (pos == NULL)
		printf("δ��ѯ��������\n");
	else
	{
		LN* prev = pos->prev;//�ҵ�pos֮ǰ�Ľڵ�
		LN* next = pos->next;//�ҵ�pos֮��Ľڵ�
		prev->next = next;
		next->prev = prev;
		free(pos);
	}
}

//��ӡ
void ListPrint(LN* p_head)
{
	assert(p_head);
	if (p_head->prev == p_head)
		printf("����Ϊ��");
	LN* cur = p_head->next;
	while (cur != p_head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}