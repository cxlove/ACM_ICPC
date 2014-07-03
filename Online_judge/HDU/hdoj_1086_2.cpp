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
}s[105];
int n;
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool across(Segment s1,Segment s2){
    if(max(s1.a.x,s1.b.x)>=min(s2.a.x,s2.b.x)&&max(s2.a.x,s2.b.x)>=min(s1.a.x,s1.b.x)
        &&max(s1.a.y,s1.b.y)>=min(s2.a.y,s2.b.y)&&max(s2.a.y,s2.b.y)>=min(s1.a.y,s1.b.y))
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
        if(zero(xmul(p[i],p[i+1],cen))) return false;
        if(zero(p[i].y-p[i+1].y)) continue;
        if(zero(xmul(s.a,s.b,p[i]))){
            if(p[i].y>p[i+1].y) cnt++;
        }
        else if(zero(xmul(s.a,s.b,p[i+1]))){
            if(p[i+1].y>p[i].y) cnt++;
        }
        else if(across(s,e))
            cnt++;
    }
    return (cnt&1?true:false);
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(across(s[i],s[j]))
                    cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
