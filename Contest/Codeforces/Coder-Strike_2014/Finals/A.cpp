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
const int N = 100005;
const int inf = 2000000007;
char f(char c){
    if (c == 'A') return 'A';
    if (c == 'H') return 'H';
    if (c == 'I') return 'I';
    if (c == 'M') return 'M';
    if (c == 'O') return 'O';
    if (c == 'T') return 'T';
    if (c == 'U') return 'U';
    if (c == 'V') return 'V';
    if (c == 'W') return 'W';
    if (c == 'X') return 'X';
    if (c == 'Y') return 'Y';
    return '$';
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    string s;
    cin >> s;
    for (int i = 0 ; i < s.size() ; i ++) {
        if (s[i] != f (s[s.size() - 1 - i])) {
            puts ("NO");
            return 0;
        }
     }
     puts ("YES");
    return 0;
}