/*
ID:cxlove
PROB:POJ 2653 Pick-up sticks
DATA:2012.2.8
HINT:线段相交
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Point{
	double x,y;
};
struct segment{
	Point a,b;
}s[100005];
int n,flag[1000005];
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
	while(scanf("%d",&n)&&n){
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
					if(across(s[i],s[j])){
						flag[i]=1;			
						break;
					}
		}
		printf("Top sticks:");
		int i;
		for(i=1;i<=n;i++)
			if(!flag[i]){
				printf(" %d",i);
				break;
			}
		for(i++;i<=n;i++)
			if(!flag[i])
				printf(", %d",i);
		printf(".\n");
	}
	return 0;
}