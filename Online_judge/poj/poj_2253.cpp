#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
using namespace std;
const int N = 205;
struct Point{
    int x,y;
}p[N];
int n;
double dist(Point p1,Point p2){
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}
bool check(double mid){
    bool vis[N];
    memset(vis,false,sizeof(vis));
    queue<int>que;
    que.push(0);
    vis[0]=true;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(u==1) return true;
        for(int i=0;i<n;i++){
            if(vis[i]||i==u) continue;
            if(dist(p[i],p[u])<=mid){
                que.push(i);
                vis[i]=true;
            }
        }
    }
    return false;
}
int main(){
    int cas=0;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        double low=0,high=dist(p[0],p[1]),mid,ans=high;
        while(high-low>1e-5){
            mid=(low+high)/2.0;
            if(check(mid)) high=mid,ans=mid;
            else low=mid;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cas,ans);
    }
    return 0;
}