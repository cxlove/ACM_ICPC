#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-8
using namespace std;
const int N = 105;
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	inline Point operator-(const Point&p)const{
		return Point(x-p.x,y-p.y);
	}
	inline double operator*(const Point &p)const{
		return x*p.y-y*p.x;
	}
	inline Point operator*(const double &k)const{
		return Point(x*k,y*k);
	}
	inline Point operator/(const double &k)const{
		return Point(x/k,y/k);
	}
}a[N],b[N],c[N],d[N],p[4];
struct Line{
	Point a,b;
	Line(){}
	Line(Point _a,Point _b):a(_a),b(_b){}
	inline double operator*(const Point &p)const{
		return (b-a)*(p-a);
	}
	inline Point CrossPoint(const Line &v){
		double s1=v*a,s2=v*b;
		return (a*s2-b*s1)/(s2-s1);
	}
};
double getarea(Point *p,int n){
	double area=0;
	for(int i=2;i<n;i++)
		area+=fabs((p[i]-p[0])*(p[i-1]-p[0]))*0.5;
	return area;
}
void out(){
	for(int i=0;i<4;i++)
		printf("%.6f %.6f\n",p[i].x+eps,p[i].y+eps);
	printf("---------------------------------------\n");
}
int n;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		a[0]=Point(0,0);a[n+1]=Point(1,0);
		b[0]=Point(0,1);b[n+1]=Point(1,1);
		c[0]=Point(0,0);c[n+1]=Point(0,1);
		d[0]=Point(1,0);d[n+1]=Point(1,1);
		for(int i=1;i<=n;i++){
			scanf("%lf",&a[i].x);
			a[i].y=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&b[i].x);
			b[i].y=1;
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&c[i].y);
			c[i].x=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&d[i].y);
			d[i].x=1;
		}
		double ans=0,sum=0;
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=n+1;j++){
				p[0]=Line(c[j-1],d[j-1]).CrossPoint(Line(a[i-1],b[i-1]));
				p[1]=Line(c[j-1],d[j-1]).CrossPoint(Line(a[i],b[i]));
				p[2]=Line(c[j],d[j]).CrossPoint(Line(a[i],b[i]));
				p[3]=Line(c[j],d[j]).CrossPoint(Line(a[i-1],b[i-1]));
				sum+=getarea(p,4);
				//out();
				ans=max(ans,getarea(p,4));
			}
		}
		//printf("%.6f\n",sum);
		printf("%.6f\n",ans);
	}
	return 0;
}