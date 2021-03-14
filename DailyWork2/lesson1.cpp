#include<iostream>
using namespace std;

int MySwep(int *a, int* b)
{
	int c = *a; *a = *b; *b = c;
	return 0;
}

int MySwep2(int& a, int& b)
{
	int c = a; a = b; b = c;
	return a;
}
void main() {
	cout << "cghjjn\\\"";
	int nx= 0x80;//00000000 00000000 000000000 10000000
	short sx;//-32768 32767
	char cx = 127;//-128 127
	cx = 129; 0b10000001; 0b01111111;
	cout << "\n"<<endl<<cx;
	//12345678
	/*
	  00000001;//1
	  00000010;//2
	  00000011;//3
	  00001001;//9
	  00001111;//0xF;
	  11111111;//-1
	  11111110;//-2
	  01111111;//127
	  10000001;//-127;
	  10000000;//-128
	  */
	long lx;
	0b11111111;
	/*
	0XFF 11111111
	1010 0111 0xA7
	*/
	/*
	little big
	10000001 little逆向储存
	*/
	int u = 129;
	char cu = *((char*)&u);//把最高位当成符号位


	char cq = 'A'+1;
	int cci= 'A' + 1;
	cout << cq;

	unsigned char ucx ;
	1;//int
	1U;//无符号
	1L;//long
	1UL;
	//无符号 与 有符号 比较，全转换为 无符号

	float f;
	3.14;//double
	3.14f;//float
	
	bool bl;//非0为true;

	cout<<3.12f * 23.65f;

	const int constV =4;
	int nV = constV;
#define PI 3.14;
	
	const int cV2=1;
	const int& cVV2 = cV2;

	int uu = 4;
	const int& np = uu;
	uu = 7;
	//引用类型 别名
	int nV1 = 2;
	int& nVV1 = nV1;

	int a(1), b(2);
	MySwep(&b, &a);


	int* pA = &a;
	const int *pA1 = &a;//整型指针常量 指向内容

	int* const pA3 = &a;//常量指针 
	*pA3 = 33;

	const int* const pA4 = &a;

	return ;
}


//匈牙利命名法 
//int n ix
//float f
//double d
//bool b;
//char c
//short short
//* p