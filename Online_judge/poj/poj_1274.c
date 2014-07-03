#include<stdio.h>
int flag[201],path[201][201];
int n,m,pre[201];
int dfs(int k)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(flag[i]==0&&path[k][i])
		{
			flag[i]=1;
			if(pre[i]==0||dfs(pre[i]))
			{
				pre[i]=k;
				return 1;
			}
		}
	}
	return 0;

}
int main()
{
	int a,i,j,sum=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{sum=0;

	memset(path,0,sizeof(path));

	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		while(a--)
		{
			scanf("%d",&j);
			path[i][j]=1;
		}
	}
	memset(pre,0,sizeof(pre));

	for(i=1;i<=n;i++)
	{
		memset(flag,0,sizeof(flag));
		if(dfs(i))  sum++;
	}
	printf("%d\n",sum);
	}
	return 0;
}


