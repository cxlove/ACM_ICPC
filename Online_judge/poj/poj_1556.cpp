/*
ID:cxlove
PROB:poj 1556 The Doors
DATA:2012.2.8
HINT:计算几何+最短路
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define inf 1<<30
using namespace std;
struct Point{
	double x,y;
}p[100];
struct segment{
	Point a,b;
}s[100];
int p_num,s_num;
double path[100][100];
double dis(Point p1,Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
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
bool check(Point a1,Point b1){
	segment temp;temp.a=a1;temp.b=b1;
	for(int i=0;i<s_num;i++)
		if(across(temp,s[i]))
			return true;
	return false;
}
int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==-1)
			break;
		p[0].x=0;p[0].y=5;
		p_num=1;s_num=0;
		for(int i=0;i<n;i++){
			double x0,y1,y2,y3,y4;
			Point temp;
			scanf("%lf%lf%lf%lf%lf",&x0,&y1,&y2,&y3,&y4);
			p[p_num].x=x0;p[p_num++].y=y1;
			temp.x=x0;temp.y=0;
			s[s_num].a=temp;s[s_num++].b=p[p_num-1];
			p[p_num].x=x0;p[p_num++].y=y2;
			p[p_num].x=x0;p[p_num++].y=y3;
			s[s_num].a=p[p_num-2];s[s_num++].b=p[p_num-1];
			p[p_num].x=x0;p[p_num++].y=y4;
			temp.x=x0;temp.y=10;
			s[s_num].a=temp;s[s_num++].b=p[p_num-1];
		}
		p[p_num].x=10;p[p_num++].y=5;
		memset(path,0,sizeof(path));
		for(int i=0;i<p_num;i++)
			for(int j=i+1;j<p_num;j++)
				if(check(p[i],p[j]))
					path[i][j]=inf;
				else
					path[i][j]=path[j][i]=dis(p[i],p[j]);
		for(int k=0;k<p_num;k++)
			for(int i=0;i<p_num;i++)
				for(int j=0;j<p_num;j++)
					path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
		printf("%.2lf\n",path[0][p_num-1]);
	}
	return 0;
}

			


