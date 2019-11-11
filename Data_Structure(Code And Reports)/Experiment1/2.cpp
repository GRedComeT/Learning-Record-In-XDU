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
        printf("empty list!\n");
        return;
    }
    Position P = L->next;
    while(P != nullptr) {
        printf("%d ", P->value);
        P = P->next;
    }
    printf("\n");
}

Position ListMerge(Position Left, Position Right) {
    Position out;
    if(Left->value < Right->value) {
        out = Left;
        Left = Left->next;
    } else {
        out = Right;
        Right = Right->next;
    }
    Position P = out;
    P->next = nullptr;
    while(Left&&Right) {
        if(Left->value < Right->value) {
            P->next = Left;
            Left = Left->next;
            P = P->next;
            P->next = nullptr;
        } else {
            P->next = Right;
            Right = Right->next;
            P = P->next;
            P->next = nullptr;
        }
    }
    if(Left != nullptr)
        P->next = Left;
    if(Right != nullptr)
        P->next = Right;
    return out;
}

Position sortList(Position head) {
    if(head == nullptr)
        return nullptr;
    if(head->next == nullptr)
        return head;
    Position slow = head;
    Position fast = head->next;
    while(fast != nullptr) {
        fast = fast->next;
        if(fast == nullptr)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    Position L1 = head, L2 = slow->next;
    slow->next = nullptr;
    Position Left = sortList(L1), Right = sortList(L2);
    Position out = ListMerge(Left, Right);
    return out;
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
    Print(Head);
    Head->next = sortList(Head->next);
    Print(Head);
    return 0;
}
