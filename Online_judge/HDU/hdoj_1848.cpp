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
int s[15]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
int get_sg(int n){
    if(sg[n]!=-1)
        return sg[n];
    int vis[105];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<15&&s[i]<=n;i++){
        sg[n-s[i]]=get_sg(n-s[i]);
        vis[sg[n-s[i]]]=1;
    }
    for(int i=0;;i++)
        if(!vis[i])
            return i;
}
int main(){
    int n,m,p;
    memset(sg,-1,sizeof(sg));
    for(int i=1000;i>=0;i--)
        if(sg[i]==-1)
            sg[i]=get_sg(i);
    while(scanf("%d%d%d",&n,&m,&p)!=EOF&&n+m+p)
        if(sg[n]^sg[m]^sg[p])
            puts("Fibo");
        else
            puts("Nacci");
    return 0;
}