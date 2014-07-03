#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int N = 100000;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
}p[N<<2];
int main(){
	int x=0,y=0,n=0,t=0;
	p[n++]=Point(0,0);
	while(true){
		y++;t++;
		p[n++]=Point(x,y);
		for(int i=1;i<t;i++)x--,y++,p[n++]=Point(x,y);
		for(int i=0;i<t;i++)x--,p[n++]=Point(x,y);
		for(int i=0;i<t;i++)y--,p[n++]=Point(x,y);
		for(int i=0;i<t;i++)x++,y--,p[n++]=Point(x,y);
		for(int i=0;i<t;i++)x++,p[n++]=Point(x,y);
		for(int i=0;i<t;i++)y++,p[n++]=Point(x,y);
		if(n>N) break;
	}
	while(scanf("%d",&n)!=EOF)
		printf("%d %d\n",p[n-1].x,p[n-1].y);
	return 0;
}