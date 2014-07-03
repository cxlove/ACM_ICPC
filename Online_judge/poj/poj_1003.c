#include <stdio.h>
int main()
{
	float a,sum=0.0;
	int count=2,flag=0;
	while(scanf("%f",&a),a!=0.0)
    {
		if(flag==1)
		   printf("\n");
		if(flag==0)
		  flag=1;
		
		count=1;
		sum=0;
		while(sum+=(1.0/(count+1)))
		{
			if(sum<a)
		 count++;
		 else break;
		 
		 }
		 printf("%d card(s)",count);
		}
	return 0;
	}
