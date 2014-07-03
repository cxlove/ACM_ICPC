#include<stdio.h>
int count[30];
int cmp(const int *a,const int *b)
{
	return count[*a]-count[*b];
}
int main()
{
	int n,m,i,j,b[30][30];
	int k,x,y;
	int ans[30];
	int flag,ip;//标志变量
	char s[10];
    while(scanf("%d%d",&n,&m)&&n+m)
	{
		flag=0;
		ip=0;
		memset(b,0,sizeof(b));
		memset(count,0,sizeof(count));
		for(i=0;i<n;i++)
		{
			ans[i]=i;
		}
		for(k=1;k<=m;k++)
		{
			scanf("%s",s);
			if(ip)  continue;
			x=s[0]-'A';
			y=s[2]-'A';
			if(b[y][x]==1)
			{
				ip=k;
				continue;
			}
			if(b[x][y])  continue;
			b[x][y]=1;
			count[x]++;
			for(i=0;i<n;i++)
			{
				if(b[i][x])
				{
					if(b[i][y]==0)
					{
						b[i][y]=1;
						count[i]++;
					}
				}
				if(b[y][i])
				{
					if(b[x][i]==0)
					{
						b[x][i]=1;
						count[x]++;
					}
				}
			}
			qsort(ans,n,sizeof(int),cmp);
			for(i=0,j=1;i<n;i++)
			{
				if(count[ans[i]]!=i)  j=0;
			}
			if(j)  flag=k;
		}
		if(flag)
		{
			printf("Sorted sequence determined after %d relations: ",flag);
			for(i=n-1;i>=0;i--)
			{
				printf("%c",ans[i]+'A');
			}
			printf(".\n");
		}
		else if(ip)
		{
			printf("Inconsistency found after %d relations.\n",ip);
		}
		else
		{
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}




				



