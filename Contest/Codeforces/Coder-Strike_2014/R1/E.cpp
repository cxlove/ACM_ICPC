#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 100005;
string s;
vector <int> pos;
bool isprefix (char ch) {
    if (isdigit (ch)) return true;
    if (isalpha (ch)) return true;
    if (ch == '_') return true;
    return false;
}
long long gao (int l , int r , int m) {
    if (m == l || m == r) return 0;
    string t = "";
    int len = r - l + 1;
    for (int i = l ; i <= r ; i ++) {
        t += s[i];
    }
    m -= l;
    int L , R = -1;
    for (L = m - 1 ; L >= 0 ; L --) {
        if (!isprefix (t[L])) 
            break;
    }
    L ++;
    if (L == m) return 0;
    for (R = m + 1 ; R < len ; R ++) {
        if (t[R] == '.') {
            break;
        }
    }
    if (R == len || R == m + 1) return 0;
    for (int i = R - 1 ; i > m ; i --) {
        if (!isalpha(t[i]) && !isdigit (t[i]))
            return 0;
    }
    int lcan = 0 , rcan = 0;
    for (int i = L ; i < m ; i ++) {
        if (isalpha (t[i])) {
            lcan ++;
        }
    }
    for (int i = R + 1 ; i < len ; i ++) {
        if (isalpha (t[i])) rcan ++;
        else break;
    }
    return 1LL * lcan * rcan;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    long long ans = 0;
    cin >> s;
    pos.push_back (-1);
    for (int i = 0 ; i < s.size() ; i ++) {
        if (s[i] == '@') 
            pos.push_back (i);
    }
    pos.push_back (s.size());
    for (int i = 1 ; i < pos.size() - 1 ; i ++) {
        ans += gao (pos[i - 1] + 1 , pos[i + 1] - 1 , pos[i]);
    }
    cout << ans << endl;
    return 0;
}