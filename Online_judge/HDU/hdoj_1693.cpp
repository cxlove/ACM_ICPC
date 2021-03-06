#include<stdio.h>
__int64 dp[12][12][1<<12];
int map[12][12];

__int64 DP_state(int n,int m)
{
    int i,j,k;
    int l1,l2;
    int p1,p2;
    bool b1,b2;
    dp[0][m][0] = 1;
    l1 = 1 << m;
    l2 = l1 << 1;
    for(i = 1;i <= n;i ++){
        for(j = 0;j < l1;j ++){
            dp[i][0][j<<1] = dp[i-1][m][j];        }
        for(j = 1;j <= m;j ++){
            for(k = 0;k < l2;k ++){
                p1 = 1 << j;
                p2 = p1 >> 1;                b1 = p1 & k;
                b2 = p2 & k;
                if(map[i][j]){                    dp[i][j][k] = dp[i][j-1][k^p1^p2];                    if(b1 != b2){
                        dp[i][j][k] += dp[i][j-1][k];                    }
                }
                else{                    if(b1==0 && b2 == 0)                        dp[i][j][k] = dp[i][j-1][k];
                    else dp[i][j][k] = 0;                }
            }
        }
    }
    return dp[n][m][0];
}

int main()
{
    int T,n,m;
    int i,j;
    int t = 1;
    __int64 ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i = 1;i <= n;i ++){
            for(j = 1;j <= m;j ++){
                scanf("%d",&map[i][j]);
            }
        }
        ans = DP_state(n,m);
        printf("Case %d: There are %I64d ways to eat the trees.\n",t++,ans);
    }
    return 0;
}
