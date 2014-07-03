#include<stdio.h>
#include<string.h>
#define Max(a,b) a>b?a:b
int a[102][102],b[102];
int main()
{
	int i,j,k,n,sum=0,max=-99999999;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
		scanf("%d",&a[i][j]);
		}
  
	for(i=1;i<=n;i++)
	{
	   for(j=1;j<=n;j++)
	   {
            b[j]=0;
	   }
		for(j=i;j<=n;j++)
		{
			for(sum=0,k=1;k<=n;k++) 
			{
				b[k]+=a[j][k];
			   sum=Max(sum+b[k],0);
 if(sum>max) max=sum;
			}
			
		}
	}
	printf("%d\n",max);
	return 0;
}