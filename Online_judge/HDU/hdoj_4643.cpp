#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 55;
const double eps = 1e-8;
struct Point {
    double x , y;
    Point () {}
    Point (double _x , double _y):x(_x) , y(_y){}
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
    void output () {
        printf ("%.10f %.10f\n" , x , y);
    }
}city[N] , sta[N];
int n , m;
double sqr (double d) {
    return d * d;
}
double dist (Point p1 , Point p2) {
    return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}
int check (Point p) {
    double mx = 1e18 ;int idx;
    for (int i = 0 ; i < m ; i ++) {
        double d = dist (p , sta[i]);
        if (d + eps < mx) mx = d , idx = i;
    }
    return idx;
}
bool zero (double d) {
    return fabs(d) < eps;
}
int solve (Point u , Point v) {
    int a = check (u) , b = check(v);
    // if (a == b || (zero(dist(u , sta[a]) - dist(v , sta[a])) && zero(dist(u , sta[b]) - dist(v , sta[b]))))  return 0;
    if(a == b) return 0;
    if(zero(dist(u,v))) return 1;
    Point p = Point((u.x + v.x) * 0.5 , (u.y + v.y) * 0.5); 
    return solve (u , p) + solve (p , v);
}
int main () {
    while (scanf ("%d %d" , &n , &m) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            city[i].input();
        }
        for (int i = 0 ; i < m ; i ++) {
            sta[i].input();
        }
        int q;
        scanf ("%d" , &q);
        while (q --) {
            int u , v;
            scanf ("%d %d" , &u, &v);
            u --;v --;
            printf ("%d\n" , solve (city[u] , city[v]));
        }
    }
    return 0;
}    