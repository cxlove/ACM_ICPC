#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define Key_value ch[ch[root][1]][0] 
#define pii pair<pair<int,int>,int>
using namespace std;
typedef long long LL;
const int N = 1000005;
char str[N];
int next[N] , vis[N];
void get_next (char *s , int l) {
    int i = 0 , j = -1;
    next[0] = -1;
    while (i < l) {
        if (j == -1 || s[i] == s[j]) {
            i ++; j ++;
            next[i] = j;
        }
        else j = next[j];
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        memset (vis , 0 , sizeof(vis));
        scanf ("%s" , str);
        int l = strlen(str);
        get_next (str , l);
        int p = next[l];
        while (p != -1) {
            vis[p] = 1;
            p = next[p];
        }
        int ans = 0;
        for (int i = 1 ; i < l ; i ++) {
            if (next[i] * 2 <= i && i + next[i] <= l && vis[next[i]]) {
                ans = max (ans , next[i]);
            }
        }
        printf ("%d\n" , ans);
    }
    return 0;
}       