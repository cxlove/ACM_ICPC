//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<cmath>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<set>
//#define maxn 200005
//#define eps 1e-8
//#define inf 1<<30
//#define zero(a) fabs(a)<eps
//#define pb(a) push_back(a)
//using namespace std;
////以下为倍增算法求后缀数组  
//int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];  
//int cmp(int *r,int a,int b,int l)  
//{return r[a]==r[b]&&r[a+l]==r[b+l];}  
//void da(const char *r,int *sa,int n,int m){  
//	int i,j,p,*x=wa,*y=wb,*t;   
//	for(i=0;i<m;i++) Ws[i]=0;   
//	for(i=0;i<n;i++) Ws[x[i]=r[i]]++;   
//	for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
//	for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;   
//	for(j=1,p=1;p<n;j*=2,m=p){   
//		for(p=0,i=n-j;i<n;i++) y[p++]=i;   
//		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;   
//		for(i=0;i<n;i++) wv[i]=x[y[i]];   
//		for(i=0;i<m;i++) Ws[i]=0;   
//		for(i=0;i<n;i++) Ws[wv[i]]++;   
//		for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
//		for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];   
//		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)   
//			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;   
//	}   
//	return;   
//}  
//int sa[maxn],Rank[maxn],height[maxn];  
////求height数组  
//void calheight(const char *r,int *sa,int n){  
//	int i,j,k=0;  
//	for(i=1;i<=n;i++) Rank[sa[i]]=i;  
//	for(i=0;i<n;height[Rank[i++]]=k)  
//		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);  
//	return;  
//}  
//char str[maxn],ch[maxn];
//int main(){
//	int n;
//	while(scanf("%d",&n)!=EOF){
//		scanf("%s%s",str,ch);
//		int l1=strlen(str),l2=strlen(ch),l=l1+l2+1;
//		strcpy(str+l1+1,ch);
//		str[l1]='@';
//		da(str,sa,l+1,150);
//		calheight(str,sa,l);
//		int ans=0,idx;
//		for(int i=1;i<=l;i++){
//			int L=min(sa[i],sa[i-1]),R=max(sa[i],sa[i-1]);
//			if(L<l1&&R>l1&&height[i]>ans) ans=height[i],idx=L;
//		}
//		for(int i=0,j=idx;i<ans;j++,i++) printf("%c",str[j]);
//		printf("\n");
//	}
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 50005
using namespace std;
int n,q,a[N];
int mx[N][18],mn[N][18];
void Rmq_Init(){
	int m=floor(log((double)n)/log(2.0));
	for(int i=1;i<=n;i++) mx[i][0]=mn[i][0]=a[i];
	for(int i=1;i<=m;i++)
		for(int j=n;j;j--){
			mx[j][i]=mx[j][i-1];
			mn[j][i]=mn[j][i-1];
			if(j+(1<<(i-1))<=n){
				mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
				mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
			}
		}
}
int Rmq_Query(int l,int r){
	int m=floor(log((double)(r-l+1))/log(2.0));
	int Max=max(mx[l][m],mx[r-(1<<m)+1][m]);
	int Min=min(mn[l][m],mn[r-(1<<m)+1][m]);
	return Max-Min;
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		Rmq_Init();
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",Rmq_Query(l,r));
		}
	}
	return 0;
}