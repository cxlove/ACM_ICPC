#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 2000005;
int n , a , b , c[N] , k;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> a >> b;
    while (a --) cin >> k , c[k] = 1;
    while (b --) cin >> k;
    for (int i = 1 ; i <= n ; i ++) cout << 2 - c[i] << endl;
    return 0;
}