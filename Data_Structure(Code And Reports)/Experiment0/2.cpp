#include<bits/stdc++.h>
using namespace std;

int a[20];

int fun(int m, int k, int t) {
    a[1] = (m + k - t) % (m-t+1);
    for (int i = 2; i <= t; ++i)
        a[i] = (a[i - 1] + k) % (m - t + i);
    return a[t];
}


int main() {
    printf("Please input m and n:");
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        printf("%d\n", fun(m, n, i));
    return 0;
}
