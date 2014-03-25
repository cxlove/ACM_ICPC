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
const int N = 200005;
const int MOD = 1000000007;
struct Node {
    int p , e;
    void input () {
        scanf ("%d %d" , &p , &e);
    }
    bool operator < (const Node &n) const {
        return p > n.p;
    }
}a[N];
int n , k;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    scanf ("%d %d" , &n , &k);k --;
    for (int i = 0 ; i < n ; i ++) {
        a[i].input ();
    }
    LL ans = 1LL << 60;
    sort (a , a + n);
    for (int d = -2 ; d < 3 ; d ++) {
        int score = a[k].p + d , before = 0;
        LL ret = 0 ;
        priority_queue <int , vector <int> , less <int> > large;
        priority_queue <int , vector <int> , greater <int> > small;
        for (int i = 0 ; i < n ; i ++) { 
            if (a[i].p <= score && a[i].p >= score - 1) {
                large.push (a[i].e);
            }
            else {
                if (a[i].p > score) before ++;
                small.push (a[i].e);
            }
        }
        if (before > k) continue;
        while (!large.empty ()) {
            if (before < k) {
                small.push (large.top ());
                before ++;
            }
            else {
                score --;
                ret += large.top ();
            }
            large.pop ();
        }
        while (score > 0 && !small.empty ()) {
            ret += small.top ();
            small.pop ();
            score --;
        }
        if (score <= 0) ans = min (ans , ret);
    }
    if (ans == 1LL << 60) ans = -1;
    printf ("%I64d\n" , ans);
    return 0;
}