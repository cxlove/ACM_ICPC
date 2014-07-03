#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define lson step<<1
#define rson step<<1|1
#define LL long long
using namespace std;
const int N = 100005;
struct Node{
	int cost,val;
	bool operator<(const Node n)const{
		return val<n.val;
	}
}a[N];
struct Seg_tree{
	int left,right;
	int small,large;
}L[N<<2];
int m,n,f,x[N],tot;
LL Left=0,Right=0;
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].small=L[step].large=0;
	if(l==r) return ;
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
}
void insert(int step,int pos,int kind){
	if(!kind) L[step].small++;
	else L[step].large++;
	if(L[step].left==pos&&pos==L[step].right) return ;
	int m=(L[step].left+L[step].right)>>1;
	if(pos<=m) insert(lson,pos,kind);
	else insert(rson,pos,kind);
}
int query(int step,int k,int kind){
	if(L[step].left==L[step].right) return L[step].left;
	int m=(L[step].left+L[step].right)>>1;
	if(!kind){
		if(L[lson].small>=k) return query(lson,k,kind);
		else return query(rson,k-L[lson].small,kind);
	}
	else{
		if(L[lson].large>=k) return query(lson,k,kind);
		else return query(rson,k-L[lson].large,kind);
	}
}
void remove(int step,int pos,int kind){
	if(!kind) L[step].small--;
	else L[step].large--;
	if(L[step].left==L[step].right) return ;
	int m=(L[step].left+L[step].right)>>1;
	if(pos<=m) remove(lson,pos,kind);
	else remove(rson,pos,kind);
}
int main(){
	scanf("%d%d%d",&m,&n,&f);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].val,&a[i].cost);
		x[i]=a[i].cost;
	}
	sort(a,a+n);
	sort(x,x+n);
	tot=unique(x,x+n)-x;
	bulid(1,1,tot);
	for(int i=0;i<m/2;i++){
		Left+=(LL)a[i].cost;
		int pos=lower_bound(x,x+tot,a[i].cost)-x+1;
		insert(1,pos,0);
	}
	for(int i=m/2+1;i<n;i++){
		int pos=lower_bound(x,x+tot,a[i].cost)-x+1;
		if(i<m){
			Right+=(LL)a[i].cost;
			insert(1,pos,1);
		}
		else{
			int idx=query(1,m/2,1);
			if(a[i].cost<x[idx-1]) Right=Right-x[idx-1]+a[i].cost;
			insert(1,pos,1);
		}
	}
	int ans=-1;
	for(int i=m/2;i<n-m/2;i++){
		if((LL)Left+Right+a[i].cost<=f){
			ans=max(ans,a[i].val);
		}
		int pos=lower_bound(x,x+tot,a[i].cost)-x+1;
		int idx=query(1,m/2,0);
		if(a[i].cost<x[idx-1]){
			Left-=(LL)x[idx-1];
			Left+=(LL)a[i].cost;
			remove(1,idx,0);
			insert(1,pos,0);
		}
		pos=lower_bound(x,x+tot,a[i+1].cost)-x+1;
		remove(1,pos,1);
		idx=query(1,m/2,1);
		if(a[i+1].cost<x[idx-1]){
			Right-=(LL)a[i+1].cost;
			Right+=(LL)x[idx-1];
		}
	}
	printf("%d\n",ans);
    return 0;
}