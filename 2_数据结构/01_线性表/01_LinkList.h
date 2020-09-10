#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _01_LINKLIST_H_
#define _01_LINKLIST_H_

typedef void LinkList;

typedef struct _LinkListNode
{
	struct _LinkListNode* next;
}LinkListNode;


//创建并且返回一个空的线性表
LinkList* LinkList_Create();

//销毁一个线性表list
void LinkList_Destroy(LinkList* list);

//将一个线性表list中的所有元素清空, 线性表回到创建时的初始状态
void LinkList_Clear(LinkList* list);

//返回一个线性表list中的所有元素个数
int LinkList_Length(LinkList* list);

//向一个线性表list的pos位置处插入新元素node
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取一个线性表list的pos位置处的元素
LinkList* LinkList_Get(LinkList* list, int pos);

//删除一个线性表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
LinkList* LinkList_Delete(LinkList* list, int pos);

#endif
