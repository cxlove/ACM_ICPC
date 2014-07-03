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
int n;
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point get_circle(Point p1,Point p2){
    Point mid=Point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(1-dist(p1,mid)*dist(p1,mid));
    return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dist(p[i],p[j])>2.0) continue;
                Point central=get_circle(p[i],p[j]);
                int cnt=0;
            //    printf("%.6f %.6f\n",dist(p[i],central),dist(p[j],central));
                for(int k=0;k<n;k++)
                    if(dist(central,p[k])<1.0+eps)
                        cnt++;
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



