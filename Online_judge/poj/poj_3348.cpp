#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#define LL long long
#define eps 1e-7
#define N 2000000
#define MOD 1000000007
#define inf 1<<30
#define zero(a) (fabs((double)(a))<eps)
using namespace std;
struct Point{
    int x,y,v,l;
}p[10005];
int n;
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
//计算距离
double dist(Point p1,Point p2){
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
//极角排序
bool cmp(Point p1,Point p2){
    if(xmul(p[0],p1,p2)>0) return true;
    else if(zero(xmul(p[0],p1,p2))&&dist(p[0],p1)<dist(p[0],p2)) return true;
    return false;
}
vector<Point>s;
void Graham_scan(){
    for(int i=1;i<n;i++)
        if(p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
            swap(p[0],p[i]);
    sort(p+1,p+n,cmp);
    s.clear();
    s.push_back(p[0]);s.push_back(p[1]);s.push_back(p[2]);
    for(int i=3;i<n;i++){
        while(s.size()>=2&&xmul(s[s.size()-2],s[s.size()-1],p[i])<eps)
            s.pop_back();
        s.push_back(p[i]);
    }
}
double area(){
    double ans=0;
    for(int i=1;i<s.size()-1;i++)
        ans+=xmul(s[0],s[i],s[i+1]);
    return ans/2;
}
int main(){
    int cas=0;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        if(n<2){printf("0\n");continue;}
        Graham_scan();
        printf("%d\n",(int)(area()/50));
    }
    return 0;
}

