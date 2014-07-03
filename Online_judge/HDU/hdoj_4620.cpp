#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node {
    int c , t , id;
    int a[15];
    bool operator < (const Node &n) const {
        return t < n.t;
    }
}p[35];
int n , m , w;
int ans , ret[35] , vis[205] , c[35];
void dfs (int idx , int now , int t) {
    if (now + n - idx < ans) return ;
    if (now > ans) {
        ans = now;
        for (int i = 0 ; i < ans ; i ++)
            ret[i] = c[i];
    }
    if (idx == n) return ;
    for (int i = idx ; i < n ; i ++) {
        if (t && t + w < p[i].t) break;
        int cnt = 0 , b[35];
        for (int j = 0 ; j < p[i].c ; j ++) {
            if (vis[p[i].a[j]] == 0)
                b[cnt ++] = p[i].a[j];
        }
        if (cnt < 3) continue;
        c[now] = p[i].id;
        for (int j = 0 ; j < cnt ; j ++)
            vis[b[j]] = 1;
        dfs (i + 1 , now + 1 , p[i].t);
        for (int j = 0 ; j < cnt ; j ++)
            vis[b[j]] = 0;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t; 
    scanf ("%d" , &t);
    while (t --) {
        memset (vis , 0 , sizeof(vis)); 
        scanf ("%d %d %d" , &n , &m , &w);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d %d" , &p[i].c , &p[i].t);
            for (int j = 0 ; j < p[i].c ; j ++) {
                scanf ("%d" , &p[i].a[j]);
            }
            p[i].id = i + 1;
        }
        sort (p , p  + n);
        ans = 0;
        dfs (0 , 0 , 0);
        printf ("%d\n" , ans);
        sort (ret , ret + ans);
        for (int i = 0 ; i < ans ; i ++) {
            printf ("%d%c" , ret[i] , i == ans - 1 ? '\n' : ' ');
        }
    }
    return 0;
}