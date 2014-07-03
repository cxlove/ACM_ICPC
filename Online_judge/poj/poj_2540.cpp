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
#define inf 10000
#define zero(a) fabs(a)<eps
#define N 20005
using namespace std;
struct Point{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}pre,cur,p[105],tp[105];
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
void Get_midperpendicular(Point p1,Point p2,double &a,double &b,double &c){
    if(zero(p1.x-p2.x)) a=0,b=1;
    else if(zero(p1.y-p2.y)) a=1,b=0;
    else b=p2.y-p1.y,a=p2.x-p1.x;
    c=-a*(p2.x+p1.x)/2-b*(p2.y+p1.y)/2;
}
Point Get_Intersection(Point p1,Point p2,double a,double b,double c){
    double u=fabs(a*p1.x+b*p1.y+c),v=fabs(a*p2.x+b*p2.y+c);
    return Point((p1.x*v+p2.x*u)/(u+v),(p1.y*v+p2.y*u)/(u+v));
}
void Cut(double a,double b,double c,Point p[],int &cnt){
    int tmp=0;
    for(int i=1;i<=cnt;i++){
        if(a*p[i].x+b*p[i].y+c>-eps) tp[++tmp]=p[i];
        else{
            if(a*p[i-1].x+b*p[i-1].y+c>eps)
                tp[++tmp]=Get_Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x+b*p[i+1].y+c>eps)
                tp[++tmp]=Get_Intersection(p[i+1],p[i],a,b,c);
        }
    }
    for(int i=1;i<=tmp;i++)
        p[i]=tp[i];
    p[0]=tp[tmp];p[tmp+1]=p[1];
    cnt=tmp;
}
double Get_Area(Point p[],int n){
    double area=0;
    for(int i=2;i<n;i++)
        area+=xmul(p[1],p[i],p[i+1]);
    return fabs(area)/2.0;
}
int main(){
    pre.x=pre.y=0;
    char str[10];
    p[1].x=0;p[1].y=0;
    p[2].x=0;p[2].y=10;
    p[3].x=10;p[3].y=10;
    p[4].x=10;p[4].y=0;
    p[0]=p[4];p[5]=p[1];
    int cnt=4;
    double area=1.0;
    while(scanf("%lf%lf%s",&cur.x,&cur.y,str)!=EOF){
        double a,b,c;
        Get_midperpendicular(pre,cur,a,b,c);
        if(strcmp(str,"Colder")==0){
            if(a*pre.x+b*pre.y+c<-eps){a=-a;b=-b;c=-c;}
        }
        else if(strcmp(str,"Hotter")==0){
            if(a*cur.x+b*cur.y+c<-eps){a=-a;b=-b;c=-c;}
        }
        else
            area=0;
        if(zero(area)){
            printf("0.00\n");
            continue;
        }
        Cut(a,b,c,p,cnt);
        area=Get_Area(p,cnt);
        printf("%.2f\n",area);
        pre=cur;
    }
    return 0;
}



