/*
ID:cxlove
PROB:POJ 3304 Segments
DATA:2012.2.8
HINT:直线线段相交
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define eps 1e-8
using namespace std;
struct Point{
	double x,y;
};
struct Segment{
	Point a,b;
}s[110];
int n;
double xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
double dis(Point a,Point b){  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}  
bool check(Point p1,Point p2){
	if(dis(p1,p2)<eps)
		return false;
	for(int i=0;i<n;i++)
		if(xmul(p1,p2,s[i].a)*xmul(p1,p2,s[i].b)>eps)
			return false;
	return true;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
		bool flag=false;
		for(int i=0;!flag&&i<n;i++)
			for(int j=i+1;!flag&&j<n;j++)
				if(check(s[i].a,s[j].a)||check(s[i].a,s[j].b)||check(s[i].b,s[j].a)||check(s[i].b,s[j].b))
					flag=true;
		if(n==1) flag=true;
		if(flag)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}
