/*
ID:cxlove
PROB:poj 1269 Intersecting Lines
DATA:2012.2.8
HINT:直线位置关系
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	printf("INTERSECTING LINES OUTPUT\n");
	while(t--){
		int x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		int a1=y1-y2;
		int a2=y3-y4;
		int b1=x2-x1;
		int b2=x4-x3;
		int c1=x2*y1-x1*y2;
		int c2=x4*y3-x3*y4;
		int d=b1*a2-b2*a1;
		int d1=c2*b1-c1*b2;
		int d2=c1*a2-c2*a1;
		if(d){
			double x=(double)((double)d1/d),y=(double)((double)d2/d);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
		else if(a1*c2==a2*c1&&b1*c2==b2*c1)
			printf("LINE\n");
		else
			printf("NONE\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
