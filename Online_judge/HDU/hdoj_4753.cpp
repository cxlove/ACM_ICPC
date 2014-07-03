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
const int N = 100005;
const int S = 30;
const int inf = 0x11111111;
int n , flag[S] , a[S] , m;
int first , second , dp[1 << 12];
vector<int>b[S];
int id (int x , int y) {
    if (y == x + 1) {
        int k = (y - 1) / 4;
        return 7 * k + x % 4;
    }
    int k = (x - 1) / 4;
    return 7 * k + 4 + ((x - 1) % 4);
}
int check (int k) {
    int ret = 0;
    for (int i = 1 , j = 1 ; i <= 9 ; i ++) {
        int a = j , b = j + 3 , c = j + 4 , d = j + 7;
        if (flag[a] && flag[b] && flag[c] && flag[d]) {
            if (k == a || k == b || k == c || k == d) 
                ret ++;
        }
        if (i % 3 == 0) j += 5;
        else j ++;
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        memset (dp , 0x11 , sizeof(dp));
        memset (flag , 0 , sizeof(flag));
        scanf ("%d" , &n);
        first = 0 ; second = 0;
        for (int i = 0 ; i < n ; i ++) {
            int x , y;
            scanf ("%d %d" , &x , &y);
            if (x > y) swap (x , y);
            int k = id (x , y);
            flag[k] = 1;
            if (i % 2 == 0) {
                first += check (k);
            }
            else {
                second += check (k);
            }
        }
        m = 0;
        for (int i = 1 ; i <= 24 ; i ++) {
            if (flag[i] == 0) {
                a[m ++] = i;
            }
        }
        for (int i = 0 ; i <= m ; i ++)
            b[i].clear ();
        for (int i = 0 ; i < (1 << m) ; i ++) {
            int cnt = 0;
            for (int j = 0 ; j < m ; j ++) {
                if (i & (1 << j))
                    cnt ++;
            }
            b[cnt].push_back (i);
        }
        dp[(1 << m) - 1] = 0;
        for (int tt = m ; tt ; tt --) {
            for (int pp = 0 ; pp < b[tt].size() ; pp ++) {
                int i = b[tt][pp];
                for (int j = 0 ; j < m ; j ++) {
                    if (i & (1 << j)) {
                        flag[a[j]] = 1;
                    }
                }
                for (int j = 0 ; j < m ; j ++) {
                    if (!(i & (1 << j))) continue;
                    int k = check (a[j]);
                    int p = k + (-dp[i]);
                    if (dp[i - (1 << j)] == inf || dp[i - (1 << j)] < p)
                        dp[i - (1 << j)] = p;
                }
                for (int j = 0 ; j < m ; j ++) {
                    if (i & (1 << j))
                        flag[a[j]] = 0;
                }
            }
        }
        int ans = first - second;
        if (n & 1) ans -= dp[0];
        else ans += dp[0];
        // cout << ans << endl;
        printf ("Case #%d: %s\n" , ++cas , ans > 0 ? "Tom200" : "Jerry404");
    }
    return 0;
}       