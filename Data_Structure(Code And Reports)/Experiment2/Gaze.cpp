#include<bits/stdc++.h>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxm = 15;

int G[maxm][maxm], vis[maxm][maxm], fa[maxm<<5];

struct Node{
    int x, y, dir;
    Node(int _x=-1, int _y=-1, int _dir=-1):x(_x), y(_y), dir(_dir){}
};

Node q[maxm<<5], s[maxm<<5];

int main() {
    int m, n;
    printf("Please input the row and the column:\n");
    scanf("%d%d", &m, &n);
    printf("Please input the gaze\n");
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &G[i][j]);
    int Sta, End;
    Sta = End = 0;
    printf("Please input the enter\n");
    int x1, y1, x2, y2;
    scanf("%d%d", &x1, &y1);
    printf("Please input the exit\n");
    scanf("%d%d", &x2, &y2);
    q[End++] = Node(x1, y1);
    bool flag = false;
    while(Sta < End) {
        Node p = q[Sta++];
        if(vis[p.x][p.y])
            continue;
        vis[p.x][p.y]= 1;
        if(p.x == x2 && p.y == y2) {
            printf("Yes\n");
            flag = true;
            End = Sta-1;
            break;
        }
        for(int i = 0; i < 4; ++i) {
            Node now = p;
            now.x += dx[i], now.y += dy[i], now.dir = i;
            if(now.x < m && now.y < n && now.x >= 0 && now.y >= 0 && !G[now.x][now.y]) {
                fa[End] = Sta-1;
                q[End++] = now;
            }
        }
    }
    if(!flag) {
        printf("No\n");
    } else {
        Sta = 0;

        while(End != 0) {
            s[Sta++] = q[End];
            End = fa[End];
        }
        for(int i = Sta-1; i >= 0; i--) {
            printf("%d %d %d\n", s[i].x, s[i].y, s[i].dir);
        }
    }
    return 0;
}
