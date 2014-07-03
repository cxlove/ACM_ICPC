/*
ID:cxlove
PROB:poj 1039 Pipe
DATA:2012.2.10
HINT:枚举 直线线段相交
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define inf 1<<30
#define eps 1e-6
using namespace std;
struct Point{
	double x,y;
}a[100],b[100];
int n;
double xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
bool across1(Point p1,Point p2,Point p3,Point p4){
	if(xmul(p1,p2,p3)*xmul(p1,p2,p4)<eps)
			return true;
	return false;
}
bool across2(Point p1,Point p2,Point p3,Point p4){
	if(xmul(p1,p2,p3)*xmul(p1,p2,p4)<0)
			return true;
	return false;
}
double getx(Point p1,Point p2,Point p3,Point p4){
	return (xmul(p1,p3,p2)*p4.x-xmul(p1,p4,p2)*p3.x)/(xmul(p1,p3,p2)-xmul(p1,p4,p2));
}
double slove(){
	double mmax=-inf;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int k;
			for(k=0;k<n;k++)
				if(!across1(a[i],b[j],a[k],b[k]))
					break;
			if(k==n)
				return -inf;
			if(k>i&&k>j){
				if(across2(a[i],b[j],a[k],a[k-1]))
					mmax=max(mmax,getx(a[i],b[j],a[k],a[k-1]));
				if(across2(a[i],b[j],b[k],b[k-1]))
					mmax=max(mmax,getx(a[i],b[j],b[k],b[k-1]));
			}
		}
	return mmax;
}
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&a[i].x,&a[i].y);
			b[i].x=a[i].x;b[i].y=a[i].y-1;
		}
		double temp=slove();
		if(temp==-inf)
			printf("Through all the pipe.\n");
		else
			printf("%.2lf\n",temp+eps);
	}
	return 0;
}

