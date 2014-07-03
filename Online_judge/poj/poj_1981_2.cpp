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
}p[300];
struct Node{
    double angle;
    bool in;
}arc[180000];
int n,cnt;
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(Node n1,Node n2){
    return n1.angle!=n2.angle?n1.angle<n2.angle:n1.in>n2.in;
}
void MaxCircleCover(){
    int ans=1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(dist(p[i],p[j])>2.0) continue;
            double angle=atan2(p[i].y-p[j].y,p[i].x-p[j].x);
            double phi=acos(dist(p[i],p[j])/2);
            arc[cnt].angle=angle-phi;arc[cnt++].in=true;
            arc[cnt].angle=angle+phi;arc[cnt++].in=false;
        }
        sort(arc,arc+cnt,cmp);
        int tmp=1;
        for(int i=0;i<cnt;i++){
            if(arc[i].in)  tmp++;
            else tmp--;
            ans=max(ans,tmp);
        }
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
            MaxCircleCover();
    }
    return 0;
}
