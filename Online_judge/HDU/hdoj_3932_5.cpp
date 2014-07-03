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
#define eps 1e-6
#define inf 999999.0
#define zero(a) fabs(a)<eps
#define N 20
#define pi acos(-1.0)
using namespace std;
struct Point{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}p[1005],tp[N],pre,cur;
double X,Y,best[N];
int n;
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Get_Dist(Point cen){
    double ret=0;
    for(int i=0;i<n;i++)
        ret=max(ret,dist(p[i],cen));
    return ret;
}
Point Get_Rand(double X,double Y){
    return Point((rand()%1000+1)/1000.0*X,(rand()%1000+1)/1000.0*Y);
}
int main(){
    srand(time(NULL));
    while(scanf("%lf%lf%d",&X,&Y,&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=0;i<N;i++){
            tp[i]=Get_Rand(X,Y);
            best[i]=Get_Dist(tp[i]);
        }
        double step=max(X,Y);
        while(step>0.001){
            for(int i=0;i<N;i++){
                pre=tp[i];
                for(int j=0;j<30;j++){
                    double angle=(rand()%1000+1)/1000.0*2*pi;
                    cur.x=pre.x+cos(angle)*step;
                    cur.y=pre.y+sin(angle)*step;
                    double dis=Get_Dist(cur);
                    if(dis<best[i]+eps){
                        best[i]=dis;
                        tp[i]=cur;
                    }
                }
            }
            step*=0.9;
        }
        double ans=inf;
        int idx;
        for(int i=0;i<N;i++)
            if(best[i]<ans){
                ans=best[i];
                idx=i;
            }
        printf("(%.1f,%.1f).\n%.1f\n",tp[idx].x,tp[idx].y,ans);
    }
    return 0;
}



