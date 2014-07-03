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
int sg[25];
int get_sg(int n,int l){
    if(sg[n]!=-1)
        return sg[n];
    int vis[105];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=l&&i<=n;i++){
        sg[n-i]=get_sg(n-i,l);
        vis[sg[n-i]]=1;
    }
    for(int i=0;;i++)
        if(!vis[i])
            return i;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ret=0;
        while(n--){
            int m,l;
            scanf("%d%d",&m,&l);
            memset(sg,-1,sizeof(sg));
            sg[m]=get_sg(m,l);
            ret^=sg[m];
        }
        if(!ret)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}