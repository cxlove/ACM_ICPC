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
Point Circumcenter(Point a,Point b,Point c){
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;
    double d = a1 * b2 - a2 * b1;
    return Point(a.x + (c1*b2 - c2*b1)/d,a.y + (a1*c2 - a2*c1)/d);
}
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF){
        Point central=Circumcenter(a,b,c);
        double r=dist(central,a);
        char ch1,ch2,ch3;
        if(central.x<eps) ch1='+';else ch1='-';
        if(central.y<eps) ch2='+';else ch2='-';
        double d=central.x*central.x+central.y*central.y-r*r;
        if(d<eps ) ch3='-';else ch3='+';
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",ch1,fabs(central.x),ch2,fabs(central.y),r);
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n",ch1,2*fabs(central.x),ch2,2*fabs(central.y),ch3,fabs(d));
    }
    return 0;
}






