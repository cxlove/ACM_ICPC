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
const int N = 2000005;
struct SegTree {
    int left , right , cnt;
}L[N << 2];
int n , m , used[N] , now[N] , ans[N];
#define lson step << 1
#define rson step << 1 | 1 
void build (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    if (l == r) {
        if (l > m) {
            L[step].cnt = 1;
        }
        else L[step].cnt = 0;
        return ;
    }
    int m = (l + r) >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
    L[step].cnt = L[lson].cnt + L[rson].cnt;
}
int get (int step , int need) {
    if (L[step].left == L[step].right) {
        return L[step].left;
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (L[lson].cnt >= need) return get (lson , need);
    else return get (rson , need - L[lson].cnt);
}
void update (int step , int pos , int val) {
    L[step].cnt += val;
    if (L[step].left == L[step].right) return;
    int m = (L[step].left + L[step].right) >> 1;
    if (pos <= m) update (lson , pos , val);
    else update (rson , pos , val);
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    memset (ans , -1 , sizeof (ans));
    memset (now , -1 , sizeof (now));
    memset (used , -1 , sizeof (used));
    scanf ("%d %d" , &n , &m);
    build (1 , 1 , n + m);
    for (int i = 0 ; i < m ; i ++) {
        int x , y;
        scanf ("%d %d" , &x , &y);
        int pos = get (1 , y);
        if (used[x] != -1 && used[x] != pos) {
            puts ("-1");
            return 0;
        } 
        if (now[pos] != -1 && now[pos] != x) {
            puts ("-1");
            return 0;
        }
        now[pos] = -1;now[m - i] = x;
        if (used[x] == -1) ans[pos - m] = x;
        used[x] = m - i;
        update (1 , pos , -1);
        update (1 , m - i , 1);
    }
    int nouse = 1;
    for (int i = 1 ; i <= n ; i ++) {
        if (ans[i] != -1) printf ("%d " , ans[i]);
        else {
            while (used[nouse] != -1) {
                nouse ++;
            }
            printf ("%d " , nouse ++);
        }
    }
    return 0;
}