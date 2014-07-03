#include<iostream>
#include<cmath>
#include<cstdio>
#define pi 3.141592653
using namespace std;
int main()
{
	int tt;
	cin>>tt;
	for(int cc=1;cc<=tt;cc++)
	{
		double n,m,t,c;
		double p1,p2,p3,p4;
		//cin>>n>>m>>t>>c;
		scanf("%lf%lf%lf%lf",&n,&m,&t,&c);
		
		printf("Case %d:\n",cc);
		p2=n*(m-1)*c*(t-c)+(m-1)*c*c+(n-1)*m*c*(t-c)+(n-1)*c*c;
		//p2=(m-1)*n*t*c+(n-1)*m*t*c-2*(m-1)*(n-1)*c*c;
		p3=(c*c-pi*c*c/4.0)*(n-1)*(m-1);
		p4=(m-1)*(n-1)*pi*c*c/4.0;
		p1=(n*m*t*t)-p2-p3-p4;

		printf("Probability of covering 1 tile  = %.4lf%%\n",p1*100/(n*m*t*t));
		//cout<<"%"<<endl;
		printf("Probability of covering 2 tiles = %.4lf%%\n",p2*100/(n*m*t*t));
		//cout<<"%"<<endl;
		printf("Probability of covering 3 tiles = %.4lf%%\n",p3*100/(n*m*t*t));
		//cout<<"%"<<endl;
		printf("Probability of covering 4 tiles = %.4lf%%\n",p4*100/(n*m*t*t));\
		//cout<<"%"<<endl;
		if(tt!=cc)
			cout<<endl;
	}
	return 0;
}