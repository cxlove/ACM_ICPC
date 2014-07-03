/*
ID:cxlove
PROB:POJ 2135 Farm Tour
DATA:2012.1.22
HINT:最小费用最大流
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Max 1010
#define inf 1<<30
using namespace std;
struct node{
	int v,w,f,c,next;
}edge[1000000];
int idx,n,m;
int pre[Max],start[Max],vis[Max],dist[Max];
void _add(int v,int w,int f,int c){
	edge[idx].v=v;edge[idx].w=w;edge[idx].c=c;edge[idx].f=f;
	edge[idx].next=start[v];start[v]=idx++;
}
void add(int v,int w,int f,int c){
	_add(v,w,f,c);
	_add(w,v,0,-c);
}
bool spfa(int s,int e,int n){
	queue<int >que;
	for(int i=0;i<n;i++){
		pre[i]=-1;dist[i]=inf;vis[i]=0;
	}
	dist[s]=0;vis[s]=1;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		vis[v]=0;
		for(int i=start[v];i!=-1;i=edge[i].next)
			if(edge[i].f){
				int w=edge[i].w;
				if(dist[w]>dist[v]+edge[i].c){
					dist[w]=dist[v]+edge[i].c;
					pre[w]=i;
					if(!vis[w]){
						vis[w]=1;
						que.push(w);
					}
				}
			}
	}
	return dist[e]!=inf;
}
int MaxCostFlow(int s,int e,int n){	
	int flow=inf,ans=0;
	while(spfa(s,e,n)){
		ans+=dist[e];
		for(int i=pre[e];i!=-1;i=pre[edge[i].v])
			flow=min(flow,edge[i].f);	
		for(int i=pre[e];i!=-1;i=pre[edge[i].v]){		 
			edge[i].f-=flow; 			
			edge[i^1].f+=flow;		
		} 
	} 
	return ans;
} 
void Init(){
	scanf("%d%d",&n,&m);
	idx=0;
	memset(start,-1,sizeof(start));
	for(int i=0;i<m;i++){
		int v,w,c;
		scanf("%d%d%d",&v,&w,&c);
		add(v,w,1,c);
		add(w,v,1,c);
	}
	add(0,1,2,0);
	add(n,n+1,2,0);
}
int main(){
	Init();
	printf("%d\n",MaxCostFlow(0,n+1,n+2));
	return 0;
}