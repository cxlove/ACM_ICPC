#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
LL dp[25][25][25];
LL l,r;
int x,y;
void Init(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<21;i++){
        for(int j=0;j<i;j++)
            for(int k=0;k<i;k++)
                if(j+k<i){
                    dp[i][j][k+1]+=dp[i-1][j][k];
                    dp[i][j+1][k]+=dp[i-1][j][k];
                    dp[i][j][k]+=dp[i-1][j][k]*8;
                }
    }
}
LL get_count(LL n){
    int bit[25],len=0;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    LL  ans=0;
    int cx=x,cy=y;
    for(int i=len;i;i--){
        for(int j=0;j<bit[i];j++)
            if(j==4){
                if(cx)
                    ans+=dp[i-1][cx-1][cy];
            }
            else if(j==7){
                if(cy)
                    ans+=dp[i-1][cx][cy-1];
            }
            else
                ans+=dp[i-1][cx][cy];
        if(bit[i]==4)
            cx--;
        if(bit[i]==7)
            cy--;
        if(cx<0||cy<0)
            break;
    }
    return ans;
}
LL slove(LL k){
    int len=1;
    while(1){
        if(dp[len-1][x][y]<k&&dp[len][x][y]>=k)
            break;
    //    k-=dp[len-1][x][y];
        len++;
    }
//    cout<<len<<endl;
    LL ret=0;
    int cx=x,cy=y;
    for(int i=len;i;i--){
        for(int j=0;j<10;j++){
            int tx=cx,ty=cy;
            if(j==4){
                tx--;
                if(tx<0)
                    continue;
            }
            if(j==7){
                ty--;
                if(ty<0)
                    continue;
            }
            if(dp[i-1][tx][ty]>=k){
                ret=ret*10+j;
                cx=tx;
                cy=ty;
                break;
            }
            k-=dp[i-1][tx][ty];
        }
    }
    return ret;
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    Init();
    while(t--){
        scanf("%I64d%I64d%d%d",&l,&r,&x,&y);
        LL a=get_count(r+1);
        LL b=get_count(l+1);
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++cas);
        while(q--){
            LL k;
            scanf("%I64d",&k);
            if(k>a-b)
                puts("Nya!");
            else
                printf("%I64d\n",slove(k+b));
        }
    }
    return 0;
}