#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define LL long long
using namespace std;
struct Line{
	int left,right,mid;
	int col,cover;
}L[100005];
struct Node{
	int left,right;
}p[10005];
int n,q[20005],cnt;
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].col=0;
	L[step].cover=0;
	if(l==r)
		return;
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int c){
	if(L[step].left==l&&L[step].right==r){
		L[step].col=c;
		L[step].cover=0;
		return;
	}
	if(L[step].cover==0){
		L[step*2].cover=L[step*2+1].cover=0;
		L[step*2].col=L[2*step+1].col=L[step].col;
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
bool flag[10005];
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
int bin(int num){
	int low=0,high=cnt,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(q[mid]==num)
			return mid;
		else if(q[mid]>num)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int idx=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].left,&p[i].right);
			q[idx++]=p[i].left;
			q[idx++]=p[i].right;
		}
		sort(q,q+idx);
		cnt=0;
		for(int i=1;i<idx;i++)
			if(q[i]!=q[cnt])
				q[++cnt]=q[i];
		bulid(1,0,cnt);
		for(int i=0;i<n;i++){
			int l=bin(p[i].left);
			int r=bin(p[i].right);
			update(1,l,r,i+1);
		}
		memset(flag,false,sizeof(flag));
		int ans=0;
		query(1,0,cnt);
		for(int i=1;i<=n;i++)
			if(flag[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}