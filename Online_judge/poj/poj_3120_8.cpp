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
char str[10][10];
int a1[3] , a2[3] , a3[3] , a4[3] , a5[3] , a6[3] , a7[3] , a8[3];
int a[9][9] , b[9][9] , c[9][9];
int f[10] , d[10] , e[10];
bool check (int l , int r) {
    memset (f , 0 , sizeof (f));
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = l ; j < r ; j ++) {
            int ii = a1[d[i]] * 3 , jj = a2[d[j]] * 3;
            if (d[i] == 0) ii += a3[e[i]]; 
            else if (d[i] == 1) ii += a4[e[i]];
            else ii += a5[e[i]];
            if (d[j] == 0) jj += a6[e[j]];
            else if (d[j] == 1) jj += a7[e[j]];
            else jj += a8[e[j]];
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
            int ii = a1[d[i]] * 3 , jj = a2[d[j]] * 3;
            if (d[i] == 0) ii += a3[e[i]]; 
            else if (d[i] == 1) ii += a4[e[i]];
            else ii += a5[e[i]];
            if (d[j] == 0) jj += a6[e[j]];
            else if (d[j] == 1) jj += a7[e[j]];
            else jj += a8[e[j]];
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
        for (int i = 0 ; i < 3 ; i ++) a1[i] = i;
        do {
            for (int i = 0 ; i < 3 ; i ++) a2[i] = i;
            do {
                for (int i = 0 ; i < 3 ; i ++) a3[i] = i;
                do {
                    for (int i = 0 ; i < 3 ; i ++) a4[i] = i;
                    do {
                        for (int i = 0 ; i < 3 ; i ++) a5[i] = i;
                        do {
                            for (int i = 0 ; i < 3 ; i ++) a6[i] = i;
                            do {
                                if (!check (0 , 3)) goto no1;
                                for (int i = 0 ; i < 3 ; i ++) a7[i] = i;
                                do {
                                    if (!check (3 , 6)) goto no2;
                                    for (int i = 0 ; i < 3 ; i ++) a8[i] = i;
                                    do {
                                        if (!check (0 , 9)) goto no3;
                                        ok = true;goto end;
                                        no3: ;
                                    }while (next_permutation (a8 , a8 + 3));
                                    no2: ;
                                }while (next_permutation (a7 , a7 + 3));
                                no1: ;
                            }while (next_permutation (a6 , a6 + 3));
                        }while (next_permutation (a5 , a5 + 3));
                    }while (next_permutation (a4 , a4 + 3));
                }while (next_permutation (a3 , a3 + 3));
            }while (next_permutation (a2 , a2 + 3));
        }while (next_permutation (a1 , a1 + 3));
        end:
        puts (ok ? "Yes" : "No");
    }
    return 0;
}