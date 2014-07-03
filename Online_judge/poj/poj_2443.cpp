#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#define error {puts("-1");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 1000;
const int M = 100005;
int v[32][M];
int main () {
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    int n , q;
    while (scanf ("%d" , &n) != EOF) {
        memset (v , 0 , sizeof(v));
        for (int i = 0 ; i < n ; i ++) {
            int c;
            scanf ("%d" , &c);
            while (c --) {
                int k;scanf ("%d" , &k);
                v[i / 32][k] |= 1 << (i % 32);
            }
        }
        scanf ("%d" , &q);
        while (q --) {
            int i , j , f = 0;
            scanf ("%d %d" , &i , &j);
            for (int k = 0 ; k < 32 ; k ++) {
                if (v[k][i] & v[k][j]) {
                    f = 1;
                    break;
                }
            }
            if (f) puts ("Yes");
            else puts ("No");
        }
    }
    return 0;
}