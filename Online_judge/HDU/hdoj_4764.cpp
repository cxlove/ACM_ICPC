#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define Key_value ch[ch[root][1]][0] 
#define pii pair<pair<int,int>,int>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , k;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &k) != EOF) {
        if (n == 0 && k == 0) {
            break;
        }
        if (n == 1) {
            puts ("Jiang");
            continue;
        }
        n --;
        if (n % (k + 1) == 0) puts ("Jiang");
        else puts ("Tang");
    }
    return 0;
}       

