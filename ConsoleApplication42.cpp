// ConsoleApplication42.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

//�����ҵ��ַ�ָ��
char*mystrstr(char*src, char*des)
{
	char *pSrc = src;
	//����src
	while(*pSrc)//��0 true
	{
		char*pSrctemp=pSrc;//src�бȽ϶��еĵ�һ��
		//����des �Ƚ�
		char*pDes = des;
		while (*pDes++ == *pSrctemp++)
		{
			{

			}
			//pSrctemp++;
			//pDes++;
			if (*pDes == 0)//Ŀ���ַ�������
				return pSrc;

		}
		pSrc++;//ָ����һ��
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

