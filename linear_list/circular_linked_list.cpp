#include "common.h"

/*
    带头节点的循环双链表是链表实现中的一种很好的方案，
    可以通过不存储数据的头结点来规避诸多的需要重复编
    码的临界条件；
*/
typedef struct DNode
{
    ElemType data;
    struct DNode *next;
    struct DNode *prior;
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
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L->next;
    if(p != L){
        j ++;
    }
    while (p != L && j < i )
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
    /*
        对于循环链表，如果插入序号大于链本身的长度，
        将结点插入到链尾即可；
    */
    int j = 1;
    LinkNode *p = L->next, *s;
    while (p != L && j < i)
    {
        j++;
        p = p->next;
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
    DNode *L;
    CreateList(L, arr, len);
    DispList(L);
    cout << "length: " << ListLength(L) << endl;
    ElemType e = -1;
    if (GetElem(L, 10, e))
    {
        cout << "get element: " << e << endl;
    }
    else
    {
        cout << "element not found" << endl;
    }
    if (ListInsert(L, 11, 10))
    {
        DispList(L);
    }
    else
    {
        cout << "insert failed!" << endl;
    }
    ListDelete(L, 2, e);
    DispList(L);
    cout << "delete element: " << e << endl;

    return 0;
}