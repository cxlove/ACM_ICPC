#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
using namespace std;
LL dp[25][1<<10][11];
LL l,r;
int k,len,bit[25];
LL dfs(int len,int mask,int lis,int lim){
    if(len==0)
        return lis==k;
    if(!lim&&dp[len][mask][k]!=-1)
        return dp[len][mask][k];
    LL ret=0;
    //cout<<len<<endl;
    int up=lim?bit[len]:9;
    for(int i=0;i<=up;i++){
        if(mask||i){
            if((1<<i)>mask)
                ret+=dfs(len-1,mask+(1<<i),lis+1,lim&(i==up));
            else if(mask&(1<<i))
                ret+=dfs(len-1,mask,lis,lim&(i==up));
            else{
                for(int j=i+1;j<=9;j++)
                    if(mask&(1<<j)){
                        ret+=dfs(len-1,mask-(1<<j)+(1<<i),lis,lim&(i==up));
                        break;
                    }
            }
        }
        //Ç°µ¼0
        else{
            ret+=dfs(len-1,0,0,lim&&(i==up));
        }
    }
    return lim?ret:dp[len][mask][k]=ret;
}
LL solve(LL n){
    len=0;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,0,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d%d",&l,&r,&k);
        //cout<<solve(r)<<" "<<solve(l-1)<<endl;
        printf("Case #%d: %I64d\n",++cas,solve(r)-solve(l-1));
    }
    return 0;
}