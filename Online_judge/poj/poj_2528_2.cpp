#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct line{
	int left,right,mid,col;
}L[70005];
struct Node{
	int l,r;
}p[10001];
int pos[20010],m,n,ans;
bool flag[20006];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].col=-1;
	if(l==r)  return;
	bulid(step*2,l,(l+r)/2);
	bulid(step*2+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int color){
	if(l<=L[step].left&&r>=L[step].right){
		L[step].col=color;
		return ;
	}
	if(L[step].col!=-1){
		L[2*step].col=L[2*step+1].col=L[step].col;
		L[step].col=-1;
	}
	if(l<=L[step].mid)  update(step*2,l,r,color);
	if(r>L[step].mid)  update(step*2+1,l,r,color);
}
void query(int step,int l,int r){
	if(L[step].col!=-1){
		if(!flag[L[step].col]){
			ans++;
			flag[L[step].col]=true;
		}
		return ;
	}
	if(r<=L[step].mid)  query(step*2,l,r);
	else if(l>L[step].mid)  query(step*2+1,l,r);
	else{
		query(step*2,l,L[step].mid);
		query(step*2+1,L[step].mid+1,r);
	}
}
int find(int num){
	int high=m-1,low=0,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(pos[mid]==num) return mid;
		if(pos[mid]<num)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main(){
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].l,&p[i].r);
			pos[2*i]=p[i].l;
			pos[2*i+1]=p[i].r;
		}
		sort(pos,pos+2*n);
		m=0;
		for(int i=0;i<2*n;i++)
			if(i==0||pos[i]!=pos[i-1])
				pos[m++]=pos[i];
		bulid(1,0,m-1);
		for(int i=1;i<=n;i++)
			update(1,find(p[i-1].l),find(p[i-1].r),i);
		memset(flag,false,sizeof(flag));
		ans=0;
		query(1,0,m-1);
		printf("%d\n",ans);
	}
	return 0;
}
	