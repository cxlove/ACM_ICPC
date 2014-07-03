#include<stdio.h>
int n,count=0;
char ope[4]="+-.";
char ch[20];
void dfs(int i)
{
	int j,sign,t,sum;
	if(i>n)  return;
	if(i==n)
	{
		sum=0;t=1;sign=1;
		for(j=1;j<n;j++)
		{
			if(ch[j]=='.')
			{
				if(j<9)
					t=t*10+j+1;
				else
					t=t*100+j+1;
			}
			else
			{
				sum+=t*sign;
				t=j+1;
				if(ch[j]=='+')
				{
					sign=1;
				}
				else
					sign=-1;
			}
		}
		sum+=t*sign;
		if(sum==0)
		{
			count++;
			if(count<=20)
			{			
				for(j=1;j<n;j++)			
				{			
					printf("%d %c ",j,ch[j]);			
				}		
				printf("%d\n",n);
			}
		}
		
	}		
	else
	{
		for(j=0;j<3;j++)
		{
			ch[i]=ope[j];
			dfs(i+1);
		}
	}
	return ;
}
		

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
	
		dfs(1);
		printf("%d\n",count);
	}
	return 0;
}
