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
const int N = 20;
LL dp[1 << N][N][2];
int n;
LL dfs (int u , int v , int k) {
    if (dp[u][v][k] != -1) return dp[u][v][k];
    LL &ret = dp[u][v][k];
    ret = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (i != v && (1 << i) & u) {
            if (k && i > v) {
                ret += dfs (u ^ (1 << v) , i , k ^ 1);
            }
            else if (!k && i < v) {
                ret += dfs (u ^ (1 << v) , i , k ^ 1);
            }
        }
    }
    return ret;
}
void bruteforce () {
    cout << "ans[20]={" ;
    for (int i = 1 ; i <= N ; i ++) {
        n = i;
        memset (dp , -1 , sizeof (dp));
        for (int j = 0 ; j < i ; j ++) {
            dp[1 << j][j][0] = dp[1 << j][j][1] = 1;
        }
        LL ans = 0;
        for (int j = 0 ; j < i ; j ++) {
            ans += dfs ((1 << i) - 1 , j , 0) + dfs ((1 << i) - 1 , j , 1);
        }
        cout << ans << ",";
    }
    cout << endl;
}
LL ans[20]={1,2,4,10,32,122,544,2770,15872,101042,707584,5405530,44736512,398721962,3807514624,38783024290,419730685952,4809759350882,58177770225664,740742376475050};

int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
    // bruteforce ();
    int t , id;
    cin >> t;
    while (t --) {
        cin >> id >> n;
        cout << id << " " << ans[n - 1] << endl;
    }
	return 0;
}