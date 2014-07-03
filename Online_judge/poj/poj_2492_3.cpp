#include<cstdio>
#define	M 2003
int father[M];
bool	sex[M];
int Find_Root(int x)//找到根节点，不含路劲压缩  time 1032ms  Accept
{
	bool s=false;
	int r=x;
	while(father[r]!=r)
	{
		s^=sex[r];
		r=father[r];
	}
	sex[x]=s;
	father[x]=r;
	return r;
}

int main()
{
	int a,b,i,j,n,m,k,root_a,root_b,l;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		bool flag=true;
		scanf("%d %d",&n,&m);
		for(l=0;l<=n;l++)
		{
			father[l]=l;
			sex[l]=false;//自己和自己性别当然相同。。。
		}
		for(j=0;j<m;j++)
		{
			scanf("%d",&a);
			scanf("%d",&b);
			if(flag)
			{
				root_a=Find_Root(a);
				root_b=Find_Root(b);
				if(root_a==root_b)
				{
					flag=sex[a]^sex[b];
				}
				else
				{
					father[root_a]=root_b;
					sex[root_a]=!(sex[a]^sex[b]);
				}
			}
		}
		printf("Scenario #%d:\n",i+1);
		if(flag)
			printf("No suspicious bugs found!\n\n");
		else
			printf("Suspicious bugs found!\n\n");
	}
	return 0;
}

