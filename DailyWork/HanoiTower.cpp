// HanoiTower.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//置n盤于塔壹，移之于塔貳
int A = 1;


void func(int remainnum, const char* c1, const char* c2,const char* c3)
{
    if (remainnum == 1) 
    {
        printf("%d: %s-->%s\n", A, c1, c2);
        A += 1;
    }
    else
    {
        func(remainnum - 1, c1, c3, c2);
        printf("%d: %s-->%s\n", A, c1, c2);
        A += 1;
        func(remainnum - 1, c3, c2, c1);
    }
}

int main()
{
    int n;
    scanf_s("%d",&n);
    func(n,"塔壹","塔貳","塔叁");
    printf("需移盤%d次",A-1);
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
