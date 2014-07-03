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
struct Node{
    int u,v,w,next;
}edge[30000];
int start[105],cnt,n,m,s,val[105],sum,total,dist[105][105];
void addedge(int u,int v,int w){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    edge[cnt].next=start[u];start[u]=cnt++;
}
bool Init(){
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)
        return false;
    memset(start,-1,sizeof(start));
    cnt=0;
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
//void spfa(){
//    bool flag[105];
//    queue<int>que;
//    memset(flag,false,sizeof(flag));
//    for(int i=0;i<=n;i++)
//        dist[i]=inf;
//    que.push(0);
//    dist[0]=0;
//    flag[0]=true;
//    while(!que.empty()){
//        int u=que.front();
//        que.pop();
//        flag[u]=false;
//        for(int i=start[u];i!=-1;i=edge[i].next){
//            int v=edge[i].v,w=edge[i].w;
//            if(dist[v]>dist[u]+w){
//                dist[v]=dist[u]+w;
//                if(!flag[v]){
//                    flag[v]=true;
//                    que.push(v);
//                }
//            }
//        }
//    }
//}
//void DP(){
//    int dp[100001];
//    for(int i=1;i<=n;i++){
//        total+=dist[i];
//        if(dist[i]==inf){
//            printf("impossible\n");
//            return;
//        }
//    }
//    for(int i=0;i<=total;i++)
//        dp[i]=0;
//    for(int i=1;i<=n;i++){
//        for(int j=total;j>=dist[i];j--)
//            dp[j]=max(dp[j],dp[j-dist[i]]+val[i]);
//    }
//    for(int i=1;i<=total;i++)
//        if(dp[i]>=(sum/2+1)){
//            printf("%d\n",i);
//            return ;
//        }
//}
int main(){
    while(Init()){
        MakeGraph();
        Floyd();
        slove();
    }
    return 0;
}