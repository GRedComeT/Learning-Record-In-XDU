#include<bits/stdc++.h>

const int maxm = 10000;

int data[maxm], n;



int newNum() {
    return rand();
}

int Sort(int num) {
    int i, t = 0;

    for(i = 0; i < n; ++i) {
        if(data[i] <= num)
            continue;
        else {
            data[n++] = num;
            for(int j = i; j < n; ++j) {
                t = data[j];
                data[j] = data[n-1];
                data[n-1] = t;
            }
            break;
        }
    }
    if(i == n) data[n++] = num;
    return 0;
}

int main() {
    for(int kase = 0; kase <= 100; ++kase) {
        Sort(newNum());
    }
    for(int k = 0; k < n; ++k)
        printf("%d\n", data[k]);
    return 0;
}

