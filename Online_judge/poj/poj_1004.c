#include<stdio.h>
int main()
{
	int i;
	double a,sum=0.0;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&a);
		sum+=a;
	}
	printf("$%.2f",sum/12);
	return 0;
}
