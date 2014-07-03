#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-10;
double a , b , l ,r;
double sqr (double d) {
    return d * d;
}
double function (double x) {
    return b * sqrt (1 - sqr(x) / sqr (a));
}
// 
double simpson_formula (double l , double r) {
    return (function (l) + 4 * function ((l + r) / 2.0) + function (r)) * (r - l) / 6.0;
}
double simpson (double l , double r) {
    double m = (l + r) / 2.0;
    double ans = simpson_formula (l , r);
    if (fabs (ans - simpson_formula (l , m) - simpson_formula (m , r)) < eps) return ans;
    return simpson (l , m) + simpson (m , r);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%lf %lf %lf %lf" , &a , &b , &l , &r);
        printf ("%.3f\n" , simpson (l , r) * 2);
    }
    return 0;
}