#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
char str[1005];
LL fac[1000005];
int main () {
    int n , m , t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s %d" , str , &m);
        fac[0] = 1;
        for (int i = 1 ; i < m ; i ++) {
            fac[i] = (fac[i - 1] * i) % m;
        }
            LL ans = 0;
        if (strlen (str) >= 7) {
            for (int i = 0 ; i < m ; i ++)
                ans = (ans + fac[i]) % m;
        }
        else {
            sscanf (str , "%d" , &n);
            for (int i = 0 ; i <= n && i < m ; i ++)
                ans = (ans + fac[i]) % m;
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}        

