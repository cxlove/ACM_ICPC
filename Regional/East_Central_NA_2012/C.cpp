#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int N = 7;
struct Node {
    int a[6];
    void init () {
        for (int i = 0 ; i < 6 ; i ++) {
            scanf ("%d" , &a[i]);
            a[i] --;
        }
    }
    void rotate () {
        int t = a[0];
        for (int i = 1 ; i < 6 ; i ++)
            a[i - 1] = a[i];
        a[5] = t;
    }
    void rotate (int p) {
        while (a[0] != p) rotate ();
    }
}a[N];
int ans , use[N];
int id[N];
void dfs (int idx) {
    if (ans) return ;
    if (idx == 7) {
        if (a[id[6]].a[5] != a[id[1]].a[1])
            return ;
        ans = 1;
        for (int i = 0 ; i < 7 ; i ++)
            printf (" %d" , id[i]);
        puts ("");
        return ;
    }
    for (int i = 0 ; i < 7 ; i ++) {
        if (use[i] == 0) {
            id[idx] = i;
            if (idx == 0) {
                a[i].rotate (0);
            }
            else {
                a[i].rotate (a[id[0]].a[idx - 1]);
            }
            if (idx > 1) {
                if (a[id[idx - 1]].a[5] != a[id[idx]].a[1]) {
                    continue;
                }
            }
            use[i] = 1;
            dfs (idx + 1);
            use[i] = 0;
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif 
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        ans = 0;
        for (int i = 0 ; i < 7 ; i ++)
            a[i].init ();
        memset (use , 0 , sizeof (use));
        printf ("Case %d:" , ++ cas);
        dfs (0);
        if (!ans) puts (" No solution");
    }
    return 0;
}