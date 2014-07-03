#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 12;
const int M = 5005;
char str[N][M] , text[M];
int n , m , next[M] , mat[M] , dp[200][1 << N] , l[N];
void get_next (char *s , int l) {
    next[0] = -1;
    int i = 0 , j = -1;
    while (i < l) {
        if (j == -1 || s[i] == s[j]) {
            i ++; j ++;
            next[i] = j;
        }
        else j = next[j];
    }
}
void match (char *p , int lp , char *s , int ls , int k) {
    int i = 0 , j = 0 ;
    while (j < ls) {
        if (i == -1 || p[i] == s[j]) {
            i ++; j ++;
            if (i == lp) {
                // cout << i << " " << j << endl;
                mat[j - 1] |= 1 << k;
                i = next[i];
            }
        }
        else i = next[i];
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF && n + m) {
        memset (mat , 0 , sizeof(mat));
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str[i]);
            l[i] = strlen (str[i]);
        }
        text[0] = '\0';
        for (int i = 0 ; i < m ; i ++) {
            scanf ("%s" , text + strlen (text));
        }
        for (int i = 0 ; i < n ; i ++) {
            get_next (str[i] , strlen (str[i]));
            match (str[i] , l[i] , text , strlen (text) , i);
        }
        // for (int i = 0 ; text[i] ; i ++)
        //     cout << i << " " << mat[i] << endl;
        memset (dp , 0 , sizeof(dp));
        int ans = 0;
        for (int i = 0 ; text[i] ; i ++) {
            for (int j = 0 ; j < n ; j ++)
                if (mat[i] & (1 << j))
                    dp[i % 200][1 << j] = 1;
            for (int j = 0 ; j < n ; j ++) {
                if (i >= l[j] && (mat[i] & (1 << j))) {
                    for (int k = 0 ; k < (1 << n) ; k ++) {
                        if (!(k & (1 << j)))
                            dp[i % 200][k | (1 << j)] |= dp[((i - l[j]) % 200 + 200) % 200][k];
                    }
                }
            }
            ans += dp[i % 200][(1 << n) - 1];
            memset (dp[(i - 105 + 200) % 200] , 0 , sizeof(dp[0]));
        }
        printf ("%d\n" , ans);
    }
    return 0;
}       

