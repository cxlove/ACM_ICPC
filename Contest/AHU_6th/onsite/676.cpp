#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int N = 205;
int n , a[N];
int main () {
    while (cin >> n) {
        int mx = 0;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            if (i > 0) mx = max (mx , a[i]);
        }
        if (a[0] > mx) {
            puts ("Oldbear, The best!");
            continue;
        }
        for (int ans = 0 ; ; ans ++) {
            int score = ans + a[0] , cnt = 0 ;
            for (int j = 1 ; j < n ; j ++) {
                cnt += max (0 , (a[j] - score + 1));
            }
            if (cnt <= ans) {
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}
