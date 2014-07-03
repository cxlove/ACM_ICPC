#include<stdio.h>
#define NIL 1<<30
int main()
{
	int n,i,j,m,t;

    double dp[55][55],sum;
    int way[60];
    char ch[100];

	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&m,&t);
		way[0]=way[m+1]=way[m+2]=0;
		for(i=1;i<=m;i++)
		{
			if(!scanf("%d",&way[i]))
			{scanf("%s",ch);  way[i]=NIL;}  
		}
	    memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		
		for(i=0;i<t;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(way[j+1] == NIL)  
                dp[i+2][j+1] += dp[i][j]*0.5;  
            else  
                dp[i+1][j+1+way[j+1]] += dp[i][j]*0.5;  
            if(way[j+2] == NIL)  
                dp[i+2][j+2] += dp[i][j]*0.5;  
            else  
                dp[i+1][j+2+way[j+2]] += dp[i][j]*0.5;  
			}
		}
		sum=0;
		for(i=0;i<=t;i++)
		{
			sum+=dp[i][m+1]+dp[i][m+2];
		}
		
		if(sum==0.5)            
			printf("Push. 0.5000\n");     
		else if(sum>0.5)          
			printf("Bet for. %.4f\n",sum);   
		else         
			printf("Bet against. %.4f\n",sum); 

		
	}
	return 0;
}

		

