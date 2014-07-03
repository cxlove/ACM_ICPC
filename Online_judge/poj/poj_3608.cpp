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
#define pi acos(-1.0)
using namespace std;
struct Point{
    double x,y;
}p[10005],q[10005],pos;
vector<Point >s1,s2;
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//Graham_scan求凸包
bool cmp(Point p1,Point p2){
    if(xmul(pos,p1,p2)>eps)  return true;
    else if(zero(xmul(pos,p1,p2))&&dist(pos,p1)<dist(pos,p2))  return true;
    return false;
}
void Graham_scan(vector<Point>&s,Point p[],int n){
    for(int i=1;i<n;i++)
        if(p[i].y<p[0].y||(zero(p[i].y==p[0].y)&&p[i].x<p[0].x))
            swap(p[i],p[0]);
    pos=p[0];
    sort(p+1,p+n,cmp);
    s.clear();
    s.push_back(p[0]);s.push_back(p[1]);s.push_back(p[2]);
    for(int i=3;i<n;i++){
        while(s.size()>=2&&xmul(s[s.size()-2],s[s.size()-1],p[i])<eps) s.pop_back();
        s.push_back(p[i]);
    }
}
double Get_angle(Point a1,Point b1,Point a2,Point b2){
    Point t;
    t.x=a2.x-(b2.x-a1.x);
    t.y=a2.y-(b2.y-a1.y);
    return xmul(a1,b1,t);
}
double Dist_Point_Seg(Point p,Point a,Point b){
    Point t=p;
    t.x+=a.y-b.y;t.y+=b.x-a.x;
    if(xmul(a,t,p)*xmul(b,t,p)>eps)
        return dist(p,a)+eps<dist(p,b)?dist(p,a):dist(p,b);
        //min(dist(p,a),dist(p,b));
    else
        return fabs(xmul(p,a,b))/dist(a,b);
}
//求面积，正为顺时针，和叉积写法有关
double Get_area(vector<Point>p,int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=xmul(p[0],p[i],p[i+1]);
    return -area/2.0;
}
//改变顺序
void Change_dir(vector<Point>&p,int n){
    for(int i=0;i<n/2;i++)
        swap(p[i],p[n-1-i]);
}
double Min_Dist_Two_Polygons(vector<Point>s1,vector<Point>s2){
    int na=s1.size(),nb=s2.size();
    int lp=0,lq=0;
    //if(Get_area(s1,na)>eps) Change_dir(s1,na);
    //if(Get_area(s2,nb)>eps) Change_dir(s2,nb);
    for(int i=1;i<na;i++)
        if(s1[i].y<s1[lp].y||(zero(s1[i].y-s1[lp].y)&&s1[i].x<s1[lp].x))
           lp=i;
    for(int i=1;i<nb;i++)
        if(s2[i].y>s2[lq].y||(zero(s2[i].y-s2[lq].y)&&s2[i].x>s2[lq].x))
           lq=i;
    s1.push_back(s1[0]);s2.push_back(s2[0]);
    double ans=dist(s1[lp],s2[lq]);
    int tp=lp,tq=lq;
    do{
        double angle=Get_angle(s1[tp],s1[tp+1],s2[tq],s2[tq+1]);
        //和两个凸包的边都重合
        if(zero(angle)){
            ans=min(ans,Dist_Point_Seg(s1[tp],s2[tq],s2[tq+1]));
            ans=min(ans,Dist_Point_Seg(s1[tp+1],s2[tq],s2[tq+1]));
            ans=min(ans,Dist_Point_Seg(s2[tq],s1[tp],s1[tp+1]));
            ans=min(ans,Dist_Point_Seg(s2[tq+1],s1[tp],s1[tp+1]));
            tp=(tp+1)%na;tq=(tq+1)%nb;
        }
        else{
            //和第二个凸包的边重合
            if(angle<-eps){
                ans=min(ans,Dist_Point_Seg(s1[tp],s2[tq],s2[tq+1]));
                tq=(tq+1)%nb;
            }
            //和第一个凸包的边重合
            else{
                ans=min(ans,Dist_Point_Seg(s2[tq],s1[tp],s1[tp+1]));
                tp=(tp+1)%na;
            }
        }
    }while(!(lp==tp&&lq==tq));
    return ans;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        Graham_scan(s1,p,n);
        for(int i=0;i<m;i++)
            scanf("%lf%lf",&q[i].x,&q[i].y);
        Graham_scan(s2,q,m);
        printf("%.5f\n",Min_Dist_Two_Polygons(s1,s2));
    }
    return 0;
}



