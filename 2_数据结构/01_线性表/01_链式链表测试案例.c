#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "01_LinkList.h"

typedef struct _People
{
	LinkListNode node;
	int age;
}People;

int main()
{
	int	ret = 0, i = 0;
	LinkList* list;

	People p1, p2, p3, p4, p5;
	p1.age = 11;
	p2.age = 12;
	p3.age = 13;
	p4.age = 14;
	p5.age = 15;

	// 创建新链表
	list = LinkList_Create();
	if (list == NULL)
	{
		return -1;
	}

	// 插入元素
	ret = LinkList_Insert(list, (LinkListNode*)(&p1), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&p2), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&p3), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&p4), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&p5), 0);

	// 遍历元素
	for (i = 0; i < LinkList_Length(list); i++)
	{
		People* tmp = (People*)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			return -2;
		}
		printf("tmp->age: %d \n", tmp->age);
	}

	printf("删除元素：\n");
	// 删除元素
	while (LinkList_Length(list))
	{
		People* tmp = (People*)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			return -2;
		}
		printf("tmp->age: %d \n", tmp->age);
	}

	// 清空
	LinkList_Clear(list);
	
	// 销毁
	LinkList_Destroy(list);

	/*
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
	*/
	system("pause");
	return ret;
}