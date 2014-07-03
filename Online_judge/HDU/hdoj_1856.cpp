/*
ID:cxlove
PROB:More is better
DATA:2012.3.12
HINT:并查集
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a,b) (a)>(b)?(a):(b) 
using namespace std;
void scanf_(int &num){
    char in;
    while((in=getchar())>'9'||in<'0');
    num=in-'0'; 
    while(in=getchar(),in>='0'&&in<='9') 
        num*=10,num+=in-'0';
} 
int n,a[100005],b[100005],pre[10000005],cnt[10000005];
int find(int x){
    if(pre[x]==x)
        return x;
    return find(pre[x]);
}
void Union(int x,int y){
    int r1=find(x);
    int r2=find(y);
    if(r1!=r2){
        if(r1<r2){
            cnt[r1]+=cnt[r2];
            pre[r2]=r1;
        }
        else{
            cnt[r2]+=cnt[r1];
            pre[r1]=r2;
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int mmax=0;
        for(int i=0;i<n;i++){
            scanf_(a[i]);
            scanf_(b[i]);
            mmax=Max(a[i],Max(b[i],mmax));
        }
        for(int i=1;i<=10000005;i++){
            cnt[i]=1;
            pre[i]=i;
        }
        for(int i=0;i<n;i++){
            Union(a[i],b[i]);
        }
        int ans=-1;
        for(int i=1;i<=10000005;i++)
            ans=Max(ans,cnt[i]);
        printf("%d\n",ans);
    }
    return 0;
}