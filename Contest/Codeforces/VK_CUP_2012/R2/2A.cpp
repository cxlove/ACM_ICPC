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
const int N = 100000;
int n , a , b , c[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> a >> b;
    for (int i = 0 ;  i < n ; i ++)
    	cin >> c[i];
    sort (c , c + n);
    cout << (c[b] - c[b - 1]) << endl;
    return 0;
}