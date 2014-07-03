/*
ID:cxlove
PROB:Frequent values
DATA:2012.2.25
HINT:线段树+离散化
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define inf 1<<30
using namespace std;
struct line{
	int left,right,mid;
	int mmax;
}L[800000];
struct Node{
	int start,end;
}Q[100005];
int n,q;
int val[100005],p[100005],pcount,ans[100005];
bool cmp(Node n1,Node n2){
	return n1.end<n2.end;
}
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	if(l==r){
		L[step].mmax=(Q[l].end-Q[l].start+1);
		return ;
	}
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
	L[step].mmax=max(L[2*step].mmax,L[2*step+1].mmax);
}
int query(int step,int l,int r){
	if(L[step].left==l&&L[step].right==r)
		return L[step].mmax;
	if(r<=L[step].mid)
		return query(2*step,l,r);
	else if(l>L[step].mid)
		return query(2*step+1,l,r);
	else
		return max(query(2*step,l,L[step].mid),query(2*step+1,L[step].mid+1,r));
}
int main(){
	while(scanf("%d",&n)&&n){
		scanf("%d",&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		int pcount=0,pre=inf;
		for(int i=1;i<=n;i++){
			if(val[i]!=pre){
				pre=val[i];
				pcount++;
				Q[pcount].start=i;
				Q[pcount].end=i;
			}
			else
				Q[pcount].end=i;
			p[i]=pcount;
		}
		bulid(1,1,pcount);
		while(q--){
			int a,b;
			scanf("%d%d",&a,&b);
			int c=p[a];
			int d=p[b];
			if(c==d)                     //两点在一个部分
				printf("%d\n",b-a+1);
			else{
				int n1=Q[c].end-a+1;     //第一部分
				int n2=b-Q[d].start+1;   //第二部分
				int n3=0;                  //第三部分
				if(d-c>1)
					n3=query(1,c+1,d-1);
				printf("%d\n",max(max(n1,n2),n3));
			}
		}
	}
	return 0;
}
		


