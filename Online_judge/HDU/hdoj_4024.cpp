#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define MOD 1000000007
using namespace std;
double xx,x2,yy,y2,lx,ly,vd,vb,l;
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xx,&yy,&x2,&y2,&lx,&ly,&vd,&vb,&l)!=EOF){
        if(zero(vd)&&zero(vb)) break;
        double low=0,high=inf,mid;
        while(fabs(high-low)>1e-7){
            mid=(low+high)/2.0;
        //    cout<<mid<<endl;
            double tx=xx+mid*lx;
            double ty=yy+mid*ly;
            double t=l*1.0/vb;
        //    cout<<(mid-t)*vd+l<<" "<<dist(tx,ty,x2,y2)<<endl;
            if(mid>=t&&dist(tx,ty,x2,y2)+(mid-t)*vd>=l&&(mid-t)*vd+l>=dist(tx,ty,x2,y2)) high=mid;
            else low=mid;
        }
        printf("%.3f %.3f\n",l,mid);
    }
    return 0;
}
