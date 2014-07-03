#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 10105;
int prime[N] , flag[N] , cnt = 0;
int path[155][N];
double dp[155][N];
vector<int>v , ret;
void Init () {
    for (int i = 2 ; i < N ; i ++) {
        if (flag[i]) continue;
        prime[cnt ++] = i;
        for (int j = 2 ; j * i < N ; j ++) {
            flag[i * j] = 1;
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d" , &t);
    Init ();
    while (t --) {
        v.clear ();
        ret.clear ();
        int n , m = 70;
        scanf ("%d" , &n);
        // while(prime[m + 1] <= n) m ++;
        for (int i = 0 ; i <= m ; i ++)
            for (int j = 0 ; j <= n ; j ++)
                dp[i][j] = 0.0;
        dp[0][0] = 0;
        for (int i = 0 ; i < m ; i ++) {
            for (int j = 0 ; j <= n ; j ++) {
                if (dp[i][j] > dp[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j];
                    path[i + 1][j] = j;
                }
                for (int k = 1 , t = prime[i]; t + j <= n ; k ++ , t = t * prime[i]) {
                    if (dp[i + 1][j + t] < dp[i][j] + k * log (prime[i])) {
                        dp[i + 1][j + t] = dp[i][j] + k * log (prime[i]);
                        path[i + 1][j + t] = j;
                    }
                }
            }
        }
        for (int i = m , t = n ; i > 0 ; i --) {
            int p = path[i][t];
            if (p == t) continue;
            int cnt = t - p , k = 0;
            // while (cnt % prime[i - 1] == 0) k ++ , cnt /= prime[i - 1];
            v.push_back (cnt);
            t = p;
            if (i == 1) {
                for (int j = 0 ; j < t ; j ++)
                    v.push_back (1);
            }
        }
        sort (v.begin () , v.end ());
        int p = 1;
        for (int i = 0 ; i < v.size() ; i ++) {
            int l = p , r = p + v[i] - 1;
            for (int j = l + 1 ; j <= r ; j ++)
                ret.push_back (j);
            ret.push_back (l);
            p = r + 1;
        }
        for (int i = 0 ; i < ret.size() ; i ++)
            printf ("%d%c" , ret[i] , i == n - 1 ? '\n' : ' ');
    }
    return 0;
}