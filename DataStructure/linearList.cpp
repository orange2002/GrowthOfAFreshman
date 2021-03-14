// linearList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

#define OK 1
#define INFEASIBLE -1
#define ERROR 0
#define TRUE 1
#define FALSE 0;
//OVERFLOW 在vs中被定义为3 这里不能重定义为-2
typedef char ElemType;
typedef int Status;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    ElemType* elem;
    int length;
    int listSize;
}Sqlist;

Status InitList(Sqlist& L) {
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(Sqlist));
    if (!L.elem)return ERROR;
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
}

Status DestoryList(Sqlist& L) {
    if (!L.listSize)return INFEASIBLE;
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listSize = 0;
    return OK;
}

Status ClearList(Sqlist& L) {
    L.length = 0;
    return OK;
}

bool ListEmpty(Sqlist L) {
    if (!L.length)return true;
    return false;
}

int ListLength(Sqlist L) {
    return L.length;
}

Status GetElem(Sqlist L, int i, ElemType& e) {
    if (i<1 || i>L.length)return ERROR;
    e = L.elem[i - 1];
    return OK;
}

Status elemCompare(ElemType a, ElemType b) {
    if (a == b)return TRUE;
    else return FALSE;
}

int LocateElem(Sqlist L, ElemType e, Status(*compare)(ElemType,ElemType)) {
    int i = 1;
    ElemType* p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e))++i;
    if (i <= L.length)return i;
    else return 0;
}

Status PriorElem(Sqlist L, ElemType cur_e, ElemType& pre_e) {
    int i=LocateElem(L, cur_e, elemCompare);
    if (i==0||i==1)return ERROR;
    pre_e = L.elem[i - 2];
    return OK;
}

Status NextElem(Sqlist L, ElemType cur_e, ElemType& next_e) {
    int i = LocateElem(L, cur_e, elemCompare);
    if (i == 0 || i == L.length)return ERROR;
    next_e = L.elem[i];
    return OK;
}

Status ListInsert(Sqlist& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1)return ERROR;
    if (L.length >= L.listSize) {
        ElemType* newbase = (ElemType*)realloc(L.elem, (L.listSize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)exit(OVERFLOW);
        L.elem = newbase;
        L.listSize += LISTINCREMENT;
    }
    ElemType* q = &(L.elem[i - 1]);
    ElemType* p = &(L.elem[L.length - 1]);
    for (; p >= q; --p)*(p + 1) = *p;
    *q = e;
    ++L.length;
    return OK;
}

Status ListDelete(Sqlist& L, int i, ElemType e) {
    if (i<1 || i>L.length)return ERROR;
    ElemType* p = &(L.elem[i - 1]);
    e = *p;
    ElemType* q = &(L.elem[L.length - 1]);
    for (; p < q; ++p)*p = *(p + 1);
    --L.length;
    return OK;
}

Status elemVisit(ElemType* a) {
    if (!a)return ERROR;
    std::cout << *a;
    return OK;
}

Status ListTraverse(Sqlist L, Status(*visit)(ElemType*)) {
    ElemType* p = L.elem;
    ElemType* q = L.elem + L.length - 1;
    for (; p <= q; p++)if (!visit(p))return ERROR;
    return OK;
}

int main()
{
    Sqlist La;
    InitList(La); cout << "init list successfully\n";
    ListInsert(La, 1, 'a'); cout << "a has been inserted\n";
    ClearList(La); cout << "clear the list\n";
    if(ListEmpty(La)==true)cout<<"list is empty"<<endl;
    int i = 1;
    for (; i <= 26; i++)ListInsert(La, i, 'a' + i-1);
    ElemType e;
    GetElem(La, 1, e);
    cout << "the first is " << e << "\n";
    cout <<"length is "<< ListLength(La)<<endl;
    cout << "the " << LocateElem(La, 'e', elemCompare) << " elem is e\n";
    PriorElem(La, 'g', e);
    cout << "the prior of g is " << e << '\n';
    NextElem(La, 'g', e);
    cout << "the next of g is " << e << '\n';
    ListDelete(La, 10, e); cout << e <<" is deleted\n";
    cout << "all: "; ListTraverse(La, elemVisit);
    DestoryList(La); cout << "\nlist destory\n";
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
