#pragma once
#include<iostream>
using namespace std;
#include<assert.h>


/*迭代器iteraotr是STL的一个重要组成部分,通过iterator可以很方便的存储集合中的元素.
STL为每个容器都写了一个行为类似于指针的类——迭代器，迭代器其实是对一个指针的包装,
它想模拟指针实现一些常用的方法,如++,--,!=,==,*,->等。
通过这些方法可以找到当前元素或是别的元素. vector是STL集合中比较特殊的一个,
因为vector中的每个元素都是连续的,所以在自己实现vector的时候可以用指针代替，List空间不连续，
要想直接使用++,--,!=,==,*,->等方法，不能使用指针，就必须使用迭代器*/


//~~~~~~~~~~~~~~~~~~~~~~~~~~~STL模拟实现库List（带头结点的双向循环链表）~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//结点构建
template<class T>
struct ListNode//定义结点类
{
	ListNode(const T& x = T())
		: _prev(0)
		, _next(0)
		, _value(x)
	{}

	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _value;
};


//迭代器功能实现,其实就是对指针的包装
template<class T, class Ref, class Ptr>//模板参数列表里定义的的三种类型
struct ListIterator//定义迭代器类
{
	typedef ListIterator<T, Ref, Ptr> Self;//类的类型是它自身的<T, Ref, Ptr>时，将类重命名为 self，简化命名
	typedef ListIterator<T, T&, T*> Iterator;//类的类型变成<T, T&, T*>（相当于对模板参数列表的三种类型实例化了），将类重命名为Iterator
	typedef ListIterator<const T, const T&, const T*> ConstItrator;
	typedef T ValueType;
	typedef Ref Reference;
	typedef Ptr Pointer;
	typedef ListNode<T>* Node;//重命名结点指针为Node
	typedef size_t SizeType;

	Node _node;

	ListIterator(Node x)
		:_node(x)
	{}

	ListIterator()
		:_node(NULL)
	{}

	ListIterator(const Iterator& x)
		:_node(x._node)
	{}

	bool operator==(const Iterator& x)
	{
		return _node == x._node;

	}

	bool operator!=(const Iterator& x)
	{
		return _node != x._node;

	}

	Reference operator*()//解引用得到当前迭代器对象里，指针_node所指向结点的_value值
	{
		return (*_node)._value;

	}

	Pointer operator->()//->得到当前迭代器对象里，指针_node所指向结点的_value值的指针
	{
		return &((*_node)._value);

	}

	//前置++
	Self& operator++()//返回迭代器类的引用
	{
		_node = _node->_next;
		return *this;
	}

	//后置++
	Self operator++(int)//返回迭代器类的对象
	{
		Self temp(*this);
		_node = _node->_next;
		return temp;

	}

	//前置--
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;

	}

	//后置--
	Self operator--(int)
	{
		Self temp(*this);
		_node = _node->_prev;
		return temp;
	}

};



//链表类
template<class T>
class List
{
public:
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef ListNode<T> Node;
	typedef Node* LinkType;
	typedef ListIterator<T, T&, T*> Iterator;
	typedef ListIterator<const T, const T& ,const T*> ConstIterator;
	typedef size_t SizeType;

	//构造
	List()
		:_head(BuyNewNode())
	{
		_head->_next = _head;
		_head->_prev = _head;

	}

	//拷贝构造
	List(const List<T>& l)
	{
		
		_head = BuyNewNode();
		_head->_next = _head;
		_head->_prev = _head;

		LinkType tmp = l._head->_next;
		while(tmp != l._head)
		{
			PushBack(tmp->_value);
			tmp = tmp->_next;
		}

	}



	//赋值运算符重载
	List& operator=(const List& l)
	{
		if(_head != l._head)	//判断不是自己给自己赋值
		{
			if(true != Empty())	//如果*this非空，清空*this
			{
				Clear();
			}

			LinkType tmp = l._head->_next;
			while(tmp != l._head)
			{
				PushBack(tmp->_value);
				tmp = tmp->_next;
			}

		}

		return *this;

	}


	
	//析构
	~List()
	{
		Clear();
		Iterator it = End();
		delete it._node;
	}

	Iterator Begin()
	{
		return (Iterator)(_head->_next);
	}
	ConstIterator Begin()const
	{
		return (ConstIterator)(_head->_next);
	}

	Iterator End()
	{
		return (Iterator)_head;
	}
	ConstIterator End()const
	{
		return (ConstIterator)_head;
	}

	bool Empty()const
	{
		return _head == _head->_next;
	}

	SizeType Size()const
	{	
		SizeType count = 0;
		Iterator it = Begin();
		while(it != End())
		{
			it++;
			count++;
		}
		return count;

	}

	Reference Front()
	{
		return *(Begin());//将Begin()返回的迭代器对象的_node指向结点的_value取出来
	}
	ConstReference Front()const
	{
		return *(Begin());
	}
	Reference Back()
	{
		return *(--End());
	}
	ConstReference Back()const
	{
		return *(--End());
	}

	//任意位置插入
	Iterator Insert(Iterator pos, const T& x)
	{
		assert(pos._node);//迭代器对象里面指向链表节点的指针不能为空（即链表不能为空）

		Iterator tmp ;
		tmp._node= BuyNewNode(x);
		tmp._node->_next = pos._node;
		tmp._node->_prev = pos._node->_prev;
		pos._node->_prev = tmp._node;
		tmp._node->_prev->_next = tmp._node;

		return tmp;

	}

	//头插
	void PushFront(const T& x)  
	{
		Insert(Begin(),x);

	}
	//尾插
	void PushBack(const T& x)
	{
		Insert(End(),x);
	}

	//任意位的删除
	Iterator Erase(Iterator pos)
	{
		//迭代器对象里面指向链表节点的指针不能为空（即链表不能为空）且也不能指向头结点
		assert(pos._node && pos._node != _head);

		pos._node->_prev->_next = pos._node->_next;
		pos._node->_next->_prev = pos._node->_prev;

		LinkType tmp = pos._node->_next;
		delete pos._node;
		pos._node = NULL;

		return (Iterator)tmp;
	}

	//头删
	void PopFront()
	{
		Erase(Begin());
	}

	//尾删
	void PopBack()
	{
		Erase(--End());//pos的_node不能指向头结点
	}

	//清空
	void Clear()
	{
		Iterator it = Begin();
		Iterator temp = it;
		while(temp != End())
		{
			it++;
			delete temp._node;
			temp = it;
		}
		it._node->_next = _head;
		it._node->_prev = _head;

	}


	//打印
	void Show()
	{
		if(true != Empty())
		{
			Iterator it = Begin();
			while(it != End())
			{
				cout<<*it<<"->";
				it++;
			}
			cout<<"end"<<endl;
		}

	}



protected:
	LinkType BuyNewNode(const T& data = T())
	{
		LinkType temp = new Node(data);
		return temp;
	}
protected:
	LinkType _head;

};



int main()
{
	//List<int> l1;
	List<int> l2;
	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
	l2.PopBack();
	l2.PopBack();
	List<int> l1(l2);
	//l1 = l2;
	//l2.Clear();
	l1.Show();
	//if(true != l2.Empty())
	//{
	//	cout<<l2.Size()<<endl;
	//}

	//l2.PushFront(1);
	//l2.PushFront(2);
	//l2.PushFront(3);
	//l2.PushFront(4);
	//l2.PopFront();
	//l2.PopFront();

	//l2.Show();

	//system("pause");
	return 0;
}




