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
#include<cassert>
#define LL long long
#define eps 1e-8
#define inf 1<<28
#define zero(a) fabs(a)<eps
using namespace std;
struct Point{
    double x,y;
}p[1505],tp[1505],q[1505];
struct Node{
    double u,v,w;
}z[105];
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
Point Intersection(Point p1,Point p2,double a,double b,double c){
    double u=fabs(a*p1.x+b*p1.y+c);
    double v=fabs(a*p2.x+b*p2.y+c);
    Point t;
    t.x=(p1.x*v+p2.x*u)/(u+v);t.y=(p1.y*v+p2.y*u)/(u+v);
    return t;
}
double Get_area(Point p[],int n){
    double area=0;
    for(int i=2;i<n;i++)
        area+=xmul(p[1],p[i],p[i+1]);
    return -area/2.0;
}
void Cut(double a,double b,double c,Point p[],int &cnt){
    int tmp=0;
    for(int i=1;i<=cnt;i++){
        if(a*p[i].x+b*p[i].y+c>-eps) tp[++tmp]=p[i];
        else{
            if(a*p[i-1].x+b*p[i-1].y+c>eps)
                tp[++tmp]=Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x+b*p[i+1].y+c>eps)
                tp[++tmp]=Intersection(p[i],p[i+1],a,b,c);
        }
    }
    for(int i=1;i<=tmp;i++)
        p[i]=tp[i];
    p[0]=p[tmp];p[tmp+1]=p[1];
    cnt=tmp;
}
int slove(int n,int idx){
    p[1].x=0;p[1].y=0;
    p[2].x=0;p[2].y=inf;
    p[3].x=inf;p[3].y=inf;
    p[4].x=inf;p[4].y=0;
    p[0]=p[4];p[5]=p[1];
    int cnt=4;
    for(int i=0;i<n;i++){
        if(i==idx) continue;
        double a,b,c;
        a=(z[idx].u-z[i].u)/(z[idx].u*z[i].u);
        b=(z[idx].v-z[i].v)/(z[idx].v*z[i].v);
        c=(z[idx].w-z[i].w)/(z[idx].w*z[i].w);
        if(a==0&&b==0&&c<eps) return 0;
        Cut(a,b,c,p,cnt);
    }
    return !zero(Get_area(p,cnt));
}
int main(){
    int n;
    while( scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&z[i].u,&z[i].v,&z[i].w);
        for(int i=0;i<n;i++)
            puts(slove(n,i)?"Yes":"No");
    }
    return 0;
}
