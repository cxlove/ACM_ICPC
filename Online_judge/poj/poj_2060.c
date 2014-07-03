#include<stdio.h>
struct point
{
	int x,y;
};
struct taxi
{
	int a,b;
	struct point s1,s2;
}
p[501];
int flag[501],pre[501],map[501][501];
int n;
int dfs(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(flag[j]==0&&map[i][j])
		{
			flag[j]=1;
			if(pre[j]==0||dfs(pre[j]))
			{
				pre[j]=i;
				return 1;
			}
		}
	}
	return 0;
}


int match()
{
	int i,count=0;
	memset(pre,0,sizeof(pre));
	for(i=1;i<=n;i++)
	{
		memset(flag,0,sizeof(flag));
		if(dfs(i))  count++;
	}
	return count;
}
int main()
{
	int t,i,j,h,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d%d%d%d%d",&h,&m,&p[i].s1.x,&p[i].s1.y,&p[i].s2.x,&p[i].s2.y);
			p[i].a=h*60+m;
			p[i].b=p[i].a+abs(p[i].s1.x-p[i].s2.x)+abs(p[i].s1.y-p[i].s2.y);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(p[j].a>p[i].b+abs(p[i].s2.x-p[j].s1.x)+abs(p[i].s2.y-p[j].s1.y))
				{
					map[i][j]=1;
				}
			}
		}
		printf("%d\n",n-match());
	}
	return 0;
}
		
		

