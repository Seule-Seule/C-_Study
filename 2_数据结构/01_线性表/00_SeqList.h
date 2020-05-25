
#ifndef _00_SEQLIST_H_
#define _00_SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

//创建并且返回一个空的线性表
SeqList* SeqList_Create(int capacity);

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

#endif
