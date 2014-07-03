#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
#define lson step << 1
#define rson step << 1 | 1
#define mp make_pair
using namespace std;
typedef long long LL;
const int N = 60006;
int q , k , x[5] , a[N][1 << 5];
multiset <int> s[1 << 5];
int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &q , &k) != EOF) {
        for (int i = 0 ; i < (1 << k) ; i ++) {
            s[i].clear();
        }
        int cnt = 0;
        while (q --) {
            int kind;scanf ("%d" , &kind);
            cnt ++;
            if (kind == 0) {
                for (int i = 0 ; i < k ; i ++) 
                    scanf ("%d" , &x[i]);
                for (int i = 0 ; i < (1 << k) ; i ++) {
                    int t = 0;
                    for (int j = 0 ; j < k ; j ++) {
                        if (i & (1 << j)) t += x[j];
                        else t -= x[j];
                    }
                    a[cnt][i] = t;
                    s[i].insert (t);
                }
            }
            else {
                int id;
                scanf ("%d" , &id);
                for (int i = 0 ; i < (1 << k) ; i ++) {
                    s[i].erase (s[i].find(a[id][i]));
                }
            }
            int ans = 0;
            for (int i = 0 ; i < (1 << k) ; i ++) {
                multiset<int> :: iterator i1 = s[i].begin () , i2 = s[i].end();
                i2 --;
                ans = max (ans , *i2 - *i1);
            }
            printf ("%d\n" , ans);
        }
    }
    return 0;
}   