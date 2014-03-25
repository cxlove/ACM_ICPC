#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main () {
    int t;cin >> t;
    while (t --) {
        string s;
        cin >> s;
        s = "@" + s;s = s + "@";
        int sum = 0 , cnt = 0;
        for (int i = 1 ; i < s.size() ; i ++) {
            if (s[i] != s[i - 1]) {
                sum += cnt * cnt;
                cnt = 1;
            }
            else cnt ++;
        }
        cout << sum << endl;
    }
    return 0;
}