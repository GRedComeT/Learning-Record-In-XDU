#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
struct Node {
    ElementType value;
    Position next;
};

List init() {
    List head = (Node*)malloc(sizeof(Node));
    head->next = nullptr;
    head->value = 0;
    return head;
}

Position Find(List L, ElementType value) {
    Position P;
    P = L->next;
    while(P != nullptr && P->value != value) {
        P = P->next;
    }
    return P;
}

Position FindPre(List L, ElementType value) {
    Position P;
    P = L->next;
    while(P->next != nullptr && P->next->value != value) {
        P = P->next;
    }
    return P;
}

void Insert(ElementType value, List L, Position p) {
    Position tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    Position tmp2 = p->next;
    p->next = tmp;
    tmp->next = tmp2;
}

void Delete(Position p, Position pre) {
    if(p == nullptr)
        return;
    Position tmp = p;
    pre->next = p->next;
    p->next = nullptr;
    free(tmp);
}

void Print(List L) {
    if(L->next == nullptr) {
        printf(" empty list!\n");
        return;
    }
    Position P = L->next;
    while(P != nullptr) {
        printf(" %d", P->value);
        P = P->next;
    }
}

int main() {
    List Head = init();
    int n = 0;
    while(true) {
        int tmp;
        scanf("%d", &tmp);
        if(!tmp)
            break;
        Insert(tmp, Head, Head);
        n++;
    }
    for (int i = 1; i <= n+1; ++i) {
        printf("The %d times output:", i);
        Print(Head);
        Delete(Head->next, Head);
        printf("\n");
    }
    
    return 0;
}
