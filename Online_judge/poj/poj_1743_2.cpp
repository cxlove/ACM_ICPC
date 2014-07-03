#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define maxn 50005
#define eps 1e-8
#define zero(a) fabs(a)<eps
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
int a[maxn],b[maxn];
bool check(int m){
	int mmax=n,mmin=0;
	for(int i=1;i<=n;i++){
		if(height[i]<m){
			mmax=sa[i];
			mmin=sa[i];
		}
		else{
			mmax=max(mmax,max(sa[i],sa[i-1]));
			mmin=min(mmin,min(sa[i],sa[i-1]));
			if(mmax-mmin>m) return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n-1;i++) b[i]=a[i+1]-a[i]+100;
		n--;
		b[n]=0;
		da(b,sa,n+1,200);
		calheight(b,sa,n);
		if(!check(4)){
			printf("0\n");
			continue;
		}
		int ans,low=0,high=n,mid;
		while(low<=high){
			mid=(low+high)/2;
			if(check(mid)){
				ans=mid;
				low=mid+1;
			}
			else
				high=mid-1;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
