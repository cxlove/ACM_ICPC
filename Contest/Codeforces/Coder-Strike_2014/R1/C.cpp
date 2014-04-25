#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N = 100005;
int n;
string s[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        cin >> s[i];
    }
    int m = s[0].size ();
    string ans;
    for (int i = 0 ; i < m ; i ++) {
        char ch;int cnt = 0;
        for (int j = 0 ; j < n ; j ++) {
            if (s[j][i] != '?') {
                if (cnt == 0) {
                    cnt ++;
                    ch = s[j][i];
                }
                else {
                    if (s[j][i] != ch) {
                        cnt ++;
                    }
                }
            }
        }
        if (cnt == 0) ans = ans + "a";
        else if (cnt == 1) ans = ans + ch;
        else ans = ans + "?";
    }
    cout << ans << endl;
    return 0;
}