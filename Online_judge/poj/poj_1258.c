#include<stdio.h>
int n,path[101][101],sum;
int flag[101],que[101],head;
void prime()
{
	int i,j,min=1<<30;
	int r,t;
	for(i=1;i<=head;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(que[i]!=j&&flag[j]==0&&path[que[i]][j]<min)
			{
				min=path[que[i]][j];
				t=que[i];
				r=j;
			}
		}
	}
	if(min==1<<30)  return;
	sum+=path[t][r];
	flag[r]=1;
	que[++head]=r;
	prime();
}


	

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",&path[i][j]);
		}
		memset(flag,0,sizeof(flag));
    	flag[1]=1;
    	que[1]=1;
    	head=1;
		sum=0;
    	prime();
		printf("%d\n",sum);
	}
	return 0;
}


