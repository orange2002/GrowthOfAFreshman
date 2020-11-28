// centAndDistance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
using namespace std;
float distance(float a1, float b1, float a2, float b2)
{
    float d = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    return d;
}
int main()
{
    int n;
    cout << "请输入点的个数:";
    cin >> n;
    float*px = new float[n];
    float* py = new float[n];
    int i;
    char temp;
    float x = 0,y=0;
    printf("请依次输入%d个点 格式:(x,y)\n", n);
    for (i = 0; i < n; i++) 
    {
        cin >> temp;
        scanf_s("%f,%f", &px[i],&py[i]);
        cin >> temp;
        x += px[i];
        y +=py[i];
    }
    printf("重心是(%f,%f)\n",x/=n,y/=n);
    float* dist=new float[n];
    int max, min;
    float maxd, mind;
    for (i = 0; i < n; i++)
    {  
        dist[i] = distance(px[i], py[i], x, y);
        if (i == 0)
        {
            max = 0; min = 0;
            maxd = dist[0]; mind = dist[0];
        }
        else 
        {
            if (dist[i] > maxd) { maxd = dist[i]; max = i; }
            if (dist[i] < mind) { mind = dist[i]; min = i; }
        }
    }
    printf("离重心最近的点：(%f,%f)\n离重心最远的点：(%f,%f)\n",px[min],py[min],px[max],py[max]);
    delete[]px;
    delete[]py;
    delete[]dist;
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
