
/*
ID:cxlove
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<25
using namespace std;
struct matrix{
    int a[80][80];
}mat[100];
int n,m,dist[105][105];
bool Init(){
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)
        return false;
    for(int k=1;k<=n;k++)
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&mat[k].a[i][j]);
    return true;
}
void check(int A,int B){
    matrix ans;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            ans.a[i][j]=0;
            for(int k=0;k<m;k++)
                ans.a[i][j]+=mat[A].a[i][k]*mat[B].a[k][j];
        }
    for(int k=1;k<=n;k++){
        bool flag=true;
        if(k==A||k==B)
            continue;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++){
                if(ans.a[i][j]!=mat[k].a[i][j]){
                    flag=false;
                    break;
                }
            }
        if(flag)
            dist[A][k]=1;
    }
}
void MakeGraph(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                check(i,j);
}
void Floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
void slove(){
    int q,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&u,&v);
        if(dist[u][v]==inf)
            printf("Sorry\n");
        else
            printf("%d\n",dist[u][v]);
    }
}
int main(){
    while(Init()){
        MakeGraph();
        Floyd();
        slove();
    }
    return 0;
}

