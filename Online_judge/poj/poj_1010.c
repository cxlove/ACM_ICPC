#include<stdio.h>
#include<stdlib.h>
int kind[100],need,cur[4],pre[4];
int type;
int a;//用的种类
int b;//总共的张数
int c;//最大的面值
int d;//最佳的个数
int cmp(const int *x,const int *y)
{
	return *x-*y;
}

void dfs(int k,int lastk,int a1,int b1,int c1,int cost)
{
	int val,K,i;
	if(b1>4||(b1==4&&cost!=need))  return ;
	if(cost==need)
	{
		if(d==0||a1>a||(a1==a&&b1<b)||(a1==a&&b1==b&&c1>c))
		{
			a=a1;b=b1;c=c1;d=1;
			for(i=0;i<b;i++)
				pre[i]=cur[i];
		}
		else
			if(b1==b&&c1==c&&a1==a)
				d++;
		return ;
	}
	for(i=k;i<type;i++)
	{
		if(cost+kind[i]>need) break;
		K=a1;val=c1;
		if(lastk!=i)  K++;
		if(val<kind[i])  val=kind[i];
		cur[b1]=kind[i];
		dfs(i,i,K,b1+1,val,cost+kind[i]);
	}
}

int main()
{
	int i;
	while(scanf("%d",&kind[0])!=EOF)
	{
		i=1;
		while(scanf("%d",&kind[i]),kind[i]!=0)
			i++;
		type=i;
		qsort(kind,i,sizeof(int),cmp);
	//	for(i=0;i<type;i++)
	//		printf("%d\n",kind[i]);
		while(scanf("%d",&need),need!=0)
		{
			a=0;b=0;c=0;d=1;
			dfs(0,-1,0,0,0,0);
			
			if(a==0)  printf("%d ---- none\n",need);
			else
				if(d>1)  printf("%d (%d): tie\n",need,a);
				else
				{
					printf("%d (%d):",need,a);
					for(i=0;i<b;i++)
						printf(" %d",pre[i]);
					printf("\n");
				}
		}
	}
	return 0;
}
