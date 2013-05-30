#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-7;
const double pi = acos(-1.0);
inline double sqr(double b){
    return b*b;
}
inline int dcmp(double d){
    return d<-eps?-1:d>eps;
}
struct Point{
    double x,y;
    Point(){}
    Point(const double &_x,const double &_y):x(_x),y(_y){}
    inline Point operator+(const Point &p)const{
        return Point(x+p.x,y+p.y);
    }
    inline Point operator-(const Point &p)const{
        return Point(x-p.x,y-p.y);
    }
    inline double operator*(const Point &p)const{
        return x*p.y-y*p.x;
    }
    inline bool operator==(const Point &p)const{
        return (dcmp(x-p.x)==0&&dcmp(y-p.y)==0);
    }
    inline Point turnLeft(){
        return Point(-y,x);
    }
    inline double Distance(Point p){
        return sqrt(sqr(p.x-x)+sqr(p.y-y));
    }
}p;
struct Line{
    Point a,b;
    inline double operator*(const Point &p)const{
        return (b-a)*(p-a);
    }
    inline double DisPointToSeg(Point p){
        if(a==b) return a.Distance(p);
        Point q=p+(a-b).turnLeft();
        if(((p-a)*(q-a))*((p-b)*(q-b))>-eps)
            return min(p.Distance(a),p.Distance(b));
        return fabs((*this)*p)/a.Distance(b);
    }
}line;
struct Circle{
    Point c;
    double r;
    inline Point GetPoint(double angle){
        return Point(cos(angle)*r+c.x,sin(angle)*r+c.y);
    } 
}cir;
double ThreeSearch(double low,double high){
    double mid,midd,ans=1LL<<60;
    while(high-low>eps){
        mid=(low+high)/2.0;
        midd=(mid+high)/2.0;
        Point t1=cir.GetPoint(mid),t2=cir.GetPoint(midd);
        double d1=t1.Distance(p)+line.DisPointToSeg(t1);
        double d2=t2.Distance(p)+line.DisPointToSeg(t2);
        if(dcmp(d1-d2)<=0){
            ans=fmin(ans,fmin(d1,d2));
            high=midd;
        }
        else{
            ans=fmin(ans,fmin(d1,d2));
            low=mid;
        }
    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%lf%lf",&p.x,&p.y)!=EOF){
        scanf("%lf%lf%lf",&cir.c.x,&cir.c.y,&cir.r);
        scanf("%lf%lf%lf%lf",&line.a.x,&line.a.y,&line.b.x,&line.b.y);
        printf("%.2f\n",fmin(ThreeSearch(0,pi),ThreeSearch(pi,2*pi)));
    }
    return 0;
}