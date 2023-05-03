#include "common.h"

#define TreeElementType char

typedef struct BtreeNode
{
    TreeElementType data;
    struct BtreeNode *lchild;
    struct BtreeNode *rchild;
} BTNode;

void CreateBTree(BTNode *&b, char *str)
{
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p, k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL)
            {
                b = p;
            }
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DispTree(BTNode *b)
{
    if (b != NULL)
    {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL)
        {
            cout << "(";
            DispTree(b->lchild);
            if (b->rchild != NULL)
                cout << ",";
            DispTree(b->rchild);
            cout << ")";
        }
    }
}

void DestroyBTree(BTNode *&b)
{
    if (b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b, TreeElementType x)
{
    BTNode *p;
    if (b != NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

int BTHeight(BTNode *b)
{
    int lchild, rchild;
    if (b == NULL)
        return (0);
    else
    {
        lchild = BTHeight(b->lchild);
        rchild = BTHeight(b->rchild);
        return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
    }
}

int main(int argc, char *argv[])
{
    char treeByBracket[] = "A(B(D(,G)),C(E,F)";
    BTNode *binaryTree = NULL;
    CreateBTree(binaryTree, treeByBracket);
    DispTree(binaryTree);
    cout << endl;
    return 0;
}