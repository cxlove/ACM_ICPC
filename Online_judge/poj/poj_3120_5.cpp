#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>  
#include <ctime>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int , int> pii;
const int N = 100005;
const int MOD = 1000000007;
int p[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
char str[10][10];
int a[9];
int goal[9][9] , b[9][9] , c[9][9];
int f[10] , d[10] , e[10];
bool check (int l , int r) {
    memset (f , 0 , sizeof (f));
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = l ; j < r ; j ++) {
            int ii = p[a[1]][d[i]] * 3 , jj = p[a[2]][d[j]] * 3;
            ii += p[a[3 + d[i]]][e[i]]; 
            jj += p[a[6 + d[j]]][e[j]];
            if (b[ii][jj]) {
                if (f[b[ii][jj]]) {
                    if (f[b[ii][jj]] != goal[i][j])
                        return false;
                }
                else {
                    f[b[ii][jj]] = goal[i][j];
                }
            }
        }
    }
    return true;
}
int main () {
    #ifndef ONLINE_JUDGE
        // freopen ("input.txt" , "r" , stdin);
    #endif
    int t;scanf ("%d" , &t);
    for (int i = 0 ; i < 10 ; i ++)
        d[i] = i / 3 , e[i] = i % 3;
    while (t --) {
        for (int i = 0 ; i < 9 ; ++ i) {
            scanf ("%s" , str[i]);
            for (int j = 0 ; j < 9 ; ++ j)
                goal[i][j] = str[i][j] - '0';
        }
        for (int i = 0 ; i < 9 ; ++ i) {
            scanf ("%s" , str[i]);
            for (int j = 0 ; j < 9 ; ++ j) 
                c[i][j] = str[i][j] - '0';
        }
        bool ok = false;
        for (int rot = 0 ; rot < 2 ; ++ rot) {
            for (int j = 0 , r = 0 ; j < 9 ; ++ j , ++ r) {
                for (int i = 8 , k = 0 ; i >= 0 ; -- i , ++ k) {
                    b[r][k] = c[i][j];
                }
            }
            memcpy (c , b , sizeof (b));
            for (a[1] = 0 ; a[1] < 6 ; ++ a[1]) {
                for (a[2] = 0 ; a[2] < 6 ; ++ a[2]) {
                    for (a[3] = 0 ; a[3] < 6 ; ++ a[3]) { 
                        for (a[4] = 0 ; a[4] < 6 ; ++ a[4]) { 
                            for (a[5] = 0 ; a[5] < 6 ; ++ a[5]) { 
                                for (a[6] = 0 ; a[6] < 6 ; ++ a[6]) { 
                                    if (check (0 , 3))
                                    for (a[7] = 0 ; a[7] < 6 ; ++ a[7]) {
                                        if (check (3 , 6)) 
                                        for (a[8] = 0 ; a[8] < 6 ; ++ a[8]) {
                                            if (check (0 , 9)) {
                                                ok = true;goto end;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        end:
        puts (ok ? "Yes" : "No");
    }
    return 0;
}