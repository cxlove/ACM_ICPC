#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long double LD;
double xa , ya , za , xb , yb , zb;
double xc , yc , zc , xd , yd , zd;
LD sqr (LD d) {
    return d * d;
}
void solve () {
    LD XA = xa , XB = xb , XC = xc , XD = xd;
    LD YA = ya , YB = yb , YC = yc , YD = yd;
    LD ZA = za , ZB = zb , ZC = zc , ZD = zd;
    LD xm , ym , zm;
    LD xn , yn , zn;
    #define E1 (sqr(XB-XA)+sqr(YB-YA)+sqr(ZB-ZA))
    #define F1 (sqr(XD-XC)+sqr(YD-YC)+sqr(ZD-ZC))
    #define G ((XB-XA)*(XD-XC)+(YB-YA)*(YD-YC)+(ZB-ZA)*(ZD-ZC))
    #define X1 ((XB-XA)*(XC-XA)+(YB-YA)*(YC-YA)+(ZB-ZA)*(ZC-ZA))
    #define Y1 ((XD-XC)*(XC-XA)+(YD-YC)*(YC-YA)+(ZD-ZC)*(ZC-ZA))
    xm = (XB-XA) * (X1 * F1 - Y1 * G) / (E1 * F1 - sqr (G)) + XA;
    ym = (YB-YA) * (X1 * F1 - Y1 * G) / (E1 * F1 - sqr (G)) + YA;
    zm = (ZB-ZA) * (X1 * F1 - Y1 * G) / (E1 * F1 - sqr (G)) + ZA;

    xn = (XD-XC) * (Y1 * E1 - X1 * G) / (-E1 * F1 + sqr (G)) + XC;
    yn = (YD-YC) * (Y1 * E1 - X1 * G) / (-E1 * F1 + sqr (G)) + YC;
    zn = (ZD-ZC) * (Y1 * E1 - X1 * G) / (-E1 * F1 + sqr (G)) + ZC;

    LD d = sqrt (sqr (xm - xn) + sqr (ym - yn) + sqr (zm - zn));
    double dist = d;
    double xmm = xm , ymm = ym , zmm = zm;
    double xnn = xn , ynn = yn , znn = zn;
    printf ("%.6f\n%.6f %.6f %.6f %.6f %.6f %.6f\n" , dist , xmm , ymm , zmm , xnn , ynn , znn);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --){
        scanf ("%lf %lf %lf %lf %lf %lf" , &xa , &ya , &za , &xb , &yb , &zb);
        scanf ("%lf %lf %lf %lf %lf %lf" , &xc , &yc , &zc , &xd , &yd , &zd);
        solve ();
    }
    return 0;
}