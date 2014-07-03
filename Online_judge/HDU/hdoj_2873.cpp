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
int sg[55][55];
int get_sg(int x,int y){
    int vis[1000];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            vis[sg[x][j]^sg[i][y]]=1;
    for(int i=0;;i++)
        if(vis[i]==0)
            return i;
}
int main(){
    for(int i=0;i<50;i++)
        sg[0][i]=i,sg[i][0]=i;
    for(int i=1;i<50;i++)
        for(int j=1;j<50;j++)
            sg[i][j]=get_sg(i,j);
    int n,m;
    char str[100][100];
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        int ret=0;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='#')
                    ret^=sg[i][j];
        }
        if(ret)
            printf("John\n");
        else
            printf("Jack\n");
    }
    return 0;
}