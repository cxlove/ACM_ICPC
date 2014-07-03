#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
const int N = 21;
const int inf = 100000005;
int g , b , s;
int a[N][N] , col[1 << N][N] , dp[1 << N] , get[1 << N][N];
int dfs (int state , int id) {
    if (dp[state] != -1) return dp[state];
    if (state == (1 << b) - 1) return 0;
    int ret = -inf;
    for (int i = 0 ; i < b ; i ++) {
        if (state & (1 << i)) continue;
        int get = 0;
        for (int j = 0 ; j < g ; j ++) {
            int t = col[state | (1 << i)][j] - col[state][j] + (col[state][j] % s);
            get += t / s;
        }
        int _id = get ? id : !id , v = dfs (state | (1 << i) , _id);
        if (get) ret = max (ret , v + get);
        else ret = max (ret , -v + get);
    }
    return dp[state] = ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d %d" , &g , &b , &s) != EOF && g + b + s) {
        for (int i = 0 ; i < b ; i ++) {
            scanf ("%d" , &a[i][0]);
            for (int j = 1 ; j <= a[i][0] ; j ++) {
                scanf ("%d" , &a[i][j]);
                a[i][j] --;
            }
        }
        for (int i = 0 ; i < g ; i ++)
            col[0][i] = 0;
        for (int i = 1 ; i < 1 << b ; i ++) {
            for (int j = 0 ; j < b ; j ++) {
                if (i & (1 << j)) {
                    for (int k = 0 ; k < g ; k ++)
                        col[i][k] = col[i ^ (1 << j)][k];
                    for (int k = 1 ; k <= a[j][0] ; k ++)
                        col[i][a[j][k]] ++;
                    break;
                    // get[i ^ (1 << j)][j] = 0;
                    // for (int k = 0 ; k < g ; k ++) {
                    //     int t = (col[i][k] - col[i ^ (1 << j)][k]) + (col[i ^ (1 << j)][k] % s);
                    //     get[i ^ (1 << j)][j] += t / s;
                    // }
                }
            }
        }
        memset (dp , -1 , sizeof(dp));
        printf ("%d\n" , dfs (0 , 0));
    }
    return 0;
}