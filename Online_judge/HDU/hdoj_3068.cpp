/*
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
#define maxn 250005
#define eps 1e-8
#define zero(a) fabs(a)<eps
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
char str[maxn];
int main(){
    while(scanf("%s",str)!=EOF){
        int l=strlen(str);
        str[l]=1;
        for(int i=l+1,j=l-1;j>=0;i++,j--)
            str[i]=str[j];
        int n=2*l+1;
        str[n]='\0';
        da(str,sa,n+1,250);
        calheight(str,sa,n);
        int idx=0,ans=1;
        for(int i=1;i<=n;i++){
            int L=min(sa[i],sa[i-1]),R=max(sa[i],sa[i-1]);
            if(L>l||R<l) continue;
            if(L+height[i]!=n-R) continue;
            if(height[i]>ans){
                ans=height[i];
                idx=L;
            }
            else if(height[i]==ans&&L<idx)
                idx=L;
        }
        for(int i=idx,j=0;j<ans;j++,i++) printf("%c",str[i]);
        printf("\n",ans);
    }
    return 0;
}
*/
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
#define maxn 250005
#define eps 1e-8
#define zero(a) fabs(a)<eps
using namespace std;
char str[maxn];
char s[maxn];
int p[maxn];
int Manacher(char *s,int n){
    p[0]=p[1]=1;
    int mx=1,id=1,ans=1;
    for(int i=2;i<n;i++){
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        for(;s[i-p[i]]==s[i+p[i]];p[i]++);
        if(i+p[i]>mx){
            mx=i+p[i];
            id=i;
        }
        ans=max(ans,p[i]);
    }
    return ans-1;
}    
int main(){
    while(scanf("%s",str)!=EOF){
        int l=strlen(str);
        s[0]='@';
        for(int i=0;i<l;i++){
            s[2*i+1]='#';
            s[2*i+2]=str[i];
        }
        s[2*l+1]='#';
        printf("%d\n",Manacher(s,2*l+2));
    }
    return 0;
}

