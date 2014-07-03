/*
ID;cxlove
PROB;poj 3469 Dual Core CPU
DATA;2012.1.24
HINT:dinic
*/
/*
POJ 1273 Drainage Ditches
DINIC练手

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
int n,m;
int d[205];
int flow[205][205]={0};
bool bfs(){
	queue<int >que;
	memset(d,0,sizeof(d));
	que.push(1);
	d[1]=1;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=1;i<=n;i++)
			if(!d[i]&&flow[v][i]>0){
				d[i]=d[v]+1;
				que.push(i);
			}
	}
	return d[n]!=0;
}
int dfs(int u,int cur_flow){
	int temp=cur_flow;
	if(u==n)
		return cur_flow;
	for(int i=1;i<=n;i++)
		if(flow[u][i]>0&&d[i]==d[u]+1){
			int f=dfs(i,min(temp,flow[u][i]));
			flow[u][i]-=f;
			flow[i][u]+=f;
			temp-=f;
		}
	return cur_flow-temp;
}
int main(){
	int cur_flow;
	scanf("%d%d",&m,&n);
	while(m--){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		flow[u][v]+=c;
	}
	int ans=0;
	while(bfs()){
		while(cur_flow=(dfs(1,inf))){
			ans+=cur_flow;
			
		}
	}
	printf("%d\n",ans);
	return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct node{
	int v,val,next;
}edge[1000000];
int n,m,idx,qd,zd,d[100000];
int start[1000000];
void _addedge(int u,int v,int val){
	edge[idx].v=v;edge[idx].val=val;
	edge[idx].next=start[u];start[u]=idx++;
}
void addedge(int u,int v,int val){
	_addedge(u,v,val);
	_addedge(v,u,0);
}
void Init(){
	int a,b,c;
	memset(start,-1,sizeof(start));
	idx=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(0,i+1,a);
		addedge(i+1,n+1,b);
	}
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	qd=0;zd=n+1;
}
bool bfs(){
	queue<int>que;
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
int main(){
	Init();
	printf("%d\n",dinic());
	return 0;
}
