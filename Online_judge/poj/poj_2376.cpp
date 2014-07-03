#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node
{
	int l,r;
}cow[25005];
bool cmp(node a1,node a2)
{
	return a1.l!=a2.l?a1.l<a2.l:a1.r>a2.r;
}
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++)
		scanf("%d%d",&cow[i].l,&cow[i].r);
	sort(cow,cow+n,cmp);
	cow[n].l=10000000;
	int qd=1,sum=0;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(cow[i].l>qd)
		{
			flag=false;
			break;
		}
		if(cow[i].l==qd)
		{
			sum++;
			qd=cow[i].r+1;
		}
		else
		{
			int k=-1,end=0;
			for(int j=i;j<n;j++)
				if(cow[j].l>qd) break;
				else if(cow[j].r>end)
				{
					end=cow[j].r;
					k=j;
				}
				if(k==-1) {flag=false;break;}
			i=k;
			sum++;qd=cow[k].r+1;
		}
		if(qd>t) break;
	}
	if(flag&&qd>t)
		printf("%d\n",sum);
	else
		printf("-1\n");
//	system("pause");
	return 0;
}






	
