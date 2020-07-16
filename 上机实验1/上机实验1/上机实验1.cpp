// 上机实验1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;
#define maxsize 20

struct List
{
	ElemType list[maxsize];
	int size;
};

void Initlist(List &L)
{
	L.size = 0;
}

void TraverseList(List &L)
{
	for (int i = 0; i < L.size; i++)
		cout << L.list[i] << ' ';
	cout << endl;
}

bool Findlist(List &L, ElemType& item)
{
	for (int i = 0; i < L.size; i++)
		if (L.list[i] == item) {
			item = L.list[i];
			return true;
		}
	return false;
}

bool InsertList(List &L, ElemType item, int pos)
{
	if (pos<-1 || pos>L.size + 1)
	{
		cout << "pos值无效" << endl;
		return false;
	}
	int i;
	if (pos == 0)
	{
		for (i = 0; i < L.size; i++)
			if (item < L.list[i])break;
		pos = i + 1;
	}
	if (L.size == maxsize)
	{
		cout <<"表满，无法插入！" << endl;
		return false;
	}
	else if (pos == -1)pos = L.size + 1;
	for (i = L.size - 1; i >= pos - 1; i--)
		L.list[i + 1] = L.list[i];
	L.list[pos - 1] = item;
	L.size++;
	return true;
}

bool Deletelist(List &L, ElemType& item, int pos)
{
	if (L.size == 0) { cout << "error"; return false; }
	if (pos<-1 || pos>L.size)
	{
		cout << "error" << endl; return false;
	}
	int i;
	if (pos == 0) {
		for (i = 0; i < L.size; i++)
			if (item == L.list[i])break;
		if (i == L.size)return false;
		pos = i + 1;
	}
	else if (pos == -1)pos = L.size;
	item = L.list[pos - 1];
	for (i = pos; i < L.size; i++)
		L.list[i - 1] = L.list[i];
	L.size--;
	return true;
}

void SortList(List &L)
{
	int i, j;
	ElemType x;
	for (i = 1; i < L.size; i++)
	{
		x = L.list[i];
		for (j = i - 1; j >= 0; j--)
			if (x < L.list[j])L.list[j + 1] = L.list[j];
			else break;
		L.list[j + 1] = x;

	}
}

int main()
{
    std::cout << "Hello World!\n"; 

	int a[12]={3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
	int i, j, k; ElemType x;
	List t;
	Initlist(t);
	for (i=0; i<12; i++)
		InsertList(t, a[i], i+1);
	cout<<"欢迎您使用数字顺序表游戏！"<<endl;
	TraverseList(t);
	cout<<"请选择："<<endl;
	cout<<"1. 新建数字顺序表"<<endl;
	cout<<"2. 查找某数是否在表中"<<endl;
	cout<<"3. 插入一个数字到表中"<<endl;
	cout<<"4. 删除表中某数"<<endl;
	cout<<"5. 给数字顺序表排序"<<endl;
	cout<<"6. 屏幕输出整个表"<<endl;
	cout<<"7. 不想玩了，拜拜！"<<endl;
	cout<<"输入您的选择：";

	for (k = 0; k < 50; k++)
	{
		cin >> j;
		if (j == 1)
		{
			int b[12], i;
			cout<<"输入新建的数字"<<endl;
			for(i=0; i<12; ++i)
			{
				cin>>b[i];
			}
			List t;
			Initlist(t);
			for (i = 0; i < 12; i++) 
				InsertList(t, b[i], i+1);
			SortList(t);
			TraverseList(t);
		}

		else if (j == 2)
		{
			cout<<"输入待查找的元素:"<<endl;
			cin>>x;
			Findlist(t, x);
		}

		else if (j == 3)
		{
			cout<<"插入一个数字到表中，请输入待插入元素"<<endl;
			cin>>x;
			InsertList(t, x, 0);
			cout<<"插入成功"<<endl;
			SortList(t);
			TraverseList(t);
		}

		else if (j == 4)
		{
			cout<<"删除表中某数,请输入删除元素的值"<<endl;
			cin>>x;
			Deletelist(t, x, 0);
			cout<<"已删除"<<endl;
			SortList(t);
			TraverseList(t);
		}

		else if (j == 5)
		{

			cout<<"给数字顺序表排序"<<endl;
			SortList(t);
			TraverseList(t);
		}

		else if (j == 6)
		{
			TraverseList(t);
		}

		else if (j == 7)
		{
			return 0;
		}

	}

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
