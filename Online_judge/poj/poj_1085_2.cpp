#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>  
#include <ctime>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 18;
const int inf = 10000007;
int dp[1 << N];
int mat[11][11] = {  
{0,0,0,0,0,0,0,0,0,0,0},    
{0,0,0,1,0,0,0,0,0,0,0},    
{0,0,0,2,3,4,0,0,0,0,0},    
{0,1,2,0,0,5,6,0,0,0,0},    
{0,0,3,0,0,7,0,9,10,0,0},    
{0,0,4,5,7,0,8,0,11,12,0},    
{0,0,0,6,0,8,0,0,0,13,14},    
{0,0,0,0,9,0,0,0,15,0,0},    
{0,0,0,0,10,11,0,15,0,16,0},    
{0,0,0,0,0,12,13,0,16,0,17},    
{0,0,0,0,0,0,14,0,0,17,0}    
};    
int tri[9] = {7,152,52,352,34304,3200,71680,12544,155648};
int gao (int old , int seg) {
    int cnt = 0 , now = old | seg;
    for (int i = 0 ; i < 9 ; i ++) {
        if ((tri[i] & old) != tri[i] && (tri[i] & now) == tri[i])
            cnt ++;
    }
    return cnt;
}     
int dfs (int now) {
    if (dp[now] != -inf) return dp[now];
    int &ret = dp[now];
    for (int i = 0 ; i < 18 ; i ++) {
        if (now & (1 << i)) continue;
        int extra = gao (now , 1 << i);
        if (extra) extra += dfs (now | (1 << i));
        else extra -= dfs (now | (1 << i));
        ret = max (ret , extra);
    }
    return dp[now];
}
int main () {
    #ifndef ONLINE_JUDGE
        // freopen ("input.txt" , "r" , stdin);
    #endif
    for (int i = 0 ; i < 1  << N ; i ++) {
        dp[i] = -inf;
    }
    dp[(1 << N) - 1] = 0;
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int now = 0 , witch = 1 , score = 0 , n;
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            int seg = mat[u][v];
            int extra = gao (now , 1 << seg);
            score += witch * extra;
            now |= 1 << seg;
            if (extra == 0) witch *= -1; 
        }
        score += witch * dfs (now);
        printf ("Game %d: %s wins.\n" , ++cas , score > 0 ? "A" : "B");
    }
    return 0;
}