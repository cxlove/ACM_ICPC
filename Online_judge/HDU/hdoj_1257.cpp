#include<stdio.h>
#define INF 0x7ffffff
#define MAXN 10000
int dp[MAXN];//dp[i]代表第i个导弹当前拦截的高度
int main()
{
    int n,x,i,res,flag;
    int minh;
    while(scanf("%d",&n)!=EOF)
    {
        res=0;
        while(n--)
        {
            scanf("%d",&x);
            flag=0;
            minh=INF;
            for(i=0;i<res;i++)
            {
                if(x<=dp[i]&&minh>dp[i]-x)
                {
                    minh=dp[i]-x;
                    dp[i]=x;
                    flag=1;
                }    
            }
            if(flag==0)
            {
                dp[res]=x;
                res++;
            }        
        }
        printf("%d\n",res);    
    }    
    return 0;
}