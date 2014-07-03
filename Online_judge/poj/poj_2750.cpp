#include <iostream>
#include <cstdio>
#include <cstring>
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N = 100005;
struct Seg{
	int left,right;
	int sum,mx,mn;
	int lmin,rmin,lmax,rmax;
	void set(int num){
		sum=mx=mn=lmin=rmin=lmax=rmax=num;
	}
}L[N<<2];
int n,a[N],q;
void push_up(int step){
	L[step].sum=L[lson].sum+L[rson].sum;
	L[step].mx=max(max(L[lson].mx,L[rson].mx),L[lson].rmax+L[rson].lmax);
	L[step].mn=min(min(L[lson].mn,L[rson].mn),L[lson].rmin+L[rson].lmin);
	L[step].lmin=min(L[lson].lmin,L[lson].sum+L[rson].lmin);
	L[step].rmin=min(L[rson].rmin,L[rson].sum+L[lson].rmin);
	L[step].lmax=max(L[lson].lmax,L[lson].sum+L[rson].lmax);
	L[step].rmax=max(L[rson].rmax,L[rson].sum+L[lson].rmax);
}
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	if(l==r){
		L[step].set(a[l]);
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
	push_up(step);
}
void update(int step,int p,int v){
	if(L[step].left==L[step].right){
		L[step].set(v);
		return ;
	}
	int m=(L[step].left+L[step].right)>>1;
	if(p<=m) update(lson,p,v);
	else update(rson,p,v);
	push_up(step);
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bulid(1,1,n);
		scanf("%d",&q);
		while(q--){
			int p,v;
			scanf("%d%d",&p,&v);
			update(1,p,v);
			if(L[1].sum==L[1].mx)
				printf("%d\n",L[1].sum-L[1].mn);
			else
				printf("%d\n",max(L[1].mx,L[1].sum-L[1].mn));
		}
	}
	return 0;
}
