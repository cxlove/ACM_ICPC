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
#define maxn 200005
#define eps 1e-8
#define inf 1<<30
#define LL long long
#define zero(a) fabs(a)<eps
using namespace std;
//以下为倍增算法求后缀数组
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
//求height数组
void calheight(const int *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
int n,m,k,l;
LL slove(int num,int len){
	LL ans=0;
	int one=0,two=0;
	if(sa[0]<n) one++;
	else two++;
	for(int i=1;i<=len;i++){
		if(height[i]<num){
			if(two>0)
		    	ans+=(LL)one;
			one=0;two=0;
			if(sa[i]<n) one++;	
			else two++;
		}
		else{
			if(sa[i]<n) one++;	
			else two++;
		}
	}
	return ans;
}
int str[maxn];
int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		l=n+m+1;
		for(int i=0;i<n;i++){
			scanf("%d",&str[i]);
			str[i]++;
		}
		str[n]=10002;
		for(int i=n+1;i<l;i++){
			scanf("%d",&str[i]);
			str[i]++;
		}
		str[l]=0;
		da(str,sa,l+1,10003);
		calheight(str,sa,l);
		printf("%I64d\n",slove(k,l)-slove(k+1,l));
	//	printf("%I64d\n",);
	}
	return 0;
}