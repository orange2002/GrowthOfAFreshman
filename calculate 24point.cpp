// calculate 24point.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

float precalculate(int condition,float prenum1,float prenum2)
{
    switch (condition)
    {
    case 1:return prenum1 + prenum2; break;
    case 2:return prenum1 - prenum2; break;
    case 3:return prenum1 * prenum2; break;
    case 4:return prenum1 / prenum2; break;
    case 5:return prenum2 - prenum1; break;
    default:break;
    }
}
void calculate(float num1, float num2, float num3, float num4)
{
    float save1,save2;
    int i,j,k;
    float final=0;
    //[(a b) c] d 第一种顺序
    for (i = 1; i <= 5; i++)
    {
        save1=precalculate(i, num1, num2 );//(a b) 
        for (j = 1; j <= 5; j++)
        {
            save2=precalculate(j, save1, num3);//[(a b) c] 
            for (k = 1; k <= 5; k++)
            {
                final=precalculate(k, save2, num4 );//[(a b) c] d
                if (final == 24.0)
                {
                    cout << "YES 可以算出24点\n";
                    system("pause");
                    exit(0);
                }
            }
        }
    }
    //(a b) (c d) 第二种顺序
    for (i = 1; i <= 5; i++)
    {
        save1 = precalculate(i, num1, num2);//(a b) 
        for (j = 1; j <= 5; j++)
        {
            save2 = precalculate(j, num3, num4);//(c d) 
            for (k = 1; k <= 5; k++)
            {
                final=precalculate(k, save1, save2 );//(a b) (c d)
                if (final == 24.0)
                {
                    cout << "YES 可以算出24点\n";
                    system("pause");
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    float number[4];
    cin >> number[0] >> number[1] >> number[2] >> number[3];//四个数共有24种排序
    calculate(number[0], number[1], number[2], number[3]);
    calculate(number[0], number[1], number[3], number[2]);
    calculate(number[0], number[2], number[1], number[3]);
    calculate(number[0], number[2], number[3], number[1]);
    calculate(number[0], number[3], number[1], number[2]);
    calculate(number[0], number[3], number[2], number[1]);
    calculate(number[1], number[0], number[2], number[3]);
    calculate(number[1], number[0], number[3], number[2]);
    calculate(number[1], number[2], number[0], number[3]);
    calculate(number[1], number[2], number[3], number[0]);
    calculate(number[1], number[3], number[0], number[2]);
    calculate(number[1], number[3], number[2], number[0]);
    calculate(number[2], number[1], number[0], number[3]);
    calculate(number[2], number[1], number[3], number[0]);
    calculate(number[2], number[0], number[1], number[3]);
    calculate(number[2], number[0], number[3], number[1]);
    calculate(number[2], number[3], number[1], number[0]);
    calculate(number[2], number[3], number[0], number[1]); 
    calculate(number[3], number[1], number[2], number[0]);
    calculate(number[3], number[1], number[0], number[2]);
    calculate(number[3], number[2], number[1], number[0]);
    calculate(number[3], number[2], number[0], number[1]);
    calculate(number[3], number[0], number[1], number[2]);
    calculate(number[3], number[0], number[2], number[1]);
    cout << "NO 不能算出24点\n";
    system("pause");
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
//created by student chen haotian from  whu