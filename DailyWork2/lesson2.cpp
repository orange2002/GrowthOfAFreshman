// lesson2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int revrtInt(int a)
{
    return
        ((a >> 24) | 0xFF)+/*       00 00 00 a1 */
        ((a >> 8) | 0xFF00)+/*      00 00 a2 00 */
        ((a << 8) | 0xFF0000)+/*    00 a3 00 00 */
        ((a << 24) | 0xFF000000);// a2 00 00 00 

}

float revrt(float f)
{
    int nCount = sizeof(f) / 2;
    char* pC = (char*)&f;
    for (int i = 0; i < nCount; i++)
    {
        char c = pC[i];
        pC[i] = pC[nCount - i - 1];
        pC[nCount - i - 1]=c;
    }
    return f;
}

double revrt(double f)  //重载函数
{
    int nCount = sizeof(f) / 2;
    char* pC = (char*)&f;
    for (int i = 0; i < nCount; i++)
    {
        char c = pC[i];
        pC[i] = pC[nCount - i - 1];
        pC[nCount - i - 1] = c;
    }
    return f;
}

//模板函数
template<class T>
T revrtUU(T v)
{
    int nCount = sizeof(v) / 2;
    char* pC = (char*)&v;
    for (int i = 0; i < nCount; i++)
    {
        char c = pC[i];
        pC[i] = pC[nCount - i - 1];
        pC[nCount - i - 1] = c;
    }
    return v;
}

int double2Bit(char* pD, double dV)
{
    char* pC = (char*)&dV;
    char T = 0x1;
    if (*pC & T == 0)
    {
        pD[7] = 1;
        pD[7] = '1';
    }

}//本周作业


int main()
{
    int a(0x01020304), b(2);
    //       00000001 00000010 00000011 00000100 逻辑顺序
    //物理顺序  4        3        2        1  little型
    int* pa = &a;
    //*pa = 4;
    short* psa =(short*) pa;
    *psa = 1;//修改 a 的前两个字节
    //*psa   00000000 00000001
    //*pa    00000001 00000010 00000000 00000001 
    cout<<(a==0x01020001);
    sizeof(pa);

    //位运算
    a=0x01020304;
    a=a >> 1;
    //            00000001 00000010 00000011 00000100
    //             0000000 10000001 00000001 10000010  左边补0或符号位（依据编译器）
    a <<= 1; //   00000001 00000010 00000011 00000100  右边补0
    //与运算 或运算
    a = 0x01010101; b = 0x01010110;
    //00000001 00000001 00000001 00000001
    //00000001 00000001 00000001 00010000
    int c = a & b;
    //00000001 00000001 00000001 00000000
    c = a | b;
    //00000001 00000001 00000001 00010001
    c = ~a;
    c = a^ b;


    char* pc = (char*)pa;
    float fV = 3.1F;
    char* pcF = (char*)&fV;
    //pcF[0] == *(pcF + 0);
    //pcF[n][m]==*(*(pcF+n)+m);
    char cx = *pcF;
    *(pcF + 0) = *(pcF + 3);
    *(pcF + 3) = c;//交换第1、3字节

    revrt(1.0F);
    revrtUU(1.0);//隐式调用
    revrtUU<int>(10);//显式调用


    const char* pX = NULL;
    char* pY = NULL;
    {
        const char* p = "1234567";
        char pC[5] = "ab&c";//{ 'a','b','64','c','\0' };
        cout << pC;
        //p[0] = 'q';
        pX = p;
        pY = pC;

    }
    char C1 = pX[0];
    char C2 = pY[0];


    char pD[32];
    double2Bit(pD,1);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
