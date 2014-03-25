#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 1005;
const int MOD = 1000000007;
vector <int> a[26];
int dp[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    string s;cin >> s;
    for (int i = 0 ; i < s.size() ; i ++) {
        a[s[i] - 'A'].push_back (i);
    }
    int ans = 0;
    for (int i = 0 ; i < 26 ; i ++) {
        int ret = 1;
        dp[0] = 1;
        for (int j = 1 ; j < a[i].size() ; j ++) {
            dp[j] = 1;
            for (int k = 0 ; k < j ; k ++) {
                if ((a[i][j] - a[i][k] - 1) % 2 == 0)
                    dp[j] = max (dp[j] , dp[k] + 1);
            }
            ret = max (ret , dp[j]);
        }
        ans = max (ans , ret);
    }
    cout << ans << endl;
    return 0;
}