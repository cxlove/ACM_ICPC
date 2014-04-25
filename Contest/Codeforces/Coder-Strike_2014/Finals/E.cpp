#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 1000001;
const double eps = 1e-8;
const double pi = acos (-1.0);
inline int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
inline double sqr (double d) {
    return d * d;
}
struct Node {
    double angle;
    int f;
    Node () {}
    Node (double a , int _f) {
        angle = a;f = _f;
    }
    bool operator < (const Node &n) const{
        return dcmp (angle - n.angle) ? angle < n.angle : f > n.f;
    }
};
int n;
double d , x[N] , r[N] , y[N];
vector <Node> v;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d %lf" , &n , &d);
    for (int i = 0 ; i < n ; i ++) {
        scanf ("%lf %lf %lf" , x + i , y + i , r + i);
    }
    int ans = 0 , ret = 0;
    for (double R = d ; R <= 100500 ; R += d) {
        for (int i = 0 ; i < n ; i ++) {
            double dist = sqr (x[i]) + sqr (y[i]);
            // 圆相交
            if (dcmp (dist - sqr (r[i] + R)) <= 0) {
                if (dcmp (dist - sqr (fabs (r[i] - R))) >= 0) {
                    double k = atan2 (y[i] , x[i]);
                    double A = R , B = sqrt (dist) , C = r[i];
                    // cos (c)
                    double angle = acos ((sqr (A) + sqr (B) - sqr (C)) / (2 * A * B));
                    v.push_back (Node (k - angle , 1));
                    if (dcmp (v.back().angle - -pi) < 0) {
                        v.back().angle += 2 * pi;
                        ret ++;
                    }
                    v.push_back (Node (k + angle , -1));
                    if (dcmp (v.back().angle - pi) >= 0) {
                        v.back().angle -= 2 * pi;
                        ret ++;
                    }
                }
            }
        }
    }
    ans = ret;
    sort (v.begin () , v.end ());
    for (int i = 0 ; i < v.size() ; i ++) {
        ret += v[i].f;
        ans = max (ans , ret);
    }
    printf ("%d\n" , ans);
    return 0;
}