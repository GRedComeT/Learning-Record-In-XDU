#include<bits/stdc++.h>
using namespace std;

const int maxm = 1000;
int st[maxm];

bool bisearch1(int siz, int aim);
bool bisearch2(int left, int right, int aim);

int main() {
	ifstream in;
	in.open("datafile.dat", ios::in);
	int siz = 0, i, j, aim;
	while(!in.eof()) {
		in >> st[siz++];
	}
	in.close();
	printf("Please input the number which you want to search.\n");
	scanf("%d", &aim);
	bool flag = false;
	for (i = 0; i < siz; ++i) {
		if(st[i] == aim) {
			flag = true;
			break;
		}
	}
	if(flag)
		printf("Success to search!(%d in st[%d])\n", aim, i);
	else
		printf("Fail to search!\n");
	for (i = 1; i < siz; ++i) {
		int tmp = st[i];
		for (j = i; j >= 1 && st[j-1] >= tmp; --j) {
			st[j] = st[j-1];
		}
		st[j] = tmp;
	}
	bisearch1(siz, aim);
	bisearch2(0, siz-1, aim);
	return 0;
}

bool bisearch1(int siz, int aim) {
	int left = 0, right = siz - 1, mid;
	while(left < right) {
		mid = (left + right) >> 1;
		if(st[mid] < aim)
			left = mid + 1;
		else if(st[mid] > aim)
			right = mid - 1;
		else {
			printf("Yes\n");
			return true;
		}
	}
	return false;
}

bool bisearch2(int left, int right, int aim) {
	int mid = (left + right) >> 1;
	if(left > right)
		return false;
	if(st[mid] < aim)
		return bisearch2(mid + 1, right, aim);
	else if(st[mid] > aim)
		return bisearch2(left, mid - 1, aim);
	else {
		printf("yes\n");
		return true;
	}	
}
