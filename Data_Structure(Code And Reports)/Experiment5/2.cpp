#include<bits/stdc++.h>
using namespace std;

typedef struct TNode* PtrToTree;
typedef PtrToTree Position;
typedef PtrToTree BiTree;

struct TNode {
	int val;
	Position Left, Right;
};

Position search(BiTree T, int aim) {
	if(T->val == aim)
		return T;
	else if(T->val < aim) {
		if(T->Right != nullptr)
			return search(T->Right, aim);
		else
			return nullptr;
	} else if(T->val > aim) {
		if(T->Left != nullptr)
			return search(T->Left, aim);
		else
			return nullptr;
	}
}

bool Insert(BiTree &T, int value) {
	if(T == nullptr) {
		T = (BiTree)malloc(sizeof(TNode));
		T->val = value;
		T->Left = T->Right = nullptr;
		return true;
	} else if(T->val < value)
		return Insert(T->Right, value);
	else if(T->val > value)
		return Insert(T->Left, value);
}

Position FindMin(BiTree T) {
	if(T->Left != nullptr)
		return FindMin(T->Left);
	return T;
}

Position Delete(BiTree T, int value) {
	if(T == nullptr)
		return nullptr;
	if(T->val < value)
		T->Right = Delete(T->Right, value);
	else if(T->val > value)
		T->Left = Delete(T->Left, value);
	else if(T->Left != nullptr && T->Right != nullptr) {
		Position t = FindMin(T->Right);
		T->val = t->val;
		T->Right = Delete(T->Right, T->val);
	} else {
		Position t = T;
		if(T->Left == nullptr)
			T = T->Right;
		else if(T->Right == nullptr)
			T = T->Left;
		free(t);
	}
	return T;
}

bool inorder(BiTree T) {
	if(T->Left)
		return inorder(T->Left);
	printf("%d ", T->val);
	if(T->Right)
		return inorder(T->Right);
	return true;
}

int main() {
	BiTree T = nullptr;
	for (int i = 1; i <= 5; ++i)
		Insert(T, i);
	Delete(T, 3);
	inorder(T);
	return 0;
}
