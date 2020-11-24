// ConsoleApplication56.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cout << "please input people numker n:";
	cin >> n;
	cout << "please input the count number k:";
	cin >> k;
	int*a = new int[n+1];
	int i,j;
	for (i = 1; i <= n; i++)a[i] = i;
	int out = 0;
	for (i = n; i > 1; i--)
	{
		out += k;
		out = out%i;
		if (out == 0)out = i;
		cout << a[out]<<endl;
		for (j = out; j < i; j++)a[j] = a[j + 1];
		out -= 1;
	}
	cout <<"the last one is:"<< a[1];
	delete []a;
    return 0;
}
//法1：一个数组不变，修改标识 0存在 1不存在
//法2：两个数组 原始 在  模拟现实
