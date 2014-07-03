#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1005;
struct Calve {
    int h , w , v;
    bool operator < (const Calve &n) const {
        return h != n.h ? h < n.h : w < n.w;
    }
}cal[N] , t[N];
int n , a , b , c , m , x[N] , p;
int main () {
    // freopen ("input.txt" , "r" , stdin);
    scanf ("%d %d %d %d" , &n , &a , &b , &c);
    for (int i = 0 ; i < n ; i ++) {
        scanf ("%d %d" , &cal[i].h , &cal[i].w);
        cal[i].v = a * cal[i].h + b * cal[i].w - c;
    }
    sort (cal , cal + n);
    int ans = 0;
    for (int i = n - 1 ; i >= 0 ; i --) {
        int h = cal[i].h;
        t[m ++] = cal[i];
        for (int j = m - 1 ; j > 0 ; j --) {
            if (t[j].w < t[j - 1].w)
                swap (t[j] , t[j - 1]);
        }
        int cnt = 0;
        priority_queue <int> que;
        for (int j = m - 1 ; j >= 0 ; j --) {
            int w = t[j].w;
            que.push (t[j].v);cnt ++;
            while (!que.empty () && que.top () > a * h + b * w) {
                que.pop ();cnt --;
            }
            ans = max (ans , cnt);
        }
    }
    printf ("%d\n" , ans);
    return 0;
}