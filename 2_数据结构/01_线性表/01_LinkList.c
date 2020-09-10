#define   _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "01_LinkList.h"


typedef struct _tag_LinkList
{
	LinkListNode header;
	int LLeaght;
}TLinkList;


//创建并且返回一个空的线性表
LinkList* LinkList_Create()
{
	TLinkList* tmp;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkList));
	return tmp;
}

//销毁一个线性表list
void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		return ;
	}
	return ;
}

//将一个线性表list中的所有元素清空, 线性表回到创建时的初始状态
void LinkList_Clear(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	
	tList = (TLinkList*)list;
	tList->header.next = NULL;
	tList->LLeaght = 0;
	return ;
}

//返回一个线性表list中的所有元素个数
int LinkList_Length(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return -1;
	}

	tList = (TLinkList*)list;
	return (tList->LLeaght);
}

//向一个线性表list的pos位置处插入新元素node
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) ERR %d !", ret);
		return ret;
	}
	tList = (TLinkList*)list;
	current = &(tList->header);
	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	// 插入节点
	node->next = current->next;
	current->next = node;
	tList->LLeaght++;

	return ret;
}

//获取一个线性表list的pos位置处的元素
LinkList* LinkList_Get(LinkList* list, int pos)
{
	int i = 0;
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	if (list == NULL || pos < 0)
	{
		
		return NULL;
	}
	tList = (TLinkList*)list;
	current = &(tList->header);
	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//删除一个线性表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
LinkList* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	LinkListNode* tmp = NULL;
	if (list == NULL || pos < 0)
	{

		return NULL;
	}
	tList = (TLinkList*)list;
	current = &(tList->header);
	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	tmp = current->next;
	current->next = tmp->next;

	tList->LLeaght--;
	
	return tmp;
}
