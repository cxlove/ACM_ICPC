#include<stdio.h>
#define max 1<<30
int n,m,w,sum;
struct map
{
	int a,b,c;
}
e[6000];
int bf()
{
	int flag,i,j;
	int path[6000];
	for(i=2,path[1]=0;i<=n;i++)
	{
		path[i]=max;
	}
	while(1)
	{
		flag=0;
		for(j=1;j<=sum;j++)
		{
			if(path[e[j].a]+e[j].c<path[e[j].b])
			{
				flag=1;
				path[e[j].b]=e[j].c+path[e[j].a];
			}
		}
		if(path[1]<0)
			return 1;
		if(flag==0)
			return 0;
	
	}
	return 0;
}



int main()
{
	int f,i,z,x,y;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d%d%d",&n,&m,&w);i=0;
		sum=2*m+w;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			e[++i].a=x;
			e[i].b=y;
			e[i].c=z;
			e[++i].a=y;
			e[i].b=x;
			e[i].c=z;
		}
		while(w--)
		{
			scanf("%d%d%d",&x,&y,&z);
			e[++i].a=x;
			e[i].b=y;
			e[i].c=-z;
		}
		if(bf()==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}


