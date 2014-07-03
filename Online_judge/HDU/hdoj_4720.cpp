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
const double eps = 1e-6;
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
double sqr (double d) {
    return d * d;
}
struct Point {
    double x , y;
    Point () {}
    Point (double _x , double _y):x(_x) , y(_y) {}
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
    double dist (Point p) {
        return (sqr(p.x - x) + sqr (p.y - y));
    }
}p[4];
Point circu (Point a , Point b , Point c) {
    double a1 = b.x - a.x , b1 = b.y - a.y , c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x , b2 = c.y - a.y , c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return Point (a.x + (c1 * b2 - c2 * b1) / d , a.y + (a1 * c2 - a2 * c1) / d);
}
double xmul (Point p , Point p1 , Point p2) {
    return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}
bool cmp (Point p1 , Point p2) {
    return dcmp (p1.x - p2.x) != 0 ? dcmp (p1.x - p2.x) > 0 : dcmp (p1.y - p2.y) > 0;
}
Point mid (Point p1 , Point p2) {
    return Point ((p1.x + p2.x) / 2 , (p1.y + p2.y) / 2.0);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        for (int i = 0 ; i < 4 ; i ++)
            p[i].input ();
        printf ("Case #%d: " , ++cas);
        sort (p , p + 3 , cmp);
        if (dcmp(xmul(p[0] , p[1] , p[2])) == 0) {
            Point cer = mid (p[0] , p[2]) ;
            double r = cer.dist (p[0]);
            if (dcmp (cer.dist (p[3]) - r) <= 0) {
                puts ("Danger");
            }
            else puts ("Safe");
        }
        else {
            double a = p[0].dist (p[1]) , b = p[1].dist (p[2]) , c = p[0].dist (p[2]);
            // printf ("%lf %lf %lf\n" , a , b , c);
            Point cer;
            double r;
            if (a + b < c || b + c < a || c + a < b) {
                if (a > b && a > c) cer = mid (p[0] , p[1]) , r = cer.dist (p[0]);
                if (b > c && b > a) cer = mid (p[2] , p[1]) , r = cer.dist (p[1]);
                if (c > a && c > b) cer = mid (p[0] , p[2]) , r = cer.dist (p[2]);
            }
            else cer = circu (p[0] , p[1] , p[2]),r = cer.dist(p[0]);
            if (dcmp (cer.dist (p[3]) - r) <= 0) {
                puts ("Danger");
            }
            else puts ("Safe");
        }
    }
    return 0;
}