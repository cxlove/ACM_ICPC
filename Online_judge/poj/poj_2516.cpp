/*
ID;cxlove
PROB:poj 2516 Minimum Cost
DATA:2012.1.24
HINT:最小费用最大流
*/
#include<iostream>
#include<cstdio>
#include<cstdio>
#include<queue>
#include<cstring>
#define inf 1<<30
using namespace std;
struct node{
	int u,v,f,c,next;
}edge[100000];
int order[50][50],need[50][50];
int path[50][50],idx,start[2000];
int dist[2000],pre[2000],vis[2000];
int n,m,k;
void _addedge(int u,int v,int f,int c){
	edge[idx].u=u;edge[idx].v=v;edge[idx].f=f;
	edge[idx].c=c;edge[idx].next=start[u];start[u]=idx++;
}
void addedge(int u,int v ,int f,int c){
	_addedge(u,v,f,c);
	_addedge(v,u,0,-c);
}
bool spfa(int s,int e,int n){
	queue<int >que;
	for(int i=0;i<n;i++){
		dist[i]=inf;pre[i]=-1;
		vis[i]=0;
	}
	que.push(s);dist[s]=0;vis[s]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();vis[u]=0;
		for(int i=start[u];i!=-1;i=edge[i].next)
			if(edge[i].f){
				int v=edge[i].v;
				if(dist[v]>dist[u]+edge[i].c){
					dist[v]=dist[u]+edge[i].c;
					pre[v]=i;
					if(!vis[v]){
						vis[v]=1;
						que.push(v);
					}
				}
			}
	}	
	return dist[e]!=inf;
}	
int MaxCostFlow(int s,int e,int n){
	int ans=0,flow=inf;
	while(spfa(s,e,n)){	
		for(int i=pre[e];i!=-1;i=pre[edge[i].u])
			flow=min(flow,edge[i].f);
		ans+=dist[e]*flow;
		for(int i=pre[e];i!=-1;i=pre[edge[i].u]){
			edge[i].f-=flow;
			edge[i^1].f+=flow;
		}
	}
	return ans;
}
int main(){
	while(scanf("%d%d%d",&n,&m,&k)){
		int ans=0;
		bool flag=true;
		if(n==0&m==0&&k==0)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<k;j++)
				scanf("%d",&order[i][j]);
		for(int i=0;i<m;i++)
			for(int j=0;j<k;j++)
				scanf("%d",&need[i][j]);
		for(int t=0;t<k;t++){
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					scanf("%d",&path[i][j]);
			idx=0;
			memset(start,-1,sizeof(start));
			for(int i=0;i<m;i++)
				addedge(0,i+1,need[i][t],0);
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					addedge(i+1,j+m+1,need[i][t],path[j][i]);
			for(int i=0;i<n;i++)
				addedge(i+m+1,n+m+1,order[i][t],0);
			int temp=0;
			for(int i=0;i<n;i++)
				temp-=order[i][t];
			for(int i=0;i<m;i++)
				temp+=need[i][t];
			if(temp<0)
				flag=false;
			if(flag)
				ans+=MaxCostFlow(0,n+m+1,n+m+2);
		}
		if(flag)
			printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}
