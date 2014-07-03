#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int N = 50005;
const double eps = 1e-9;
double sqr (double d) {
    return d * d;
}
inline int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
struct Point {
    double x ;
    double y;
    Point () {}
    Point (int _x , int _y):x(_x) , y(_y) {}
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
    void output () {
        printf ("%f %f " , x , y);
    }
    inline double dist (Point &p) {
        return sqrt(sqr (x - p.x -0.) + sqr (y - p.y - 0.));
    }
    inline bool operator == (const Point &p) const {
        return dcmp (x - p.x) == 0 && dcmp (y - p.y) == 0;
    }
    inline Point operator - (const Point &p) const {
        return Point (x - p.x , y - p.y);
    }
    inline Point operator + (const Point &p) const {
        return Point (x + p.x , y + p.y);
    }
    inline Point turnLeft () {
        return Point (-y , x);
    }
    inline double operator * (const Point &p) const {
        return x * p.y - y * p.x;
    }
};
struct Circle {
    Point p;double r;
    void input () {
        p.input ();
        scanf ("%lf" , &r);
    }
}c[N];
int n , l[N] , r[N] , up[N] , rank[N];
set<int >s;
set<int > :: iterator it ;
bool gao (int p , double mid) {
    s.insert (p);
    it = s.find (p);
    if (it != s.begin ()) {
        it --;
        int i = up[p] , j = up[(*it)];
        double d = c[i].p.dist (c[j].p);
        if (dcmp (d - c[i].r - c[j].r - mid * 2) <= 0)
            return true;
        it ++;
    }
    it ++;
    if (it != s.end ()) {
        int i = up[p] , j = up[(*it)];
        double d = c[i].p.dist (c[j].p);
        if (dcmp (d - c[i].r - c[j].r - mid * 2) <= 0)
            return true;
    }
    return false;
}
bool check (double mid) {
    s.clear ();
    int i = 0 , j = 0;
    while (i < n || j < n) {
        // cout << rank[l[i]] << endl;
        if (j == n || (i != n && dcmp (c[l[i]].p.x - c[l[i]].r - 2 * mid - (c[r[j]].p.x + c[r[j]].r)) < 0)) {
            if (gao (rank[l[i ++]] , mid))
             return true;
        }
        else {
            s.erase (rank[r[j ++]]);
        }
    }
    return false;
}
bool cl (int a , int b) {
    return c[a].p.x - c[a].r < c[b].p.x - c[b].r;
}
bool cr (int a , int b) {
    return c[a].p.x + c[a].r < c[b].p.x + c[b].r;
}
bool cu (int a , int b) {
    if (c[a].p.y == c[b].p.y) return c[a].p.x < c[b].p.x;
    else return c[a].p.y < c[b].p.y;
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            c[i].input ();
        }
        for (int i = 0 ; i < n ; i ++)
            l[i] = r[i]  = up[i] = i;
        sort (l , l + n , cl);
        sort (r , r + n , cr);
        sort (up , up + n , cu);
        for (int i = 0 ; i < n ; i ++)
            rank[up[i]] = i;
        // for (int i = 0 ; i < n ; i ++) {
        //     cout << l[i] << " " << r[i] << " " << up[i] << " " << rank[i] << endl; 
        // }
        double low = 0 , high = 1e7 , mid , ans;
        while (fabs (low - high) > 1e-9) {
            mid = (low + high) / 2.0;
            if (check (mid)) {
                high = mid;
            }
            else {
                ans = mid;
                low = mid;
            }
        }
        // cout << check (0.6) << endl;
        printf ("%.6f\n" , ans * 2);
    }
    return 0;
}       
    