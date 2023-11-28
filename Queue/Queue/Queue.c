#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//队列初始化
void QueueInitial(Queue *pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//入队-其实是尾插
void QueuePush(Queue* pq,QDataType data)
{
	assert(pq);
	//新建节点
	QNode* new_node = malloc(sizeof(QNode));
	if (new_node == NULL)
		perror("内存开辟失败");
	else
	{
		new_node->data = data;//将data放入节点中
		new_node->next = NULL;//新建节点的next需指向NULL
		//只有1个节点
		if (pq->tail == NULL)
			pq->head = pq->tail = new_node;//head、tail均指向该节点
		// >1个节点
		else
		{
			pq->tail->next=new_node;//最初的尾节点的next指向新建的节点，即新的尾节点
			pq->tail = new_node;//tail指向新的尾节点
		}
		pq->size++;
	}
}

//出队-其实是首删
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
		printf("队列为空，无法继续删除\n");
	//将要删除最后一个节点
	else if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	//删除后队列不为空，至少还剩1个节点
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

//判断队列是否为空,0表示空，1表示非空
int QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->size == 0 ? 0 : 1;
}

//获取队首数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
	{
		printf("队列为空，无任何数据\n");
		exit(-1);
	}
	else
		return pq->head->data;
}
//获取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
	{
		printf("队列为空，无任何数据\n");
		exit(-1);
	}
	else
		return pq->tail->data;
}

//获取队列数据个数
int QueueSize(Queue *pq)
{
	assert(pq);
	return pq->size;
}

//打印
void QueuePrint(Queue* pq)
{
	assert(pq);
	if (pq->tail == NULL)
		printf("队列为空，无任何数据\n");
	QNode* cur = pq->head;
	while (cur)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//销毁队列
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
