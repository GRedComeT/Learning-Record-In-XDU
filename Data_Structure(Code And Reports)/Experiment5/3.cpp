#include<bits/stdc++.h>
using namespace std;

struct Node {
	int isEmpty = 0;
	long long phoneNumber;
	string Name, address;
};

struct Node2 {
	long long phoneNumber;
	char *Name, *address;
	struct Node2 *Next;
};

struct NodeList {
	int siz;
	struct Node2 **HashTable2;
};

struct Node Hashtable1[100];
int Hash1(long long phoneNumber) {   //取后四位
	return ((phoneNumber % 10000) + 101) % 101;
}
int Hash2(string Name) {   // prime-29 名字在单词表出现顺序
	int sum = 0, len = Name.size();
	for (int i = 0; i < len; ++i)
		sum += (Name[i] - 'a');
	return (sum + 29) % 29;
}

Node Find1(long long phoneNumber) {
	int hash = Hash1(phoneNumber);
	while(Hashtable1[hash].isEmpty == 1) {
		if(Hashtable1[hash].phoneNumber == phoneNumber)
			return Hashtable1[hash];
		else
			hash++;
	}
}

bool isequal(char *s1, char *s2) {
	int l1 = strlen(s1), l2 = strlen(s2);
	if(l1 != l2)
		return false;
	for (int i = 0; i < l1; ++i)
		if(s1[i] != s2[i])
			return false;
	return true;
}

Node2* Find2(NodeList* HT, char *Name) {
	int hash = Hash2(Name);
	Node2 *L = HT->HashTable2[hash];
	L = L->Next;
	while(L != nullptr) {
		if(isequal(L->Name, Name))
			return L;
		L = L->Next;
	}
	return nullptr;
}

int main() {
	long long phoneNumber;
	char Name[50], address[60];
	ifstream in;
	in.open("data.txt", ios::in);
	NodeList *HT2 = (NodeList*)malloc(sizeof(NodeList));
	HT2->siz = 29;
	HT2->HashTable2 = (Node2 **)malloc(sizeof(Node2*)*HT2->siz);
	for(int i = 0; i < HT2->siz; ++i) {
		HT2->HashTable2[i] = (Node2 *)malloc(sizeof(struct Node2));
		HT2->HashTable2[i]->Next = nullptr;
	}
	while(!in.eof()) {
		in >> phoneNumber >> Name >> address;
		// using phoneNumber be the key
		int hashNumber1 = Hash1(phoneNumber);
		while(Hashtable1[hashNumber1].isEmpty != 0)
			hashNumber1++;
		Hashtable1[hashNumber1].isEmpty = 1;
		Hashtable1[hashNumber1].phoneNumber = phoneNumber;
		Hashtable1[hashNumber1].Name = Name;
		Hashtable1[hashNumber1].address = address;
		// using Name be the key
		int hashNumber2 = Hash2(Name);
		Node2 *h = HT2->HashTable2[hashNumber2];
		Node2 *t = (Node2 *)malloc(sizeof(Node2));
		t->phoneNumber = phoneNumber;
		int l1 = strlen(Name);
		t->Name = (char*)malloc(sizeof(char)*(l1+2));
		for(int i = 0; i < l1; ++i)
			t->Name[i] = Name[i];
		t->Name[l1] = '\0';
		l1 = strlen(address);
		t->address = (char*)malloc(sizeof(char)*(l1+2));
		for(int i = 0; i < l1; ++i)
			t->address[i] = address[i];
		t->address[l1] = '\0';
		t->Next = h->Next;
		h->Next = t;
	}
	in.close();
	printf("Please input the phoneNumber you will search.\n");
	scanf("%lld", &phoneNumber);
	Node j = Find1(phoneNumber);
	cout << j.Name << endl;
	printf("Please input the Name you will search.\n");
	scanf("%s", Name);
	Node2 *k = Find2(HT2, Name);
	return 0;
}
