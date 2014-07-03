#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int MOD = 51123987;
const int N = 50005;
struct Node {
    int l , r , id;
    inline void input (int i) {
        id = i;
        scanf ("%d %d" , &l , &r);
    }
    bool operator < (const Node &n) const {
        return l < n.l;
    }
}a[N];
int ans[N] , n;
set <pair <int , int> > s;
set <pair <int , int> > :: iterator it;
int main () { 
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            a[i].input (i);
        }
        sort (a , a + n);
        s.clear ();
        int idx = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (s.empty () || s.begin () -> first > a[i].l) {
                s.insert (make_pair (a[i].r + 1 , ++ idx));
                ans[a[i].id] = idx;
            }
            else {
                pair <int , int> t = *s.begin ();
                t.first = a[i].r + 1;
                ans[a[i].id] = t.second;
                s.erase (s.begin ());s.insert (t);
            }
        }
        printf ("%d\n" , idx);
        for (int i = 0 ; i < n ; i ++)
            printf ("%d\n" , ans[i]);
    }
    return 0;
}