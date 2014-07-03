#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N (1<<7)+5
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
double x,y;
int d;
double dist(double x1,double y1,int x2,int y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
    int cas=0;
    while(scanf("%d%lf%lf",&d,&x,&y)!=EOF&&!zero(d+x+y)){
        bool flag=false;
        while(1){
            int X,Y;
            scanf("%d%d",&X,&Y);
            if(X==-1&&Y==-1) break;
            if(flag) continue;
            if(dist(x,y,X,Y)+eps<=d+1){
                flag=true;
                printf("Firefly %d caught at (%d,%d)\n",++cas,X,Y);
            }
            double angle=atan2(Y-y,X-x);
            x=x+d*cos(angle);y=y+d*sin(angle);
        }
        if(!flag) printf("Firefly %d not caught\n",++cas);
    }
}
