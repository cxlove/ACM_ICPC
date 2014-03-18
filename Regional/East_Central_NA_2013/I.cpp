#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long LL;
const int N = 62;
LL n , m , cnt[N] , sum[N] , c[N][N] , two[N];
void init () {
    for (int i = 0 ; i < N ; i ++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1 ; j < i ; j ++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (int n = 1 ; n < N ; n ++) {
        for (int a = 0 ; a <= n ; a ++) {
            for (int ab = 0 ; ab * 2 + a <= n ; ab ++) {
                if ((n - ab * 2 - a) & 1) continue;
                int bb = (n - ab * 2 - a) / 2;
                cnt[n] += c[a + ab + bb][a] * c[ab + bb][ab];
            }
        }
        sum[n] = sum[n - 1] + cnt[n];
    }
    two[0] = 1;
    for (int i = 1 ; i < N ; i ++)
        two[i] = two[i - 1] * 2;
}
string gao (LL n) {
    int len = 1;
    while (sum[len] < n) len ++;
    LL now = sum[len - 1];
    string ans = "";
    for (int i = len - 1 ; i >= 0 ;) {
        if (now + two[i] >= n) {
            ans += "a";
            LL remain = n - now - 1;
            for (int j = i - 1 ; j >= 0 ; j --)
                if ((1LL << j) & remain)
                    ans += "b";
                else ans += "a";
            return ans; 
        }
        ans += "bb";
        now += two[i];
        i -= 2;
    }
    return ans;
}
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
#endif
    init ();
    int cas = 0;
    while (cin >> n >> m && n + m) {
        cout << "Case " << ++ cas << ": ";
        cout << gao (n * (m - 1) + 1) << " ";
        cout << gao (n * m) << endl;
    }
    return 0;
}