// teachersstrstr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

//返回找到字符指针
char*mystrstr(char*src, char*des)
{
	char *pSrc = src;
	//遍历src
	while(*pSrc)//非0 true
	{
		char*pSrctemp=pSrc;//src中比较段中的第一个
		//遍历des 比较
		char*pDes = des;
		while (*pDes++ == *pSrctemp++)
		{
			//pSrctemp++;
			//pDes++;
			if (*pDes == 0)//目标字符串结束
				return pSrc;
		}
		pSrc++;//指向下一个
	}
	return NULL;
}

int main()
{
	char*str1 ="abcdef";
	char*str2 = "cde";
	printf("%s", mystrstr(str1, str2));
	system("pause");
}

