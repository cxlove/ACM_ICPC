#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 70005
using namespace std;
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(const char *r,int *sa,int n,int m){
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
void calheight(const char *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
char str[maxn];
char ch;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		while(!isalpha(ch=getchar()));
		str[i]=str[n+n-i]=ch;
	}
	str[n]=str[n+n+1]=1;
	da(str,sa,n+n+2,120);
	calheight(str,sa,n+n+1);
	int l=0,r=n+1,m=0;
	for(int i=0;i<n;i++,m++){
		if(m==80){
			puts("");
			m=0;
		}
		if(Rank[l]<Rank[r]) putchar(str[l++]);
		else putchar(str[r++]);
	}
	puts("");
	return 0;
}