#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100005;
const int inf = 1000000007;
int n , k , que[N];
double a[N];
int get() {
    int s=0 ;
    char ch=getchar() ;
    while(ch<'0' || ch>'9')ch=getchar() ;
    while(ch<='9' && ch>='0') {
        s=s*10+ch-'0' ;
        ch=getchar() ;
    }
    return s ;
}
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
#endif
    while (scanf ("%d %d" , &n , &k) != EOF) {
        for (int i = 1 ; i <= n ; i ++) {
            int r = get ();
            a[i] = a[i - 1] + r;
        }
        int head = 0 , tail = 0;
        double ans = 0.0;
        for (int i = k ; i <= n ; i ++) {
            int now = i - k;
            while (head + 1 < tail) {
                double x1 = que[tail - 1] - que[tail - 2] , x2 = now - que[tail - 1];
                double y1 = a[que[tail - 1]] - a[que[tail - 2]] , y2 = a[now] - a[que[tail - 1]];
                if (y1 * x2 >= x1 * y2) tail --;
                else break;
            }
            que[tail ++] = now;
            while (head + 1 < tail) {
                double x1 = i - que[head] , x2 = i - que[head + 1];
                double y1 = a[i] - a[que[head]] , y2 = a[i] - a[que[head + 1]];
                if (y1 * x2 <= x1 * y2) head ++;
                else break;
            }
            ans = max (ans , (a[i] - a[que[head]] + 0.0) / (i - que[head]));
        }
        printf ("%.2f\n" , ans);
    }
    return 0;
}