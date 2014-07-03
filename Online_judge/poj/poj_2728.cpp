#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1005;
const double eps = 1e-5;
struct Point{
	int x,y,h;
	void input(){
		scanf("%d%d%d",&x,&y,&h);
	}
}p[N];
int n;
double len[N][N],cost[N][N];
inline double sqr(double a){
	return a*a;
}
inline double  getdist(Point p1,Point p2){
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}
double prime(double mid){
	bool vis[N];
	double dist[N];
	int pre[N];
	for(int i=0;i<n;i++){
		dist[i]=cost[0][i]-mid*len[0][i];
		vis[i]=false;
		pre[i]=0;
	}
	vis[0]=true;
	double up=0.0,down=0.0;
	for(int i=1;i<n;i++){
		double mn=1000000000.0;
		int idx;
		for(int j=0;j<n;j++){
			if(!vis[j]&&dist[j]<mn){
				mn=dist[j];
				idx=j;
			}
		}
		vis[idx]=true;
		up+=cost[pre[idx]][idx];
		down+=len[pre[idx]][idx];
		for(int j=0;j<n;j++){
			if(!vis[j]&&dist[j]>cost[idx][j]-mid*len[idx][j]){
				dist[j]=cost[idx][j]-mid*len[idx][j];
				pre[j]=idx;
			}
		}
	}
	//cout<<up<<" "<<down<<endl; 
	return up/down;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)
			p[i].input();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cost[i][j]=abs(p[i].h-p[j].h);
				len[i][j]=getdist(p[i],p[j]);
			}
		}
		double ans=1.0;
		while(true){
			double tmp=prime(ans);
			if(abs(tmp-ans)<eps)
				break;
			ans=tmp;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}