#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1005;
const int HASH = 1000000007;
int n , len[N];
char str[N];
int hash[N][505] , inv[N][505] , p[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    p[0] = 1;
    for (int i = 1 ; i < N ; i ++)
        p[i] = p[i - 1] * HASH;
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str);
            len[i] = strlen (str);
            hash[i][0] = inv[i][0] = 0;
            for (int j = 0 ; j < len[i] ; j ++) {
                hash[i][j + 1] = hash[i][j] * HASH + str[j];
                inv[i][j + 1] = inv[i][j] * HASH + str[len[i] - j - 1];
            }

        }
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                if (i == j) continue;
                int A = hash[i][len[i]] * p[len[j]] + hash[j][len[j]];
                int B = inv[j][len[j]] * p[len[i]] + inv[i][len[i]];
                if (A == B) ans ++;
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}