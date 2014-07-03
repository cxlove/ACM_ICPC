#include <iostream>
#include <cstdio>
#include <cstring>
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N = 200005;
struct People{
	int pos,val;
}p[N];
struct Seg{
	int left,right,sum;
}L[N<<2];
int n,ans[N];
void push_up(int step){
	L[step].sum=L[lson].sum+L[rson].sum;
}
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	if(l==r){
		L[step].sum=1;
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
	push_up(step);
}
int query(int step,int num){
	if(L[step].left==L[step].right)
		return L[step].left;
	if(L[lson].sum>=num) return query(lson,num);
	return query(rson,num-L[lson].sum);
}
void update(int step,int pos){
	if(L[step].left==pos&&L[step].right==pos){
		L[step].sum=0;
		return ;
	}
	int m=(L[step].left+L[step].right)>>1;
	if(pos<=m) update(lson,pos);
	else update(rson,pos);
	push_up(step);
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].pos,&p[i].val);
		bulid(1,1,n);
		for(int i=n-1;i>=0;i--){
			int pos=query(1,p[i].pos+1);
			ans[pos]=p[i].val;
			update(1,pos);
		}
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}