#include <stdio.h>

int main()
{
	int i,j,l;
	int left[5000],right[5000];
	float doubt[5000];
	int record[5000];
	char t;
	int num,k;
	int n,max,count;
	scanf("%d%d",&num,&k);
	memset(doubt,0,sizeof(doubt));
	memset(record,0,sizeof(record));
	while(k--)
	{
		
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&left[i]);
		for(i=0;i<n;i++)
		scanf("%d",&right[i]);
		getchar();
		scanf("%c",&t);
		if(t=='<')
		{
			for(i=0;i<n;i++)
			{
				doubt[left[i]]--;
				doubt[right[i]]++;
				record[left[i]]++;
				record[right[i]]++;
			}
		}
		else if(t=='>')
		{
			for(i=0;i<n;i++)
			{
				doubt[left[i]]++;
				doubt[right[i]]--;
				record[left[i]]++;
				record[right[i]]++;
			}
		}
		else if(t=='=')
		{
			for(i=0;i<n;i++)
			{
				doubt[left[i]]=0;
				doubt[right[i]]=0;
				record[left[i]]++;
				record[right[i]]++;
			}
		}
	}
	max=fabs(doubt[num]);
	count=num;
	l=num;
	j=1;
	while(num)
	{
		num--;
		if(fabs(doubt[num])>max)
		{
			max=fabs(doubt[num]);
			count=num;
		}
	}
	if(max)
	while(l)
	{
		if(l==count){l--;continue;}
		if(max==fabs(doubt[l]))
		{
			j=0;
			break;
		}
		l--;
	}	
	else 
	{
		k=0;
		for(i=1;i<=l;i++)
		{
			if(record[i]==0)
			{
				count=i;
				k++;
				if(k>1){j=0;break;}
			}
		}
	}
	if(j)
	printf("%d\n",count);
	else printf("0\n");
	return 0;
}

