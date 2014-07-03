#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define mem(a,b) memset(a , b , sizeof(a))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int N = 17;
struct Edge {
    int v , w , next;
}e[N << 5];
int one[1 << N] , two[1 << N] , dp[1 << N][N];
int n , m , tot , start[N] , k , des;
bool in[1 << N][N];
void _add (int u , int v , int w) {
    e[tot].v = v;e[tot].w = w;
    e[tot].next = start[u];
    start[u] = tot ++;
}
void add (int u , int v , int w) {
    _add (u , v , w);
    _add (v , u , w);
}
void spfa () {
    queue<pair<int,int> > que;
    mem (dp , 0x11);
    dp[1][0] = 0;
    que.push(mp(1 , 0));
    in[1][0] = true;
    while (!que.empty()) {
        pair<int , int> u = que.front();
        que.pop();
        in[u.first][u.second] = false;
        for (int i = start[u.second] ; i != -1 ; i = e[i].next) {
            int v = e[i].v , w = e[i].w;
            if (dp[u.first][u.second] + w < dp[u.first | (1 << v)][v]) {
                dp[u.first | (1 << v)][v] = dp[u.first][u.second] + w;
                if (!in[u.first | (1 << v)][v]) {
                    in[u.first | (1 << v)][v] = true;
                    que.push(mp(u.first | (1 << v) , v));
                }
            }
        }
    }
    for (int i = 0 ; i < (1 << n) ; i ++) {
        one[i] = 0x11111111;
        for (int j = 0 ; j < n ; j ++)
            one[i] = min (one[i] , dp[i][j]);
    }
    return ;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = 0 ;
        mem (start , -1);
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < m ; i ++) {
            int u , v , w;
            scanf ("%d %d %d" , &u , &v , &w);
            u -- ; v --;
            add (u , v , w);
        }
        des = 0;
        scanf ("%d" , &k);
        for (int i = 0 ; i < k ; i ++) {
            int u ;
            scanf ("%d" , &u);
            u --;
            des |= (1 << u);
        }
        spfa ();
        for (int i = 0 ; i < (1 << n) ; i ++) {
            if (i % 2 == 0) continue;
            two[i] = one[i];
            for (int sub = i ; sub > 0 ; sub = (sub - 1) & i) {
                int other = (i - sub) | 1;
                two[i] = min (two[i] , max(one[sub] , one[other]));
            }
        }
        int ans = 0x11111111;
        for (int i = 0 ; i < (1 << n) ; i ++) {
            if (i % 2 == 0 | (i & des) != des) continue;
            for (int sub = i ; sub > 0 ; sub = (sub - 1) & i) {
                int other = (i - sub) | 1;
                ans = min (ans , max(one[sub] , two[other]));
            }
        }
        if (ans == 0x11111111) ans = -1;
        printf ("Case %d: %d\n" , ++cas , ans);
    }    
    return 0;
}