#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//申请一个节点
SLNode* SListBuyNode(SLDataType data)
{
	SLNode* new_node=malloc(sizeof(SLNode));//开辟一个节点的内存
	if (new_node == NULL)
		perror("节点申请失败");
	else
	{
		new_node->data = data;//将数据放到节点中
		new_node->next_node = NULL;//将指针成员初始化为空指针
	}

	return new_node;
}

//查询某个元素的位置（地址）
SLNode* SListFind(SLNode* cur, SLDataType data)
{
	while (cur != NULL)
	{
		if (cur->data == data)
			break;
		cur = cur->next_node;
	}
	return cur;//data对应节点的上一个节点的指针成员的，地址
}

//头插
void SListPushFront(SLNode** pp_head, SLDataType data)
{
	assert(pp_head);
	
	SLNode* new_node = SListBuyNode(data);//新建节点指针，指向开辟的内存
	new_node->next_node = *pp_head;//节点成员-指针需要指向原来的第一个节点，而原来的pList，即pp_head是指向第一个节点的
	*pp_head = new_node;//原来的pList，即pp_head需要指向新的第一个节点
}

//尾插
void SListPushBack(SLNode** pp_head, SLDataType data)//当0个节点时，会对pp_head进行修改，因此二级指针
{
	assert(pp_head);

	SLNode* new_node = SListBuyNode(data);//新建节点指针，指向开辟的内存

	if (*pp_head == NULL)//0个节点
	{
		//new_node->next_node本身就是NULL
		*pp_head = new_node;//pList，即*pp_head需要指向新建的节点
	}
	else//节点数大于0个
	{
		SLNode* tail=*pp_head;
		//找到尾节点
		while (tail->next_node)//当tail==倒数第二个节点的指针成员时，tail->next_node（最后一个节点的指针成员）==NULL，将不再进入循环
			tail = tail->next_node;
		
		//new_node->next_node本身就是NULL
		tail->next_node = new_node;//tail->next_node（原来的最后一个节点的指针成员）需要指向新建的节点
	}
}

//指定元素之后插入
void SListInsertAfter(SLNode* pp_head,SLDataType data_dest, SLDataType data_src)
{
	SLNode* pos = SListFind(pp_head, data_dest);//查询

	if (pos == NULL)
		printf("\n未查询到该数据，无法插入\n");
	else
	{
		SLNode* new_node = SListBuyNode(data_src);//新建节点指针，指向开辟的内存
		new_node->next_node = pos->next_node;//新建节点指针的指针成员==pos的指针成员，即 新建节点指针的指针成员 指向 data对应节点的下一个节点
		pos->next_node = new_node;//data对应节点的指针成员指向新开辟的内存，即新的节点
	}
}

//指定元素之前插入
void SListInsertBefore(SLNode** pp_head, SLDataType data_dest, SLDataType data_src)
{
	SLNode* pos = SListFind(*pp_head, data_dest);//查询

	if (pos == NULL)
		printf("\n未查询到该数据，无法插入\n");
	else
	{
		if (pos == *pp_head)
			SListPushFront(pp_head,data_src);
		else
		{
			//找到pos之前的位置
			SLNode* prev = *pp_head;
			while (prev->next_node != pos)
			{
				prev = prev->next_node;
			}
			
			SLNode* new_node = SListBuyNode(data_src);//新建节点指针，指向开辟的内存
			new_node->next_node = prev->next_node;//新建节点指针的指针成员==prev指向的节点（data对应节点的，前一个节点）的指针成员，即 新建节点指针的指针成员 指向 data对应节点
			prev->next_node = new_node;//data对应节点的,前一个节点的指针成员指向新开辟的内存，即新的节点
		}
	}
}

