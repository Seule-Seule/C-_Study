#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "00_SeqList.h"

/*
//创建并且返回一个空的线性表
SeqList* SeqList_Create(int n);

//销毁一个线性表SeqList
void SeqList_Destroy(SeqList* SeqList);

//将一个线性表SeqList中的所有元素清空, 线性表回到创建时的初始状态
void SeqList_Clear(SeqList* SeqList);

//返回一个线性表SeqList中的所有元素个数
int SeqList_Length(SeqList* SeqList);

//向一个线性表SeqList的pos位置处插入新元素node
int SeqList_Insert(SeqList* SeqList, SeqListNode* node, int pos);

//获取一个线性表SeqList的pos位置处的元素
SeqListNode* SeqList_Get(SeqList* SeqList, int pos);

//删除一个线性表SeqList的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
SeqListNode* SeqList_Delete(SeqList* SeqList, int pos);
*/


int main()
{
	int	ErroMsg = 0;
	int i = 0;

	SeqList* list;

	// 创建
	list = SeqList_Create(10);
	if (list == NULL)
	{
		printf("Func SeqList_Create()  Error! ");
		return -1;
	}

	// 插入元素
	for (i = 0; i < 8; i++)
	{
		ErroMsg = SeqList_Insert(list, (SeqListNode*)&i, 0);
		if (ErroMsg != 0)
		{
			printf("Func SeqList_Insert() Error!");
			return -2;
		}
	}
	
	// 遍历
	for (i = 0; i < SeqList_Length(list); i++)
	{
		int* tmp = SeqList_Get(list, 0);
		printf("%d   ", *tmp);
	}

	// 删除元素
	int deleteTmp = SeqList_Delete(list, (SeqListNode*)5);
	printf("Delete %d success!", deleteTmp);

	// 清空
	SeqList_Clear(list);

	// 删除线性表
	SeqList_Destroy(list);
	
	system("pause");
	return ErroMsg;
}