#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1505;

int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        LL a , b , c , d , e , m;
        cin >> a >> b >> c >> d >> e >> m;
        LL now = a + b + c + d + e;
        cout << "Case #" << ++ cas << ": ";
        if (now >= m) {
            cout << 0 << endl;
            continue;
        }
        if (now <= 0) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        while (now < m) {
            now = now * 2LL;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}