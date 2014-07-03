#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define LL long long
using namespace std;
struct Line{
	int left,right,mid;
	int col,cover;
}L[500005];
int n,t,q;
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].col=1;
	L[step].cover=0;
	if(l==r)
		return ;	
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int c){
	if(L[step].left==l&&r==L[step].right){
		L[step].col=c;
		L[step].cover=0;
		return;
	}
	if(L[step].cover==0){
		L[2*step].col=L[2*step+1].col=L[step].col;
		L[2*step].cover=L[2*step+1].cover=0;
		L[step].cover=1;
	}
	if(r<=L[step].mid)
		update(2*step,l,r,c);
	else if(l>L[step].mid)
		update(2*step+1,l,r,c);
	else{
		update(2*step,l,L[step].mid,c);
		update(2*step+1,L[step].mid+1,r,c);
	}
}
bool flag[50];
void query(int step,int l,int r){
	if(L[step].cover==0){
		flag[L[step].col]=1;
		return;
	}
	if(r<=L[step].mid)
		query(2*step,l,r);
	else if(l>L[step].mid)
		query(2*step+1,l,r);
	else{
		query(2*step,l,L[step].mid);
		query(2*step+1,L[step].mid+1,r);
	}
}
int main(){
	char str[10];
	int x,y,c;
	while(scanf("%d%d%d",&n,&t,&q)!=EOF){
		bulid(1,1,n);
		while(q--){
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%d%d%d",&x,&y,&c);
				update(1,x,y,c);
			}
			else{
				scanf("%d%d",&x,&y);
				memset(flag,false,sizeof(flag));
				query(1,x,y);
				int ans=0;
				for(int i=1;i<=t;i++)
					if(flag[i])
						ans++;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
