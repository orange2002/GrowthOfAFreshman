// LinkListApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;

#define OK 1
#define INFEASIBLE -2
#define ERROR -1
#define TRUE 1
#define FALSE 0
//OVERFLOW 在vs中被定义为3 这里不能重定义

typedef char ElemType;
typedef int Status;

typedef struct LNode {
    ElemType data;       //数据域
    struct LNode* next;   //指针域
}LNode, * LinkList;//结点

typedef struct tag_LinkList {
    LinkList head;//头结点指针
    int Listlength;
} SLinkList;//链表

Status InitList(SLinkList& L) {
    L.Listlength = 0;
    L.head = (LinkList)malloc(sizeof(LNode));
    if (L.head == NULL)return ERROR;//防止vs警告
    L.head->next = NULL;
    return OK;
} //初始化链表

Status GetElem(SLinkList L, int i, ElemType& e) {
    LNode* p = L.head->next;
    int j = 1;//计数器
    while (p && j < i) {
        p = p->next; ++j;
    }
    if (!p || j > i)return ERROR;
    e = p->data;
    return OK;
}//获取元素

Status ListInsert(SLinkList& L, int i, ElemType e) {
    LNode* p = L.head;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next; ++j;
    }
    if (!p || j > i - 1)return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    if (s == NULL)return ERROR;//防止vs警告
    s->data = e; s->next = p->next;
    p->next = s;
    ++L.Listlength;
    return OK;
}//插入元素

Status ListDelete(SLinkList& L, int i, ElemType& e) {
    LinkList p = L.head;
    int j = 0;
    while ((p->next) && j < i - 1) {
        p = p->next; ++j;
    }
    if (!(p->next) || j > i - 1)return ERROR;
    LinkList s = p->next;
    p->next = s->next;
    e = s->data;
    free(s);
    --L.Listlength;
    return OK;
}//删除元素

Status ClearList(SLinkList& L) {
    LinkList p = L.head;
    LinkList q;
    if (p == NULL)return ERROR;//链表未初始化或被摧毁，无头结点
    p = p->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }//从前往后依次删除结点
    L.head->next = NULL;
    L.Listlength = 0;
    return OK;
}//清空链表

Status DestoryList(SLinkList& L) {
    LinkList p = L.head;
    LinkList q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    L.Listlength = 0;
    L.head = NULL;
    return OK;
}//摧毁链表

int ListLength(SLinkList L) {
    if (L.head == NULL)return ERROR;//链表未初始化或被摧毁
    return L.Listlength;
}//获取长度

Status ListEmpty(SLinkList L) {
    if (L.head == NULL)return ERROR;//链表未初始化或被摧毁
    if (L.head->next)return FALSE;//不是空表
    else return TRUE;//是空表
}//检查是否为空

Status ListReverse(SLinkList& L) {
    LinkList r, p1, p2;
    if (!L.head)return ERROR;//链表未初始化或被摧毁
    r=NULL; 
    p1 = L.head->next;
    if (!p1)return ERROR;//空表
    p2 = p1->next;
    while (p2->next) {
        p1->next = r;
        r = p1;
        p1 = p2;
        p2 = p1->next;
    }
    p1->next = r;
    p2->next = p1;
    L.head->next = p2;
    return OK;
}//链表逆序

Status ListTraverse(SLinkList L) {
    LinkList p = L.head;
    if (!p)return ERROR;//链表未初始化或被摧毁
    p = p->next;
    while (p) {
        cout << (p->data);
        p = p->next;
    }
    cout << endl;
    return OK;
}//遍历链表，输出全部元素

int main() {
    SLinkList L;//声明链表L
    if (InitList(L) == OK) {
        cout << "initialize successfully\n";
    }//初始化链表L
    if (ListEmpty(L) == TRUE)cout << "list is empty\n";//检查是否为空
    int i;
    for (i = 25; i >= 0; --i) ListInsert(L, 1, 'A' + i);//将A~Z插入链表中
    cout << "list: "; ListTraverse(L);//遍历链表
    cout << "list length is "<< ListLength(L) <<endl;
    ElemType e;
    GetElem(L, 10, e);
    cout << "the 10 elem is " << e << endl;//获取第10个元素
    ListDelete(L, 20, e);
    cout << "the 20 elem " << e << " is deleted\n";//删除第二十个元素
    ListReverse(L);
    cout << "reversed list: "; ListTraverse(L);//链表反转
    if (ClearList(L) == OK)cout << "list is clear\n";
    if (DestoryList(L) == OK)cout << "list is destoryed\n";
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
