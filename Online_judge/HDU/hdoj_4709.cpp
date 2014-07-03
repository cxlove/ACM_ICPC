#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
struct Point {
    double x , y;
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
}p[100];
double xmul (Point p , Point p1 , Point p2) {
    return fabs((p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y) ) / 2.0; 
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , n;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            p[i].input ();
        }
        double ans = -1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i + 1 ; j < n ; j ++) {
                for (int k = j + 1 ; k < n ; k ++) {
                    double t = xmul (p[i] , p[j] , p[k]);
                    if (t > 0 && (ans < 0 || t < ans)) ans = t;
                }
            }
        }
        if (ans < 0) puts ("Impossible");
        else printf ("%.2f\n" , ans);
    }
    return 0;
}