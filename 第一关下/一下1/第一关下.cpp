// 一下1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct course
{
	char Cname[20];
	int Chour;
	int Cterm;
};

bool operator==(course r1, char* key1)
{
	if (strcmp(r1.Cname, key1)==0)return true;
	else return false;
}

bool operator==(course r, int key)
{
	if (r.Chour==key)return true;
	else return false;
}

int operator>(course r2, int key) 
{
	return r2.Chour>key;
}

int main()
{
    std::cout << "Hello World!\n"; 

	int i;
	course a[5]={ {"高等数学" ,90, 1}, {"离散数学", 72, 2}, {"英语", 72, 1}, {"计算机组成原理", 90, 2}, {"程序设计基础", 63, 3} };

	cout<<"查找出课程名为“英语”的记录:"<< endl;
	cout<<"课程名称  开课学时  开课学期"<< endl;
	const char* p="英语";
	for(i=0; i<5; i++)
		if(a[i]==p)break;
	cout <<a[i].Cname<<" "<< a[i].Chour<<" "<< a[i].Cterm<< endl;


	cout<<"查找课时72的所有记录:"<< endl; 
	cout<<"课程名称  开课学时  开课学期"<< endl;
	int b=72;
	for(i=0; i<5; i++)
		if(a[i]==b)
	cout <<a[i].Cname<<" "<<a[i].Chour<<" "<<a[i].Cterm<< endl;

	cout<<"查找课时>80的所有记录:"<< endl;
	cout<<"课程名称  开课学时  开课学期"<< endl;
	int c=80;
	for(i=0; i<5; i++)
		if (a[i]>c)
	cout<<a[i].Cname<<" "<<a[i].Chour<<" "<<a[i].Cterm<< endl;

	return 0;
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
