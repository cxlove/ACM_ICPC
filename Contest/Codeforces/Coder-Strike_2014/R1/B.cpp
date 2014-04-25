#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N = 105;
int n , k , a[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
    sort (a , a + n);
    reverse (a , a + n);
    cout << a[k - 1] << endl;
    return 0;
}