#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , n;
    cin >> t;
    while (t --) {
        cin >> n;
        if (n == 1 || n == 2) cout << 1 << endl;
        else if (n == 4) cout << 3 << endl;
        else if (n & 1) cout << (LL)(n / 2) * (n / 2 + 1) << endl;
        else if ((n / 2) & 1) cout << (LL)(n / 2 - 2) * (n / 2 + 2) << endl;
        else cout << (LL)(n / 2 - 1) * (n / 2 + 1) << endl;
    }
    return 0;
}