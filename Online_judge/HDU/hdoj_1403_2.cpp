#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 210000
using namespace std;
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void debug(int *a,int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
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
bool check(int i,int n){
    return (sa[i]<=n)!=(sa[i-1]<=n);
}
int main(){
    string s1,s2;
    while(s1.clear(),s2.clear(),cin>>s1>>s2){
        int len=s1.size();
        s1+='#';
        s1+=s2;
        da(s1.c_str(),sa,s1.size(),128);
        calheight(s1.c_str(),sa,s1.size());
        int ans=0;
        for(int i=1;i<s1.size();i++)
            if(height[i]>ans&&check(i,len))
                ans=height[i];
        cout<<ans<<endl;
    }
    return 0;
}