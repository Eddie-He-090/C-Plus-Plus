// 上级实验2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef int ElemType;

struct LNode
{
	ElemType data;
	LNode *next;
};

void InitList(LNode *&HL);

void ClearList(LNode *&HL);

int LenthList(LNode *HL);

bool EmptyList(LNode *HL);

ElemType GetList(LNode *HL, int pos)
{
	if (pos < 1)
	{
		cerr << "pos is out range!" << endl;
		exit(1);
	}
	int i = 0;
	while (HL != NULL)
	{
		i++;
		if (i == pos)
			break;
		HL = HL->next;
	}
	if (HL != NULL)
		return HL->data;
	else
	{
		cerr << "pos is out range!" << endl;
		exit(1);
	}
}

void TraverseList(LNode *HL);

bool FindList(LNode *HL, ElemType &item);

bool UpdateList(LNode *HL, const ElemType &item);

bool InsertList(LNode *&HL, ElemType item, int pos);

bool DeleteList(LNode *&HL, ElemType &item, int pos);

void SortList(LNode *&HL);

int main()
{
	std::cout << "Hello World!\n";

	int a[12] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
	int i;
	ElemType x;
	LNode *t;
	InitList(t);
	for (i = 0; i < 12; i++)
		InsertList(t, a[i], 0);
	InsertList(t, 48, -1);
	InsertList(t, 40, 0);
	cout << GetList(t, 4) << ' ' << GetList(t, 9) << endl;
	TraverseList(t);
	cout << "输入待查找的元素值：";
	cin >> x;
	if (FindList(t, x))
		cout << "查找成功！" << endl;
	else
		cout << "查找失败！" << endl;
	cout << "输入待删除元素的值：";
	cin >> x;
	if (DeleteList(t, x, 0))
		cout << "删除成功！" << endl;
	else
		cout << "删除失败！" << endl;
	for (i = 0; i < 6; i++)
		DeleteList(t, x, 0);
	TraverseList(t);
	cout << "按值输入，输入待插入元素的值：";
	cin >> x;
	if (InsertList(t, x, 0))
		cout << "插入成功！" << endl;
	else
		cout << "插入失败！" << endl;
	TraverseList(t);
	cout << "单链表长度：" << LenthList(t) << endl;
	if (EmptyList(t))
		cout << "单链表为空！" << endl;
	else
		cout << "单链表不空！" << endl;
	ClearList(t);

	LNode *t1;
	InitList(t1);
	for (i = 0; i < 5; i++)
	{
		cin >> x;
		InsertList(t1, x, 0);
	}
	TraverseList(t1);
	cout << "单链表长度：" << LenthList(t1) << endl;
	cout << "表头添加56" << endl;
	InsertList(t1, 56, NULL);
	cout << "表尾添加77" << endl;
	InsertList(t1, 77, -1);
	TraverseList(t1);
	cout << "请输入56以删除表头元素" << endl;
	cin >> x;
	DeleteList(t1, x, NULL);
	cout << "请输入77以删除表尾元素" << endl;
	cin >> x;
	DeleteList(t1, x, -1);
	TraverseList(t1);
	cout << "请输入5以删除5" << endl;
	cin >> x;
	DeleteList(t1, x, 0);

	return 0;
}

void InitList(LNode *&HL)
{
	HL = NULL;
}

void ClearList(LNode *&HL)
{
	LNode *cp, *np;	   //用cp作为指向当前接点（即待处理接点）的指针，用np作为指向当前                     //接点的后继接点的指针；
	cp = HL;		   //表头指针附给cp
	while (cp != NULL) //遍历单链表，向系统交回每一个接点
	{
		np = cp->next;
		delete cp;
		cp = np;
	}
	HL = NULL;
}

int LenthList(LNode *HL)
{
	int i = 0;
	while (HL != NULL)
	{
		i++;
		HL = HL->next;
	}
	return i;
}

bool EmptyList(LNode *HL)
{
	return HL == NULL;
}

void TraverseList(LNode *HL)
{
	while (HL != NULL)
	{
		cout << HL->data << " ";
		HL = HL->next;
	}
	cout << endl;
}

bool FindList(LNode *HL, ElemType &item)
{
	while (HL != NULL)
		if (HL->data == item)
		{
			item = HL->data;
			return true;
		}
		else
			HL = HL->next;
	return false;
}

bool UpdateList(LNode *HL, const ElemType &item)
{
	while (HL != NULL)
		if (HL->data == item)
			break;
		else
			HL = HL->next;
	if (HL == NULL)
		return false;
	else
	{
		HL->data = item;
		return true;
	}
}

bool InsertList(LNode *&HL, ElemType item, int pos)
{
	if (pos < -1)
	{
		cout << "pos值无效！" << endl;
		return false;
	}

	LNode *newptr;
	newptr = new LNode;
	newptr->data = item;
	newptr->next = NULL;

	LNode *cp = HL;
	LNode *ap = NULL;
	if (pos == 0)
	{
		while (cp != NULL)
			if (item < cp->data)
				break;
			else
			{
				ap = cp;
				cp = cp->next;
			}
	}
	else if (pos == -1)
		while (cp != NULL)
		{
			ap = cp;
			cp = cp->next;
		}
	else
	{
		int i = 0;
		while (cp != NULL)
		{
			i++;
			if (i == pos)
				break;
			else
			{
				ap = cp;
				cp = cp->next;
			}
		}
		if (cp == NULL && i + 1 < pos)
		{
			cout << "pos值超出单链表长度加1！" << endl;
			return false;
		}
	}
	if (ap == NULL)
	{
		newptr->next = HL;
		HL = newptr;
	}
	else
	{
		newptr->next = cp;
		ap->next = newptr;
	}
	return true;
}

bool DeleteList(LNode *&HL, ElemType &item, int pos)
{
	if (HL == NULL)
	{
		cerr << "HL is NULL!" << endl;
		return false;
	}
	if (pos < -1)
	{
		cout << "pos值无效！" << endl;
		return false;
	}
	LNode *ap, *cp;
	ap = NULL;
	cp = HL;
	if (pos == 0)
	{
		while (cp != NULL)
		{
			if (cp->data == item)
				break;
			else
			{
				ap = cp;
				cp = cp->next;
			}
		}
		if (cp == NULL)
		{
			cout << "单链表中没有相应的结点可删除！" << endl;
			return false;
		}
	}
	else if (pos == -1)
		while (cp->next != NULL)
		{
			ap = cp;
			cp = cp->next;
		}
	else
	{
		int i = 0;
		while (cp != NULL)
		{
			i++;
			if (i == pos)
				break;
			else
			{
				ap = cp;
				cp = cp->next;
			}
		}
		if (cp == NULL)
		{
			cerr << "deleted element is not exit!" << endl;
			return 0;
		}
	}
	if (ap == NULL)
		HL = HL->next;
	else
		ap->next = cp->next;
	delete cp;
	return 1;
}

void SortList(LNode *&HL)
{
	LNode *SL;
	InitList(SL);
	LNode *r = HL;
	while (r != NULL)
	{
		LNode *t = r->next;
		LNode *cp = SL;
		LNode *ap = NULL;
		while (cp != NULL)
		{
			if (r->data < cp->data)
				break;
			else
			{
				ap = cp;
				cp = cp->next;
			}
		}
		if (ap == NULL)
		{
			r->next = SL;
			SL = r;
		}
		else
		{
			r->next = cp;
			ap->next = r;
		}
		r = t;
	}
	HL = SL;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
