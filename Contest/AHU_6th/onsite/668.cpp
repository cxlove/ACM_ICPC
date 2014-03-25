#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;
const int N = 1005;
const double eps = 1e-6;
int a[N] , n = 1000;
void del (int k) {
    for (int i = k + 1 ; i <= n ; i ++)
        a[i - 1] = a[i];
    n --;
}
int main () {
#ifndef ONLINE_JUDGE 
    //freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    for (int i = 1 ; i <= n ; i ++)
        a[i] = i;
    for (int i = 2 ; i <= 10  ; i ++) {
        for (int j = i ; j <= n ; j += i - 1)
            del (j);
    }
    int t;cin >> t;
    while (t --) {
        int k;cin >> k;
        cout << a[k] << endl;
    }
    return 0;
}