#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define mp(a , b) make_pair(a , b)
using namespace std;
typedef long long LL;
LL n , a[5] , pri;
bool check (LL x , LL MOD) {
    LL ret = 0;
    for (int i = n ; i >= 0 ; i --) {
        ret = ret * x + a[i];
        ret %= MOD;
        ret = (ret + MOD) % MOD;
    }
    return ret == 0 ;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        bool ok =false;
        cin >> n;
        for (int i = n ; i >= 0 ; i --)
            cin >> a[i];
        cin >> pri;
        cout << "Case #" << ++ cas << ": " ;
        for (int i = 0 ; i < pri && !ok ; i ++) {
            if (check(i , pri)) {
                for (int j = i ; j < pri * pri && !ok ; j += pri) {
                    if (check(j , pri * pri)) {
                        cout << j << endl;
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
        if (!ok) cout << "No solution!" << endl;
    }    
    return 0;
}