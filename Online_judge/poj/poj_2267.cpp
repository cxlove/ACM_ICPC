/*
ID:cxlove
PROB:AOJ 319 From Dusk till Dawn
DATA:2012.1.21
HINT:最短路
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
using namespace std;
struct node{
	int u,v;
	int sta,end;
}con[1000];
struct edge{
	int u,val,next;
}edg[1000000];
char name[100][35];
int namenum,qd,zd,pathnum,s,e,ans,idx;
int pre[1000],que[1000000];
int path[1000];
bool vis[1000];
int getnum(char temp[35]){
	for(int i=0;i<namenum;i++)
		if(strcmp(name[i],temp)==0)
			return i;
	strcpy(name[namenum],temp);
	namenum++;
	return namenum-1;
}
void addnode(char name1[35],char name2[35],int sta,int cost){
	int t1=getnum(name1);
	int t2=getnum(name2);
	con[pathnum].u=t1;
	con[pathnum].v=t2;
	con[pathnum].sta=sta;
	con[pathnum++].end=sta+cost;
}
void Init(){
	int m,sta,cost;
	char name1[35],name2[35];
	namenum=0;
	pathnum=0;
	scanf("%d",&m);
	while(m--){
		scanf("%s%s%d%d",name1,name2,&sta,&cost);
		sta=(sta+6)%24;
		if(sta+cost<=12)
			addnode(name1,name2,sta,cost);
	}
	scanf("%s%s",name1,name2);
	s=getnum(name1);
	e=getnum(name2);
}
int check(int i,int j){
	if(con[i].end<=con[j].sta)
		return 0;
	return 1;
}
void addedge(int i,int j,int k){
	edg[idx].u=j;edg[idx].val=k;edg[idx].next=pre[i];pre[i]=idx++;
}
void bulid(){
	idx=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<pathnum;i++)
		for(int j=0;j<pathnum;j++)
			if(con[i].v==con[j].u)
				addedge(i,j,check(i,j));
}
void print(int tt){
	printf("Test Case %d.\n",tt);
	if(s==e)
		printf("Vladimir needs 0 litre(s) of blood.\n");  
	else if (ans == inf) 
		printf("There is no route Vladimir can take.\n");          
	else 
		printf("Vladimir needs %d litre(s) of blood.\n", ans);  
}
void spfa(int s,int e,int n){	 
	int front,rear;  
    front=rear=0;  
    for(int i=0;i<n; i ++){         
		path[i]=inf,vis[i]=false;  
        if(con[i].u==s){  
           que[rear ++] = i;  
           vis[i] = true;  
           path[i] = 0;              
        }  
     }  
     while (front < rear ){  
          int s=que[front++];  
          vis[s] = false;  
          for(int i=pre[s];i!=-1;i=edg[i].next){  
              int temp=edg[i].u;  
              if(path[temp]>path[s]+edg[i].val){  
                  path[temp]=path[s]+edg[i].val;  
                  if (!vis[temp]){  
                     que[rear++]=temp;  
                     vis[temp]=true;                 
				  }
			  }
		  }
	 }
	 for (int i =0; i < n; i ++) 
         if (ans>path[i]&&con[i].v==e)
            ans=path[i];              
}
int main(){
//	freopen("dusk.in","r",stdin);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		Init();
		bulid();
		ans=inf;
		spfa(s,e,pathnum);
		print(tt);
	}
	return 0;
}	
/*
3
3
Ulm Muenchen 17 2
Ulm Muenchen 19 12
Ulm Muenchen 5 2
Ulm Ulm
3
Ulm Muenchen 17 2
Ulm Muenchen 19 12
Ulm Muenchen 5 2
Ulm Muenchen
10
Lugoj Sibiu 12 6
Lugoj Sibiu 18 6
Lugoj Sibiu 24 5
Lugoj Medias 22 8
Lugoj Medias 18 8
Lugoj Reghin 17 4
Sibiu Reghin 19 9
Sibiu Medias 20 3
Reghin Medias 20 4
Reghin Bacau 24 6
Lugoj Bacau
*/