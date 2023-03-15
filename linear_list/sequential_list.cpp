#include "common.h"

typedef struct /* sqlist */
{
    ElemType data[MaxSize]; // 存放线性表中的元素
    int length;             // 存放线性表的长度
} Sqlist;
// 顺序表类型
void InitList(Sqlist *&L);

void CreateList(Sqlist *&L, ElemType a[], int n) // 由 a 中的 n 个元素建立顺序表
{
    int i = 0, k = 0; // k 表示 L 中元素的个数，初始值为 0
    InitList(L);      // 分配存放线性表的空间
    while (i < n)     // i 扫描数组 a 的元素
    {
        L->data[k] = a[i]; // 将元素 a[i]存放到 L 中
        k++;
        i++;
    }
    L->length = k; // 设置 L 的长度 k
}

void InitList(Sqlist *&L)
{
    L = (Sqlist *)malloc(sizeof(Sqlist)); // 分配存放线性表的空间
    L->length = 0;                        // 置空线性表的长度为 0
}

void DestoryList(Sqlist *&L)
{
    free(L); // 释放 L 所指的顺序表空间
}

bool ListEmpty(Sqlist *L)
{
    return (L->length == 0);
}

int ListLength(Sqlist *L)
{
    return (L->length);
}

void DispList(Sqlist *L)
{
    for (int i = 0; i < L->length; i++) // 释放顺序表输出各元素值
    {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

bool GetElem(Sqlist *L, int i, ElemType &e)
{
    if (i < 1 || i > L->length)
    {
        return false; // 参数 i 错误时返回 false
    }
    e = L->data[i - 1]; // 取元素的值
    return true;        // 成功找到元素时返回 true
}

int LocateElem(Sqlist *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
    {
        i++; // 查找元素 e
    }
    if (i >= L->length) // 未找到时返回 0
    {
        return 0;
    }
    else //  找到后返回其逻辑符号
    {
        return i + 1;
    }
}

bool ListInsert(Sqlist *&L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1 || L->length == MaxSize)
    {
        return false; // 参数 i 错误时返回 false
    }
    i--;                                // 将顺序表的逻辑序号转化为物理序号
    for (int j = L->length; j > i; j--) // 将 data[i] 及后面的元素移一个位置
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e; // 插入元素 e
    L->length++;    // 顺序表的长度增 1
    return true;    // 成功插入返回 true
}

bool ListDelete(Sqlist *&L, int i, ElemType &e)
{
    if (i < 1 || i > L->length) // 参数 i 错误时返回 false
    {
        return false;
    }
    i--; // 将顺序表的逻辑序号转化为物理信号
    e = L->data[i];
    for (int j = i; j < L->length; j++) // 将 data[i] 之后的元素前移一个位置
    {
        L->data[j] = L->data[j++];
    }
    L->length--; // 顺序表的长度减 1
    return true; // 成功删除返回 true
}

int main()
{
    ElemType arr[] = {6, 8, 9, 10, 12, 13, 18, 26, 21};
    int len = sizeof(arr) / sizeof(ElemType);
    Sqlist *p;
    CreateList(p, arr, len);
    DispList(p);
    return 0;
}
