#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
#include<string>
#define LL long long
#define LD long double
#define eps 1e-7
#define inf 1<<30
#define MOD 1000000007
#define N 100005
using namespace std;
struct MergeTree{
	int left,right,mid;
}tree[N*4];
int num[N],mer[20][N];
int n,q;
void create(int step,int l,int r,int deep){
	tree[step].left=l;
	tree[step].right=r;
	tree[step].mid=(l+r)>>1;
	if(l==r){
		mer[deep][l]=num[l];
		return;
	}
	create(step<<1,l,(l+r)/2,deep+1);
	create((step<<1)|1,(l+r)/2+1,r,deep+1);
	int i=l,j=(l+r)/2+1,p=l;
	while(i<=(l+r)/2&&j<=r){
		if(mer[deep+1][i]>mer[deep+1][j])
			mer[deep][p++]=mer[deep+1][j++];
		else
			mer[deep][p++]=mer[deep+1][i++];
	}
	while(i<=(l+r)/2)
		mer[deep][p++]=mer[deep+1][i++];
	while(j<=r)
		mer[deep][p++]=mer[deep+1][j++];
}
int query(int step,int l,int r,int deep,int key){
	if(tree[step].right<l||tree[step].left>r)
		return 0;
	if(tree[step].left>=l&&tree[step].right<=r)
		return lower_bound(&mer[deep][tree[step].left],&mer[deep][tree[step].right]+1,key)-&mer[deep][tree[step].left];
	return query(2*step,l,r,deep+1,key)+query(2*step+1,l,r,deep+1,key);
}
int slove(int l,int r,int k){
	int high=n,low=1,mid;
	while(low<high){
		mid=(low+high+1)>>1;
		int cnt=query(1,l,r,1,mer[1][mid]);
		if(cnt<=k)
			low=mid;
		else
			high=mid-1;
	}
	return mer[1][low];
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		create(1,1,n,1);
		while(q--){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",slove(l,r,k-1));
		}
	}
	return 0;
}