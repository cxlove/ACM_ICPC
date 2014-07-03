#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int dp[1005][2005][2]={0};
int main(){
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=2*i;j++){
            dp[i][j][0]=(dp[i-1][j][0]+2*dp[i-1][j][1]+dp[i-1][j-1][0]+dp[i-1][j-1][1])%MOD;
            dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][j-1][0]*2+dp[i-1][j-1][1]*2)%MOD;
            if(j>1)
                dp[i][j][1]=(dp[i][j][1]+(dp[i-1][j-2][0]+dp[i-1][j-2][1]))%MOD;
            //cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
            //system("pause");
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(b==2*a||b==1)
            printf("1\n");
        else
            printf("%d\n",(dp[a][b][0]+dp[a][b][1])%MOD);
    }
    return 0;
}