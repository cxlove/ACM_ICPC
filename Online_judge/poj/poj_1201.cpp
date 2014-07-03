/*
ID:cxlove
PROB:AOJ 517 序列
DATA:2012.3.3
HINT:差分约束
*/
/*
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define inf 1<<30
using namespace std;
int mmap[1005][1005],dist[1005];
int dis[1005];
void spfa(int u){
	memset(dis,0,sizeof(dis));
	for(int i=0;i<=1001;i++)
		dist[i]=inf;
	dist[u]=0;
	queue<int>que;
	que.push(u);
	dis[u]=1;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		dis[v]=0;
		for(int i=0;i<=1001;i++){
			if(i==v) continue;
			if(dist[i]>dist[v]+mmap[v][i]){
				dist[i]=dist[v]+mmap[v][i];
				if(!dis[i]){
					dis[i]=1;
					que.push(i);
				}
			}
		}
	}
}
int main(){
	int m;
	scanf("%d",&m);
	for(int i=0;i<=1001;i++)
		for(int j=0;j<=1001;j++)
			mmap[i][j]=inf;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mmap[a-1][b]=-c;
	}
	for(int i=1;i<=1000;i++){
		mmap[i][i+1]=0;
		mmap[i+1][i]=1;
	}
	for(int i=0;i<1001;i++)
		mmap[0][i]=0;
	spfa(0);
	printf("%d\n",-dist[1001]);
	return 0;
}
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define inf 1<<30
using namespace std;
struct node{
	int u,v,w,next;
}edge[500005];
int dist[50005],start[50005];
int dis[50005],cnt;
void addedge(int u,int v,int w){
	edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
	edge[cnt].next=start[u];start[u]=cnt++;
}
void spfa(int u){
	memset(dis,0,sizeof(dis));
	for(int i=0;i<=50001;i++)
		dist[i]=inf;
	dist[u]=0;
	queue<int>que;
	que.push(u);
	dis[u]=1;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		dis[v]=0;
		for(int i=start[v];i!=-1;i=edge[i].next){
			int t=edge[i].v;
			if(t==v) continue;
			if(dist[t]>dist[v]+edge[i].w){
				dist[t]=dist[v]+edge[i].w;
				if(!dis[t]){
					dis[t]=1;
					que.push(t);
				}
			}
		}
	}
}
int main(){
	int m;
	scanf("%d",&m);
	int cnt=0;
	memset(start,-1,sizeof(start));
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a-1,b,-c);
	}
	for(int i=0;i<=50000;i++){
		addedge(i,i+1,0);
		addedge(i+1,i,1);
	}
	spfa(0);
	printf("%d\n",-dist[50001]);
	return 0;
}


