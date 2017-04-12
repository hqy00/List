#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//实现无头单链表的如下操作
typedef int DataType;

typedef struct Node
{
	struct Node * next;
	struct Node * random;
	DataType data;
}Node,*PNode;



// 初始化单链表---思考为什么要传递二级指针
void InitList(PNode* pHead);

// 在链表尾部插入值为data的新结点
void PushBack(PNode* pHead, DataType data);

// 删除链表的最后一个节点
void PopBack(PNode* pHead);

// 在链表头部插入置为data的新节点
void PushFront(PNode* pHead, DataType data);

// 删除链表的第一个结点
void PopFront(PNode* pHead);

// 查找链表中值为data的结点，存在返回该结点的地址，否则返回空
PNode Find(PNode Head, DataType data);

//在链表pos位置后插入值为data的新节点
void Insert(PNode* pHead,PNode pos, DataType data);

// 删除单链表pos位置上的结点
void Erase(PNode* pHead, PNode pos);

// 移除链表中第一个值为data的结点
void Remove(PNode* pHead, DataType data);

// 移除链表中所有值为data的结点
void RemoveAll(PNode* pHead, DataType data);

// 获取链表中结点的总个数
size_t Size(PNode pHead);

// 获取链表中第一个结点
PNode Front(PNode pHead);

// 获取链表中最后一个节点
PNode Back(PNode pHead);

// 判断链表是否为空
int Empty(PNode pHead);

// 打印单链表
void PrintList(PNode pHead);

// 构建新节点
PNode BuyNode(DataType data);

//////////////////链表面试题////////////////////////////////////
// 从尾到头打印单链表
void PrintListFromTail2Head(PNode pHead);

// 删除无头单链表的非尾结点，要求：不能遍历单链表
void DeleteNotTailNode(PNode pHead,PNode pos);

// 在无头单链表非头结点前插入新节点
void InsertNotHeadNode(PNode* pHead,PNode pos, DataType data);

// 用单链表实现约瑟夫环
PNode JosephCircle(PNode *pHead, size_t M);

// 逆置单链表--三个指针
PNode ReverseList(PNode pHead);

// 逆置单链表--头插法
PNode ReverseList_P(PNode pHead);

// 对单链表进行冒泡排序--升序
void BubbleSort(PNode pHead);

// 查找单链表的中间结点，要求只能够遍历一次链表
PNode FindMidNode(PNode pHead);

// 查找单链表的倒数第K个结点，只能够遍历一次链表
PNode FindLastKNode(PNode pHead, size_t K);

// 查找单链表的倒数第K个结点，只能够遍历一次链表
PNode FindLastK2Node(PNode pHead, size_t K);

// 删除单链表的倒数第K个结点
PNode DeleteLastKNode(PNode * pHead, size_t K);

// 合并两个有序单链表，合并之后依然有序
PNode MergeList(PNode * pHead1, PNode * pHead2);

//判断两个链表是否相交
int IsListCross(PNode pHead1, PNode pHead2);

//若两链表相交，求交点
PNode GetCrossNode(PNode pHead1, PNode pHead2);

//判断链表是否带环
PNode HasCircle(PNode pHead);

//求环的长度
size_t GetCircleLen(PNode pMeetNode);

//求环的入口点
PNode GetEnterNode(PNode pHead,PNode pMeetNode);

//判断两个链表是否带环
int HasCircleWithCircle(PNode pHead1,PNode pHead2);

//复杂链表的复制
PNode CopyComplexList(PNode pHead);

#endif