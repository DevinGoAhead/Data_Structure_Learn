#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//���г�ʼ��
void QueueInitial(Queue *pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//���-��ʵ��β��
void QueuePush(Queue* pq,QDataType data)
{
	assert(pq);
	//�½��ڵ�
	QNode* new_node = malloc(sizeof(QNode));
	if (new_node == NULL)
		perror("�ڴ濪��ʧ��");
	else
	{
		new_node->data = data;//��data����ڵ���
		new_node->next = NULL;//�½��ڵ��next��ָ��NULL
		//ֻ��1���ڵ�
		if (pq->tail == NULL)
			pq->head = pq->tail = new_node;//head��tail��ָ��ýڵ�
		// >1���ڵ�
		else
		{
			pq->tail->next=new_node;//�����β�ڵ��nextָ���½��Ľڵ㣬���µ�β�ڵ�
			pq->tail = new_node;//tailָ���µ�β�ڵ�
		}
		pq->size++;
	}
}

//����-��ʵ����ɾ
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
		printf("����Ϊ�գ��޷�����ɾ��\n");
	//��Ҫɾ�����һ���ڵ�
	else if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	//ɾ������в�Ϊ�գ����ٻ�ʣ1���ڵ�
	else
	{
		/*QNode* new_head = pq->head->next;
		free(pq->head);
		pq->head = new_head;*/

		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
	}
	pq->size--;
}

//�ж϶����Ƿ�Ϊ��,0��ʾ�գ�1��ʾ�ǿ�
int QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->size == 0 ? 0 : 1;
}

//��ȡ��������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
	{
		printf("����Ϊ�գ����κ�����\n");
		exit(-1);
	}
	else
		return pq->head->data;
}
//��ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
	{
		printf("����Ϊ�գ����κ�����\n");
		exit(-1);
	}
	else
		return pq->tail->data;
}

//��ȡ�������ݸ���
int QueueSize(Queue *pq)
{
	assert(pq);
	return pq->size;
}

//��ӡ
void QueuePrint(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
		printf("����Ϊ�գ����κ�����\n");
	QNode* cur = pq->head;
	while (cur)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//���ٶ���
void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->head;
	QNode* del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
