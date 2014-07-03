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
}p,q;
struct Node{
    double l,r;
}line[505];
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(Node n1,Node n2){
    return n1.l<n2.l;
}
int main(){
    int n;
    double r;
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%lf%lf",&p.x,&p.y);
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf",&q.x,&q.y,&r);
            double d=dist(p,q);
            double a=asin(r/d),b=asin((p.x-q.x)/d);
            double ang1=a+b,ang2=b-a;
         //   cout<<ang1<<" "<<ang2<<endl;
            line[i].l=p.x-p.y*tan(ang1);
            line[i].r=p.x-p.y*tan(ang2);
        }
        sort(line,line+n,cmp);
        double L=line[0].l,R=line[0].r;
        for(int i=1;i<n;i++){
            if(line[i].l>R){
                printf("%.2f %.2f\n",L,R);
                L=line[i].l;R=line[i].r;
            }
            else
                R=max(line[i].r,R);
        }
        printf("%.2f %.2f\n\n",L,R);
    }
    return 0;
}
