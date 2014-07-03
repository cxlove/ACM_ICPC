#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<30
using namespace std;
struct Node{
	int idx,next;
}a[1005];
int cnt,n,root,c[1005],num[1005],pre[1005],start[1005];
bool visit[1005];
int addedge(int u,int v){
	a[cnt].idx=v;
	a[cnt].next=start[u];
	return cnt++;
}
int find_root(){
	double mmax=0;
	int k;
	for(int i=1;i<=n;i++)
		if(!visit[i]&&(double)c[i]/num[i]>mmax&&i!=root){
			mmax=(double)c[i]/num[i];
			k=i;
		}
	return k;
}
void Union(int k,int p){
	num[p]+=num[k];
	c[p]+=c[k];
	for(int i=start[k];i;i=a[i].next)
		pre[a[i].idx]=p;
}
int slove(){
	int ans=0;
	for(int i=1;i<n;i++){
		int k=find_root();
		visit[k]=true;
		int p=pre[k];
		while(visit[p]) p=pre[p];
		ans+=num[p]*c[k];
		Union(k,p);
	}
	return ans+c[root];
}
int main(){
	while(scanf("%d%d",&n,&root)!=EOF&&n+root){
		memset(start,0,sizeof(start));
		memset(visit,false,sizeof(visit));
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			num[i]=1;
		}
		cnt=1;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			start[u]=addedge(u,v);
			pre[v]=u;
		}
		printf("%d\n",slove());
	}
	return 0;
}