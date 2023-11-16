#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//����һ���ڵ�
SLNode* SListBuyNode(SLDataType data)
{
	SLNode* new_node=malloc(sizeof(SLNode));//����һ���ڵ���ڴ�
	if (new_node == NULL)
		perror("�ڵ�����ʧ��");
	else
	{
		new_node->data = data;//�����ݷŵ��ڵ���
		new_node->next_node = NULL;//��ָ���Ա��ʼ��Ϊ��ָ��
	}

	return new_node;
}

//��ѯĳ��Ԫ�ص�λ�ã���ַ��
SLNode* SListFind(SLNode* cur, SLDataType data)
{
	while (cur != NULL)
	{
		if (cur->data == data)
			break;
		cur = cur->next_node;
	}
	return cur;//data��Ӧ�ڵ����һ���ڵ��ָ���Ա�ģ���ַ
}

//ͷ��
void SListPushFront(SLNode** pp_head, SLDataType data)
{
	assert(pp_head);
	
	SLNode* new_node = SListBuyNode(data);//�½��ڵ�ָ�룬ָ�򿪱ٵ��ڴ�
	new_node->next_node = *pp_head;//�ڵ��Ա-ָ����Ҫָ��ԭ���ĵ�һ���ڵ㣬��ԭ����pList����pp_head��ָ���һ���ڵ��
	*pp_head = new_node;//ԭ����pList����pp_head��Ҫָ���µĵ�һ���ڵ�
}

//β��
void SListPushBack(SLNode** pp_head, SLDataType data)//��0���ڵ�ʱ�����pp_head�����޸ģ���˶���ָ��
{
	assert(pp_head);

	SLNode* new_node = SListBuyNode(data);//�½��ڵ�ָ�룬ָ�򿪱ٵ��ڴ�

	if (*pp_head == NULL)//0���ڵ�
	{
		//new_node->next_node�������NULL
		*pp_head = new_node;//pList����*pp_head��Ҫָ���½��Ľڵ�
	}
	else//�ڵ�������0��
	{
		SLNode* tail=*pp_head;
		//�ҵ�β�ڵ�
		while (tail->next_node)//��tail==�����ڶ����ڵ��ָ���Աʱ��tail->next_node�����һ���ڵ��ָ���Ա��==NULL�������ٽ���ѭ��
			tail = tail->next_node;
		
		//new_node->next_node�������NULL
		tail->next_node = new_node;//tail->next_node��ԭ�������һ���ڵ��ָ���Ա����Ҫָ���½��Ľڵ�
	}
}

//ָ��Ԫ��֮�����
void SListInsertAfter(SLNode* pp_head,SLDataType data_dest, SLDataType data_src)
{
	SLNode* pos = SListFind(pp_head, data_dest);//��ѯ

	if (pos == NULL)
		printf("\nδ��ѯ�������ݣ��޷�����\n");
	else
	{
		SLNode* new_node = SListBuyNode(data_src);//�½��ڵ�ָ�룬ָ�򿪱ٵ��ڴ�
		new_node->next_node = pos->next_node;//�½��ڵ�ָ���ָ���Ա==pos��ָ���Ա���� �½��ڵ�ָ���ָ���Ա ָ�� data��Ӧ�ڵ����һ���ڵ�
		pos->next_node = new_node;//data��Ӧ�ڵ��ָ���Աָ���¿��ٵ��ڴ棬���µĽڵ�
	}
}

//ָ��Ԫ��֮ǰ����
void SListInsertBefore(SLNode** pp_head, SLDataType data_dest, SLDataType data_src)
{
	SLNode* pos = SListFind(*pp_head, data_dest);//��ѯ

	if (pos == NULL)
		printf("\nδ��ѯ�������ݣ��޷�����\n");
	else
	{
		if (pos == *pp_head)
			SListPushFront(pp_head,data_src);
		else
		{
			//�ҵ�pos֮ǰ��λ��
			SLNode* prev = *pp_head;
			while (prev->next_node != pos)
			{
				prev = prev->next_node;
			}
			
			SLNode* new_node = SListBuyNode(data_src);//�½��ڵ�ָ�룬ָ�򿪱ٵ��ڴ�
			new_node->next_node = prev->next_node;//�½��ڵ�ָ���ָ���Ա==prevָ��Ľڵ㣨data��Ӧ�ڵ�ģ�ǰһ���ڵ㣩��ָ���Ա���� �½��ڵ�ָ���ָ���Ա ָ�� data��Ӧ�ڵ�
			prev->next_node = new_node;//data��Ӧ�ڵ��,ǰһ���ڵ��ָ���Աָ���¿��ٵ��ڴ棬���µĽڵ�
		}
	}
}

