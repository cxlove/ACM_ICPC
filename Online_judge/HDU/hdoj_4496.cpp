#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10005;
const int M = 100005;
int pre[N] , u[M] , v[M] , ans[M] , n , m;
int find (int x) {
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        for (int i = 0 ; i < m ; i ++) {
            scanf ("%d %d" , &u[i] , &v[i]);
        }
        int cnt = n;
        for (int i = 0 ; i < n ; i ++) 
            pre[i] = i;
        for (int i = m - 1 ; i >= 0 ; i --) {
            ans[i] = cnt;
            int ra = find (u[i]) , rb = find (v[i]);
            if (ra != rb) {
                pre[ra] = rb;
                cnt --;
            }
        } 
        for (int i = 0 ; i < m ; i ++)
            printf ("%d\n" , ans[i]);
    }
    return 0;
}