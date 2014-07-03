#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1005;
const int M = 5005;
const double eps = 1e-5;
struct Edge{
	int v,next;
	double w;
}e[M<<1];
int tot,start[N],n,m,val[N];
void _add(int u,int v,double w){
	e[tot].v=v;e[tot].w=w;
	e[tot].next=start[u];start[u]=tot++;
}
void add(int u,int v,double w){
	_add(u,v,w);
	_add(v,u,w);
}
bool spfa(double mid){
	bool vis[N],in[N];
	int cnt[N];
	double dist[N];
	for(int i=1;i<=n;i++){
		vis[i]=false;
		cnt[i]=0;
		dist[i]=0;
		in[i]=false;
	}
	for(int s=1;s<=n;s++){
		if(vis[s]) continue;
		queue<int>que;
		vis[s]=1;
		que.push(s);
		in[s]++;
		while(!que.empty()){
			int u=que.front();
			que.pop();
			in[u]=false;
			vis[u]=true;
			for(int i=start[u];i!=-1;i=e[i].next){
				int v=e[i].v;double w=val[v]-mid*e[i].w;
				if(dist[v]<dist[u]+w){
					dist[v]=dist[u]+w;
					if(!in[v]){
						in[v]=true;
						cnt[v]++;
						if(cnt[v]>n) return true;
						que.push(v);
					}
				}
			}
		}
	}
	return false;
}
int main(){
	//freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
		tot=0;memset(start,-1,sizeof(start));
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		for(int i=0;i<m;i++){
			int u,v;double w;
			scanf("%d%d%lf",&u,&v,&w);
			_add(u,v,w);
		}
		double low=0.0,mid,high=N*N;
		while(high-low>eps){
			mid=(low+high)/2.0;
			if(!spfa(mid)) high=mid;
			else low=mid;
		}
		if(low<eps) puts("0");
		else printf("%.2f\n",low);
	}
	return 0;
}