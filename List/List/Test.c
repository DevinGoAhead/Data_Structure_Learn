#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//查询数据的地址
LN* ListFind(LN *p_head,LTDataType data)
{
	assert(p_head);
	if (p_head->next == p_head)
		printf("链表为空，无任何数据\n");
	LN* cur = p_head->next;//虽然不使用cur也是可以的，但是定义cur可增加代码的可读性
	while (cur !=p_head )
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//申请新节点
LN* ListBuyNode(LTDataType data)
{
	LN* new_node = malloc(sizeof(LN));
	if (new_node == NULL)//判断内存是否开辟成功
	{
		perror("节点申请失败");
	}
	else
	{
		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	return new_node;
}

//初始化
void ListInitial(LN** pp_head)
{
	*pp_head = ListBuyNode(0);//新建哑节点/哨兵节点/头节点
	(*pp_head)->prev = *pp_head;//当只有头节点时，其prev、next均指向自己
	(*pp_head)->next = *pp_head;
}

//尾插
void ListPushBack(LN* p_head,LTDataType data)//通过分析，无论是0个有效节点或者非0个有效节点，均不需要改变头结点指针，因此一级指针
{
	assert(p_head);
	//通过分析，无论是0个有效节点或者非0个有效节点，尾插的操作都一样，因此不需要分情况
	LN *new_node=ListBuyNode(data);//申请新节点并把data放进去
	LN *tail = p_head->prev;//找到最初的尾节点
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = p_head;//新的尾节点的next需指向头结点
	p_head->prev = new_node;//头节点的prev需指向新的尾节点
}

//首插
void ListPushFront(LN* p_head, LTDataType data)//一级指针，原因同尾插
{
	assert(p_head);
	//通过分析，无论是0个有效节点或者非0个有效节点，首插的操作都一样，因此不需要分情况
	LN* new_node = ListBuyNode(data);//申请新节点并把data放进去
	LN* first = p_head->next;//找到最初的首节点
	first->prev = new_node;
	new_node->next = first;
	new_node->prev = p_head;//新的首节点的prev需指向头结点
	p_head->next = new_node;//头节点的next需指向新的首节点
}

//指定位置之后插入
void ListInsert(LN* p_head, LTDataType data_dest, LTDataType data_src)
{
	LN* pos = ListFind(p_head, data_dest);
	if (pos == NULL)
		printf("未查询到该数据\n");
	else
	{
		LN* new_node = ListBuyNode(data_src);//申请新节点并把data_src放进去
		LN* next = pos->next;//找到pos之后的节点
		pos->next = new_node;
		new_node->prev = pos;
		new_node->next = next;
		next->prev = new_node;
	}
}

//尾删
void ListPopBack(LN* p_head)//不需要改变头结点指针，因此一级指针
{
	assert(p_head);
	assert(p_head->next != p_head);//当0个有效节点时，就不能再删除了，否则会删除头结点，破坏链表结构
	LN* tail = p_head->prev;//找到最初的尾节点
	LN* prev = tail->prev;//找到最初的倒数第二个节点
	prev->next = p_head;//最初的倒数第二个节点的next需要指向头结点
	p_head->prev = prev;//头结点的prev需要指向最初的倒数第二个节点，即最新的尾节点
	free(tail);//释放最初的尾节点内存
}

//首删
void ListPopFront(LN* p_head)//不需要改变头结点指针，因此一级指针
{
	assert(p_head);
	assert(p_head->next != p_head);//当0个有效节点时，就不能再删除了，否则会删除头结点，破坏链表结构
	LN* first = p_head->next;//找到最初的首节点
	LN* second = first->next;//找到最初的第二个节点
	second->prev = p_head;//最初的第二个节点的prev需要指向头结点
	p_head->next = second;//头结点的next需要指向最初的第二个节点，即最新的头节点
	free(first);//释放最初的头节点内存
}

//指定位置删除
void ListErase(LN* p_head, LTDataType data)
{
	LN* pos = ListFind(p_head, data);
	if (pos == NULL)
		printf("未查询到该数据\n");
	else
	{
		LN* prev = pos->prev;//找到pos之前的节点
		LN* next = pos->next;//找到pos之后的节点
		prev->next = next;
		next->prev = prev;
		free(pos);
	}
}

//打印
void ListPrint(LN* p_head)
{
	assert(p_head);
	if (p_head->prev == p_head)
		printf("链表为空");
	LN* cur = p_head->next;
	while (cur != p_head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}