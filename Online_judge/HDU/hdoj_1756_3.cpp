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
#define zero(a) fabs(a)<eps
#define inf 1<<30
#define pi acos(-1.0)
using namespace std;
struct Point{
    double x,y;
}p[105],tp[105],pre,cur;
struct Segment{
    Point a,b;
};
int n;
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool online(Point p1,Point p2,Point p){
    if(zero(xmul(p1,p2,p))&&((p.x-p1.x)*(p.x-p2.x)<eps&&(p.y-p1.y)*(p.y-p2.y)<eps))
        return true;
    return false;
}
bool across(Segment s1,Segment s2){
    if(max(s1.a.x,s1.b.x)>=min(s2.a.x,s2.b.x)+eps&&max(s2.a.x,s2.b.x)>=min(s1.a.x,s1.b.x)+eps
        &&max(s1.a.y,s1.b.y)>=min(s2.a.y,s2.b.y)+eps&&max(s2.a.y,s2.b.y)>=min(s1.a.y,s1.b.y)+eps)
        if(xmul(s1.a,s1.b,s2.a)*xmul(s1.a,s1.b,s2.b)<eps)
            if(xmul(s2.a,s2.b,s1.a)*xmul(s2.a,s2.b,s1.b)<eps)
                return true;
    return false;
}
bool Parallel(Segment s1,Segment s2){
    return zero((s1.a.x-s1.b.x)*(s2.a.y-s2.b.y)-(s2.a.x-s2.b.x)*(s1.a.y-s1.b.y));
}
bool In_Polygon(Point cen){
    int cnt=0;
    Segment s,e;
    s.a=cen;s.b.y=cen.y;s.b.x=20000.0;
    for(int i=0;i<n;i++){
        e.a=p[i];e.b=p[i+1];
        if(online(p[i],p[i+1],cen)) return false;
        if(Parallel(s,e)) continue;
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
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n]=p[0];
        int m,cnt=0;
        scanf("%d",&m);
        while(m--){
            scanf("%lf%lf",&cur.x,&cur.y);
            if(In_Polygon(cur)) puts("Yes");
            else puts("No");
        }
      //  printf("%d\n",cnt);
    }
    return 0;
}
