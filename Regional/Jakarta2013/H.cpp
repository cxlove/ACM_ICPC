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
const int N = 1305;
const int HASH = 1000000007;
int n , m;
double minP[N][N] , maxP[N][N];
double c[N] , w[N];
double correct[N] , wrong[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lf" , &c[i]);
            c[i] /= 100.0;
        }
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lf" , &w[i]);
            w[i] /= 100.0;
        }
        for (int i = 1 ; i <= n ; i ++) {
            // the answer you give is correct
            correct[i] = c[i] - w[i] + (1.0 - c[i] - w[i]);
            // ..... incorrect
            wrong[i] = c[i] - w[i] - (1.0 - c[i] - w[i]);
        }
        for (int i = 0 ; i <= m ; i ++)
            minP[0][i] = maxP[0][i] = 15000;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 0 ; j <= min (i , m) ; j ++) {
                minP[i][j] = min (minP[i - 1][j] * correct[i] , maxP[i - 1][j] * correct[i]);
                maxP[i][j] = max (minP[i - 1][j] * correct[i] , maxP[i - 1][j] * correct[i]);
                if (j) {
                    minP[i][j] = min (minP[i][j] , min (minP[i - 1][j - 1] * wrong[i] , maxP[i - 1][j - 1] * wrong[i]));
                    maxP[i][j] = max (maxP[i][j] , max (minP[i - 1][j - 1] * wrong[i] , maxP[i - 1][j - 1] * wrong[i]));
                }
            }
        }
        double ans = 15000;
        for (int i = 0 ; i <= m ; i ++)
            ans = min (ans , minP[n][i]);
        printf ("Case #%d: %.3f\n" , ++cas , ans);
    }
    return 0;
}