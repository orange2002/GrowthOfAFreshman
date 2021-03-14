#include <iostream>
using namespace std;
//double 类型变量的二进制位输出
void Double2CharBit(double dV, char Bit[65])
{
	char* pC = (char*)&dV;
	int nCount = sizeof(dV);//字节数
	int i, j;
	char c ;
	for (i = 1; i <= nCount; i++)//依次处理每个字节
	{
		c=*pC;
		for (j = 1; j <= 8; j++)//一个字节8比特
		{
			(c & 0x1) == 0?Bit[8 * i - j] = '0':Bit[8 * i - j] = '1';
			c>>= 1;
		}
		if(i!=nCount)pC++;
	}
	Bit[8 * nCount] = '\0';
	return;
}
//float 类型变量的二进制位输出
void Float2CharBit(float fV, char Bit[33])
{
	char* pC = (char*)&fV;
	int nCount = sizeof(fV);
	int i, j;
	char c;
	for (i = 1; i <= nCount; i++)
	{
		c = *pC;
		for (j = 1; j <= 8; j++)
		{
			(c & 0x1) == 0 ? Bit[8 * i - j] = '0' : Bit[8 * i - j] = '1';
			c >>= 1;
		}
		if (i != nCount)pC++;
	}
	Bit[8 * nCount] = '\0';
	return;
}
//int 类型变量的二进制位输出
void Int2CharBit(int nV, char Bit[33])
{
	char* pC = (char*)&nV;
	int nCount = sizeof(nV);
	int i, j;
	char c;
	for (i = 1; i <= nCount; i++)
	{
		c = *pC;
		for (j = 1; j <= 8; j++)
		{
			(c & 0x1) == 0 ? Bit[8 * i - j] = '0' : Bit[8 * i - j] = '1';
			c >>= 1;
		}
		if (i != nCount)pC++;
	}
	Bit[8 * nCount] = '\0';
	return;
}
//short 类型变量的二进制位输出
void Short2CharBit(short sV, char Bit[17])
{
	char* pC = (char*)&sV;
	int nCount = sizeof(sV);
	int i, j;
	char c;
	for (i = 1; i <= nCount; i++)
	{
		c = *pC;
		for (j = 1; j <= 8; j++)
		{
			(c & 0x1) == 0 ? Bit[8 * i - j] = '0' : Bit[8 * i - j] = '1';
			c >>= 1;
		}
		if (i != nCount)pC++;
	}
	Bit[8 * nCount] = '\0';
	return;
}

//char 类型变量的二进制位输出
void Char2CharBit(char cV, char Bit[9])
{
	char* pC = (char*)&cV;
	int nCount = sizeof(cV);
	int i, j;
	char c;
	for (i = 1; i <= nCount; i++)
	{
		c = *pC;
		for (j = 1; j <= 8; j++)
		{
			(c & 0x1) == 0 ? Bit[8 * i - j] = '0' : Bit[8 * i - j] = '1';
			c >>= 1;
		}
		if (i != nCount)pC++;
	}
	Bit[8 * nCount] = '\0';
	return;
}

int main()
{
	char cArray[65] = { 0 };
	Double2CharBit(123.45, cArray);
	cout << "double类型: " << cArray << endl;
	cArray[0] = 0;

	Float2CharBit(123.45F, cArray);
	cout << "float类型: " << cArray << endl;
	cArray[0] = 0;

	Int2CharBit(0x10F, cArray);
	cout << "int类型: " << cArray << endl;
	cArray[0] = 0;

	Short2CharBit(0x7001, cArray);
	cout << "short类型: " << cArray << endl;
	cArray[0] = 0;

	Char2CharBit('A', cArray);
	cout << "char类型: " << cArray << endl;
	cArray[0] = 0;

	system("pause");
}
