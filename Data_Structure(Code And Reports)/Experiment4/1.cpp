#include<bits/stdc++.h>

typedef struct TNode *PtrToTNode;
typedef PtrToTNode Tree;

struct TNode {
    char value;
    Tree Left, Right;
};

void BuildBiTree(Tree &T) {
    char tmp;
    scanf("%c", &tmp);
    if(tmp == '\n')return;
    if(tmp == '.')
        T = NULL;
    else {
        T = (Tree)malloc(sizeof(TNode));
        if(T == NULL)
            return;
        T->value = tmp;
        BuildBiTree(T->Left);
        BuildBiTree(T->Right);
    }
}

void preorder(Tree T) {
    if(T == NULL)
        return;
    printf("%c ", T->value);
    preorder(T->Left);
    preorder(T->Right);
}

void inorder(Tree T) {
    if(T == NULL)
        return;
    inorder(T->Left);
    printf("%c ", T->value);
    inorder(T->Right);
}

void postorder(Tree T) {
    if(T == NULL)
        return;
    postorder(T->Left);
    postorder(T->Right);
    printf("%c ", T->value);
}

int main() {
    Tree T;
    BuildBiTree(T);
    preorder(T);
    printf("\n");
    inorder(T);
    printf("\n");
    postorder(T);
    printf("\n");
    return 0;
}
