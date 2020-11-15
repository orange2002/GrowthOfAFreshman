// GetCrossPoint.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

bool GetCrossPoint(float* px1, float* py1, float* px2, float* py2, float* px, float* py)
{
    if ((px1[0] == px1[1] && py1[0] == py1[1]) || (px2[0] == px2[1] && py1[0] == py1[1]))
        return false;
    if ((py1[1] - py1[0]) * (px2[1] - px2[0]) == (py2[1] - py2[0]) * (px1[1] - px1[0]))
        return false;
    float a[2], b[2], c[2];
    a[0] = px1[1] - px1[0]; b[0] = py1[0] - py1[1]; c[0] = px1[1] * py1[0] - px1[0] * py1[1];
    a[1] = px2[1] - px2[0]; b[1] = py2[0] - py2[1]; c[1] = px2[1] * py2[0] - px2[0] * py2[1];
    *px = ((c[0] * a[1] - c[1] * a[0]) / (a[1] * b[0] - a[0] * b[1]));
    *py = ((c[0] * b[1] - c[1] * b[0]) / (b[1] * a[0] - b[0] * a[1]));
    return true;
}

int main()
{
    float* px = new float[1];
    float* px1 = new float[2];
    float* px2 = new float[2];
    float* py = new float[1];
    float* py1 = new float[2];
    float* py2 = new float[2];
    cout << "px1[0]=";
    cin>> px1[0];
    cout << "py1[0]=";
    cin >> py1[0];
    cout << "px1[1]=";
    cin >> px1[1];
    cout << "py1[1]=";
    cin >> py1[1];
    cout << "px2[0]=";
    cin >> px2[0];
    cout << "py2[0]=";
    cin >> py2[0];
    cout << "px2[1]=";
    cin >> px2[1];
    cout << "py2[1]=";
    cin >> py2[1];
    bool cross= GetCrossPoint(px1, py1, px2, py2, px, py);
    cout << boolalpha << cross<<"\n";
    if (cross == 1)
        cout << "(" << *px << "," << *py << ")";
    delete[]px;
    delete[]px1;
    delete[]px2;
    delete[]py;
    delete[]py1;
    delete[]py2;

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
