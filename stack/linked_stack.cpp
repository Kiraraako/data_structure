#include <iostream>
#include <malloc.h>

#define MaxSize 500
typedef int ElementType;

typedef struct linknode
{
    ElementType data;      // 数据域
    struct linknode *next; // 指针域
} LinkStnode;              // 链栈节点类型

void InitStack(LinkStnode *&s)
{
    s = (linknode *)malloc(sizeof(LinkStnode));
    s->next = NULL;
}

void DestroyStack(LinkStnode *&s)
{
    LinkStnode *pre, *p = s->next; // pre 指向头节点， p 指向首节点
    while (p != NULL)              // 循环到 p 为空
    {
        free(pre); // 释放 pre 节点
        pre = p;
        p = pre->next; // pre、p 同步后移
    }
    free(pre);
}

bool StackEmpty(LinkStnode *s)
{
    return (s->next == NULL);
}

bool Push(LinkStnode *&s, ElementType e)
{
    LinkStnode *p;
    p = (LinkStnode *)malloc(sizeof(LinkStnode)); // 新建节点
    p->data = e;                                  // 存放元素
    p->next = s->next;                            // 将 p 节点插入作为首节点
    s->next = p;
    return true;
}

bool Pop(LinkStnode *&s, ElementType &e)
{
    linknode *p;
    if (s->next == NULL) // 栈空的情况
    {
        return false;
    }
    p = s->next;       // p 指向首结点
    e = p->data;       // 提取首结点值
    s->next = p->next; // 删除首节点
    free(p);           // 释放被删除结点的空间
    return true;
}

bool GetTop(LinkStnode *s, ElementType &e)
{
    if (s->next == NULL) // 栈空的情况
    {
        return false;
    }
    e = s->next->data; // 提取首结点值
    return true;
}

int main()
{
    return 0;
}