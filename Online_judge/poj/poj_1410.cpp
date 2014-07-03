/*
ID:cxlove
PROB:POJ 1410 Intersection
DATA:2012.2.9
HINT:线段与矩形相交
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-8
using namespace std;
struct Point{
	int x,y;
}top_left,down_right,top_right,down_left;
struct segment{
	Point a,b;
}seg,s[4];
int xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
bool across(segment s1,segment s2){
	if(max(s1.a.x,s1.b.x)>=min(s2.a.x,s2.b.x)&&max(s2.a.x,s2.b.x)>=min(s1.a.x,s1.b.x)
		&&max(s1.a.y,s1.b.y)>=min(s2.a.y,s2.b.y)&&max(s2.a.y,s2.b.y)>=min(s1.a.y,s1.b.y))
		if(xmul(s1.a,s1.b,s2.a)*xmul(s1.a,s1.b,s2.b)<=eps)
			if(xmul(s2.a,s2.b,s1.a)*xmul(s2.a,s2.b,s1.b)<=eps)
				return true;
	return false;
}
bool check(segment seg){
	for(int i=0;i<4;i++)
		if(across(seg,s[i]))
			return true;
	return false;
}
bool inside(segment seg){
	if(seg.a.x>=top_left.x&&seg.a.x<=down_right.x&&seg.a.y<=top_left.y&&seg.a.y>=down_right.y)
		if(seg.b.x>=top_left.x&&seg.b.x<=down_right.x&&seg.b.y<=top_left.y&&seg.b.y>=down_right.y)
			return true;
	return false;
}
int main(){
	int t;
	//freopen("1410.in","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&seg.a.x,&seg.a.y,&seg.b.x,&seg.b.y);
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		top_left.x=min(x1,x2);top_left.y=max(y1,y2);
		top_right.x=max(x1,x2);top_right.y=max(y1,y2);
		down_right.x=max(x1,x2);down_right.y=min(y1,y2);
		down_left.x=min(x1,x2);down_left.y=min(y1,y2);
		s[0].a=top_left;s[0].b=top_right;
		s[1].a=top_right;s[1].b=down_right;
		s[2].a=down_right;s[2].b=down_left;
		s[3].a=down_left;s[3].b=top_left;
		bool flag=false;
		if(check(seg))
			flag=true;
		else if(inside(seg))
			flag=true;
		if(flag)
			printf("T\n");
		else
			printf("F\n");
	}
	return 0;
}
