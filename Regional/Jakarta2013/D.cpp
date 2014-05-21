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
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 20005;
const int inf = 1000000007;
struct Node {
    int u ,v , w;
    bool operator < (const Node &n) const {
        return w < n.w;
    }
}e[N];
int pre[N] , n , m , k;
int find (int x) {
    return pre[x] = (pre[x] == x ? x : find (pre[x]));
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &m , &k);
        for (int i = 0 ; i <= n ; i ++) {
            pre[i] = i;
        }
        for (int i = 0 ; i < k ; i ++) {
            int p;scanf ("%d" , &p);
            int ra = find (0) , rb = find (p);
            if (ra != rb) pre[ra] = rb;
        }
        for (int i = 0 ; i < m ; i ++) {
            scanf ("%d %d %d" , &e[i].u , &e[i].v , &e[i].w);
        }
        sort (e , e + m);
        
        int ans = 0;
        for (int i = 0 ; i < m ; i ++) {
            int ra = find (e[i].u) , rb = find (e[i].v);
            if (ra != rb) {
                pre[ra] = rb;
                ans += e[i].w;
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}