//头删
void SListPopFront(SLNode** pp_head)
{
	assert(pp_head);
	if(*pp_head ==NULL)
	{
		printf("\n链表为空，无法继续删除\n");
		//也可以直接return退出或直接assert(*pphead != NULL);
	}
	else
	{
		SLNode* pp_head_temp = *pp_head;
		*pp_head = (*pp_head)->next_node;//使pp_head指向第二个节点
		pp_head_temp->next_node = NULL;//将第一个节点的指针成员置为NULL
		free(pp_head_temp);//释放第一个节点的内存
	}
}

////尾删-v1，这种思路没有考虑仅有一个节点的情况
//void SListPopBack(SLNode* pp_head)//不需要对pp_head进行修改，因此一级指针
//{
//	if (pp_head != NULL)
//	{
//		//找到尾节点
//		while (pp_head->next_node->next_node)//当pp_head==倒数第三个节点的指针成员时，pp_head->next_node->next_node（最后一个节点的指针成员）==NULL，将不再进入循环
//		{
//			pp_head = pp_head->next_node;
//		}
//		free(pp_head->next_node);//释放pp_head指向的节点的，指针成员指向的，内存（即最后一个节点的内存）
//		pp_head->next_node = NULL;//将pp_head指向的节点的，指针成员（即倒数第二个节点的指针成员）置为NULL
//	}
//	else
//	{
//		printf("\n链表为空，无法继续删除\n");
//	}
//}

//尾删-v2
void SListPopBack(SLNode** pp_head)//可能需要对pp_head进行修改，因此二级指针
{
	if (*pp_head == NULL)//0个节点
	{
		printf("\n链表为空，无法继续删除\n");
	}
	else
	{
		if ((*pp_head)->next_node==NULL)//1个节点
		{
			free(*pp_head);//释放节点内存
			*pp_head = NULL;//将pp_head置为NULL
		}
		else
		{
			//找到尾节点，这个找尾节点的思路与v1稍有不同，各有优缺
			SLNode* prev = NULL;
			SLNode* cur = *pp_head;
			while (cur->next_node)//当cur==倒数第二个节点的指针成员时，cur->next_node（最后一个节点的指针成员）==NULL，将不再进入循环
			{
				prev = cur;
				cur = cur->next_node;
			}

			free(cur);//释放cur指向的节点内存（即原来最后一个节点的内存）
			prev->next_node = NULL;//将prev指向的节点的，指针成员（即原来倒数第二个节点的指针成员）置为NULL
		}
	}
}

//指定元素删除
void SListErase(SLNode** pp_head, SLDataType data_dest)
{
	SLNode* pos = SListFind(*pp_head, data_dest);//查询

	if (pos == NULL)
		printf("\n未查询到该数据，无法删除\n");
	else
	{
		if (pos == *pp_head)//data位于第一个节点
		{
			SLNode* pp_head_temp = *pp_head;
			*pp_head = (*pp_head)->next_node;//将pp_head指向第二个节点
			pp_head_temp->next_node = NULL;//将第一个节点的指针成员置为NULL
			free(pp_head_temp);//释放第一个节点的内存
		}
		else
		{
			//找到pos之前的位置
			SLNode* prev = *pp_head;
			while (prev->next_node != pos)
			{
				prev = prev->next_node;
			}

			prev->next_node = pos->next_node;//prev指向pos对应的节点，prev->next_node即为data对应节点的前一个节点，该节点的指针成员需要指向data后面的节点
			pos->next_node = NULL;//data对应节点的,前一个节点指针成员置为NULL
			free(pos);//pos指向data对应的节点，释放data对应的节点内存
		}
	}
}

//打印
void SListPrintf(SLNode* cur)
{
	
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next_node;
	}
	printf("\n");
}

//销毁链表
void SListDestroy(SLNode** pp_head)
{
	SLNode* pp_head_temp;
	while (*pp_head)
	{
		pp_head_temp = *pp_head;
		*pp_head = (*pp_head)->next_node;
		pp_head_temp->next_node = NULL;
		free(pp_head_temp);
	}
}
