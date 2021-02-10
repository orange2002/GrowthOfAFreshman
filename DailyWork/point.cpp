// point.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct doublePoint
{
    float x1, y1, x2, y2;
};
struct myDistance
{
    float d,x, y;
};
int main()
{
    doublePoint p1;
    scanf_s("%f,%f", &p1.x1, &p1.y1);
    scanf_s("%f,%f", &p1.x2, &p1.y2);
    myDistance p2;
    p2.x = p1.x2 - p1.x1;
    p2.y = p1.y2 - p1.y1;
    p2.d = p2.y * p2.y + p2.x * p2.x;
    p2.d = sqrt(p2.d);
    std::cout << "distance " << p2.d << "\n" << "(" << p2.x << "," << p2.y << ")\n";
    
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
