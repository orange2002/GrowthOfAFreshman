// phraseString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const int AllWord=400;//400测试，正式31851
const int MaxString = 28;//只许州官放火，不许百姓点灯\n\0

int main()
{
    //读入成语----------------------------------------
    FILE* fp;
    fopen_s(&fp, "e:\\repo\\cy.txt", "r");
    if (fp == NULL) 
    {
        cout << "error";
        return 0;
    }
    
    char (*str)[MaxString]=new char[AllWord][MaxString];
    int strLen[AllWord];
    int i=0,j=0,k=0;
    for (i = 0; i < AllWord; i++) 
    {
        fgets(str[i], MaxString, fp);
        strLen[i] = strlen(str[i])-1;
        str[i][strLen[i]] = '\0';
    }
    fclose(fp);
    //读入完成-----------------------------------------
    //核心功能区---------------------------------------
    int inputNum;
    int inputwordLen;

    char wordtemp[28];
mode0:
    cout << "select mode\n";
    cin >> inputNum;
    
    
    switch (inputNum)
    {
    case 0:
        goto modeend;
    case 1:
        goto mode1;
    case 2:
        goto mode2;
    case 3:
        goto mode3;
    default:
        cout << "error";
        goto mode1;
    }

mode1:
    cout << "please input word\n";
    char inputWord[MaxString];
    cin >> inputWord;
    if (strcmp(inputWord,"0")==0)
        goto mode0;
    inputwordLen = strlen(inputWord);
    if (inputwordLen >= MaxString)
    {
        cout << "error\n";
        goto mode1;
    }
    for (i = 0; i < AllWord; i++)
    {
        for (j = 0; j < inputwordLen; j += 2)
        {
            k = 0;
            while (str[i][k] != '\0')
            {
                if ((str[i][k] == inputWord[j]) && (str[i][k + 1] == inputWord[j + 1]))
                    break;
                k += 2;
            }
            if (k == strLen[i])
                break;
            if (j == inputwordLen - 2)
                cout << str[i];
            
        }
    }
    cout << "finished find\n\n";
    goto mode1;

mode2:
    cout << "toss a coin... ";
    if(rand() % 2 ==0){
        cout << "it's computer's turn\n";
        strcpy_s(wordtemp,str[rand()% AllWord]);
        cout << wordtemp<<endl;
    }
    else {
        wordtemp[0] = '0';
        wordtemp[1] = '0';
    }
    while (wordtemp[0] != '0')
    {
        int lentemp;
        lentemp = strlen(wordtemp);
    }
    cout << "it's your turn ";
    cout << "please input a phrase\n";
    cin >> inputWord;
    if (strcmp(inputWord, "0") == 0)
        goto mode0;
    inputwordLen = strlen(inputWord);

    int inttemp[1000];
    int n; 
    n= 0;
    for (i = 0; i < AllWord; i++)
    {
        if (strcmp(str[i], inputWord) == 0)break;
        if (i== AllWord - 1) 
        {
            cout << "what you input is not a phrase, you lose\n\n";
            goto mode2;

        }
    }
    for (i = 0; i < AllWord; i++)
    {
        if ((str[i][0] == inputWord[inputwordLen - 2]) && (str[i][1] == inputWord[inputwordLen - 1]))
        {
            inttemp[n] = i;
            n += 1;
        }
    }
    if (n == 0)
    {
        cout << "find nothing, you win\n\n";
        goto mode2;
    }
    
    strcpy_s(wordtemp, str[inttemp[rand() % n]]);
    cout << wordtemp <<"\ncontinue ";
    goto mode2;

mode3:
    ;

modeend:

    delete[] str;
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
