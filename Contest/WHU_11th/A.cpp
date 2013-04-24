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
const int N = 10005 ;
struct Edge{
    int u,v,w;
    bool operator<(const Edge e)const{
        return w>e.w;
    }
}e[N];
int n,t,k;
int pre[N],r[N];
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&t,&k);
        for(int i=0;i<n-1;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        for(int i=1;i<=n;i++)
            pre[i]=i,r[i]=0;
        sort(e,e+n-1);
        int ans=0;
        for(int i=0;i<t;i++){
            int u;scanf("%d",&u);
            r[u]=1;
        }
        for(int i=0;i<n-1;i++){
            int fa=find(e[i].u),fb=find(e[i].v);
            int w=e[i].w;
            if(r[fa]&&r[fb]){
                if(t>k+1) pre[fa]=fb,r[fb]+=r[fa],t--;
                else ans+=w; 
            }
            else pre[fa]=fb,r[fb]+=r[fa];
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}