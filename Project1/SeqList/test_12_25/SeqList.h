#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>


// 实现顺序表的以下接口
typedef int DataType; //将类型重命名
#define MaxSize 10
#define NULL 0

typedef struct SeqList
{
	DataType array[MaxSize];
	int size;   // 有效数据元素的个数
}SeqList;


void InitSeqList(SeqList* seq);	// 初始化顺序表

void PushBack(SeqList* pSeq, DataType data);// 在顺序表的尾部插入值为data的元素

void PopBack(SeqList* pSeq);// 删除顺序表的最后一个元素

void PushFront(SeqList* pSeq, DataType data);// 在顺序表的头部插入值为data的元素

void PopFront(SeqList* pSeq);// 删除顺序表头部元素

void Insert(SeqList* pSeq, size_t pos, DataType data);// 在顺序表中pos位置上插入值为data的元素

void Erase(SeqList* pSeq, size_t pos);// 删除顺序表中pos位置上的元素

int Find(SeqList* pSeq, DataType data);// 在顺序表中查找值为data的元素，找到返回该元素的位置，否则返回-1

void PrintSeqList(SeqList* pSeq);    //打印顺序表

void DG_PrintSeqList(SeqList* pSeq,int p_size);    //递归打印顺序表

void Remove(SeqList* pSeq, DataType data);// 删除顺序表中第一个值为data的元素

void RemoveAll(SeqList* pSeq, DataType data);// 删除顺序表中所有值为data的元素

void BubbleSort(SeqList* pSeq);// 使用冒泡排序给顺序表中的元素排序

void SelectSort(SeqList* pSeq);// 使用选择排序给顺序表中的元素排序

int BinarySearch(SeqList* pSeq, DataType data);// 使用二分查找在顺序表中查找值为data

int DG_BinarySearch(SeqList* pSeq, DataType data,int left,int right)// 递归实现二分查找




#endif 










