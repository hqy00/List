#include "list.h"



//初始化，分配了一个头结点，其他什么也没做。
//而你创建链表做的事就是为每一个节点分配空间并且初始化数据域 


//初始化一个没有头结点的单链表
void InitList(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;

}



// 在链表尾部插入值为data的新结点
void PushBack(PNode* pHead, DataType data)
{
	assert(pHead);
	if(NULL == *pHead)
	{
		*pHead = (PNode)malloc(sizeof(Node));
		(*pHead)->data = data;
		(*pHead)->next = NULL;
	}
	else
	{

		PNode NewNode,tag;							
		NewNode = (PNode)malloc(sizeof(Node));		//创造新结点
		NewNode->data = data;		
		NewNode->next = NULL;
		tag = *pHead;
		while(tag->next)
		{
			tag = tag->next;
		}
		tag->next = NewNode;

	}

}


// 删除链表的最后一个节点
void PopBack(PNode* pHead)
{
	assert(pHead);
	PNode ppre,pcur;
	ppre = *pHead;
	pcur = ppre->next;
	if(NULL == *pHead)
	{
		return;
	}

	if(NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;

	}
	else
	{
		while(pcur->next)
		{
			ppre = pcur;
			pcur = pcur->next;
		}
		free(pcur);
		ppre->next = NULL;
	}

}


// 在链表头部插入置为data的新节点
void PushFront(PNode* pHead, DataType data)
{
	assert(pHead);
	PNode NewNode;							
	NewNode = (PNode)malloc(sizeof(Node));		//创造新结点
	NewNode->data = data;	
	if(NewNode->data == NULL)
	{
		return;
	}
	NewNode->next = *pHead;
	*pHead = NewNode;

}


// 删除链表的第一个结点
void PopFront(PNode* pHead)
{
	assert(pHead);
	PNode ppre,pcur;
	ppre = *pHead;
	pcur = ppre->next;
	if(NULL == *pHead)
	{
		return;
	}
	*pHead = pcur;
	free(ppre);

}


// 查找链表中值为data的结点，存在返回该结点的地址，否则返回空
PNode Find(PNode Head, DataType data)
{
	assert(Head);
	PNode tag;
	tag = Head;
	while(tag)
	{
		if(data == tag->data)
		{
			return tag;
		}
		tag = tag->next;
	}
	return NULL;

}


//在链表pos位置后插入值为data的新节点
void Insert(PNode* pHead,PNode pos, DataType data)
{
	assert(pHead);
	PNode ppre,pcur,NewNode;							
	ppre = *pHead;
	pcur = ppre->next;
	NewNode = (PNode)malloc(sizeof(Node));		//创造新结点
	NewNode->data = data;
	while(ppre!=pos)
	{
		ppre = pcur;
		pcur = pcur->next;
	}
	ppre->next = NewNode;
	NewNode->next = pcur;


}

// 删除单链表pos位置上的结点
void Erase(PNode* pHead, PNode pos)
{
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
	{
		return;
	}
	if(pos == *pHead)
	{
		(*pHead) = pos->next;
		free(pos);
	}
	else
	{
		PNode ppre,pcur;							
		ppre = *pHead;
		pcur = ppre->next;
		while(pcur!=pos)
		{
			ppre = pcur;
			pcur = pcur->next;
		}
		ppre->next = pos->next;
		free(pos);
	}


}


// 移除链表中第一个值为data的结点
void Remove(PNode* pHead, DataType data)
{
	assert(pHead);
	PNode Head,pos,tag;
	Head = *pHead;
	tag = *pHead;
	pos = Find(Head,data);
	if(NULL == *pHead || NULL == pos)
	{
		return;
	}
	if(pos == *pHead)
	{
		(*pHead) = pos->next;
		free(pos);
	}
	else
	{
		while(tag->next != pos)
		{
			tag = tag->next;
		}
		tag->next = pos->next;
		free(pos);

	}


}


// 移除链表中所有值为data的结点
void RemoveAll(PNode* pHead, DataType data)
{
	assert(pHead);
	PNode ppre,pcur;
	while(NULL != Find(*pHead,data))
	{
		ppre = *pHead;
		pcur = ppre->next;
		if(NULL == *pHead)
		{
			return;
		}
		if(data == ppre->data)
		{
			*pHead = pcur;
			free(ppre);
		}
		else
		{
			while(pcur->data != data)
			{
				ppre = pcur;
				pcur = pcur->next;
			}
			ppre->next = pcur->next;
			free(pcur);

		}
	}

}

