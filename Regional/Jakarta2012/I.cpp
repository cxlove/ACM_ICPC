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
const int N = 1005;
const int HASH = 1000000007;
LL a , b , c , A , B , C;
LL f (LL a , LL A , LL b , LL B) {
    return abs (a * B - A * b);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        cin >> a >> A >> b >> B >> c >> C;
        cout << "Case #" << ++ cas << ": " << __gcd (__gcd (f (a , A , b , B) , f (a , A , c , C)) , f (b , B , c , C)) << endl;
    }
    return 0;
}