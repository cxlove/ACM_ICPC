#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
using namespace std;
struct temp{
    int u,v,w;
}a[3][10005],tmp;
struct node{
    int v,val,next;
}edge[100005],e[100005];
int n,m,idx,qd,zd,d[100005];
int start[2505],temp_start[2505];
int num[105],p1,p2,p3;
void _addedge(int u,int v,int val){
    edge[idx].v=v;edge[idx].val=val;
    edge[idx].next=start[u];start[u]=idx++;
}
void addedge(int u,int v,int val){
    _addedge(u,v,val);
    _addedge(v,u,0);
}
bool bfs(){
    queue<int>que;
    while(!que.empty())
        que.pop();
    que.push(qd);
    memset(d,-1,sizeof(d));
    d[qd]=0;
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int i=start[v];i!=-1;i=edge[i].next){
            int j=edge[i].v;
            if(edge[i].val&&d[j]==-1){
                que.push(j);
                d[j]=d[v]+1;
            }
        }
    }
    return d[zd]!=-1;
}
int dfs(int u,int cur_flow){
    if(u==zd)
        return cur_flow;
    int temp=cur_flow;
    for(int i=start[u];i!=-1;i=edge[i].next){
        int j=edge[i].v;
        if(edge[i].val&&d[j]==d[u]+1){
            int f=dfs(j,min(temp,edge[i].val));
            edge[i].val-=f;
            edge[i^1].val+=f;
            temp-=f;
        }
    }
    return cur_flow-temp;
}
int dinic(){
    int ans=0,cur_flow;
    while(bfs())
        while(cur_flow=dfs(qd,inf))
            ans+=cur_flow;
    return ans;
}
void debug(){
    for(int i=0;i<idx;i++)
        printf("%d %d %d\n",edge[i].v,edge[i].val,edge[i].next);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        p1=p2=p3=0;
        for(int i=0;i<m;i++){
            int p;
            scanf("%d%d%d%d",&tmp.u,&tmp.v,&tmp.w,&p);
            if(p<0)
                a[0][p1++]=tmp;
            else if(p==0)
                a[1][p2++]=tmp;
            else
                a[2][p3++]=tmp;
        }
        int min_cost=inf,max_val=-inf;
        qd=0;zd=n+1;
        idx=0;
        memset(start,-1,sizeof(start));
        for(int j=1;j<=n;j++)
            addedge(0,j,num[j]);
        for(int j=0;j<p2;j++)
            addedge(a[1][j].u,a[1][j].v,inf);
        for(int j=0;j<p1;j++){
            addedge(a[0][j].u,a[0][j].v,inf);
               addedge(a[0][j].u,zd,a[0][j].w);
        }
        int pos_bridge[20];
        for(int j=0;j<p3;j++){
            pos_bridge[j]=idx;
            addedge(a[2][j].u,a[2][j].v,1);

        }
        memcpy(e,edge,idx*sizeof(node));
        memcpy(temp_start,start,idx*sizeof(int));
        int cnt=idx;
        for(int i=0;i<(1<<p3);i++){
            int cost=0;
            memcpy(edge,e,cnt*sizeof(node));
            memcpy(start,temp_start,cnt*sizeof(int));    
            for(int j=0;j<p3;j++)
                if(i&(1<<j)){
                    cost+=a[2][j].w;
                    edge[pos_bridge[j]].val=inf;
                }
            int val=dinic();
            if(val>max_val){
                max_val=val;
                min_cost=cost;
            }
            else if(val==max_val&&cost<min_cost){
                min_cost=cost;
                max_val=val;
            }
        }
        if(max_val<=0)
            printf("Poor Heaven Empire\n");
        else
            printf("%d %d\n",max_val,min_cost);
    }
    return 0;
}