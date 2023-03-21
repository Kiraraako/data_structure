#include "common.h"

typedef struct
{
    ElemType data;
    LinkNode *next;

} LinkNode;

void initQueue(LinkNode *&rear)
{
    rear = NULL;
}

bool enQueue(LinkNode *&rear, ElemType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    if (rear == NULL)
    {
        s->next = s;
        rear = s;
    }
    else
    {
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
    return true;
}

bool deQueue(LinkNode *&rear, ElemType &e)
{
    LinkNode *p;
    if (rear == NULL)
    {
        return false;
    }
    if (rear->next == rear)
    {
        e = rear->data;
        free(rear);
        rear = NULL;
    }
    else
    {
        p = rear->next;
        e = p->data;
        rear->next = p->next;
        free(p);
    }
    return true;
}

bool queueEmpty(LinkNode *rear)
{
    return (rear == NULL);
}