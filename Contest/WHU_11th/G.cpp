#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define test puts("OK");
using namespace std;
const int N = 45;
int n,m,pre[N];
int cost[N];
struct Node{
    int k,idx;
    int a[N];
}g[N];
bool cmp(int a,int b){
    return cost[a]<cost[b];
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&cost[i]);
        for(int i=0;i<n;i++){
            g[i].idx=0;
            scanf("%d",&g[i].k);
            for(int j=0;j<g[i].k;j++)
                scanf("%d",&g[i].a[j]);
            sort(g[i].a,g[i].a+g[i].k,cmp);
        }
        int now=0,ans=0;
        memset(pre,0,sizeof(pre));
        for(int T=0;T<20;T++){
            for(int i=0;i<n;i++){
                if(g[i].k==g[i].idx) continue;
                now+=cost[g[i].a[g[i].idx++]];
                ans+=max(0,now-pre[i]);
                pre[i]=max(pre[i],now+20);
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}