#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <set>
#include <queue>
#include <vector>
#define LD long double
#define inf 0x11111111
#define pi acos(-1.0)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 305;
const int M = 14005;
struct Station{
  int tb,tp;
	int ori;
	Station(){}
	Station(int _o,int _t1,int _t2):ori(_o),tb(_t1),tp(_t2){}
}a[N];
struct Edge{
	int v,w,next;
}edge[M<<2];
int s,e;
int n,m;
int start[N],tot=0;
int pre[N];
int dist[N];
bool in[N]={0};
void _add(int u,int v,int w){
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].next=start[u];
	start[u]=tot++;
}
void add(int u,int v,int w){
	_add(u,v,w);
	_add(v,u,w);
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int solve(int u,int v,int t){
	int m1=a[u].tb+a[u].tp;
	int m2=a[v].tb+a[v].tp;
	int up=lcm(m1,m2);
	for(int i=0;i<max(m1,m2);i++){
		int now=t+i;
		int t1=(now-a[u].ori)%m1;
		int t2=(now-a[v].ori)%m2;
		if(t1<a[u].tb&&t2<a[v].tb) return i;
		else if(t1>=a[u].tb&&t2>=a[v].tb) return i;
	}
	return inf;
}
void dfs(int v){
	int u=pre[v];
	if(v==s) return ;
	dfs(u);
	printf(" %d",v);
}
void spfa(){
	queue<int>que;
	memset(dist,0x11,sizeof(dist));
	dist[s]=0;
	que.push(s);
	in[s]=true;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		in[u]=false;
		for(int i=start[u];i!=-1;i=edge[i].next){
			int v=edge[i].v,w=edge[i].w;
			int tmp=solve(u,v,dist[u])+w;
			if(dist[v]>dist[u]+tmp){
				pre[v]=u;
				dist[v]=dist[u]+tmp;
				//cout<<u<<" "<<v<<" "<<tmp-w<<endl;
				if(in[v]==false){
					in[v]=true;
					que.push(v);
				}
			}
		}
	}
	if(dist[e]>=inf){puts("0");return ;}
	printf("%d\n",dist[e]);
	printf("%d",s);
	dfs(e);
}
int main(){
	memset(start,-1,sizeof(start));
	scanf("%d%d",&s,&e);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char str[5];
		int c,t1,t2,o;
		scanf("%s%d%d%d",str,&c,&t1,&t2);
		if(str[0]=='B') o=0-(t1-c);
		else o=0-(t2-c)-t1;
		a[i]=Station(o,t1,t2);
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	spfa();
	return 0;
}