// 获取链表中结点的总个数
size_t Size(PNode pHead)
{
	assert(pHead);
	size_t count = 0;
	PNode tag = pHead;
	while(tag)
	{
		tag = tag->next;
		count++;
	}
	return count;

}

// 获取链表中第一个结点
PNode Front(PNode pHead)
{
	assert(pHead);
	if(NULL == pHead)
	{
		return NULL;
	}
	else
		return pHead;

}


// 获取链表中最后一个节点
PNode Back(PNode pHead)
{
	assert(pHead);
	PNode tag;
	tag = pHead;
	if(NULL == tag)
	{
		return NULL;
	}
	else
	{
		while(tag->next)
		{
			tag = tag->next;
		}
		return tag;

	}

}

// 判断链表是否为空
int Empty(PNode pHead)
{
	assert(pHead);
	if(NULL == pHead)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}

// 打印单链表
void PrintList(PNode pHead)
{
	assert(pHead);
	PNode tag;
	tag = pHead;
	if(NULL == tag)
	{
		return;
	}
	else
	{
		while(tag)
		{
			printf("%3d",tag->data);
			tag = tag->next;
		}

	}
}

// 构建新节点
PNode BuyNode(DataType data)
{
	PNode NewNode;							
	NewNode = (PNode)malloc(sizeof(Node));	
	NewNode->data = data;
	return NewNode;
}

// 从尾到头打印单链表,采用递归的方法。
void PrintListFromTail2Head(PNode pHead)
{
	PNode tag;
	tag = pHead;
	if(NULL == tag)
	{
		return;
	}
	else
	{
		PrintListFromTail2Head(tag->next);
		printf("%3d",tag->data);
	}

}


// 删除无头单链表的非尾结点，要求：不能遍历单链表
void DeleteNotTailNode(PNode* pHead,PNode pos)
{
	//采用替换法
	assert(pHead);
	PNode tag;
	if(NULL == pos->next || NULL == pos || NULL == *pHead)
	{
		return;
	}
	tag = pos->next;
	pos->data = tag->data;
	pos->next = tag->next;
	free(tag);

}


// 在无头单链表非头结点前插入新节点
void InsertNotHeadNode(PNode* pHead,PNode pos, DataType data)
{
	assert(pHead);
	PNode tag,NewNode;
	tag = pos->next;
	if(*pHead == pos || NULL == pos || NULL == *pHead)
	{
		return;
	}						
	NewNode = (PNode)malloc(sizeof(Node));	
	NewNode->data = pos->data;
	pos->next = NewNode;
	NewNode->next = tag;
	pos->data = data;

}


// 用单链表实现约瑟夫环
PNode JosephCircle(PNode *pHead, size_t M)
{
	assert(pHead);
	PNode back,ppre,pcur;
	if(NULL == *pHead)
	{
		return NULL;
	}
	back = Back(*pHead);
	back->next = *pHead;
	ppre = *pHead;
	pcur = ppre->next;
	while(ppre != ppre->next)
	{
		int tmp = M;
		while(--tmp)
		{	
			ppre = pcur;
			pcur = pcur->next;
		}
		//用替换法删除
		ppre->data = pcur->data;
		ppre->next = pcur->next;
		free(pcur);
		pcur =ppre->next;
	}
	ppre->next = NULL;
	return ppre;

}



// 逆置单链表--三个指针
PNode ReverseList(PNode pHead)
{
	assert(pHead);
	PNode ppre,pcur,pnext;
	ppre = pHead;
	pcur = ppre->next;
	pnext = pcur->next;
	if(NULL == pHead->next)
	{
		return pHead;
	}
	else
	{
		while(pnext)
		{
			pcur->next = ppre;
			ppre = pcur;
			pcur = pnext;
			pnext = pnext->next;
		}
		pcur->next = ppre;
		pHead->next = pnext;	//处理逆置以后的最后一个节点
		pHead = pcur;			//处理头结点指针pHead

	}

	return pHead;

}


// 逆置单链表--头插法
PNode ReverseList_P(PNode pHead)
{
	assert(pHead);
	PNode pNewhead,pcur;
	pNewhead = NULL;
	pcur = pHead->next;
	if(NULL == pHead->next)
	{
		return pHead;
	}
	else
	{
		while(pcur)
		{
			pHead->next = pNewhead;
			pNewhead = pHead;
			pHead = pcur;
			pcur = pcur->next;
		}
		pHead->next = pNewhead;
		pNewhead = pHead;
	}

	return pHead;

}




