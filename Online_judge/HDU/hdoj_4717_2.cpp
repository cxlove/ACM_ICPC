#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 305;
const double eps = 1e-6;
int n;
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
double sqr (double d) {
    return d * d;
}
struct Node {
    double x , y , vx , vy;
    void input () {
        scanf ("%lf %lf %lf %lf" , &x , &y , &vx , &vy);
    }
}p[N];
double gao (double mid) {
    double dis = 0;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = i + 1 ; j < n ; j ++) {
            dis = max (dis , sqr (p[i].x - p[j].x + mid * (p[i].vx - p[j].vx)) + sqr (p[i].y - p[j].y + mid * (p[i].vy - p[j].vy)));
        }
    }
    return sqrt (dis);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            p[i].input ();
        }
        double low = 0 , high = 1000 , mid , midd;
        int cnt = 300;
        while (cnt --) {
            mid = (low + high) / 2.0;
            midd = (mid + high) / 2.0;
            double t1 = gao (mid);
            double t2 = gao (midd);
            if (dcmp (t1 - t2) <= 0) {
                high = midd;
            } 
            else {
                low = mid;
            }
        }
        printf ("Case #%d: %.2lf %.2lf\n" , ++cas , mid , gao (mid));
    }
    return 0;
}       

