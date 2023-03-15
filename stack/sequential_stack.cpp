#include "common.h"

typedef struct
{
    ElemType data[MaxSize]; // 存放栈中的数据元素
    int top;                   // 栈顶指针
} SqStack;                     // 顺序栈类型

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack)); // 分配一个顺序栈空间，首地址放在 s 中
    s->top = -1;                            // 栈顶指针置为-1
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *&s)
{
    return (s->top == -1);
}

bool Push(SqStack *&s, ElemType &e)
{
    if (s->top == MaxSize - 1) // 栈满的情况，栈上溢出
    {
        return false;
    }
    s->top++;            // 栈顶指针增 1
    s->data[s->top] = e; // 元素 e 放在栈顶指针处
    return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1) // 栈满的情况，栈上溢出
    {
        return false;
    }
    e = s->data[s->top]; // 取栈顶元素
    s->top--;            // 栈顶指针减一
    return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1) // 栈为空的情况，即栈下溢出
    {
        return false;
    }
    e = s->data[s->top]; // 取栈顶元素
    return true;
}

bool symmetry(ElemType str[])
{
    ElemType e;
    SqStack *st;
    InitStack(st);
    for (int i = 0; str[i] != '\0'; i++)
    {
        Push(st, str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        Pop(st, e);
        if (str[i] != e)
        {
            DestroyStack(st);
            return false;
        }
    }
    DestroyStack(st);
    return true;
}

int main()
{
    return 0;
}
