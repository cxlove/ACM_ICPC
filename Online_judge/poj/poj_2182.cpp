/*
ID:cxlove
PROB:Lost Cows
DATA:2012.2.22
HINT:线段树
*/
#include<iostream>
#include<cstdio>
using namespace std;
struct line{
	int left,right,mid;
	int sum;
}L[50000];
int a[10000];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].sum=r-l+1;
	if(l==r)
		return;
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
int query(int step,int idx){
	L[step].sum--;
	if(L[step].left==L[step].right)
		return L[step].left;
	if(L[2*step].sum>=idx)
		return query(2*step,idx);
	else return query(2*step+1,idx-L[2*step].sum);
}
int main(){
	int n;
	a[1]=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	bulid(1,1,n);
	for(int i=n;i>0;i--)
		a[i]=query(1,a[i]+1);
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}