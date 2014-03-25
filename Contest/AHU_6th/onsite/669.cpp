#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;
const int N = 505;
int n , dp[N];
char str[N];
 
int main () {
#ifndef ONLINE_JUDGE 
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%s" , str + 1);
        n = strlen (str + 1);
        memset (dp , 0 , sizeof (dp));
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            int cnt = 0;
            for (int j = i ; j >= 1 ; j --) {
                if (str[i] == str[j]) {
                    cnt ++;
                }
                dp[i] = max (dp[i] , dp[j - 1] + cnt * cnt);
            }
            ans = max (ans , dp[i]);
        }
        printf ("%d\n" , ans);
    }
    return 0;
}