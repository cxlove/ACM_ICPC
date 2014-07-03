#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int n;
int num[101];

double x[101][41];
double y[101][41];

double dp[101][41];

void read(){
//	ifstream cin("in.txt");
	int i,j,k,s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
		for(j=1;j<=num[i];j++)
			cin>>x[i][j]>>y[i][j];
	}
	double ans=-1;
	for(i=1;i<=num[1];i++)
	{
		for(j=1;j<=num[2];j++)
			dp[2][j]=sqrt((x[2][j]-x[1][i])*(x[2][j]-x[1][i])+(y[2][j]-y[1][i])*(y[2][j]-y[1][i]));
		for(j=3;j<=n;j++)
			for(k=1;k<=num[j];k++)
			{
				dp[j][k]=100000000;
				for(s=1;s<=num[j-1];s++)
					dp[j][k]=min(dp[j][k],dp[j-1][s]+sqrt((x[j-1][s]-x[j][k])*(x[j-1][s]-x[j][k])+(y[j-1][s]-y[j][k])*(y[j-1][s]-y[j][k])));
			}
		double t=100000000;
		for(j=1;j<=num[n];j++)
		{
			t=min(t,dp[n][j]+sqrt((x[n][j]-x[1][i])*(x[n][j]-x[1][i])+(y[n][j]-y[1][i])*(y[n][j]-y[1][i])));
		}

		if(ans==-1) ans=t;
		else ans=min(ans,t);
	}
	printf("%d\n",(int)(100*ans));
					

}

int main(){
	read();
	return 0;
}
