#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#define mp(a , b) make_pair (a , b)
#define pb push_back
#pragma comment(linker,"/STACK:100000000,100000000")
using namespace std;
typedef long long LL;
const int N = 1000005;
char str[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s" , str);
        if (strcmp (str , "MI") == 0) {
            puts ("Yes");
            continue;
        }
        if (str[0] != 'M') puts ("No");
        else {
            bool ok = true;
            int cnt = 0 , tot = 0;
            for (int i = 1 ; str[i] ; i ++) {
                if (str[i] == 'M') ok = false;
                if (str[i] == 'U') cnt ++;
                else tot ++;
            }
            if (!ok) puts ("No");
            else {
                int tmp = cnt * 3 + tot;
                if (tmp % 6 == 2 || tmp % 6 == 4) puts ("Yes");
                else puts ("No");
            }
        }
    }
    return 0;
}        

