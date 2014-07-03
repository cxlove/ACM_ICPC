#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;
const int N = 50;
int a[N];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t;
    while (cin >> t && t) {
        memset (a , 0 , sizeof (a));
        int ans = 0;
        while (t --) {
            for (int i = 0 ; i < 6 ; i ++) {
                int k;
                cin >> k;
                if (k >= 1 && k < N) a[k] = 1;
            }
        }
        for (int i = 1 ; i < N ; i ++) {
            ans += 1 - a[i];
        }
        if (ans == 0) puts ("Yes");
        else puts ("No");
    }
    return 0;
}
