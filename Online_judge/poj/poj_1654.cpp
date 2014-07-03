#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#define LL __int64
#define eps 1e-7
#define N 2000000
#define MOD 1000000007
#define inf 1<<30
#define zero(a) (fabs((double)(a))<eps)
using namespace std;
struct Point{
    int x,y;
}p[1000005];
int n;
int way[9][2]={1,-1,1,0,1,1,0,-1,0,0,0,1,-1,-1,-1,0,-1,1};
LL xmul(Point p0,Point p1,Point p2){
    return (LL)(p1.x-p0.x)*(p2.y-p0.y)-(LL)(p2.x-p0.x)*(p1.y-p0.y);
}
LL area(){
    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=xmul(p[0],p[i],p[i+1]);
    return ans<0?-ans:ans;
}
char str[1000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        p[0].x=0;p[0].y=0;
        for(n=0;str[n+1];n++){
            int dir=str[n]-'1';
            p[n+1].x=p[n].x+way[dir][0];
            p[n+1].y=p[n].y+way[dir][1];
        }
        LL ans=area();
        if(ans%2==0) printf("%I64d\n",ans/2);
        else printf("%I64d.5\n",ans/2);
    }
    return 0;
}

