#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 510000
using namespace std;
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(const int *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb,*t; 
	for(i=0;i<m;i++) Ws[i]=0; 
	for(i=0;i<n;i++) Ws[x[i]=r[i]]++; 
	for(i=1;i<m;i++) Ws[i]+=Ws[i-1]; 
	for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i; 
	for(j=1,p=1;p<n;j*=2,m=p){ 
		for(p=0,i=n-j;i<n;i++) y[p++]=i; 
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; 
		for(i=0;i<n;i++) wv[i]=x[y[i]]; 
		for(i=0;i<m;i++) Ws[i]=0; 
		for(i=0;i<n;i++) Ws[wv[i]]++; 
		for(i=1;i<m;i++) Ws[i]+=Ws[i-1]; 
		for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i]; 
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) 
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; 
	} 
	return; 
}
int sa[maxn],Rank[maxn],height[maxn];
void calheight(const int *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
int n;
bool check(int mid){
	int mmax=n,mmin=0;
	for(int i=1;i<=n;i++){
		if(height[i]<mid){
			mmax=sa[i];
			mmin=sa[i];
		}
		else{
			mmax=max(mmax,max(sa[i],sa[i-1]));
			mmin=min(mmin,min(sa[i],sa[i-1]));
			if(mmax-mmin>mid)
				return true;
		}
	}
	return false;
}
int a[maxn],x[maxn];
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&x[0]);
		for(int i=1;i<n;i++){
			scanf("%d",&x[i]);
			a[i-1]=x[i]-x[i-1]+100;
		}
		a[n-1]=0;
		n--;
		da(a,sa,n+1,200);
		calheight(a,sa,n);
		if(!check(4)){
			printf("0\n");
			continue;
		}
		int low=0,high=n,mid;
		while(low<high){
			mid=(low+high+1)/2;
			if(!check(mid))
				high=mid-1;
			else
				low=mid;
		}
		printf("%d\n",low+1);
	}
	return 0;
}
