#include "SeqList.h"
#include<assert.h>
#include<string.h>


void InitSeqList(SeqList* seq)	// 初始化顺序表
{
	assert(seq);
	memset(seq->array,0,sizeof(seq->array));
	seq->size = 0;

}


void PushBack(SeqList* pSeq, DataType data)// 在顺序表的尾部插入值为data的元素
{
	assert(pSeq);
	if(pSeq->size >MaxSize)//插入的时候要注意是否已满
	{
		return;
	}
	else
	{
		pSeq->array[pSeq->size] = data;
		pSeq->size++;
	}

}


void PopBack(SeqList* pSeq)// 删除顺序表的最后一个元素
{
	assert(pSeq);
	if(0==pSeq->size)	//删除的时候要判断是否为空
	{
		return;
	}
	else
	{
		pSeq->size--;
	}

}

void PushFront(SeqList* pSeq, DataType data)// 在顺序表的头部插入值为data的元素
{
	assert(pSeq);
	int i =0;
	if(pSeq->size >MaxSize)
	{
		return;
	}
	else
	{
		for(i=pSeq->size-1;i>=0;i--)
		{
			pSeq->array[i+1] = pSeq->array[i];
		}
		pSeq->array[0] = data;
		pSeq->size++;

	}
}


void PopFront(SeqList* pSeq)// 删除顺序表头部元素
{
	assert(pSeq);
	int i =0;
	if(0==pSeq->size)	
	{
		return;
	}
	else
	{
		for(i =0;i<pSeq->size-1;i++)
		{
			pSeq->array[i] = pSeq->array[i+1];
		}
		pSeq->size--;

	}

}


void Insert(SeqList* pSeq, int pos, DataType data)// 在顺序表中pos位置上插入值为data的元素
{
	assert(pSeq);
	int i =0;
	if(pos > pSeq->size)            //必须在已有数据的任意位置插入（或头部或尾部或中间任意处）
	{
		return;
	}
	if(pSeq->size >MaxSize)
	{
		return;
	}
	else
	{
		for(i =pSeq->size-1;i>=pos;i--)
		{
			pSeq->array[i+1] = pSeq->array[i];
		}
		pSeq->array[pos] = data;
		pSeq->size++;

	}

}

void Erase(SeqList* pSeq, size_t pos)// 删除顺序表中pos位置上的元素
{
	assert(pSeq);
	int i =0;
	if(0==pSeq->size)	
	{
		return;
	}
	else
	{
		for(i=pos;i<pSeq->size-1;i++)
		{
			pSeq->array[i] = pSeq->array[i+1];
		}
		pSeq->size--;

	}


}

int Find(SeqList* pSeq, DataType data)// 在顺序表中查找值为data的元素，找到返回该元素的位置，否则返回-1
{
	assert(pSeq);
	int i =0;
	for(;i<pSeq->size;i++)
	{
		if(data == pSeq->array[i])
		{
			return i;
		}
	}

	return -1;
}


void PrintSeqList(SeqList* pSeq)    //打印顺序表
{
	assert(pSeq);
	int i =0;
	for(;i<pSeq->size;i++)
	{
		printf(" %d ",pSeq->array[i]);
	}

}

void Remove(SeqList* pSeq, DataType data)// 删除顺序表中第一个值为data的元素
{
	assert(pSeq);
	if( -1 == Find(pSeq,data))
	{
		return;
	}
	else
	{
		Erase(pSeq, Find(pSeq,data));
	}
}


void RemoveAll(SeqList* pSeq, DataType data)// 删除顺序表中所有值为data的元素
{
	assert(pSeq);
	int i =0,count =0;
	for(;i<pSeq->size;i++)
	{
		if(data == pSeq->array[i])	//是否等于data
		{
			count++;
		}
		else
		{
			pSeq->array[i-count] = pSeq->array[i];	//搬移count步
		}
	}
	pSeq->size -= count;
}



void BubbleSort(SeqList* pSeq)// 使用冒泡排序给顺序表中的元素排序
{
	int flag =0,i =0;
	for(;i<pSeq->size-1;i++)
	{
		int j =0;
		for(;j<pSeq->size-i-1;j++)
		{
			if(pSeq->array[j]>pSeq->array[j+1])	//交换
			{
				int tmp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j+1];
				pSeq->array[j+1] = tmp;
				flag =1;
			}
			
		}

		if(0==flag)
		{
			return;
		}

	}

}


