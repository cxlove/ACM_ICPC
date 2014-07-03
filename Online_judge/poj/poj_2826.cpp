/*
ID:cxlove
PROB:POJ 2826 An Easy Problem?!
DATA:2012.2.10
HINT:计算几何
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct Point{
	double x,y;
}inter;
struct segment{
	Point a,b;
}s1,s2;
double Abs(double num){ return num<0?-num:num;}
double xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
bool across(segment s1,segment s2){
	if(max(s1.a.x,s1.b.x)>=min(s2.a.x,s2.b.x)&&max(s2.a.x,s2.b.x)>=min(s1.a.x,s1.b.x)
		&&max(s1.a.y,s1.b.y)>=min(s2.a.y,s2.b.y)&&max(s2.a.y,s2.b.y)>=min(s1.a.y,s1.b.y))
		if(xmul(s1.a,s1.b,s2.a)*xmul(s1.a,s1.b,s2.b)<eps)
			if(xmul(s2.a,s2.b,s1.a)*xmul(s2.a,s2.b,s1.b)<eps)
		    	return true;
	return false;
}
Point searchpoint(segment s1,segment s2){
	Point temp;
	temp.x=(xmul(s1.a,s2.b,s1.b)*s2.a.x-xmul(s1.a,s2.a,s1.b)*s2.b.x)/(xmul(s1.a,s2.b,s1.b)-xmul(s1.a,s2.a,s1.b));
	temp.y=(xmul(s1.a,s2.b,s1.b)*s2.a.y-xmul(s1.a,s2.a,s1.b)*s2.b.y)/(xmul(s1.a,s2.b,s1.b)-xmul(s1.a,s2.a,s1.b));
	return temp;
}
double area(Point p1,Point p2,Point p3){
	segment t1,t2;
//	printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	Point temp1,temp2,temp;
	temp1.x=p2.x+10000;temp1.y=p2.y;
	temp2.x=p2.x-10000;temp2.y=p2.y;
	t1.a=temp1;t1.b=temp2;t2.a=p1;t2.b=p3;
	temp=searchpoint(t1,t2);
//	printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n",p1.x,p1.y,p2.x,p2.y,temp.x,temp.y);
	return Abs(xmul(p1,p2,temp)/2.0);
}
bool parallel(segment s1,segment s2){
	return Abs((s1.a.x-s1.b.x)*(s2.a.y-s2.b.y)-(s2.a.x-s2.b.x)*(s1.a.y-s1.b.y))<eps;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf%lf",&s1.a.x,&s1.a.y,&s1.b.x,&s1.b.y);
		scanf("%lf%lf%lf%lf",&s2.a.x,&s2.a.y,&s2.b.x,&s2.b.y);
		if(!across(s1,s2)||Abs(s2.a.y-s2.b.y)<eps||Abs(s1.a.y-s1.b.y)<eps||parallel(s1,s2)){
			printf("0.00\n");
			continue;
		}
		inter=searchpoint(s1,s2);
	//	printf("%.2lf %.2lf\n",inter.x,inter.y);
		Point p1,p2;
		if(s1.a.y<s1.b.y) p1=s1.b;
		else p1=s1.a;
		if(s2.a.y<s2.b.y) p2=s2.b;
		else p2=s2.a;
		if(p1.y>p2.y) 
			swap(p1,p2);
		if(Abs(p1.x-p2.x)<eps)
			printf("0.00\n");
		else if(p2.x<p1.x&&p1.x<inter.x&&xmul(inter,p2,p1)>eps)
			printf("0.00\n");
		else if(p1.x<p2.x&&p1.x>inter.x&&xmul(inter,p1,p2)>eps)
			printf("0.00\n");
		else
			printf("%.2lf\n",area(inter,p1,p2)+eps);
	}
	return 0;
}