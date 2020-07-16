// 第三关.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdio.h>

using namespace std;
typedef int ElemType;

struct SNode
{
	ElemType data;
	SNode* next;
};

void Transform(long num, int r);

void InitStack(SNode*& HS);

void Push(SNode*& HS, const ElemType& item);

ElemType Pop(SNode*& HS);

bool EmptyStack(SNode* HS);

int main()
{
    std::cout << "Hello World!\n"; 

	cout << "Please input a number x"<< endl;
	ElemType x, y;
	cin >> x;
	cout << "Please input 需转换的进制 y" << endl;
	cin >> y;
	cout << "此数的y进制为：";
	Transform(x, y);
}

void Transform(long num, int r)
{
	SNode* a;
	InitStack(a);
	while (num != 0)
	{
		int k = num % r;
		Push(a, k);
		num /= r;
	}
	while (!EmptyStack(a)) cout << Pop(a);
	cout << endl;
}

void InitStack(SNode*& HS)
{
	HS = NULL;
}

void Push(SNode*& HS, const ElemType& item)
{
	SNode* newptr = new SNode;
	newptr->data = item;
	newptr->next = HS;
	HS = newptr;
}

ElemType Pop(SNode*& HS)
{
	if (HS == NULL)
	{
		cerr << "Linked stack is empty!" << endl;
		exit(1);
	}
	SNode* p = HS;
	HS = HS->next;
	ElemType temp = p->data;
	delete p;
	return temp;
}

bool EmptyStack(SNode* HS)
{
	return HS == NULL;
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
