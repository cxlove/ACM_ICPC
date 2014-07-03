#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 300;
const double pi = acos(-1.0);
struct Point{
	int x,y;
	void input(){
		scanf("%d%d",&x,&y);
	}
}p[N];
int n;
double cal(double mid){
	double d=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			double x=(p[i].x-p[j].x),y=(p[i].y-p[j].y);
			double d1=fabs(y*cos(mid)-sin(mid)*x);
			double d2=fabs(x*cos(mid)+sin(mid)*y);
			d=fmax(fmax(d1,d2),d);
		}
	}
	return d;
}
int main(){
	// freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			p[i].input();
		double low=0.0,high=asin(1.0),mid,midd,ans=1000000;
		while(high-low>1e-9){
			mid=low+(high-low)/3.0;
			midd=high-(high-low)/3.0;
			double t1=cal(mid),t2=cal(midd);
			if(t1>t2) ans=t2,low=mid;
			else ans=t1,high=midd;
		}
		printf("%.2f\n",ans*ans);
	}
	return 0;
}