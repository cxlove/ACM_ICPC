/*
ID:cxlove
PROB:poj 1066 Treasure Hunt
DATD:2012.2.9
HINT:枚举+线段相交
*/
#include<iostream>
#include<cstdio>
using namespace std;
struct Point{
	double x,y;
}treasure;
struct segment{
	Point a,b;
}s[100];
int n;
double xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
bool across(segment s1,segment s2){
	if(max(s1.a.x,s1.b.x)>min(s2.a.x,s2.b.x)&&max(s2.a.x,s2.b.x)>min(s1.a.x,s1.b.x)
		&&max(s1.a.y,s1.b.y)>min(s2.a.y,s2.b.y)&&max(s2.a.y,s2.b.y)>min(s1.a.y,s1.b.y))
		if(xmul(s1.a,s1.b,s2.a)*xmul(s1.a,s1.b,s2.b)<0)
			if(xmul(s2.a,s2.b,s1.a)*xmul(s2.a,s2.b,s1.b)<0)
				return true;
	return false;
}
int main(){
	int ans=10000;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf%lf%lf",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
	scanf("%lf%lf",&treasure.x,&treasure.y);
	for(int i=0;i<n;i++){
		int sum=0;
		segment temp;
		temp.a=treasure;temp.b=s[i].a;		
		for(int i=0;i<n;i++)
			if(across(temp,s[i]))
				sum++;
		ans=min(sum+1,ans);
		temp.a=treasure;temp.b=s[i].b;	
		sum=0;
		for(int i=0;i<n;i++)
			if(across(temp,s[i]))
				sum++;
		ans=min(sum+1,ans);
	}
	if(n==0)  ans=1;
	printf("Number of doors = %d\n",ans);
	return 0;
}
