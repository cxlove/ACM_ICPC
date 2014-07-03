#include<iostream>
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
#include<ctime>
#define LL long long
#define eps 1e-8
#define inf 999999.0
#define zero(a) abs(a)<eps
#define N 20
#define MOD 100000007
#define pi acos(-1.0)
using namespace std;
struct Point{
    int x,y;
    Point(){}
   // Point(double tx,double ty){x=tx;y=ty;}
}t,q;
vector<Point >p;
int n;
double r;
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dist(Point p1,Point p2){
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
    while(scanf("%d%d%lf",&q.x,&q.y,&r)!=EOF){
        if(r<0) break;
        scanf("%d",&n);
        p.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&t.x,&t.y);
            if(dist(t,q)<=r*r+eps) p.push_back(t);
        }
        int ans=0;
        for(int i=0;i<p.size();i++){
            int cnt=0;
            for(int j=0;j<p.size();j++)
                if(xmul(p[i],q,p[j])<=0)
                    cnt++;
            if(2*cnt<p.size()) cnt=p.size()-cnt;
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}



