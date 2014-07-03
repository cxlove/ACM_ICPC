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
char ch[maxn];
int str[maxn];
int l[105];
int in[maxn];
int k;
bool check(int mid,int n,int out){
	bool flag[105];
	int cnt=0;
	memset(flag,false,sizeof(flag));
	for(int i=1;i<=n;i++){
		if(height[i]<mid) {
			if(cnt>k/2&&out){
				for(int j=0,r=sa[i-1];j<mid;j++)
					printf("%c",str[j+r]+'a'-1);
				printf("\n");
			}
			cnt=0;
			memset(flag,false,sizeof(flag));
		}
		else{
			if(!flag[in[sa[i-1]]]){
				flag[in[sa[i-1]]]=true;
				cnt++;
			}
			if(!flag[in[sa[i]]]){
				flag[in[sa[i]]]=true;
				cnt++;
			}
			if(!out&&cnt>k/2) return true;
		}
	}
	return false;
}
int main(){
	int cnt=0;
	while(scanf("%d",&k)!=EOF&&k){
		int n=0;
		if(cnt) printf("\n");
		cnt++;
		for(int i=0;i<k;i++){
			scanf("%s",ch);
			l[i]=strlen(ch);
			for(int j=n;j<n+l[i];j++){
				str[j]=ch[j-n]-'a'+1;
				in[j]=i;
			}
			n+=l[i]+1;
			str[n-1]=27+i;
		}
		n--;
		str[n]=0;
		da(str,sa,n+1,27+k+5);
		calheight(str,sa,n);
		int low=0,high=1000,mid,ans=-1;
		while(low<=high){
			mid=(low+high)/2;
			if(check(mid,n,0)){ans=mid;low=mid+1;}
			else high=mid-1;
		}
		if(ans<=0) puts("?");
		else check(ans,n,1);
	}
	return 0;
}
