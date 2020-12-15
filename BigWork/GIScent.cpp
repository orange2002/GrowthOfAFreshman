// GIScent.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
struct gisInfo
{
    int id;
    char name[29];
    int pointNum;
    double x[101];
    double y[101];
    //(x[0],y[0])表示重心
};
double distance(double a1, double b1, double a2, double b2)
{
    double d = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    return d;
}
void mycent(int num,double xx[],double yy[])
{
    xx[0] = 0; yy[0] = 0;
    int i;
    for (i = 1; i <= num; i++)
    {
        xx[0] += xx[i];
        yy[0] += yy[i];
    }
    xx[0] /= num; yy[0] /= num;
}
int main()
{
    //----------------------------------------
    //测试数据
    //----------------------------------------
    /*gisInfo example;
    example.id = 0;
    strcpy_s(example.name,"测试点");
    example.pointNum = 2;
    example.x[1] = 0;
    example.y[1] = 0;
    example.x[2] = 1;
    example.y[2] = 1;
    mycent(example.pointNum, example.x, example.y);*/
    //---------------------------------------
    //数据输入部分
    //---------------------------------------
    cout << "请输入地物个数:";
    int allnum;
    cin >> allnum;
    gisInfo *gis = new gisInfo[allnum];
    int j;
    for (j = 0; j < allnum; j++)
    {
        printf("请输入第%d个点的id:", j + 1); cin>> gis[j].id;
        char str1[29];
        cout << "请输入地物名称:\n";
        cin>>str1;
        str1[28] = '\0'; strcpy_s(gis[j].name, str1);
        cout << "请输入边界点数:"; cin >> gis[j].pointNum;
        cout << "请依次输入坐标点:";
        int k;
        for (k = 1; k <= gis[j].pointNum; k++)
        {
            cin >> gis[j].x[k];
            cin >> gis[j].y[k];
        }
       
        mycent(gis[j].pointNum, gis[j].x, gis[j].y);
    }
    //-------------------------------------
    //以下为数据处理
    //-------------------------------------
    double x; double y;
    cout << "请输入点的坐标 "; cin >> x; cin >> y;
    double* dist = new double[allnum];
    int min,i;
    double mind;
    for (i = 0; i < allnum; i++)
    {
        dist[i] = distance(gis[i].x[0], gis[i].y[0], x, y);
        if (i == 0)
        {
            min = 0;
            mind = dist[0];
        }
        else
        {
            if (dist[i] < mind) { mind = dist[i]; min = i; }
        }
    }
    cout << "最近的地物GIS信息\n";
    cout <<"id:"<< gis[min].id<<endl;
    cout << "名称:"<<gis[min].name<<endl;

    delete[]gis;
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
