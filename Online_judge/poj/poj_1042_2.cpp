#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,h,f[30],d[30],t[30],Case=0;
	while(scanf("%d",&n),n>0)
	{
		if(Case!=0)  printf("\n");
		Case++;
		scanf("%d",&h);
		h=h*60;
		for(int i=1;i<=n;i++)
			scanf("%d",&f[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		t[1]=0;
		for(int i=1;i<=n-1;i++)
		{
			int a;
			scanf("%d",&a);
			t[i+1]=t[i]+a*5;
		}
		int fish=0;
		int f_temp[30];
		int spe[30];
		int spe_temp[30];
		int tt;
		for(int i=1;i<=n;i++)
			spe[i]=-1;
	
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			tt=h-t[i];
			for(int j=1;j<=n;j++)
				f_temp[j]=f[j];
			memset(spe_temp,0,sizeof(spe_temp));
			while(tt>=5)
			{
				int mmax=0,maxj=-1;
				for(int j=1;j<=i;j++)
				{
					if(f_temp[j]>mmax)
					{
						mmax=f_temp[j];
						maxj=j;
					}
				}
				if(maxj==-1)
					break;
					tt=tt-5;
				spe_temp[maxj]++;
				sum+=f_temp[maxj];
				f_temp[maxj]=f_temp[maxj]-d[maxj];
			}
			if(sum>fish)
			{
				fish=sum;
				for(int j=1;j<=n;j++)
					spe[j]=spe_temp[j];
				spe[1]+=tt/5;
			}
			else if(sum==fish)
			{
				bool flag=false;
				for(int j=1;j<=n;j++)
					if(spe[j]<spe_temp[j])
					{
						flag=true;
						break;
					}
					else if(spe[j]>spe_temp[j])
						break;
				if(flag)
				{
					fish=sum;
			    	for(int j=1;j<=n;j++)
				    	spe[j]=spe_temp[j];
			    	spe[1]+=tt/5;
				}
			}
		}
		for(int i=1;i<n;i++)
			printf("%d, ",spe[i]*5);
		printf("%d\nNumber of fish expected: %d\n",spe[n]*5,fish);
	}
	return 0;
}



				



