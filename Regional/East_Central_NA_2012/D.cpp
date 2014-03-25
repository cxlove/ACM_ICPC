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
int dp[10][20];
void init () {
    dp[0][0] = 1;
    for (int i = 0 ; i < 6 ; i ++) {
        for (int j = 0 ; j <= 15 ; j ++) {
            for (int k = 0 ; k + j <= 15 ; k ++) {
                dp[i + 1][j + k] += dp[i][j];
            }
        }
    }
}
char ope[6];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif 
    int cas = 0;
    init ();
    while (scanf ("%s" , ope) != EOF && ope[0] != 'e') {
        printf ("Case %d:" , ++ cas);
        if (ope[0] == 'm') {
            int a[6];for (int i = 0 ; i < 6 ; i ++) scanf ("%d" , &a[i]);
            int remain = 15 , ans = 0;
            for (int i = 0 ; i < 6 ; i ++) {
                for (int j = 0 ; j < a[i] ; j ++) {
                    ans += dp[5 - i][remain - j];
                }
                remain -= a[i];
            }
            printf (" %d\n" , ans);
        }
        else {
            int k , remain = 15;scanf ("%d" , &k);k ++;
            for (int i = 0 ; i < 6 ; i ++) {
                for (int j = 0 ; j <= remain ; j ++) {
                    if (dp[5 - i][remain - j] >= k) {
                        printf (" %d" , j);
                        remain -= j;
                        break;
                    }
                    else k -= dp[5 - i][remain - j];
                }
            }
            printf ("\n");
        }
    }
    return 0;
}