#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 100005;
int n , m , mn , mx;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    cin >> n >> m >> mn >> mx;
    int a = 101 , b = -1;
    for (int i = 0 ; i < m ; i ++) {
        int k;cin >> k;
        a = min (a , k);
        b = max (b , k);
    }
    if (a < mn || b > mx) {
        puts ("Incorrect");
        return 0;
    }
    if (a == mn && b == mx) puts ("Correct");
    else if ((a == mn || b == mx) && n - m) puts ("Correct");
    else if ((n - m) >= 2) puts ("Correct");
    else puts ("Incorrect");
    return 0;
}