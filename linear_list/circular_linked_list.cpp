#include <iostream>
#include <stdlib.h>

/*
    带头节点的循环双链表是链表实现中的一种很好的方案，
    可以通过不存储数据的头结点来规避诸多的重复编码的
    临界条件；
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
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL, L->prior = NULL;

    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        s->prior = L;
        L->next = s;
    }
    s->next = L;  // 将尾节点指向 Head 节点形成环
    L->prior = s; // 将 Head 节点的 prior 指针指向最后一个节点
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
    if (L->next == NULL)
    {
        return false;
    }
    else
    {
        /* 从头节点出发，遍历一圈为止 */
        LinkNode *p = L;
        for (int j = 0; j < i; j++)
        {
            p = p->next;
            if (p->next = L->next)
            {
                break;
            }
        }
        /* 如果走了一圈，则说明没找到 */
        if (p == L->next && j > 0)
        {
            return false;
        }
        else
        {
            e = p->data;
            return true;
        }
    }
}

int LocateElem(LinkNode *L, ElemType e)
{
    int i = 1;
    if (L->next == NULL)
    {
        i = 0;
    }
    else
    {

        LinkNode *p = L->next;
        while (p->data != e)
        {
            p = p->next;
            i++;
            if (p = L->next)
            {
                i = 0;
                break;
            }
        }
    }
    return i;
}

bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    if (i <= 0 || L->next == NULL)
    {
        return false;
    }
    LinkNode *p = L->next, *s;
    if (i == 1 && p->data == e)
    {
        return true;
    }
    else
    {
        p = p->next;
    }
    while (j < i - 1)
    {
        j++;
        p = p->next;
        if (p == L->next)
        {
            return false;
        }
    }
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    if (i <= 0 || L->next == NULL)
    {
        return false;
    }
    LinkNode *p = L, *q;
    if (i == 1)
    {
        q = L->next;
        e = q->data;
        p = q->next;
        return true;
    }
    int j = 1;
    while (j <= i)
    {
        j++;
        p = p->next;
        if (p = L->next)
        {
            return false;
        }
    }
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    return 0;
}