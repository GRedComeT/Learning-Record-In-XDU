#include<bits/stdc++.h>
using namespace std;

typedef struct TNode *PtrToTNode;
typedef PtrToTNode Tree;

struct TNode {
    double power;
    char value;
    Tree Left, Right;
    TNode(double _power=0.0, char _value='\0', Tree _Left=nullptr, Tree _Right=nullptr):power(_power), value(_value), Left(_Left), Right(_Right) {}
};

struct cmp {
	bool operator() (Tree a, Tree b) {
		return a->power > b->power;
	}
};

priority_queue<Tree, vector<Tree>, cmp> q;
map<char, string> hfcode;

int res[100];

void preorder(Tree T, ofstream& p) {
	if(T != nullptr) {
		p << T->power << ' ' << T->value << '\n';
		preorder(T->Left, p);
		preorder(T->Right, p);
	}
}

void inorder(Tree T, ofstream& i) {
	if(T != nullptr) {
		inorder(T->Left, i);
		i << T->power << ' ' << T->value << '\n';
		inorder(T->Right, i);
	}
}

void encode(Tree T, int num, int i) {
	if(T->Left == nullptr && T->Right == nullptr) {
		res[i] = num;
		char *tmp = (char*)malloc(sizeof(char) * (i + 4));
		for (int k = 0; k <= i; ++k)
			tmp[k] = res[k] + '0';
		tmp[i + 1] = '\0';
		hfcode[T->value] = tmp;
	} else {
		if(num > -1)
			res[i] = num;
		encode(T->Left, 0, i+1);
		encode(T->Right, 1, i+1);
	}
}

char decode(Tree T, int& i, string str) {
	if(T->Left == nullptr && T->Right == nullptr) {
		return T->value;
	} else {
		if(str[i++] == '0') 
			return decode(T->Left, i, str);
		else
			return decode(T->Right, i, str);
	}
}

int main() {
    int n;
    char val;
    double po;
    printf("Please input the sum of letter\n");
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; ++i) {
        printf("Please input the letter\n");
        scanf("%c", &val);
        getchar();
        printf("Please input its power\n");
        scanf("%lf", &po);
        getchar();
		Tree k = new TNode();
		k->value = val, k->power = po;
		q.push(k);
    }
    while(q.size() != 1) {
        Tree t1, t2;
        t1 = q.top(), q.pop();
        t2 = q.top(), q.pop();
        Tree t3 = new TNode(t1->power+t2->power, '0', t1, t2);
        q.push(t3);
    }
	encode(q.top(), -1, -1);
	// using tree's preorder and inorder to store the tree
	ofstream pre, inor;
	pre.open("preorder.dat", ios::out), inor.open("inorder.dat", ios::out);
	preorder(q.top(), pre);
	pre.close();
	inorder(q.top(), inor);
	inor.close();
	ifstream in, in2;
	ofstream out1, out2;
	in.open("ToBeTran.dat", ios::in), out1.open("CodeFile.dat", ios::out), out2.open("TextFile.dat", ios::out);
	char tmp1;
	while(in.get(tmp1) && !in.eof()) {
		if(tmp1 == '\n')
			out1 << tmp1;
		else
			out1 << hfcode[tmp1];
	}
	in.close(), out1.close();
	in2.open("CodeFile.dat", ios::in);
	char tmp[1024];
	while(!in2.eof()) {
		in2.getline(tmp, 1024);
		int i = 0, len = strlen(tmp);
		while(i < len) {
			out2 << decode(q.top(), i, tmp);
		}
		out2 << '\n';
	}
	in2.close(), out2.close();
	return 0;
}
