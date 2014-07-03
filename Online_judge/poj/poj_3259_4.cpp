#include <iostream>
#include<string.h>
using namespace std;
const int MAX = 1<<30;
int f;
int n;
int m;
int w;
int edgeNum;

typedef struct
{
	int v1;
	int v2;
	int w;
}Edge;
Edge e[5201];

bool bellmanFord()
{
	bool flag;
	int i,j;
	int d[501];
	for(i = 2,d[1] = 0; i <= n; i++)
		d[i] = MAX;
	for(i = 1; i <= n; i++)
	{
		flag = false;
		for(j = 1; j <= edgeNum; j++)
		{
			if(d[e[j].v1] != MAX && d[e[j].v1] + e[j].w < d[e[j].v2])
			{
				d[e[j].v2] = d[e[j].v1] + e[j].w;
				flag = true;
			}
		}
		if(!flag) break;
	}
	if(i == n + 1)
		return true;
	else
		return false;
}

int main()
{
	int i,j,p,q,w1;
	cin>>f;
	for(i = 0; i < f; i++)
	{
		edgeNum = 0;
		memset(e,0,sizeof(e));
		cin>>n>>m>>w;
		for(j = 1; j <= m; j++)
		{
			edgeNum ++;
			cin>>p>>q>>w1;
			e[edgeNum].v1 = p;
			e[edgeNum].v2 = q;
			e[edgeNum].w = w1;
			edgeNum ++;
			e[edgeNum].v1 = q;
			e[edgeNum].v2 = p;
			e[edgeNum].w = w1;
		}
		for(j = 1; j <=w; j++)
		{
			edgeNum ++;
			cin>>p>>q>>w1;
			e[edgeNum].v1 = p;
			e[edgeNum].v2 = q;
			e[edgeNum].w = (-1)*w1;
		}
		if(bellmanFord())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
