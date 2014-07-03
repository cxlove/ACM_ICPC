#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , a[N];
int s[N][32];
bool check (int l , int r) {
    int limit = 1;
    for (int i = 30 ; i >= 0 ; i --) {
        int cnt = s[r][i] - s[l - 1][i];
        if (m & (1 << i)) {
            if (cnt == 0) limit = 0; 
        }
        else {
            if (limit && cnt) return false;
        }
    }
    if (limit) return false;
    return true;
}
int main () { 
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        memset (s , 0 , sizeof(s));
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
            for (int j = 0 ; j < 31 ; j ++) {
                s[i][j] = s[i - 1][j];
                if (a[i] & (1 << j)) {
                    s[i][j] ++;
                }
            }
        }
        LL ans = 0LL;
        for (int i = 1 , j = 1 ; i <= n ; i ++) {
            while (j <= i && !check(j , i)) j ++;
            ans += max (0LL , 0LL + i - j + 1);
        }
        printf ("Case #%d: %I64d\n" , ++cas , ans);
    }
    return 0;

}
