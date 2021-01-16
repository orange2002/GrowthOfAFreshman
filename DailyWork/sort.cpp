// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//排序求中值

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    float* array = new float[n+1];
    int i=0,j=0;
    for(i=1;i<=n;i++)
    {
        scanf_s("%f", &array[i]);
        array[0] = array[i];
        for (j = i; j >= 1; j--)
        {
            if (array[0] > array[j - 1])
            {
                array[j] = array[j-1];
                array[j-1] = array[0];
            }
            else break;
        }
    }
    for (i = 1; i <= n; i++)cout<<array[i]<<" ";
    cout << "中值是：";
    if (n % 2 == 1) cout << array[(n + 1) / 2];
    else cout << (array[n / 2] + array[n / 2 + 1]) / 2;
    cout << "\n";
    delete[]array;
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
