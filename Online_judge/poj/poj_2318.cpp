/*
ID:cxlove
PROB:POJ 2318 TOYS
DATA:2012.2.6
HINT:叉积 计算几何
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Point{
	int x,y;
}lu,rd;
struct line{
	Point a,b;
}l[5005];
int ans[5005],n,m;
bool cmp(line l1,line l2){
	return l1.a.x<l2.a.x;
}
int xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
int main(){
	while(scanf("%d",&n)&&n!=0){
		scanf("%d%d%d%d%d",&m,&lu.x,&lu.y,&rd.x,&rd.y);
		for(int i=0;i<n;i++){
			scanf("%d%d",&l[i].a.x,&l[i].b.x);
			l[i].a.y=lu.y;
			l[i].b.y=rd.y;
		}
		l[n].a.x=rd.x;l[n].a.y=lu.y;
		l[n].b.x=rd.x;l[n].b.y=rd.y;
		memset(ans,0,sizeof(ans));
		sort(l,l+n,cmp);
		while(m--){
			Point p;
			scanf("%d%d",&p.x,&p.y);
			for(int i=0;i<=n;i++)
				if(xmul(l[i].a,l[i].b,p)<0){
					ans[i]++;
					break;
				}
		}
		for(int i=0;i<=n;i++)
			printf("%d: %d\n",i,ans[i]);
		printf("\n");
	}
	return 0;
}
				

