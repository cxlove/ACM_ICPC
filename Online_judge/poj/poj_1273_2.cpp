/*
ID:cxlove
PROB:poj 1273 Drainage Ditches
DATA:2012.1.14
HINT:最大流
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
using namespace std;
int n,m;
int path[201][201]={0};
int maxflow_ff(){
	int flow[201][201]={0};
	int maxflow=0;
	int pre[201];
	int que[201];
	while(1){
		int head=0,tail=0;
		que[tail++]=1;
		memset(pre,-1,sizeof(pre));
		pre[1]=-2;
		int minflow=inf;
		while(head<tail){
			int temp=que[head++];
			for(int i=1;i<=m;i++)
				if(pre[i]==-1&&flow[temp][i]<path[temp][i]){
					pre[i]=temp;
					que[tail++]=i;
					minflow=min(minflow,-flow[temp][i]+path[temp][i]);
				}
			if(pre[m]!=-1){
				int k=m;
				while(pre[k]>0){
					flow[pre[k]][k]+=minflow;
					flow[k][pre[k]]-=flow[pre[k]][k];
					k=pre[k];
				}
				break;
			}
		}
		if(pre[m]==-1)  return maxflow;
		else maxflow+=minflow;
	}
}			
int main(){
	while(cin>>n>>m){
		memset(path,0,sizeof(path));
	while(n--){
		int i,j,k;
		cin>>i>>j>>k;
		path[i][j]+=k;
	}
	cout<<maxflow_ff()<<endl;
	}
	return 0;
}