// 对单链表进行冒泡排序--升序
void BubbleSort(PNode pHead)
{
	assert(pHead);
	PNode ppre,pcur,ptail;
	ppre = pHead;
	pcur = ppre->next;
	ptail = NULL;
	if(NULL == pHead->next)
	{
		return;
	}
	else
	{
		while(pHead->next != ptail)
		{
			ppre = pHead;
			pcur = ppre->next;
			while(pcur != ptail)
			{
				if(ppre->data > pcur->data)
				{
					int tmp = ppre->data;
					ppre->data = pcur->data;
					pcur->data = tmp;
				}
				ppre = pcur;
				pcur = pcur->next;
			}
			ptail = ppre;
		}

	}

}



// 查找单链表的中间结点，要求只能够遍历一次链表
PNode FindMidNode(PNode pHead)
{
	assert(pHead);
	PNode p1,p2;	//让p1一次走一步，p2一次走两步
	p1 = pHead;
	p2 = pHead;
	while(NULL != p2 && NULL != p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}

	return p1;

}


// 查找单链表的倒数第K个结点，只能够遍历一次链表
PNode FindLastKNode(PNode pHead, size_t K)
{
	assert(pHead);
	PNode p1,p2;	//先让p2走k步，再p1,p2一起走，一直走到p2为NULL
	p1 = pHead;
	p2 = pHead;
	size_t count = Size(pHead);
	if(K > count || K<=0)
	{
		return NULL;
	}
	else
	{
		while(K--)
		{
			p2 = p2->next;
		}
		while(p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
}

// 查找单链表的倒数第K个结点，只能够遍历一次链表
PNode FindLastK2Node(PNode pHead, size_t K)
{
	assert(pHead);
	PNode p1,p2;	//先让p2走k-1步，再p1,p2一起走，一直走到p2->next为NULL
	p1 = pHead;
	p2 = pHead;
	size_t count = Size(pHead);
	if(K > count || K<=0)
	{
		return NULL;
	}
	else
	{
		while(--K)
		{
			p2 = p2->next;
		}
		while(p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
}

// 删除单链表的倒数第K个结点
PNode DeleteLastKNode(PNode * pHead, size_t K)
{
	assert(pHead);
	PNode pos,tag;
	pos = FindLastKNode(*pHead,K);
	if(NULL == pos)
	{
		return NULL;
	}
	if(pos == *pHead)
	{
		*pHead = (*pHead)->next;
		free(pos);
	}
	else
	{
		tag = pos->next;
		pos->data = tag->data;
		pos->next = tag->next;
		free(tag);
	}
	return *pHead;


}

// 合并两个有序单链表，合并之后依然有序
PNode MergeList(PNode * pHead1, PNode * pHead2)
{
	assert(pHead1);
	assert(pHead2);
	PNode p1,p2,pNewhead,tag1,tag2;
	p1 = *pHead1;
	p2 = *pHead2;
	pNewhead = NULL;
	if(NULL == p1 || NULL == p2)
	{
		return NULL;
	}

	while(p1 && p2)
	{
		if(p1->data <= p2->data)
		{
			tag1 = p1->next;
			p1->next = pNewhead;
			pNewhead = p1;
			p1 = tag1;
		}
		else
		{
			tag2 = p2->next;
			p2->next = pNewhead;
			pNewhead = p2;
			p2 = tag2;
		}

	}
	if(NULL == p1 && NULL != p2)	//此时p1完了，p2没完
	{
		while(p2)
		{
			tag2 = p2->next;
			p2->next = pNewhead;
			pNewhead = p2;
			p2 = tag2;
		}
	}
	if(NULL == p2 && NULL != p1)	//此时p2完了，p1没完
	{
		while(p1)
		{
			tag1 = p1->next;
			p1->next = pNewhead;
			pNewhead = p1;
			p1 = tag1;
		}
	}

	return pNewhead;

}

//判断两个链表是否相交
int IsListCross(PNode pHead1, PNode pHead2)
{
	PNode PTail1 = pHead1;
	PNode PTail2 = pHead2;
	if(NULL == pHead1|| NULL == pHead2)
	{
		return 0;
	}

	while(PTail1)
	{
		PTail1 = PTail1->next;
	}
	while(PTail2)
	{
		PTail2 = PTail2->next;
	}

	if(PTail1 == PTail2)
		return 1;

return 0;

}


//若两链表相交，求交点
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	size_t count1 = 0;
	size_t count2 = 0;
	int gap = 0;//差值
	PNode PL1 = pHead1;
	PNode PL2 = pHead2;
	if(0 == IsListCross(pHead1,pHead2))
	{
		return NULL;
	}
	count1 = Size(pHead1);
	count2 = Size(pHead2);
	gap = count1 - count2;
	if(gap > 0)
	{
		while(gap--)
		{
			PL1 = PL1->next;
		}
	}
	else
	{
		gap = 0 - gap;
		while(gap--)
		{
			PL2 = PL2->next;
		}
	}

	while(PL1 != PL2)
	{
		PL1 = PL1->next;
		PL2 = PL2->next;
	}

	return PL1;


}
//判断链表是否带环,带环的话返回相遇点
PNode HasCircle(PNode pHead)
{
	PNode PFast = pHead;
	PNode PSolw = pHead;

	while(PFast && PFast->next)
	{
		PFast = PFast->next->next;
		PSolw = PSolw->next;
		if(PFast == PSolw)
		{
			return PFast;
		}
	}

	return NULL;
}
//求环的长度
size_t GetCircleLen(PNode pMeetNode)
{
	PNode pCurNode = pMeetNode;
	size_t count = 0;
	if(NULL == pMeetNode)
	{
		return 0;
	}

	while(pCurNode->next != pMeetNode)
	{
		count++;
		pCurNode = pCurNode->next;

	}
	count += 1;//把最后的pMeetNode加上

	return count;
}

//求环的入口点
PNode GetEnterNode(PNode pHead,PNode pMeetNode)
{
	PNode pH = pHead;//给一个指向头部的指针
	PNode pM = pMeetNode;//给一个指向相遇点的指针
	if(NULL == pHead || NULL == pMeetNode)
	{
		return NULL;
	}

	while(pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}

	return pH;

}
//判断两个链表是否带环
int HasCircleWithCircle(PNode pHead1,PNode pHead2)
{
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;

	//判断两个链表是否带环
	PNode pMeetNode1 = HasCircle(pHead1);
	PNode pMeetNode2 = HasCircle(pHead2);

	//若都不带环
	if(NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		while(pL1->next)
		{
			pL1 = pL1->next;
		}
		while(pL2->next)
		{
			pL2 = pL2->next;
		}
		//如果尾结点相同就是相交
		if(pL1 == pL2)
		{
			return 1;
		}

	}
	else if(pMeetNode1 && pMeetNode2)//两个链表都带环,若相交则肯定pCurNode绕一圈会遇到pMeetNode2
	{
		PNode pCurNode = pMeetNode1;
		while(pCurNode->next  != pMeetNode1)
		{
			if(pCurNode == pMeetNode2)
			{
				return 2;
			}
			pCurNode = pCurNode->next;
		}
		if(pCurNode == pMeetNode2)
		{
			return 2;
		}
	}

	return 0;

}


//复杂链表的复制
PNode CopyComplexList(PNode pHead)
{
	PNode p1 = pHead;
	PNode p2 = NULL;
	PNode pNewNode = NULL;
	if(NULL == pHead)
	{
		return NULL;
	}

	//首先，在原链表每个结点之后插入一个新结点
	while(p1)
	{
		pNewNode = BuyNode(p1->data);
		assert(pNewNode);//判断pNewNode是否为空
		pNewNode->next = p1->next;
		p1->next = pNewNode;
		p1 = p1->next->next;
	}

	//接着，给新结点的随机域赋值
	p1 = pHead;
	p2 = p1->next;
	while(p2->next)
	{
		if(NULL == p1->random)
		{
			p2->random = NULL;
		}
		else
		{			
			p2->random = p1->random->next;
		}
		p1 = p2->next;
		p2 = p1->next;
	}
	//跳出循环处理最后一个结点
	if(NULL == p1->random)
	{
		p2->random = NULL;
	}
	else
	{			
		p2->random = p1->random->next;
	}

	//拆分原链表
	p1 = pHead;
	p2 = p1->next;
	pNewNode  = p2;//保存新链表表头
	while(p2->next)
	{
		p1->next = p2->next;
		p2->next = p1->next->next;
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = p2->next;

	return pNewNode;


}
void fun1()
{
	PNode head;
	InitList(&head);
	//PushBack(&head,1);
	//PushBack(&head,2);
	//PushBack(&head,3);
	//PushBack(&head,4);
	//PopBack(&head);
	//PopBack(&head);
	PushFront(&head,1);
	PushFront(&head,2);
	PushFront(&head,3);
	PushFront(&head,4);
	PopFront(&head);
	PopFront(&head);

}


void fun2()
{
	PNode head,ps;
	InitList(&head);	
	PushBack(&head,11);
	PushBack(&head,4);
	PushBack(&head,8);
	PushBack(&head,2);
	//PushBack(&head,3);
	//ps = head->next;
	//Insert(&head,ps,5);
	//ps = head;
	//Erase(&head, ps);
	//Remove(&head,2);
	//Remove(&head,1);
	//RemoveAll(&head,2);
	//Size(head);
	//Front(head);
	//Back(head);
	//Empty(head);
	//PrintList(head);
	//BueNode(10);
	//PrintListFromTail2Head(head);
	//DeleteNotTailNode(&head,ps);
	//InsertNotHeadNode(&head,ps,5);
	//ps = JosephCircle(&head, 3);
	//printf("%d",ps->data);
	//ps = ReverseList_P(head);
	//PrintList(ps);
	//BubbleSort(head);
	//PrintList(head);
	//ps = FindMidNode(head);
	//printf("%d",ps->data);
	//ps = FindLastKNode(head,3);
	//printf("%d",ps->data);
	//ps = FindLastK2Node(head,3);
	//printf("%d",ps->data);
	//ps = DeleteLastKNode(&head,3);
	//PrintList(ps);

}


void fun3()
{
	PNode head1,head2,ps;
	InitList(&head1);
	InitList(&head2);
	PushBack(&head1,8);
	PushBack(&head1,11);
	PushBack(&head1,21);
	PushBack(&head1,28);
	PushBack(&head2,4);
	PushBack(&head2,17);
	PushBack(&head2,32);
	PushBack(&head2,45);
	ps = MergeList(&head1,&head2);
	PrintList(ps);

}

void fun4()
{
	PNode head1,head2,ptail,ret;
	InitList(&head1);
	InitList(&head2);
	PushBack(&head1,1);
	PushBack(&head1,2);
	PushBack(&head1,3);
	PushBack(&head1,4);
	PushBack(&head1,5);
	PushBack(&head1,6);

	PushBack(&head2,4);
	PushBack(&head2,5);
	PushBack(&head2,6);

	ptail = Back(head2);//使两链表相交
	ptail->next = Find(head1,5);
	ret = GetCrossNode(head1,head2);
	printf("%d\n",ret->data);

}

void fun5()
{
	PNode head1,pTailNode,pMeetNode,pEnterNode;
	InitList(&head1);
	PushBack(&head1,1);
	PushBack(&head1,2);
	PushBack(&head1,3);
	PushBack(&head1,4);
	PushBack(&head1,5);
	PushBack(&head1,6);
	PushBack(&head1,7);
	PushBack(&head1,8);
	PushBack(&head1,9);

	pTailNode = Back(head1);//构环
	pTailNode->next = Find(head1,5);

	pMeetNode = HasCircle(head1);
	if(NULL == pMeetNode)
	{
		printf("不带环\n");
	}
	else
	{
		printf("%d\n",GetCircleLen(pMeetNode));

	}

	pEnterNode = GetEnterNode(head1,pMeetNode);
	printf("%d\n",pEnterNode->data);
}

void fun6()
{
	PNode head1,head2,ptail1,ptail2;

	InitList(&head1);
	PushBack(&head1,1);
	PushBack(&head1,2);
	PushBack(&head1,3);
	PushBack(&head1,4);
	PushBack(&head1,5);
	PushBack(&head1,6);

	InitList(&head2);
	PushBack(&head2,4);
	PushBack(&head2,5);
	PushBack(&head2,6);

	//构造环外相交
	ptail1 = Back(head1);//先让链表1构环
	ptail1->next = Find(head1,4);

	ptail2 = Back(head2);//再让链表2与链表1环外相交
	ptail2->next = Find(head1,2);

	printf("%d\n",HasCircleWithCircle(head1,head2));


}

void fun7()
{
	Node node1,node2,node3,node4,*pHead;
	node1.data = 1;
	node1.next = &node2;
	node1.random = &node3;

	node2.data = 2;
	node2.next = &node3;
	node2.random = &node2;

	node3.data = 3;
	node3.next = &node4;
	node3.random = NULL;

	node4.data = 4;
	node4.next = NULL;
	node4.random = &node2;

	pHead = CopyComplexList(&node1);
}

int main()
{
	//fun1();
	//fun2();
	//fun3();
	//fun4();
	//fun5();
	//fun6();
	fun7();
	return 0;
}