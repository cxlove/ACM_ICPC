/*
 长度平方比为 d = |b[1] - b[0]| / |a[1] - a[0]|
 (a[1] - a[0]) . (a[i] - a[1]) = d * (b[1] - b[0]).(b[i] - b[1])
 (a[1] - a[0]) * (a[i] - a[1]) = d * (b[1] - b[0])*(b[i] - b[1])
 */
#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
#define MAXN 10010
int n;
struct Point{
    double x, y;
}a[MAXN], b[MAXN];
double dist(Point p, Point q){
    return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}
int main(){
    int i, j, tt, t;
    Point p1, p2, q1;
    double d1, d2, t1, t2;
    double a1, b1, c1, a2, b2, c2;
    scanf ("%d", &tt);
    for (t = 1; t <= tt; t++)
    {
        scanf ("%d", &n);
        for (i = 0; i < n; i++){
            scanf ("%lf %lf", &a[i].x, &a[i].y);
        }
        for (i = 0; i < 2; i++)
            scanf ("%lf %lf", &b[i].x, &b[i].y);
        d1 = dist(a[1], a[0]);
        d2 = dist(b[1], b[0]);        
        for (i = 2; i < n; i++)        {
            p1.x = a[1].x - a[0].x, p1.y = a[1].y - a[0].y;
            p2.x = a[i].x - a[1].x, p2.y = a[i].y - a[1].y;
            q1.x = b[1].x - b[0].x, q1.y = b[1].y - b[0].y;
            t1 = d2 * (p1.x * p2.y - p1.y * p2.x); 
            t2 = d2 * (p1.x * p2.x + p1.y * p2.y); 
            a1 = -q1.y *d1; b1 = d1 * q1.x;   c1 = t1 + d1 * (q1.x * b[1].y - q1.y * b[1].x);
            a2 = d1 * q1.x; b2 = d1 * q1.y;   c2 = t2 + d1 * (q1.x * b[1].x + q1.y * b[1].y);
            b[i].x = (b1 * c2 - b2 * c1) / (a2 * b1 - a1 * b2);
            b[i].y = (a2 * c1 - a1 * c2) / (a2 * b1 - a1 * b2);
        }
        printf ("Case %d:\n", t);
        for (i = 0; i < n; i++)    {
            printf ("%.2lf %.2lf\n", b[i].x, b[i].y);
        }
    }
    return 0;
}
