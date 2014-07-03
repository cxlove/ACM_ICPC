/*
ID:cxlove
PROB:poj 1511
DATA;2012.1.21
HINT:邻接表+spfa
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
#define MAX 1000005
using namespace std;
typedef struct node{
	int u,val,next;
}edge;
edge edg1[MAX],edg2[MAX];
int n,m;
int pre1[MAX],pre2[MAX];
int que[MAX];
int path[MAX];
__int64 spfa(edge edg[],int pre[]){	
	int head=0,tail=0;	
	for(int i=1;i<=n;i++)
		path[i]=inf;
	que[tail++]=1;
	path[1]=0;
	while(head<tail){
		int temp=que[head++];
		for(int i=pre[temp];i!=-1;i=edg[i].next){
			if(path[edg[i].u]>path[temp]+edg[i].val){
				path[edg[i].u]=path[temp]+edg[i].val;
				que[tail++]=edg[i].u;
			}
		}
	}
	__int64 sum=0;
	for(int i=1;i<=n;i++)
		sum+=path[i];
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(pre1,-1,sizeof(pre1));
		memset(pre2,-1,sizeof(pre2));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int u,v,val;
			scanf("%d%d%d",&u,&v,&val);
			edg1[i].val=val;
			edg1[i].next=pre1[u];
			edg1[i].u=v;
			pre1[u]=i;
			edg2[i].val=val;
			edg2[i].next=pre2[v];
			edg2[i].u=u;
			pre2[v]=i;
		}
		printf("%I64d\n",spfa(edg1,pre1)+spfa(edg2,pre2));
	}
	return 0;
}





