#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=300505;
const int INF=400005;
typedef __int64 lld ;
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
        for(i=0;i<n;i++) wv[i]=x[y[i]]; //x[]->上次排序的排名
        for(i=0;i<m;i++) Ws[i]=0; 
        for(i=0;i<n;i++) Ws[wv[i]]++; 
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1]; 
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i]; 
        //y[i]->二级排序后第i大的下标，循环从n-1到0由于一级排序相同要看二级排序
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) 
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; 
    } 
    return; 
}
int sa[maxn],Rank[maxn],height[maxn];
//求height数组
//sa[1,n]取值范围[0,n-1],sa[0]为特殊字符
//Rank[0,n-1]取值范围[1,n]
//height[1,n]表示排名相邻的两个后缀的最长公共前缀
//height[i]表示sa[i]和sa[i-1]的最长前缀 排名为i与i-1的最长公共前缀
void calheight(const int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) Rank[sa[i]]=i;
    for(i=0;i<n;height[Rank[i++]]=k)
        for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
/*
da(r,sa,n+1,128);
n+1表示加入特殊字符后的长度[0,n];
calheight(r,sa,n);
去掉特殊字符[1,n]长度，就是输入字符串长度n
*/

char b[maxn];
int a[maxn];
lld de[maxn];

int main(){
    int T,cas;
    int dif,len;
    int n,m,num;
    int i,j,k;
    lld ans,min;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++){
        dif=30;
        scanf("%d",&num);
        scanf("%s",b);
        n=strlen(b);
        for(i=0,m=0;i<n;i++){
            a[m++]=b[i]-'a'+1;
        }
        a[m++]=dif++;
        for(i=0;i<num;i++){
            scanf("%s",b);
            len=strlen(b);
            for(j=0;j<len;j++){
                a[m++]=b[j]-'a'+1;
            }
            a[m++]=dif++;
        }
        a[m]=0;
        da(a,sa,m+1,dif+5);
        calheight(a,sa,m);
        ans=(lld)n*(n+1)/2;
        memset(de,0,sizeof(de));
        //printf("ans1===%d\n",ans);
        lld min=INF;
        for(i=1;i<=m;i++){
            if(sa[i]<n){
                if(min>height[i])min=height[i];
                if(de[sa[i]]<min)de[sa[i]]=min;
            }else if(sa[i]>=n){
                min=INF;
            }
        }
        min=INF;
        for(i=m;i>=1;i--){
            if(sa[i-1]<n){
                if(min>height[i])min=height[i];
                if(de[sa[i-1]]<min)de[sa[i-1]]=min;
            }else if(sa[i-1]>=n){
                min=INF;
            }
        }
        for(i=1;i<=m;i++){
            if(sa[i]<n && sa[i-1]>=n){
                if(de[sa[i]]<height[i])
                    de[sa[i]]=height[i];
            }else if(sa[i]<n && sa[i-1]<n){
                if(de[sa[i-1]]<height[i])
                    de[sa[i-1]]=height[i];
            }else if(sa[i]>=n && sa[i-1]<n ){
                if(de[sa[i-1]]<height[i])
                    de[sa[i-1]]=height[i];
            }
        }
        for(i=0;i<n;i++){
            ans-=de[i];
        }
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}