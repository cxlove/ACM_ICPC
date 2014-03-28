#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int N = 50;
int vis[N][N][N] , pre[N][N][N];
int X , Y , Z , a[3][3];
struct Node {
    int c[3];
    Node () {}
    Node (int _x , int _y , int _z){
        c[0] = _x;c[1] = _y;c[2] = _z;
    }
    bool change (int k) {
        if (k < 3) {
            if (c[k] <= 0) return false;
            c[k] --;
            for (int i = 0 ; i < 3 ; i ++) {
                c[i] += a[k][i];
            }
        }
        else {
            k -= 3;
            for (int i = 0 ; i < 3 ; i ++) {
                c[i] -= a[k][i];
                if (c[i] < 0) return false;
            }
            c[k] ++;
        }
        for (int i = 0 ; i < 3 ; i ++) {
            if (c[i] >= N) return false;
        }
        return true;
    }
};
char ans[2000];
void bfs (int x , int y , int z) {
    memset (vis , -1 , sizeof (vis));
    memset (pre , -1 , sizeof (pre));
    queue <Node> que;
    que.push (Node (x , y , z));
    vis[x][y][z] = 0;
    while (!que.empty ()) {
        Node u = que.front ();
        que.pop ();
        if (u.c[0] == X && u.c[1] == Y && u.c[2] == Z) {
            printf ("%d " , vis[X][Y][Z]);
            int l = vis[X][Y][Z];ans[l] = 0;
            while (pre[u.c[0]][u.c[1]][u.c[2]] != -1) {
                l --;
                int ope = pre[u.c[0]][u.c[1]][u.c[2]];
                if (ope < 3) ans[l] = 'A' + ope;
                else ans[l] = 'a' + ope - 3;
                u.change (ope < 3 ? ope + 3 : ope - 3);
            }
            puts (ans);
            return ;
        }
        for (int i = 0 ; i < 6 ; i ++) {
            Node v = u;
            if (!v.change (i)) continue;
            if (vis[v.c[0]][v.c[1]][v.c[2]] == -1) {
                vis[v.c[0]][v.c[1]][v.c[2]] =  vis[u.c[0]][u.c[1]][u.c[2]] + 1;
                que.push (v);
                pre[v.c[0]][v.c[1]][v.c[2]] = i;
            }
        }
    }
    puts ("NO SOLUTION");
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        int id , q;
        scanf ("%d %d" , &id , &q);
        printf ("%d %d\n" , id , q);
        for (int i = 0 ; i < 3 ; i ++) {
            for (int j = 0 ; j < 3 ; j ++) {
                scanf ("%d" , &a[i][j]);
            }
        }
        while (q --) {
            scanf ("%d" , &id);
            printf ("%d " , id);
            int x , y , z;
            scanf ("%d %d %d %d %d %d" , &x , &y , &z , &X , &Y , &Z);
            if (x == X && y == Y && z == Z) puts ("0");
            else bfs (x , y , z);
        }
    }
	return 0;
}