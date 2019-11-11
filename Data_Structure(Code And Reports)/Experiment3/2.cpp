#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

bool isEqual(string t1, string t2, int len) {
	for (int i = 0; i < len; ++i)
		if(t1[i] != t2[i])
			return false;
	return true;
}

int tot[1024];

int main() {
	ifstream in;
	in.open("oo.txt", ios::in);
	stringstream ss;
	string a1;
	char str[150], sor[150];
	long long sum = 0;
	printf("Please input the searched word\n");
	scanf("%s", sor);
	int l1 = strlen(sor), lineNum = 0;
	while(!in.eof()) {
		in.getline(str, 120);
		++lineNum;
		ss.clear();
		ss.str(str);
		while(ss >> a1) {
			if(a1.size() == l1 && isEqual(a1, sor, l1)) {
				sum++;
				tot[lineNum]++;
			}
		}
	}
	printf("The '%s' appear tot %I64d times\n", sor, sum);
	for (int i = 1; i <= lineNum; ++i) {
		if(tot[i]) {
			printf("The %d line have appear the '%s' %d times\n", i, sor, tot[i]);
		}
	}
	in.close();
	return 0;
}
