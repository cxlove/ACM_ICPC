#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 105;
int t  , cas = 0;
string s;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    cin >> t;
    while (t --) {
        cin >> s;
        if (s.length() >= 4) {
            if (s.substr (s.length() - 4 , 4) == "desu") {
                s = s.substr(0 , s.length() - 4);
                s = s + "nanodesu";
            }
            else s = s + "nanodesu";
        }
        else s = s + "nanodesu";
        cout << "Case #" << ++cas << ": " << s << endl;
    }
    return 0;
}       