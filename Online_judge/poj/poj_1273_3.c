#include<stdio.h>
#define MIN(x,y)  (x>y?y:x)
#define INF 1<<30
int n,m,path[205][205];
int maxflow()
{
	int que[201],head,tail;//BFS队列找路径
	int sum=0;
	int minflow;//每条路径的限制流量
	int pre[205];//记录父亲节点
	int flow[205][205];//记录当前流量
	int temp,i,j,k;
	memset(flow,0,sizeof(flow));
	while(1)
	{
		head=0;
		tail=0;
		memset(pre,-1,sizeof(pre));
		que[tail++]=1;
		minflow=INF;
		pre[1]=-2;
		while(head<tail)
		{
			temp=que[head++];
			for(i=1;i<=m;i++)
			{
				if(pre[i]==-1&&flow[temp][i]<path[temp][i])
				{
					que[tail++]=i;
					pre[i]=temp;
					minflow=MIN(minflow,(path[temp][i]-flow[temp][i]));
				}
			}
			if(pre[m]!=-1)
			{
				k=m;
				while(pre[k]>0)
				{
					flow[pre[k]][k]+=minflow;
					flow[k][pre[k]]-=flow[pre[k]][k];
					k=pre[k];
				}break;
			}
		}
		if(pre[m]==-1)   return sum;
		else sum+=minflow;
	}
}		

		
int main()
{
	int a,b,c;	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	memset(path,0,sizeof(path));
	while(n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		path[a][b]+=c;
	}
	printf("%d\n",maxflow());
	}
}

