#include<iostream>
using namespace std;
#define max_n 9999999
int d[6000],sp[20000];
int count,n;
bool flag;
struct edge
{
	int l,r,t;
}e[6000];
bool search(int v)
{
	int i,j,k,t=0,temp=-1;
	bool jud;
	for(i=0;i<v;i++)
		d[i]=max_n;
	d[1]=0;
	for(;;)
	{
		jud=false;
		for(j=0;j<v;j++)
		{
			if(d[e[j].r]>d[e[j].l]+e[j].t)
			{
				d[e[j].r]=d[e[j].l]+e[j].t;jud=true;

			}
		}
		if(d[1]<0)
			return true;
		if(!jud)
			return false;
	}



	return false;
}
int main()
{
	int w,m,f,i,j;
	//freopen("d:\\1.txt","r",stdin);
	cin >> f;
	while(f--)
	{
		cin >> n >> m >> w;j=0;
		for(i=0;i<m;i++)
		{
			cin >> e[j].l >> e[j].r >> e[j].t;j++;
			e[j].l=e[j-1].r;e[j].r=e[j-1].l;e[j].t=e[j-1].t;j++;
		}
		for(i=0;i<w;i++)
		{
			cin >> e[j].l >> e[j].r >> e[j].t;
			e[j].t=-e[j].t;j++;
		}
		flag=search(j);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}