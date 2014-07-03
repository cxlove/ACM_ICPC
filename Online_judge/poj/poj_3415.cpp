#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define LL long long
#define maxn 200005
using namespace std;
//以下为倍增算法求后缀数组  
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
//求height数组  
void calheight(const char *r,int *sa,int n){  
	int i,j,k=0;  
	for(i=1;i<=n;i++) Rank[sa[i]]=i;  
	for(i=0;i<n;height[Rank[i++]]=k)  
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);  
	return;  
}
char str[maxn],ch[maxn];
int k;
int s[maxn][2];
LL tot,top;
int main(){
	while(scanf("%d",&k)!=EOF&&k){
		int l1,l2;
		scanf("%s%s",str,ch);
		l1=strlen(str);l2=strlen(ch);
		str[l1]='@';
		for(int i=l1+1;i<=l1+l2;i++)
			str[i]=ch[i-l1-1];
		int n=l1+l2+1;
		str[n]='\0';
		da(str,sa,n+1,130);
		calheight(str,sa,n);
		tot=top=0;
		LL sum=0;
		for(int i=1;i<=n;i++){
			if(height[i]<k) top=tot=0;
			else{
				int cnt=0;
				if(sa[i-1]<l1) cnt++,tot+=height[i]-k+1;
				while(top>0&&height[i]<=s[top-1][0]){
					top--;
					tot-=s[top][1]*(s[top][0]-height[i]);
					cnt+=s[top][1];
				}
				s[top][0]=height[i];s[top++][1]=cnt;
				if(sa[i]>l1) sum+=tot;
			}
		}
		tot=top=0;
		for(int i=1;i<=n;i++){
			if(height[i]<k) top=tot=0;
			else{
				int cnt=0;
				if(sa[i-1]>l1) cnt++,tot+=height[i]-k+1;
				while(top>0&&height[i]<=s[top-1][0]){
					top--;
					tot-=s[top][1]*(s[top][0]-height[i]);
					cnt+=s[top][1];
				}
				s[top][0]=height[i];s[top++][1]=cnt;
				if(sa[i]<l1) sum+=tot;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
	