#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
const double eps = 1e-8;
double check (double a , double b) {
    return a <= b + eps;
}
double sqr (double d) {
    return d * d;
}
inline int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
struct Point3 {
    double x , y , z;
    Point3 () {}
    Point3 (double _x , double _y , double _z): x(_x) , y(_y) , z(_z) {}
    void input() {
        scanf ("%lf %lf %lf", &x, &y , &z);
    }
    inline Point3 operator - (const Point3 &p) const {
        return Point3 (x - p.x , y - p.y , z - p.z);
    }
    inline Point3 operator * (const Point3 &p) const {
        return Point3 (y * p.z - p.y * z , p.x * z - x * p.z , x * p.y - p.x * y);
    }
    inline Point3 operator * (const double k) const {
        return Point3 (x * k , y * k , z * k);
    }
    inline double Distance (const Point3 &p) const {
        return sqrt(sqr(x - p.x) + sqr(y - p.y) + sqr(z - p.z));
    }
    inline double len() const {
        return sqrt(sqr(x) + sqr(y) + sqr(z));
    }
    inline double operator / (const Point3 &p) const {
        return x * p.x + y * p.y + z * p.z;
    }
    inline Point3 scale(double k) const {
        return dcmp(len()) ? (*this) * (k / len()) : (*this);
    }
    inline Point3 operator + (const Point3 &p) const {
        return Point3 (x + p.x , y + p.y , z + p.z);
    }
}a , b , c;
struct Line3 {
    Point3 a, b;
    Line3 () {}
    Line3 (Point3 _a , Point3 _b):a(_a) , b(_b) {}
    inline double line_to_line (const Line3 &v) const {
        return v.PointToLine(a).Distance(a);
    }
    inline Point3 PointToLine (const Point3 &p) const {
        return a + ((b - a).scale(((b - a) / (p - a)) / a.Distance(b)));
    }
}line[300];
struct Plane {
    Point3 a , b , c , o;
    Plane () {}
    Plane (Point3 _a , Point3 _b , Point3 _c):a(_a) , b(_b) , c(_c){
        o = Pvector();
    }
    Point3 Pvector() const {
        return (b - a) * (c - a);
    }
}plane[300];
double LtoL(Point3 a,Point3 b,Point3 c,Point3 d){
    Point3 v=(a-b)*(c-d);
    return fabs((a-c)/v)/v.len();
}
int n;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif 
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            a.input(); b.input(); c.input();
            plane[i]  = Plane (a , b , c);
            line[i].a = plane[i].a;
            line[i].b = plane[i].o + plane[i].a;
           // printf ("%.5f %.5f %.5f %.5f %.5f %.5f\n",line[i].a.x,line[i].a.y,line[i].a.z,line[i].b.x,line[i].b.y,line[i].b.z);
        }
        double ans = 1e18;
        bool lucky = false;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i + 1 ; j < n ; j ++) {
                double r1 = plane[i].a.Distance(plane[i].b);
                double r2 = plane[j].a.Distance(plane[j].b);
                double d = LtoL(line[i].a,line[i].b,line[j].a,line[j].b);    
                //line[i].line_to_line(line[j]);
               // cout << d << " " << r1 << " " << r2 << endl;
                if( check( d , r1 + r2) ) lucky = true;
                else ans = fmin (ans , d - r1 - r2);
            }
        }
        if (lucky) puts("Lucky");
        else printf ("%.2f\n",ans);
    }
    return 0;
}    