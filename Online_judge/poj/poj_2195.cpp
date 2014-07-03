/*
ID:cxlove
PROB:aoj 171 going home
DATA:2012.1.23
HINT:最小费用最大流
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct Point{
	int x,y;
}man[1005],house[1005];
struct node{
	int u,v,f,c,next;
}edge[500005];
int man_num,house_num,n,m,idx;
int start[1005],dist[1005],vis[1005],pre[1005];
char  str[105][105];
int Abs(int a){
	return a<0?-a:a;
}
bool Init(){
	scanf("%d%d",&n,&m);
	if(n==0&m==0)
		return false;
	man_num=0;house_num=0;
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
		for(int j=0;j<m;j++)
			if(str[i][j]=='H'){
				house_num++;
				house[house_num].x=i;
				house[house_num].y=j;				
			}
			else if(str[i][j]=='m'){
				man_num++;
				man[man_num].x=i;
				man[man_num].y=j;			
			}
	}
	return true;
}
void _addedge(int u,int v,int flow,int cost){
	edge[idx].u=u;edge[idx].v=v;edge[idx].f=flow;edge[idx].c=cost;
	edge[idx].next=start[u];start[u]=idx++;
}
void addedge(int u,int v,int flow,int cost){
	_addedge(u,v,flow,cost);
	_addedge(v,u,0,-cost);
}
int Distance(int i,int j){
	return Abs(man[i].x-house[j].x)+Abs(man[i].y-house[j].y);
}
void bulidmap(){
	idx=0;
	memset(start,-1,sizeof(start));
	for(int i=1;i<=man_num;i++)
		addedge(0,i,1,0);
	for(int i=1;i<=house_num;i++)
		addedge(i+man_num,man_num+house_num+1,1,0);
	for(int i=1;i<=man_num;i++)
		for(int j=1;j<=house_num;j++)
			addedge(i,j+man_num,1,Distance(i,j));
}
bool spfa(int s,int e,int n){
	queue<int>que;
	for(int i=0;i<n;i++){
		dist[i]=inf;vis[i]=0;pre[i]=-1;
	}
	que.push(s);dist[s]=0;vis[s]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		vis[u]=0;
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
		ans+=dist[e];
		for(int i=pre[e];i!=-1;i=pre[edge[i].u])
			flow=min(flow,edge[i].f);
		for(int i=pre[e];i!=-1;i=pre[edge[i].u]){
			edge[i].f-=flow;
			edge[i^1].f+=flow;
		}
	}
	return ans;
}
int main(){
	while(Init()){
		bulidmap();
		printf("%d\n",MaxCostFlow(0,man_num+house_num+1,man_num+house_num+2));
	}
	return 0;
}

