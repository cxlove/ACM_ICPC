#include<iostream>
#include<cmath>
using namespace std;
struct Point
{
	int x,y;
}p[1005];
int q[1005];
int n,len;
float dis(Point p1,Point p2)
{
	return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float xmul(Point p1,Point p2,Point p0)
{
	return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
}
void gramscan()
{
	int k=0;
	for(int i=1;i<n;i++)
	{
		if(p[i].y<p[k].y||(p[i].y==p[i].y&&p[i].x<p[k].x))
			k=i;
	}
	Point temp;
	temp=p[0];
	p[0]=p[k];
	p[k]=temp;
	for(int i=1;i<n-1;i++)
	{
		k=i;
		for(int j=i+1;j<n;j++)
			if(xmul(p[j],p[k],p[0])>0||(xmul(p[j],p[k],p[0])==0&&dis(p[j],p[0])<dis(p[k],p[0])))
				k=j;
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	}
	q[0]=0;
	q[1]=1;
	int top=2;
	for(int i=2;i<n;i++)   {     
		while(top>1&&xmul(p[i],p[q[top-1]],p[q[top-2]])>=0)  top--;      	
		q[top++]=i;    
	}
	len=top;
}
bool judge()
{
	for(int i=0;i<len;i++)
	{
		int p1=i,p2=(i+1)%len;
		int num=0;
		for(int j=0;j<n;j++)
		{
			if((p[j].x==p[q[p1]].x&&p[j].y==p[q[p1]].y)||(p[j].x==p[q[p2]].x&&p[j].y==p[q[p2]].y))
			continue;
		//	if((p[j].x==p[p1].x&&p[p1].x==p[p2].x)||(p[j].y==p[p1].y&&p[p1].y==p[p2].y)||((p[p2].x-p[p1].x)*(p[j].y-p[p1].y)==(p[p2].y-p[p1].y)*(p[j].x-p[p1].x)&&(p[j].x-p[p1].x)*(p[p2].x-p[j].x)<0))
			if( xmul( p[j], p[ q[p1] ], p[ q[p2] ] ) == 0 )	
			    num++;
		}
		if(!num)
			return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		if(n<=5)
		{
			cout<<"NO"<<endl;
			continue;
		}
		gramscan();
		if(judge())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}


		



	
