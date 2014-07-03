#include<stdio.h>
#define nil 1<<30
int path[101][101],n,flag[101];
int dis[101];
int sum;
int dij(int i,int num)
{
	int min=nil,t,j;
	for(j=1;j<=n;j++)
	{
		if(dis[j]>dis[i]+path[i][j]&&i!=j&&path[i][j]>0)
			dis[j]=dis[i]+path[i][j];
	}
	for(j=1;j<=n;j++)
	{
		if(flag[j]==0&&min>dis[j])
		{
			t=j;
			min=dis[j];
		}
	}
	if(min==nil)  
	{
		if(num==n)  return dis[i];
		else
			return nil;
	}
	flag[t]=1;	
	dij(t,num+1);
}




int main()
{
	int m,i,j,a,b,min,t;
	while(scanf("%d",&n)&&n)
	{
    	memset(path,-1,sizeof(path));
    	for(i=1;i<=n;i++)
		{
	    	scanf("%d",&m);
	     	while(m--)
			{
		    	scanf("%d%d",&a,&b);
	    		path[i][a]=b;
			}
		}min=nil;
		for(i=1;i<=n;i++)
		{

			memset(flag,0,sizeof(flag));
			for(j=1;j<=n;j++)
				dis[j]=nil;
		
		//	printf("%d\n",dis[4]);
			dis[i]=0;		
			flag[i]=1;
			sum=dij(i,1);
		//	printf("%d\n",sum);


			if(sum<min)
			{
				min=sum;
				t=i;
			}
		}
		if(min==nil)
		{
			printf("disjoint\n");
		}
		else
			printf("%d %d\n",t,min);
	}
	return 0;
}






