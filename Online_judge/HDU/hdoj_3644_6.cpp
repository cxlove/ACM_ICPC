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
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<30
#define N 20
#define pi acos(-1.0)
using namespace std;
struct Point{
    double x,y;
    double val;
}p[100],tp[100],pre,cur;
struct Segment{
    Point a,b;
};
int n;
inline double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
inline double Dist_Point_Seg(Point p,Point a,Point b){
    Point t=p;
    t.x+=a.y-b.y;t.y+=b.x-a.x;
    if(xmul(a,t,p)*xmul(b,t,p)>eps)
        return dist(p,a)+eps<dist(p,b)?dist(p,a):dist(p,b);
    else
        return fabs(xmul(p,a,b))/dist(a,b);
}
inline bool online(Point p1,Point p2,Point p){
    if(zero(xmul(p1,p2,p))&&((p.x-p1.x)*(p.x-p2.x)<eps&&(p.y-p1.y)*(p.y-p2.y)<eps))
        return true;
    return false;
}
inline bool across(Segment s1,Segment s2){
    if(xmul(s1.a,s1.b,s2.a)*xmul(s1.a,s1.b,s2.b)<eps)
        if(xmul(s2.a,s2.b,s1.a)*xmul(s2.a,s2.b,s1.b)<eps)
            return true;
    return false;
}
inline bool Parallel(Segment s1,Segment s2){
    return zero((s1.a.x-s1.b.x)*(s2.a.y-s2.b.y)-(s2.a.x-s2.b.x)*(s1.a.y-s1.b.y));
}
inline bool In_Polygon(Point cen){
    int cnt=0;
    Segment s,e;
    s.a=cen;s.b.y=cen.y;s.b.x=20000.0;
    for(int i=0;i<n;i++){
        e.a=p[i];e.b=p[i+1];
        if(online(p[i],p[i+1],cen)) return false;
        if(zero(p[i].y-p[i+1].y)) continue;
        if(online(s.a,s.b,p[i])){
            if(p[i].y>p[i+1].y) cnt++;
        }
        else if(online(s.a,s.b,p[i+1])){
            if(p[i+1].y>p[i].y) cnt++;
        }
        else if(across(s,e))
            cnt++;
    }
    return cnt&1;
}
inline void Get_Min_Dist(Point &cur){
    double ret=inf;
    for(int i=0;i<n;i++)
       ret=min(ret,Dist_Point_Seg(cur,p[i],p[i+1]));
    cur.val=ret;
}
int main(){
    double r,best[105];
    srand(time(NULL));
    while(scanf("%d",&n)!=EOF&&n){
        double maxx=0,maxy=0,minx=inf,miny=inf;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            maxx = maxx>p[i].x?maxx:p[i].x;
            maxy = maxy>p[i].y?maxy:p[i].y;
            minx = minx<p[i].x?minx:p[i].x;
            miny = miny<p[i].y?miny:p[i].y;
        }
        p[n]=p[0];
        scanf("%lf",&r);
        int m=min(n,N);
        for(int i=0;i<n;i++){
            tp[i].x=(p[i].x+p[i+1].x)/2;
            tp[i].y=(p[i].y+p[i+1].y)/2;
            tp[i].val=0;
        }
        double step=sqrt((maxx-minx)*(maxx-minx)+(maxy-miny)*(maxy-miny))/2;
        bool flag=false;
        while(step>1e-3&&!flag){
            for(int i=0;i<m&&!flag;i++){
                for(int j=0;j<5&&!flag;j++){
                    double angle=rand();
                    cur.x=tp[i].x+step*cos(angle);
                    cur.y=tp[i].y+step*sin(angle);
                    if(!In_Polygon(cur)) continue;
                    Get_Min_Dist(cur);
                    if(cur.val+1e-3>tp[i].val){
                        tp[i]=cur;
                        if(cur.val+1e-3>r) flag=true;
                    }
                }
            }
            step*=0.88;
        }
        puts(flag?"Yes":"No");
    }
    return 0;
}
