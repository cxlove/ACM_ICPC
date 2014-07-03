/*
ID:cxlove
PROB:poj 1459 power network
DATA;2012.1.14
HINT:最大流
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
using namespace std;
int n,np,nc,m;
char temp[20];
int path[205][105];
int Edmonds_Karp(){
	int maxflow=0;
	int pre[205];
	int que[205]={0};
	int flow[205][205]={0};
	int a[205];
	while(1){
		int head=0,tail=0;
		que[tail++]=0;
		memset(a,0,sizeof(a));
		a[0]=inf;
		while(head<tail){
			int temp=que[head++];
			for(int i=0;i<=n+1;i++)
				if(a[i]==0&&flow[temp][i]<path[temp][i]){
					pre[i]=temp;
					que[tail++]=i;
					a[i]=min(a[temp],path[temp][i]-flow[temp][i]);
				}
		}
		if(a[n+1]==0) break;
		for(int i=n+1;i!=0;i=pre[i]){
			flow[pre[i]][i]+=a[n+1];
			flow[i][pre[i]]-=a[n+1];
		}
		maxflow+=a[n+1];	
	}
	return maxflow;
}			
int main(){
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
		memset(path,0,sizeof(path));
		for(int i=0;i<m;i++){
			int u,v,z;
			scanf("%s",temp);
			sscanf(temp,"(%d,%d)%d",&u,&v,&z);
			path[u+1][v+1]=z;
		}
		for(int i=0;i<np;i++){
			int u,z;
			scanf("%s",temp);
			sscanf(temp,"(%d)%d",&u,&z);
			path[0][u+1]=z;
		}
		for(int i=0;i<nc;i++){
			int u,z;
			scanf("%s",temp);
			sscanf(temp,"(%d)%d",&u,&z);
			path[u+1][n+1]=z;
		}
		printf("%d\n",Edmonds_Karp());
	}
	return 0;
}