#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1000005;
int t , cas = 0;
char s[N] , e[N] , ans[N];
int a[10] , b[10];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s%s" , s , e);
        memset (a , 0 , sizeof(a));
        memset (b , 0 , sizeof(b));
        int n = strlen(s);
        printf ("Case #%d: " , ++cas);
        if (n == 1) {
            printf ("%d\n" , (s[0] + e[0] - '0' - '0') % 10);
            continue;
        }
        for (int i = 0 ; i < n ; i ++) {
            a[s[i] - '0'] ++;
            b[e[i] - '0'] ++;
        }
        for (int i = 9 ; i >= 0 ; i --) {
            int flag = 0;
            for (int j = 1 ; j < 10 && !flag ; j ++) {
                int k = (100 + i - j) % 10;
                    if (k!=0 && (j + k) % 10 == i && a[j] && b[k]) {
                        flag = 1;
                        a[j] --;
                        b[k] --;
                    }
            }
            ans[0] = '0' + i;
            if (flag) break;
        }
        int tot = 1;
        ans[n] = '\0';
        for (int m = 9 ; m >= 0 ; m --) {
            for (int i = 0 ; i < 10 ; i ++) {
                for (int j = 0 ; j < 10 ; j ++) {
                    if ((i + j) % 10 == m) {
                        int cnt = min (a[i] , b[j]);
                        for (int k = 0 ; k < cnt ; k ++) {
                            ans[tot ++] = '0' + m;
                        }
                        a[i] -= cnt;b[j] -= cnt;
                    }
                }
            }
        }
        int pos = 0;
        for (pos = 0 ; pos < n - 1 ; pos ++) 
            if (ans[pos] != '0')
                break;
        puts (ans + pos);
    }
    return 0;
}