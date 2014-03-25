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
const int N = 1000005;
const int MOD = 1000000007;
int n , m;
struct Node {
    int x1 , y1 , x2 , y2 , kind , l;
    void input (int k) {
        kind = k;
        scanf ("%d %d %d" , &x1 , &y1 , &l);
        if (k == 0) x2 = x1 + l , y2 = y1;
        else x2 = x1 , y2 = y1 + l;
    }
}hor[N] , ver[N];
struct Line {
    int x1 , x2 , y , f;
    Line () {}
    Line (int _x1 , int _x2 , int _y , int _f = 0) {
        x1 = _x1;x2 = _x2;y = _y;f = _f;
    }
    bool operator < (const Line &n) const {
        return y != n.y ? y < n.y : f > n.f;
    }
}a[N] , b[N];
bool check (int l) {
    int row = 0 , col = 0;
    for (int i = 0 ; i < m ; i ++) {
        if (hor[i].l >= l * 2) {
            a[row ++] = Line (hor[i].x1 + l , hor[i].x2 - l , hor[i].y1);
        }
    }
    sort (a , a + row);
    for (int i = 0 ; i < n ; i ++) {
        if (ver[i].l >= l * 2) {
            b[col ++] = Line (ver[i].x1 , ver[i].x1 , ver[i].y1 + l , 1);
            b[col ++] = Line (ver[i].x1 , ver[i].x1 , ver[i].y2 - l + 1);
        }
    }
    sort (b , b + col);
    multiset<int> myset;
    for (int i = 0 , j = 0 ; i < row ; i ++) {
        while (j < col && b[j].y <= a[i].y) {
            if (b[j].f) myset.insert (b[j].x1);
            else myset.erase (myset.find (b[j].x1));
            j ++;
        }
        multiset <int> :: iterator it = myset.lower_bound (a[i].x1);
        if (it != myset.end () && *it <= a[i].x2) return true;
    }
    return false;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    scanf ("%d %d" , &n , &m);
    for (int i = 0 ; i < n ; i ++)
        ver[i].input (1);
    for (int i = 0 ; i < m ; i ++)
        hor[i].input (0);
    int low = 1 , high = 100000000 , mid , ans = 0;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (check (mid)) ans = mid , low = mid + 1;
        else high = mid - 1;
    }
    printf ("%d\n" , ans);
    return 0;
}