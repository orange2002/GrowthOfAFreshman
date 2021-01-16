// circle from n.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    const float pi = 3.1415926535;
    int i;//次数
    float x;//横坐标
    float y;//纵坐标
    float xn, yn;//坐标
    float r;//半径
    int n;//边数
    cout << "请依次输入横坐标、纵坐标、半径、多边形边数\n";
    cin >> x >> y >> r >> n;
    float a = 2 * pi / n;//单角度
    for(i=1;i<=n;i++)           //循环求坐标（顺时针）
    {
        xn = x + r*sin(a * i - a / 2);
        yn = y + r*cos(a * i - a / 2);
        printf("(%.5f,%.5f)\n", xn, yn);//输出
    }
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
