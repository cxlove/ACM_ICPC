#include<stdio.h>
#include<math.h>
double path[101][101];
int n,flag[101],que[101],head;
int head;
double sum=0;
struct point
{
	double x,y;
}
a[101];
void prime()
{
	int j,i,r=-1,t;
	double min=1<<30;
	for(i=1;i<=head;i++)
	{
		for(j=1;j<=n;j++)
		{
	    	if(que[i]!=j&&path[que[i]][j]<min&&flag[j]==0)			
			{
		    	min=path[que[i]][j];
				t=que[i];
		    	 r=j;
			}
		}
	}
	if(min==1<<30)
		return;
    flag[r]=1;
	sum=sum+path[t][r];
	que[++head]=r;
	prime();
}
int main()
{
    int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			path[i][j]=path[j][i]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
		//	printf("%f\n",path[i][j]);
		}
	}
	memset(flag,0,sizeof(flag));
	flag[1]=1;
	que[1]=1;
	head=1;
	prime();
	printf("%.2f\n",sum);
	return 0;
}
