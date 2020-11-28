// bignum_pro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct BigNumber
{
    char strnum[33];
};

BigNumber AddBigNum(BigNumber a, BigNumber b)
{
    BigNumber final;
    final.strnum[32] = '\0';
    int i;
    int num[33];
    num[0] = 0;                  //num[0]防溢出
    for (i = 32; i >0; i--)
        num[i] = (int)a.strnum[i-1] + (int)b.strnum[i-1] - 96;//'0'的ASCII 码是48
    for (i = 32; i >0; i--)
    {
        if (num[i] >= 10)
        {
            num[i -1] += num[i] / 10;
            num[i] = num[i] % 10;
        }
        final.strnum[i-1] = num[i] + 48;
    }
    final.strnum[32] = '\0';
    return final;
}

BigNumber MultiplyBigNum(BigNumber a, BigNumber b)
{
    BigNumber final;
    final.strnum[32] = '\0';
    int i,j;
    int num[65];//防溢出,有用的是33~64
    for (i = 0; i <= 64; i++)num[i] = 0;
    for (i = 32; i > 0; i--)
    {
        for (j = 32; j > 0; j--)
        {
            num[i+j] += ((int)a.strnum[i-1] - 48) * ((int)b.strnum[j - 1] - 48);
        }
    }
    for (i = 64; i > 32; i--)
    {
        if (num[i] >= 10)
        {
            num[i - 1] += num[i] / 10;
            num[i] = num[i] % 10;
        }
        final.strnum[i - 33] = num[i] + 48;
    }
    final.strnum[32] = '\0';
    return final;
}

int main()
{
    char str1[100], str2[100];
    cout << "请依次分行输入两个大数（32位以内,超过取其前32位），这个程序会依次输出它们的和与积\n请注意，运算结果只保留32位\n";
    gets_s(str1);
    gets_s(str2);
    str1[32] = '\0'; str2[32] = '\0';
    BigNumber num1, num2, numAdd,numMul;
    int i;
    for (i = 0; i < 32; i++)
    {
        num1.strnum[i] = '0';
        num2.strnum[i] = '0';
    }
    num1.strnum[32] = '\0'; num2.strnum[32] = '\0';
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (i = 0; i <len1; i++)
        num1.strnum[i+32-len1] = str1[i];            //正序储存 0~31
    for (i = len2; i > 0; i--)
        num2.strnum[31-len2 + i] = str2[i - 1];
    numAdd = AddBigNum(num1, num2);
    cout << "相加的结果为 ";
    for (i = 0; i <= 31; i++)
        cout << numAdd.strnum[i];
    cout << endl;

    numMul = MultiplyBigNum(num1, num2);
    cout << "相乘的结果为 ";
    for (i = 0; i <= 31; i++)
        cout << numMul.strnum[i];
    cout << "\n";
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
