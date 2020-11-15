// GetFileTitle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void GetFileTitle( char* strPathName, char** strTitle, int* num_chars)
{
    char*pstr = strrchr(strPathName, '\\');   //最后的路径，如 \main.cpp

    if (pstr == "\\" ||pstr== NULL)   //不存在时
    {     
        num_chars = 0;
        *strTitle = NULL;
        cout << "错误！";
        exit(0);
    }
    else
    { 
        pstr += 1; //后移一位 main.cpp
        char*strtemp = strrchr(pstr, '.');
        int a = strlen(pstr);
        int b = 0;
        if (strtemp != NULL)b = strlen(strtemp);
        pstr[a - b] = '\0';   //去掉文件类型
        *num_chars = strlen(pstr);
        *strTitle = pstr;
        return;
    }
    return;
}

int main()
{
    char strInput[1000];
    gets_s(strInput);
    char* strPathName = strInput;
    char* strTitle[1]; //指针数组
    int* num_chars = new int;
    GetFileTitle(strPathName, strTitle, num_chars);
    cout <<"标题是："<< *strTitle << endl;
    delete num_chars;
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
