#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
#define lson step<<1
#define rson step<<1|1
#define LL long long 
#define MOD 1000000007
using namespace std;
int t,n,b[1000];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double ans=0,tot=(double)n*(n-1)*(n-2)/6.0;
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
            ans+=b[i]*(n-b[i]-1)/2.0;
        printf("%.3f\n",(tot-ans)/tot); 
    }
    return 0;
}