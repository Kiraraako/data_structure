#include <iostream>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;

// 头插法
void CreateListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *tail;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;

    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
        if (i == 0)
        {
            tail = s;
        }
    }
    tail->next = L->next; // 将尾节点指向首节点形成环
}

// 尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = L->next;
}

void InitList(LinkNode *&L)
{
    /* 初始化只需要创建用于记录节点起始位置的头节点即可 */
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void DestroyList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool ListEmpty(LinkNode *L)
{
    return (L->next == NULL);
}

int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    if (p->next != NULL)
    {
        while (p != L->next)
        {
            n++;
            p = p->next;
        };
    }

    return (n);
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    if (p->next != NULL)
    {
        while (p != L->next)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
    }
    std::cout << std::endl;
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
        if(p->next == L->next){
            break;
        }
    }
    if (p == NULL)
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
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        return (0);
    }
    else
    {
        return (i);
    }
}

bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
    {
        return false;
    }
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return false;
    }
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0)
    {
        return false;
    }
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return false;
    }
    else
    {
        q = p->next;
        if (q == NULL)
        {
            return false;
        }
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

int main()
{
}