#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b)
{
	return *b-*a;
}
int main()
{
	int n,i,color[12],num,gray,remain[12],max;
	while(scanf("%d",&n)&&n)
	{
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&color[i]);
			if(color[i]>max)  max=color[i];
		}
		scanf("%d",&gray);
		
		if(max%50==0)   num=max/50;
		else  num=max/50+1;
		for(i=0;i<n;i++)
		{
			remain[i]=num*50-color[i];
		}
		while(gray)
		{
			qsort(remain,n,sizeof(int),cmp);
			if(remain[2]<=0)
			{
				num++;
				for(i=0;i<n;i++)
					remain[i]+=50;
			}
			remain[0]--;
			remain[1]--;
			remain[2]--;
			gray--;
		}
		printf("%d\n",num);
	}
	return 0;
}
