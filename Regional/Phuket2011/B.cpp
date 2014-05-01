#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 100005;
int n , a[N];
void gao (int l , int r , int root) {
    int m;
    for (m = l ; m <= r ; m ++) {
        if (a[m] > a[root]) {       
            break;
        }
    }
    if (l < m) gao (l + 1 , m - 1 , l);
    if (r >= m) gao (m + 1 , r , m);
    printf ("%d\n" , a[root]);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    while (scanf ("%d" , &a[n ++]) != EOF);
    gao (1 , n - 2 , 0);
    return 0;
}