#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int path[1001][1001],que[1001],n,m,sum=0,dis[1005];
bool vis[1001],mark=true;
int prime()
{
	for(int i=1;i<=n;i++)
		dis[i]=path[1][i];
	vis[1]=true;
	for(int k=1;k<n;k++)
	{
		int mmin=0;
		int temp=-1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<mmin){
				mmin=min(mmin,dis[j]);
				temp=j;
			}
		}
		if(temp==-1)  return temp;
		else{
			sum-=mmin;
			vis[temp]=true;
		}
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])
				dis[j]=min(path[temp][j],dis[j]);
		}
	}
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(vis,false,sizeof(vis));
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		path[a][b]=min(path[a][b],-c);
		path[b][a]=min(path[b][a],-c);
	}
	printf("%d\n",prime());
	//system("pause");
	return 0;
}
	
