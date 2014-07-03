#include<stdio.h>
#define pi 3.1415926
int main()
{
	int n,year,s=1;
	double x,y;
	scanf("%d",&n);
	while(n--)
	{
	
		scanf("%lf%lf",&x,&y);
		for(year=1;;year++)
		{
			if((year*100.0)/pi>(x*x+y*y))
				break;
		}
        printf("Property %d: This property will begin eroding in year %d.\n",s,year);
		s++;
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
		