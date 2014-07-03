#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
struct Node{
    int x,y,v,t;
}a[205];
struct stone{
    int v,t;
}tmp;
vector<stone>vv;
int n,m;
bool cmp(Node n1,Node n2){
    return (n1.x*n1.x+n1.y*n1.y)<(n2.x*n2.x+n2.y*n2.y);
}
int dp[40005];
int main(){
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].t,&a[i].v);
        sort(a,a+n,cmp);
        memset(dp,0,sizeof(dp));
        bool flag[205];
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n;i++){
            if(flag[i])  continue;
            tmp.v=a[i].v;
            tmp.t=a[i].t;
            vv.clear();
            vv.push_back(tmp);
            flag[i]=true;
            for(int j=i+1;j<n;j++){
                if(!flag[j]&&(a[j].x*a[i].y==a[i].x*a[j].y)){
                        tmp.v+=a[j].v;
                        tmp.t+=a[j].t;
                        vv.push_back(tmp);
                        flag[j]=true;
                }
            }
            for(int j=m;j>=0;j--)
                for(int k=0;k<vv.size();k++)
                     if(j>=vv[k].t)
                         dp[j]=max(dp[j],dp[j-vv[k].t]+vv[k].v);
        }
        int ans=0;
        for(int i=0;i<=m;i++)
            ans=max(ans,dp[i]);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
