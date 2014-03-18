#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
const int N = 1005;
int n , m , k;
int a[N] , b[N];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
#endif
    int cas = 0;
    while (scanf ("%d %d %d" , &n , &m , &k) != EOF && n + m + k) {
        memset (a , -1 , sizeof (a));
        memset (b , -1 , sizeof (b));
        while (k --) {
            int num , idx = 0;scanf ("%d" , &num);
            while (true) {
                if (idx == 0) {
                    if (a[num % n] == -1) {
                        a[num % n] = num;
                        break;
                    }
                    swap (a[num % n] , num);
                    idx ^= 1;
                }
                else {
                    if (b[num % m] == -1) {
                        b[num % m] = num;
                        break;
                    }
                    swap (b[num % m] , num);
                    idx ^= 1;
                }
            }
        }
        printf ("Case %d:\n" , ++ cas);
        int first = 1;
        for (int i = 0 ; i < n ; i ++) 
            if (a[i] != -1) {
                if (first) printf ("Table 1\n");
                printf ("%d:%d\n" , i , a[i]);
                first = 0;
            }
        first = 1;
        for (int i = 0 ; i < m ; i ++)
            if (b[i] != -1) {
                if (first) printf ("Table 2\n");
                printf ("%d:%d\n" , i , b[i]);  
                first = 0;
            }
    }
    return 0;
}