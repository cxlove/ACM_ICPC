#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 999983
using namespace std;
struct node{
	int a,b;
}que[2000000];
short int vis[205][20005]={0},n;
int bfs(){
	memset(vis,0,sizeof(vis));
	int head=0,tail=0;
	node u,v;
	u.a=0;u.b=1;
	vis[0][1]=1;
	que[tail++]=u;
	while(head<tail){
		u=que[head++];
		int aa=u.b-u.a,bb=u.a;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.b-u.a,bb=u.b;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.b+u.a,bb=u.a;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.b+u.a,bb=u.b;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.a+u.a,bb=u.a;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.a+u.a,bb=u.b;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.b+u.b,bb=u.a;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
		aa=u.b+u.b,bb=u.b;
		if(aa>bb) swap(aa,bb);
		if(aa<=200&&bb<=20000&&vis[aa][bb]==0){
			v.a=aa;v.b=bb;
			vis[aa][bb]=vis[u.a][u.b]+1;
			if(aa==n||bb==n)
				return vis[aa][bb]-1;
			que[tail++]=v;
		}
	}
}
int main(){
	int n1=3,n2=4;
	while(cin>>n)
	cout<<bfs()<<endl;
	return 0;
}
	