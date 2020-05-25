#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "00_SeqList.h"

typedef struct _SeqListHandle
{
	int length;
	int capacity;
	unsigned int* node;
}SeqListHandle;


//创建并且返回一个空的线性表
SeqList* SeqList_Create(int capacity)
{
	SeqListHandle* tmp;
	tmp = (SeqListHandle*)malloc(sizeof(SeqListHandle));
	if (tmp == NULL)
	{
		printf("Func SeqList_Create() Error! ");
		return NULL;
	}

	memset(tmp, 0, sizeof(SeqListHandle));

	tmp->length = 0;
	tmp->capacity = capacity;
	
	// 根据capacity申请空间
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capacity);
	if (tmp->node == NULL)
	{
		printf("Func SeqList_Create() Error! malloc Err");
		return NULL;
	}

	return tmp;
}

//销毁一个线性表SeqList
void SeqList_Destroy(SeqList* _SeqList)
{
	SeqListHandle* tmp;
	if (_SeqList == NULL)
	{
		return;
	}
	tmp = (SeqListHandle*)_SeqList;
	if (tmp->node != NULL)
	{
		free(tmp->node);
	}
	free(tmp);

	return;
}

//将一个线性表SeqList中的所有元素清空, 线性表回到创建时的初始状态
void SeqList_Clear(SeqList* _SeqList)
{
	SeqListHandle* tmp;
	if (_SeqList == NULL)
	{
		return;
	}
	tmp = (SeqListHandle*)_SeqList;
	tmp->length = 0;
	return;
}

//返回一个线性表SeqList中的所有元素个数
int SeqList_Length(SeqList* _SeqList)
{
	SeqListHandle* tmp;
	if (_SeqList == NULL)
	{
		return -1;
	}
	tmp = (SeqListHandle*)_SeqList;
	return tmp->length;
}

//向一个线性表SeqList的pos位置处插入新元素node
int SeqList_Insert(SeqList* _SeqList, SeqListNode* node, int pos)
{
	SeqListHandle* tmp;
	int i = 0;
	if (_SeqList == NULL || node == NULL || pos < 0)
	{
		return -1; 
	}
	tmp = (SeqListHandle*)_SeqList;

	// 判断是否满了
	if (tmp->length == tmp->capacity)
	{
		return -2;
	}

	// 插入位置修正
	if (pos > tmp->length)
	{
		pos = tmp->length;
	}

	// 插入位置前元素后移 
	for (i = tmp->length; i > pos; i--)
	{
		tmp->node[i] = (unsigned int *)tmp->node[i-1];
	}

	// 插入元素
	tmp->node[i] = node;
	tmp->length++;
	return 0;
}

//获取一个线性表SeqList的pos位置处的元素
SeqListNode* SeqList_Get(SeqList* _SeqList, int pos)
{
	SeqListHandle* tmp;
	int i = 0;
	if (_SeqList == NULL)
	{
		return NULL;
	}
	tmp = (SeqListHandle*)_SeqList;

	if (pos< 0 || pos > tmp->length)
	{
		return NULL;
	}

	return (SeqListNode * )tmp->node[pos];
}

//删除一个线性表SeqList的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
SeqListNode* SeqList_Delete(SeqList* _SeqList, int pos)
{
	SeqListHandle* tmp;
	SeqListNode* tmpNode;
	int i = 0;
	if (_SeqList == NULL)
	{
		return NULL;
	}
	tmp = (SeqListHandle*)_SeqList;

	if (pos< 0 || pos >= tmp->length)
	{
		return NULL;
	}
	
	tmpNode = (SeqListNode*)tmp->node[pos];
	// 插入位置前元素前移 
	for (i = pos +1; i < tmp->length; i++)
	{
		tmp->node[i-1] = tmp->node[i];
	}
	tmp->length--;
	return tmpNode;
}

