/*
ID:cxlove
PROB:Largest Rectangle in a Histogram 
DATA:2012.3.8
HINT:DP
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,val[100005],l[100005],r[100005];
int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
            l[i]=r[i]=i;
        }
        val[0]=val[n+1]=-1;
        for(int i=2;i<=n;i++)
            while(val[l[i]-1]>=val[i])
                l[i]=l[l[i]-1];
        for(int i=n-1;i>=1;i--)
            while(val[r[i]+1]>=val[i])
                r[i]=r[r[i]+1];
        __int64 ans=0,temp;
        for(int i=1;i<=n;i++){
            temp=(__int64)(r[i]-l[i]+1)*val[i];
            if(temp>ans)
                ans=temp;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}