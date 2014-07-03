#include<iostream>
#include<cstring>
#include<cmath>
#define INF 100000000
#define Min(a,b)  a<b?a:b
using namespace std;
struct Point
{
	double x,y;
}cow[105][45];
int s[105];
double dp[105][45];
double Distance(Point &p1,Point &p2)
{
	double dis;
	dis=sqrt(1.0*(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	return dis;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i];j++)
		{
			cin>>cow[i][j].x>>cow[i][j].y;
		}
	}
//	memset(dp,0,sizeof(dp));
	double mm=INF;
	for(int i=0;i<s[0];i++)
	{
		for(int j=0;j<s[1];j++)
			dp[1][j]=Distance(cow[1][j],cow[0][i]);
		for(int j=2;j<n;j++)
	    {
	    	for(int k=0;k<s[j];k++)
	    	{
		    	dp[j][k]=INF;
		    	for(int r=0;r<s[j-1];r++)
			    {
				     dp[j][k]=Min(dp[j][k],dp[j-1][r]+Distance(cow[j-1][r],cow[j][k]));
		    	}
			}	    
		}
		double temp=INF;
    	for(int j=0;j<s[n-1];j++)
    	{
			temp=Min(temp,dp[n-1][j]+Distance(cow[0][i],cow[n-1][j]));
	    	
	    }
		mm=Min(mm,temp);
	}
	int ans=( int) (100*mm);

	cout<<ans<<endl;
//	system("pause");
	return 0;
}








