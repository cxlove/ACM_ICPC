#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
#include<cassert>
#define LL long long
#define eps 1e-8
#define inf 999999.0
#define zero(a) abs(a)<eps
#define N 20
#define MOD 100000007
#define pi acos(-1.0)
using namespace std;
struct Point{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}a,b,c;
Point Orthocenter(Point p0,Point p1,Point p2){
    double a1,b1,a2,b2,c1,c2;
    a1 = p2.x-p1.x; b1=p2.y-p1.y;c1 = 0;
    a2 = p2.x-p0.x; b2=p2.y-p0.y;c2 = (p1.x-p0.x)*a2+(p1.y-p0.y)*b2;
    double d = a1 * b2 - a2 * b1;
    return Point(p0.x+(c1*b2-c2*b1)/d,p0.y+(a1*c2-a2*c1)/d);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        Point central=Orthocenter(a,b,c);
        printf("%.4f %.4f\n",central.x,central.y);
    }
    return 0;
}






