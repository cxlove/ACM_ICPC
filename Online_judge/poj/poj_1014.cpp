#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<30
using namespace std;
int dp[200005];
int cnt[6],m;
void zeroonepack(int cost){
    for(int i=m;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]);
}
void completepack(int cost){
    for(int i=cost;i<=m;i++)
        dp[i]=max(dp[i],dp[i-cost]);
}
void doublepack(int cost,int count){
    if(cost*count>=m)
        completepack(cost);
    else{
        int tmp=1;
        while(tmp<=count){
            zeroonepack(cost*tmp);
            count-=tmp;
            tmp<<=1;
        }
        zeroonepack(cost*count);
    }    
}
int main(){
    int cas=0;
    while(scanf("%d%d%d%d%d%d",&cnt[0],&cnt[1],&cnt[2],&cnt[3],&cnt[4],&cnt[5])!=EOF){
        m=cnt[0]+2*cnt[1]+3*cnt[2]+4*cnt[3]+5*cnt[4]+6*cnt[5];
        if(m==0)
            break;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        printf("Collection #%d:\n",++cas);
        if(m&1){
            printf("Can't be divided.\n\n");
            continue;
        }
        for(int i=0;i<6;i++)
            doublepack(i+1,cnt[i]);
        if(dp[m/2])
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    return 0;
}