void SelectSort(SeqList* pSeq)// 使用选择排序给顺序表中的元素排序
{
	int begin =0,end =pSeq->size-1;
	int minpos =0,maxpos =end;
	int i =0;
	while(begin < end)
	{
		minpos =begin;
		maxpos =end;
		for(i=begin;i<=end;i++)
		{
			if(pSeq->array[i] > pSeq->array[maxpos])
			{
				maxpos = i;
			}
			if(pSeq->array[i] < pSeq->array[minpos])
			{
				minpos = i;
			}
		}

		//四种情况
		if(minpos != end && maxpos == begin)	//最小位不在尾部，最大位在首部	
		{
			int p1 =pSeq->array[minpos];
			pSeq->array[minpos] = pSeq->array[begin];
			pSeq->array[begin] = p1;

			int p2 =pSeq->array[minpos];
			pSeq->array[minpos] = pSeq->array[end];
			pSeq->array[end] = p2;
		}
			
		if(maxpos != begin && minpos == end)	//最大位不在首部，最小位在尾部
		{
			int q1 =pSeq->array[maxpos];
			pSeq->array[maxpos] = pSeq->array[end];
			pSeq->array[end] = q1;

			int q2 =pSeq->array[maxpos];
			pSeq->array[maxpos] = pSeq->array[begin];
			pSeq->array[begin] = q2;
		}


		if(minpos != end && maxpos != begin)		//最小位不在尾部，最大位不在首部
		{
			int temp1 =pSeq->array[minpos];
			pSeq->array[minpos] = pSeq->array[begin];
			pSeq->array[begin] = temp1;

			int temp2 =pSeq->array[maxpos];
			pSeq->array[maxpos] = pSeq->array[end];
			pSeq->array[end] = temp2;
		}

			if(minpos == end && maxpos ==begin)		//最小位在尾部，最大位在首部
		{
			int tmp3 =pSeq->array[minpos];
			pSeq->array[minpos] = pSeq->array[maxpos];
			pSeq->array[maxpos] = tmp3;

		}

		begin++;
		end--;

	}
}






int BinarySearch(SeqList* pSeq, DataType data)// 使用二分查找在顺序表中查找值为data
{
	int left =0,right =0,mid =0;
	left =0;						//关键要看这里给的区间的左右值是否能取到
	right =pSeq->size-1;
	while(left <= right)
	{
		mid = left + ((right-left)>>1);
		if(data == pSeq->array[mid])
		{
			return mid;
		}
		else if(pSeq->array[mid] < data)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}











int DG_BinarySearch(SeqList* pSeq, DataType data,int left,int right)// 递归实现二分查找
{
	int mid;
	if(left > right)
	{
		return 0;
	}
	mid = left + ((right - left)>>1);
	if(data == pSeq->array[mid])
	{
		return mid;
	}
	else if(data > pSeq->array[mid])
	{
		DG_BinarySearch(pSeq,data,mid+1,right);
	}
	else
	{
		DG_BinarySearch(pSeq,data,left,mid-1);
	}

}








void DG_PrintSeqList(SeqList* pSeq,int p_size)    //递归打印顺序表
{
	assert(pSeq);
	p_size--;
	if(p_size != 0)
	{
		DG_PrintSeqList(pSeq,p_size);
	}

	printf(" %d ",pSeq->array[p_size]);

}

//void DG_PrintSeqList(SeqList* pSeq)    //递归打印顺序表
//{
//	assert(pSeq);
//	pSeq->size--;
//	if(pSeq->size != 0)
//	{
//		DG_PrintSeqList(pSeq);
//	}
//
//	printf(" %d ",pSeq->array[pSeq->size++]);
//
//}











void fun1()
{
	SeqList Sx; 
	InitSeqList(&Sx);
	PushBack(&Sx,3);
	PushBack(&Sx,7);
	PushBack(&Sx,11);
	PushBack(&Sx,19);
	PushBack(&Sx,23);
	PushBack(&Sx,37);
	PushBack(&Sx,40);
	PushBack(&Sx,55);
	//int ret = DG_BinarySearch(&Sx,11,0,Sx.size - 1);
	//printf("%d",ret);
	DG_PrintSeqList(&Sx,Sx.size);
	//SelectSort(&Sx);
	//int ret = BinarySearch(&Sx,18);
	//printf("%d",ret);
	//BubbleSort(&Sx);
	//RemoveAll(&Sx, 2);
	//Remove(&Sx, 2);
	//Find(&Sx, 2);
	//Find(&Sx, 5);
	//PrintSeqList(&Sx);
	//Insert(&Sx, 1,5);
	//Erase(&Sx,3);
	//Erase(&Sx,0);
	//PopBack(&Sx);
	//PopBack(&Sx);
	
}

//void fun2()
//{
//	SeqList Sx; 
//	InitSeqList(&Sx);
//	PushFront(&Sx,1);
//	PushFront(&Sx,2);
//	PushFront(&Sx,3);
//	PushFront(&Sx,4);
//	PopFront(&Sx);
//	PopFront(&Sx);
//}






int main()
{
	fun1();
	//fun2();
	return 0;
}