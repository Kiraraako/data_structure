#include <iostream>
#include <stdlib.h>

/*
    带头节点的循环双链表是链表实现中的一种很好的方案，
    可以通过不存储数据的头结点来规避诸多的需要重复编
    码的临界条件；
*/

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    struct LNode *prior;
} LinkNode;

void CreateList(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *p;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = L, L->prior = L;
    p = L;

    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->prior = p;
        p->next = s;
        p = s;
    }
    s->next = L;  // 将尾节点指向 Head 节点形成环
    L->prior = s; // 将 Head 节点的 prior 指针指向最后一个节点
}

void InitList(LinkNode *&L)
{
    /* 初始化只需要创建用于记录节点起始位置的头节点即可 */
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = L, L->prior = L;
}

void DestroyList(LinkNode *&L)
{
    LinkNode *p = L->next;
    while (p != L)
    {
        p = p->next;
        free(p->prior);
    }
    free(L);
}

bool ListEmpty(LinkNode *L)
{
    return (L->next == L);
}

int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L->next;
    while (p != L)
    {
        n++;
        p = p->next;
    }

    return (n);
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != L)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L->next;
    while (j < i && p != L)
    {
        j++;
        p = p->next;
    }
    if (p == L) /* 如果走了一圈，则说明没找到 */
    {
        return false;
    }
    else
    {
        e = p->data;
        return true;
    }
}

int LocateElem(LinkNode *L, ElemType e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != L && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == L)
    {
        return (0);
    }
    return i;
}

bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 1;
    LinkNode *p = L->next, *s;
    while (p != L && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == L && j > i)
    {
        return false;
    }
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->prior = p->prior;
    s->next = p;
    s->prior->next = s;
    s->next->prior = s;
    return true;
}

bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 1;
    LinkNode *p = L->next;
    while (p != L && j < i)
    {
        j++;
        p = p->next;
    }
    if ( p == L && j > i){
        return false;
    }
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

int main()
{
    ElemType arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(ElemType);
    LNode *L;
    CreateList(L, arr, len);
    DispList(L);
    std::cout << "length: " << ListLength(L) << std::endl;
    ElemType e = -1;
    if (GetElem(L, 12, e))
    {
        std::cout << "get element: " << e << std::endl;
    }
    else
    {
        std::cout << "element not found" << std::endl;
    }
    if (ListInsert(L, 11, 10))
    {
        DispList(L);
    }
    else
    {
        std::cout << "insert failed!" << std::endl;
    }
    ListDelete(L, 2, e);
    DispList(L);
    std::cout << "delete element: " << e << std::endl;

    return 0;
}