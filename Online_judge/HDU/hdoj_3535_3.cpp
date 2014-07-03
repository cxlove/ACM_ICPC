#include<cstdio> 
#include<cstring> 
int dp[110][110]; 
int max(int a,int b) 
{ 
    return a>b?a:b; 
} 
int main() 
{ 
    int n,T,i,j,k,m,s,w,v; 
    while(scanf("%d%d",&n,&T)!=EOF) 
    { 
        memset(dp,0,sizeof(dp)); 
        for(i=1;i<=n;i++) 
        { 
            scanf("%d%d",&m,&s); 
            if(s==0)//至少选一个 
            { 
                for(j=0;j<=T;j++) 
                    dp[i][j]=-1;//保证下面会有一个被选中 
                for(j=1;j<=m;j++) 
                { 
                    scanf("%d%d",&w,&v); 
                    for(k=T;k>=w;k--) 
                    { 
                        //下面这两句话为什么一换就错啊，不懂了。。。。 
                        if(dp[i][k-w]!=-1)     dp[i][k]=max(dp[i][k],dp[i][k-w]+v);//如果dp[i][k-w]存在，则表示i组已经取过了，就相当与在去过的基础上再取，即，至少一个 
                        if(dp[i-1][k-w]!=-1)        dp[i][k]=max(dp[i-1][k-w]+v,dp[i][k]);//保证一定取一个 
                    } 
                } 
            } 
            if(s==1)//至多选一个 
            { 
                for(j=0;j<=T;j++) 
                    dp[i][j]=dp[i-1][j]; 
                for(j=1;j<=m;j++) 
                { 
                    scanf("%d%d",&w,&v); 
                    for(k=T;k>=w;k--) 
                    { 
                        if(dp[i-1][k-w]!=-1) 
                            dp[i][k]=max(dp[i][k],dp[i-1][k-w]+v); 
                    } 
                } 
            } 
            if(s==2)//随意选 
            { 
                for(j=0;j<=T;j++) 
                    dp[i][j]=dp[i-1][j]; 
                for(j=1;j<=m;j++) 
                { 
                    scanf("%d%d",&w,&v); 
                    for(k=T;k>=w;k--) 
                    { 
                        if(dp[i][k-w]!=-1) 
                            dp[i][k]=max(dp[i][k],dp[i][k-w]+v); 
                    } 
                } 
            } 
        } 
        int ans=-1; 
        for(i=0;i<=T;i++) 
        { 
            if(dp[n][i]>ans) 
                ans=dp[n][i]; 
        } 
        printf("%d\n",ans); 
    } 
    return 0; 
}