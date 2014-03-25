#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 2005;
const int MOD = 1000000007;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    int cnt = 0 , len = 1;
    string s;cin >> s;s = s + " ";
    for (int i = 1 ; i < s.size() ; i ++) {
        if (s[i] != s[i - 1]) {
            if (len % 2 == 0) cnt ++;
            len = 1;
        }
        else len ++;
    }
    cout << cnt << endl;
    return 0;
}