//ͷɾ
void SListPopFront(SLNode** pp_head)
{
	assert(pp_head);
	if(*pp_head ==NULL)
	{
		printf("\n����Ϊ�գ��޷�����ɾ��\n");
		//Ҳ����ֱ��return�˳���ֱ��assert(*pphead != NULL);
	}
	else
	{
		SLNode* pp_head_temp = *pp_head;
		*pp_head = (*pp_head)->next_node;//ʹpp_headָ��ڶ����ڵ�
		pp_head_temp->next_node = NULL;//����һ���ڵ��ָ���Ա��ΪNULL
		free(pp_head_temp);//�ͷŵ�һ���ڵ���ڴ�
	}
}

////βɾ-v1������˼·û�п��ǽ���һ���ڵ�����
//void SListPopBack(SLNode* pp_head)//����Ҫ��pp_head�����޸ģ����һ��ָ��
//{
//	if (pp_head != NULL)
//	{
//		//�ҵ�β�ڵ�
//		while (pp_head->next_node->next_node)//��pp_head==�����������ڵ��ָ���Աʱ��pp_head->next_node->next_node�����һ���ڵ��ָ���Ա��==NULL�������ٽ���ѭ��
//		{
//			pp_head = pp_head->next_node;
//		}
//		free(pp_head->next_node);//�ͷ�pp_headָ��Ľڵ�ģ�ָ���Աָ��ģ��ڴ棨�����һ���ڵ���ڴ棩
//		pp_head->next_node = NULL;//��pp_headָ��Ľڵ�ģ�ָ���Ա���������ڶ����ڵ��ָ���Ա����ΪNULL
//	}
//	else
//	{
//		printf("\n����Ϊ�գ��޷�����ɾ��\n");
//	}
//}

//βɾ-v2
void SListPopBack(SLNode** pp_head)//������Ҫ��pp_head�����޸ģ���˶���ָ��
{
	if (*pp_head == NULL)//0���ڵ�
	{
		printf("\n����Ϊ�գ��޷�����ɾ��\n");
	}
	else
	{
		if ((*pp_head)->next_node==NULL)//1���ڵ�
		{
			free(*pp_head);//�ͷŽڵ��ڴ�
			*pp_head = NULL;//��pp_head��ΪNULL
		}
		else
		{
			//�ҵ�β�ڵ㣬�����β�ڵ��˼·��v1���в�ͬ��������ȱ
			SLNode* prev = NULL;
			SLNode* cur = *pp_head;
			while (cur->next_node)//��cur==�����ڶ����ڵ��ָ���Աʱ��cur->next_node�����һ���ڵ��ָ���Ա��==NULL�������ٽ���ѭ��
			{
				prev = cur;
				cur = cur->next_node;
			}

			free(cur);//�ͷ�curָ��Ľڵ��ڴ棨��ԭ�����һ���ڵ���ڴ棩
			prev->next_node = NULL;//��prevָ��Ľڵ�ģ�ָ���Ա����ԭ�������ڶ����ڵ��ָ���Ա����ΪNULL
		}
	}
}

//ָ��Ԫ��ɾ��
void SListErase(SLNode** pp_head, SLDataType data_dest)
{
	SLNode* pos = SListFind(*pp_head, data_dest);//��ѯ

	if (pos == NULL)
		printf("\nδ��ѯ�������ݣ��޷�ɾ��\n");
	else
	{
		if (pos == *pp_head)//dataλ�ڵ�һ���ڵ�
		{
			SLNode* pp_head_temp = *pp_head;
			*pp_head = (*pp_head)->next_node;//��pp_headָ��ڶ����ڵ�
			pp_head_temp->next_node = NULL;//����һ���ڵ��ָ���Ա��ΪNULL
			free(pp_head_temp);//�ͷŵ�һ���ڵ���ڴ�
		}
		else
		{
			//�ҵ�pos֮ǰ��λ��
			SLNode* prev = *pp_head;
			while (prev->next_node != pos)
			{
				prev = prev->next_node;
			}

			prev->next_node = pos->next_node;//prevָ��pos��Ӧ�Ľڵ㣬prev->next_node��Ϊdata��Ӧ�ڵ��ǰһ���ڵ㣬�ýڵ��ָ���Ա��Ҫָ��data����Ľڵ�
			pos->next_node = NULL;//data��Ӧ�ڵ��,ǰһ���ڵ�ָ���Ա��ΪNULL
			free(pos);//posָ��data��Ӧ�Ľڵ㣬�ͷ�data��Ӧ�Ľڵ��ڴ�
		}
	}
}

//��ӡ
void SListPrintf(SLNode* cur)
{
	
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next_node;
	}
	printf("\n");
}

//��������
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
