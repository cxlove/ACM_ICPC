#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 23333;
struct Point {
    double x , y;
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
}s , e;
double xmul(Point p0,Point p1,Point p2){  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);  
}  
int main () {
    int t;scanf ("%d" , &t);
    while (t --) {
        int n ;scanf ("%d" , &n);
        s.input ();e.input ();
        int ans = 0;
        while (n --) {
            Point a , b;
            a.input ();b.input ();
            if (xmul (a , b , s) * xmul (a , b , e) < 0) ans ++;
        }
        printf ("%d\n" , ans);
    }
    return 0;
}