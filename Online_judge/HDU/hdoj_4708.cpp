#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 20;
int n , a[N][N];
vector<int> v[20];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++)
            v[i].clear ();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                scanf ("%d" , &a[i][j]);
            }
        }
        for (int i = 0 ; i < n / 2 ; i ++) {
            for (int j = i ; j < n - i ; j ++)
                v[i].push_back (a[i][j]);
            for (int j = i + 1 ; j < n - i ; j ++)
                v[i].push_back (a[j][n - i - 1]);
            for (int j = n - i - 2 ; j >= i ; j --)
                v[i].push_back (a[n - i - 1][j]);
            for (int j = n - i - 2 ; j > i ; j --)        
                v[i].push_back (a[j][i]);
        }
        int ans = 0 , cnt = 0;
        if (n & 1) ans = a[n / 2][n / 2];
        for (int i = 0 ; i < n / 2 ; i ++) {
            int c = 0 , d = 0 , m = n - 2 * i - 1;
            for (int j = 0 ; j < v[i].size() ; j ++) {
                int tmp = v[i][j] + v[i][(j + m) % (int)v[i].size()] + v[i][(j + 2 * m) % (int)v[i].size()] + v[i][(j + 3 * m) % (int)v[i].size()];
                if (tmp > c) {
                    c = tmp;
                    d = min (j , (int)v[i].size() - j);
                }
                else if (tmp == c && min (j , (int)v[i].size() - j) < d) {

                    c = tmp;
                    d = min (j , (int)v[i].size() - j);
                }
            }
            ans += c;
            cnt += d;
        }
        printf ("%d %d\n" , ans , cnt);
    }
    return 0;
}