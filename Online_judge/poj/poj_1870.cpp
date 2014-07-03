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
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(!a&&!b) break;
		a--;b--;
		int x=(p[a].x-p[b].x),y=(p[a].y-p[b].y),ans;
		if(x*y>0) ans=abs(x+y);
		else ans=max(abs(x),abs(y));
		printf("The distance between cells %d and %d is %d.\n",a+1,b+1,ans);
	}
	return 0;
}