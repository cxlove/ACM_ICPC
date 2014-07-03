#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define LL long long
using namespace std;
vector<int>v[1005];
int sg[1005];
int get_sg(int n){
    if(sg[n]!=-1)
        return sg[n];
    int ret=0;
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<v[n].size();i++){
        int u=v[n][i];
        sg[u]=get_sg(u);
        vis[sg[u]]=1;
    }
    for(int i=0;;i++)
        if(vis[i]==0)
            return sg[n]=i;

}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        memset(sg,-1,sizeof(sg));
        for(int i=0;i<n;i++){
            v[i].clear();
            int k,u;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&u);
                v[i].push_back(u);
            }
        }
        int q,r;
        while(scanf("%d",&q)&&q){
            int ret=0;
            while(q--){
                scanf("%d",&r);
                if(sg[r]==-1)
                    sg[r]=get_sg(r);
                ret^=sg[r];
            }
            if(ret)
                puts("WIN");
            else
                puts("LOSE");
        }
    }
    return 0;
}
