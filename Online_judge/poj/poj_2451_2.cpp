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
#define eps 1e-7
#define inf 10000
using namespace std;
struct Point{
    double x,y;
}p[50005],tp[50005],q[50005];
struct Segment{
    Point aa,bb;
}seg[20005];
//叉积
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
//通过两点，确定直线方程
void Get_equation(Point p1,Point p2,double &a,double &b,double &c){
    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=p2.x*p1.y-p1.x*p2.y;
}
//求交点
Point Intersection(Point p1,Point p2,double a,double b,double c){
    double u=fabs(a*p1.x+b*p1.y+c);
    double v=fabs(a*p2.x+b*p2.y+c);
    Point t;
    t.x=(p1.x*v+p2.x*u)/(u+v);t.y=(p1.y*v+p2.y*u)/(u+v);
    return t;
}
//求面积，正为顺时针，和叉积写法有关
double Get_area(Point p[],int n){
    double area=0;
    for(int i=2;i<n;i++)
        area+=xmul(p[1],p[i],p[i+1]);
    return -area/2.0;
}
//改变顺序
void Change_dir(Point p[],int n){
    for(int i=1;i<=n/2;i++)
        swap(p[i],p[n+1-i]);
}
//加入一条边，切割
void Cut(double a,double b,double c,Point p[],int &cnt){
    int tmp=0;
    for(int i=1;i<=cnt;i++){
        //当前点就在右侧
        if(a*p[i].x+b*p[i].y+c>-eps) tp[++tmp]=p[i];
        else{
            //前一个点在右侧，产生交点
            if(a*p[i-1].x+b*p[i-1].y+c>eps)
                tp[++tmp]=Intersection(p[i-1],p[i],a,b,c);
            //同理
            if(a*p[i+1].x+b*p[i+1].y+c>eps)
                tp[++tmp]=Intersection(p[i],p[i+1],a,b,c);
        }
    }
    for(int i=1;i<=tmp;i++)
        p[i]=tp[i];
    p[0]=p[tmp];p[tmp+1]=p[1];
    cnt=tmp;
}
void slove(Segment s[],int n){
    p[1].x=0;p[1].y=0;
    p[2].x=0;p[2].y=inf;
    p[3].x=inf;p[3].y=inf;
    p[4].x=inf;p[4].y=0;
    p[0]=p[4];p[5]=p[1];
    int cnt=4;
    for(int i=1;i<=n;i++){
        double a,b,c;
        Get_equation(s[i].bb,s[i].aa,a,b,c);
        Cut(a,b,c,p,cnt);
    }
    printf("%.1f\n",fabs(Get_area(p,cnt)));
}
int main(){
    int t,n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&seg[i].aa.x,&seg[i].aa.y,&seg[i].bb.x,&seg[i].bb.y);
        slove(seg,n);
    }
    return 0;
}
