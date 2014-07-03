#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int sg[1005];
int get_sg(int n,int m){
    if(sg[n]!=-1)
        return sg[n];
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=(n-m);i++){
        sg[i]=get_sg(i,m);
        sg[n-i-m]=get_sg(n-i-m,m);
        vis[sg[i]^sg[n-i-m]]=1;
    }
    for(int i=0;;i++)
        if(vis[i]==0)
            return i;
}
int main(){
    int t,n,m,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Case #%d: ",++cas);
        if(n<m){
            puts("abcdxyzk");
            continue;
        }
        memset(sg,-1,sizeof(sg));
        if(sg[n-m]==-1)
            sg[n-m]=get_sg(n-m,m);
        if(sg[n-m]==0)
            puts("aekdycoin");
        else
            puts("abcdxyzk");
    }
    return 0;
}
