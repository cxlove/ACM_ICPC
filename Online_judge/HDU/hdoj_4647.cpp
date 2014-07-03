#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a , b)
#define lowbit(x) (x & (-x))
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 100005;
struct Node {
    LL point , edge;
    bool operator < (const Node &n) const {
        return 2 * point + edge > 2 * n.point + n.edge;
    }
}p[N];
int n , m;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%I64d" , &p[i].point);
            p[i].edge = 0;
        }
        for (int i = 0 ; i < m ; i ++) {
            int u ,v , w;
            scanf ("%d %d %d", &u , &v , &w);
            u -- ; v --;
            p[u].edge += w;
            p[v].edge += w;
        }
        sort (p , p + n);
        LL one = 0LL , two = 0LL;
        for (int i = 0 ; i < n ; i ++) {
            if (i & 1) two += p[i].point * 2 + p[i].edge;
            else one += p[i].point * 2 + p[i].edge;
        }
        printf ("%I64d\n" , (one - two) / 2);
    }
    return 0;
}