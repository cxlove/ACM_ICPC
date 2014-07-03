/*
ID:cxlove
PROB:POJ 1696 Space Ant
DATA:2012.2.9
HINT:叉积
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
struct Point{
	int x,y;
}p[100],qd,zd,temp;
int n,idx,mark[100];
double mmax;
vector<int>que;
int xmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.y-p.y)-(p2.x-p.x)*(p1.y-p.y);
}
int pmul(Point p,Point p1,Point p2){
	return (p1.x-p.x)*(p2.x-p1.x)+(p1.y-p.y)*(p2.y-p1.y);
}
double dis(Point p1,Point p2){
	return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(mark,0,sizeof(mark));
		zd.y=10000;
		for(int i=0;i<n;i++){
			int j,x,y;
			scanf("%d%d%d",&j,&x,&y);
			p[j].x=x;p[j].y=y;
			if(y<zd.y){
				zd.y=y;
				zd.x=x;
				idx=j;
			}
			else if(y==zd.y&&x<zd.x){
				zd.x=x;
				idx=j;
			}
		}
		qd.x=0.;qd.y=zd.y;
		que.clear();
		mark[idx]=1;
		que.push_back(idx);
		int ans=1;	
		while(1){
			idx=-1;mmax=-100000.0;
			for(int i=1;i<=n;i++){
				if(mark[i]==0){
					int tt=xmul(qd,zd,p[i]);
					double ttt=(double)pmul(qd,zd,p[i])/(1.0*dis(qd,zd)*dis(zd,p[i]));
					if((tt>=0&&(ttt-mmax)>(1e-8))||(tt>=0&&fabs(ttt-mmax)<(1e-8)&&dis(zd,p[i])<dis(zd,p[idx]))){
						idx=i;
						mmax=ttt;
					}
				}
			}
			if(idx==-1)
				break;
			ans++;
			mark[idx]=1;
			qd=zd;zd=p[idx];
			que.push_back(idx);
		}
		printf("%d",ans);
		for(int i=0;i<que.size();i++)
			printf(" %d",que[i]);
		printf("\n");
	}
	return 0;
}