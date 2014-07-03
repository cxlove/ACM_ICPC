/*
ID:cxlove
PROB:Harmony Forever 
DATA:2012.2.24
HINT:线段树，鸽巢原理
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
#define MAX 500000
using namespace std;
struct line{
	int left,right,mid;
	int val;
}L[MAX*4];
int pos[MAX+5],cnt,val[MAX+5];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].val=inf;
	if(l==r)
		return;
	bulid(step<<1,l,(l+r)/2);
	bulid(step<<1|1,(l+r)/2+1,r);
}
void update(int step,int pos){
	if(L[step].left>pos||L[step].right<pos)
		return;
	if(L[step].left>=pos&&L[step].right<=pos){
		L[step].val=pos;
		return ;
	}
	if(pos<=L[step].mid)
		update(step<<1,pos);
	else
		update(step<<1|1,pos);
	L[step].val=min(L[step<<1].val,L[step<<1|1].val);
}
int query(int step,int l,int r){
	if(L[step].left>r||L[step].right<l)
		return inf;
	if(L[step].left>=l&&r>=L[step].right)
		return L[step].val;
	if(L[step].left<L[step].right)
		return min(query(step<<1,l,r),query(step<<1|1,l,r));
	return inf;
}
void slove(int mod){
	int l=0,r=mod-1,ans=-1,temp,k;
	while(l<=MAX){
		if(r>MAX)
			r=MAX;
		temp=query(1,l,r);		
		if(temp!=inf){
			if(ans==-1||(temp%mod)<(ans%mod))
				ans=temp;
			else if((temp%mod)==(ans%mod)&&pos[temp]>pos[ans])
				ans=temp;
		}
		l+=mod;
		r+=mod;
	}
	printf("%d\n",pos[ans]);
}
void fun(int mod){
	int ans=inf,k;
	for(int i=cnt-1;i>=1;i--){
		if(val[i]%mod==0){
			k=i;
			break;
		}
		if(val[i]%mod<ans){
			ans=val[i]%mod;
			k=i;
		}
	}
	printf("%d\n",k);
}
int main(){
	int q,m,tt=0;
	char str[5];
	while(scanf("%d",&q)&&q){
		if(tt>0)
			printf("\n");
		printf("Case %d:\n",++tt);
		bulid(1,0,MAX);
		cnt=1;
		for(int i=0;i<q;i++){
			scanf("%s",str);
			if(str[0]=='B'){
				scanf("%d",&m);
				val[cnt]=m;
				pos[m]=cnt++;
				update(1,m);
			}
			else{
				scanf("%d",&m);
				if(cnt==1)
					printf("-1\n");
				else if(m<=5000)
					fun(m);
				else
			    	slove(m);
			}
		}
	}
	return 0;
}
/*
5 
B 1 
A 5 
B 10 
A 5
A 40 
2
B 1
A 2
*/
