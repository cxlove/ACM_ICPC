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
#define eps 1e-6
#define inf 1ll<<50
#define zero(a) fabs(a)<eps
#define N 20005
using namespace std;
struct Point{
    double x,y;
}p[105],cur,pre;
int n;
int way[4][2]={0,1,0,-1,1,0,-1,0};
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double get_dist(Point cen){
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=dist(cen,p[i]);
    return sum;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        pre.x=0;pre.y=0;
        double step=100,best=get_dist(pre);
        while(step>0.2){
            bool ok=true;
            while(ok){
                ok=false;
                for(int i=0;i<4;i++){
                    cur.x=way[i][0]*step+pre.x;
                    cur.y=way[i][1]*step+pre.y;
                    double dis=get_dist(cur);
                    if(dis<best){best=dis;pre=cur;ok=true;}
                }
            }
            step/=2.0;
        }
        printf("%d\n",(int)(best+0.5)*100/100);
    }
    return 0;
}










