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
int sg[205][205];
int get_sg(int n,int m){
    if(sg[n][m]!=-1)
        return sg[n][m];
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n-i;i++)
        vis[get_sg(i,m)^get_sg(n-i,m)]=1;
    for(int i=2;i<=m-i;i++)
        vis[get_sg(n,i)^get_sg(n,m-i)]=1;
    for(int i=0;;i++)
        if(vis[i]==0)
            return sg[n][m]=i;
}
int main(){
    int n,m;
    memset(sg,-1,sizeof(sg));
  //  sg[2][2]=sg[2][3]=sg[3][2]=0;
    while(scanf("%d%d",&n,&m)!=EOF){

        if(get_sg(n,m))
            printf("WIN\n");
        else
            printf("LOSE\n");
    }
    return 0;
}




