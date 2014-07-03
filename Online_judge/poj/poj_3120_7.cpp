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
int a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8;
int a[9][9] , b[9][9] , c[9][9];
int f[10] , d[10] , e[10];
bool check (int l , int r) {
    memset (f , 0 , sizeof (f));
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = l ; j < r ; j ++) {
            int ii = p[a1][d[i]] * 3 , jj = p[a2][d[j]] * 3;
            if (d[i] == 0) ii += p[a3][e[i]]; 
            else if (d[i] == 1) ii += p[a4][e[i]];
            else ii += p[a5][e[i]];
            if (d[j] == 0) jj += p[a6][e[j]];
            else if (d[j] == 1) jj += p[a7][e[j]];
            else jj += p[a8][e[j]];
            if (b[ii][jj]) {
                if (f[b[ii][jj]]) {
                    if (f[b[ii][jj]] != a[i][j])
                        goto no;
                }
                else {
                    f[b[ii][jj]] = a[i][j];
                }
            }
        }
    }
    return true;
    no: ;
    memset (f , 0 , sizeof (f));
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = l ; j < r ; j ++) {
            int ii = p[a1][d[i]] * 3 , jj = p[a2][d[j]] * 3;
            if (d[i] == 0) ii += p[a3][e[i]]; 
            else if (d[i] == 1) ii += p[a4][e[i]];
            else ii += p[a5][e[i]];
            if (d[j] == 0) jj += p[a6][e[j]];
            else if (d[j] == 1) jj += p[a7][e[j]];
            else jj += p[a8][e[j]];
            if (c[ii][jj]) {
                if (f[c[ii][jj]]) {
                    if (f[c[ii][jj]] != a[i][j])
                        return false;
                }
                else {
                    f[c[ii][jj]] = a[i][j];
                }
            }
        }
    }
    return true;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;scanf ("%d" , &t);
    for (int i = 0 ; i < 10 ; i ++)
        d[i] = i / 3 , e[i] = i % 3;
    while (t --) {
        for (int i = 0 ; i < 9 ; i ++) {
            scanf ("%s" , str[i]);
            for (int j = 0 ; j < 9 ; j ++)
                a[i][j] = str[i][j] - '0';
        }
        for (int i = 0 ; i < 9 ; i ++) {
            scanf ("%s" , str[i]);
            for (int j = 0 ; j < 9 ; j ++) 
                c[i][j] = str[i][j] - '0';
        }
        for (int j = 0 , r = 0 ; j < 9 ; j ++ , r ++) {
            for (int i = 8 , k = 0 ; i >= 0 ; i -- , k ++) {
                b[r][k] = c[i][j];
            }
        }
        bool ok = false;
        for (a1 = 0 ; a1 < 6 ; a1 ++) {
            for (a2 = 0 ; a2 < 6 ; a2 ++) {
                for (a3 = 0 ; a3 < 6 ; a3 ++) { 
                    for (a4 = 0 ; a4 < 6 ; a4 ++) { 
                        for (a5 = 0 ; a5 < 6 ; a5 ++) { 
                            for (a6 = 0 ; a6 < 6 ; a6 ++) { 
                                if (!check (0 , 3)) goto no1;
                                for (a7 = 0 ; a7 < 6 ; a7 ++) {
                                    if (!check (3 , 6)) goto no2;
                                    for (a8 = 0 ; a8 < 6 ; a8 ++) {
                                        if (!check (0 , 9)) goto no3;
                                        ok = true;goto end;
                                        no3: ;
                                    }
                                    no2: ;
                                }
                                no1: ;
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