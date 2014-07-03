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
#define eps 1e-10
#define inf 10000
#define zero(a) fabs(a)<eps
#define N 20005
using namespace std;
struct Point{
    double x,y;
}p[N*2];
struct Segment{
    Point s,e;
    double angle;
    void get_angle(){angle=atan2(e.y-s.y,e.x-s.x);}
}seg[N];
int m;
//叉积为正说明，p2在p0-p1的左侧
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
Point Get_Intersect(Segment s1,Segment s2){
    double u=xmul(s1.s,s1.e,s2.s),v=xmul(s1.e,s1.s,s2.e);
    Point t;
    t.x=(s2.s.x*v+s2.e.x*u)/(u+v);t.y=(s2.s.y*v+s2.e.y*u)/(u+v);
    return t;
}
bool cmp(Segment s1,Segment s2){
    //先按极角排序
    if(s1.angle>s2.angle) return true;
    //极角相等，内侧的在前
    else if(zero(s1.angle-s2.angle)&&xmul(s2.s,s2.e,s1.e)>-eps) return true;
    return false;
}
void HalfPlaneIntersect(Segment seg[],int n){
    sort(seg,seg+n,cmp);
    int tmp=1;
    for(int i=1;i<n;i++)
        if(!zero(seg[i].angle-seg[tmp-1].angle))
            seg[tmp++]=seg[i];
    n=tmp;
    Segment deq[N];
    deq[0]=seg[0];deq[1]=seg[1];
    int head=0,tail=1;
    for(int i=2;i<n;i++){
        while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
        while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
        deq[++tail]=seg[i];
    }
    while(head<tail&&xmul(deq[head].s,deq[head].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
    while(head<tail&&xmul(deq[tail].s,deq[tail].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
    if(head==tail) return;
    m=0;
    for(int i=head;i<tail;i++)
        p[m++]=Get_Intersect(deq[i],deq[i+1]);
    if(tail>head+1)
        p[m++]=Get_Intersect(deq[head],deq[tail]);
}
double Get_area(Point p[],int &n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=xmul(p[0],p[i],p[i+1]);
    return fabs(area)/2.0;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        seg[0].s.x=0;seg[0].s.y=0;seg[0].e.x=10000;seg[0].e.y=0;seg[0].get_angle();
        seg[1].s.x=10000;seg[1].s.y=0;seg[1].e.x=10000;seg[1].e.y=10000;seg[1].get_angle();
        seg[2].s.x=10000;seg[2].s.y=10000;seg[2].e.x=0;seg[2].e.y=10000;seg[2].get_angle();
        seg[3].s.x=0;seg[3].s.y=10000;seg[3].e.x=0;seg[3].e.y=0;seg[3].get_angle();
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&seg[i+4].s.x,&seg[i+4].s.y,&seg[i+4].e.x,&seg[i+4].e.y);
            seg[i+4].get_angle();
        }
        HalfPlaneIntersect(seg,n+4);
        printf("%.1f\n",Get_area(p,m));
    }
    return 0;
}
