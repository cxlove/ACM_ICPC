#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define eps 1e-6
using namespace std;
const int N = 105;
inline double sqr(double a){
	return a*a;
}
struct Point3{
	double x,y,z;
	Point3(){}
	Point3(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
	inline double Distance(const Point3 &p)const{
		return sqrt(sqr(x-p.x)+sqr(y-p.y)+sqr(z-p.z));
	}
};
struct Ball{
	Point3 cer;
	double r;
}ball[N];
double dist[N][N],d[N][N];
int num[N],tot,n;
void dfs(int u){
	num[u]=tot;
	for(int i=0;i<n;i++){
		if(u==i) continue;
		if(dist[u][i]<eps&&num[i]==-1)
			dfs(i);
	}
}
double prime(int cur){
	int idx,vis[N];
	double sum=0,graph[N];
	memset(vis,false,sizeof(vis));
	vis[cur]=true;
	for(int i=0;i<tot;i++)
		graph[i]=d[cur][i];
	for(int i=1;i<tot;i++){
		double mincost=1e20;
		for(int j=0;j<tot;j++){
			if(!vis[j]&&graph[j]<mincost){
				mincost=graph[j];
				idx=j;
			}
		}
		vis[idx]=true;
		sum+=mincost;
		for(int j=0;j<tot;j++){
			if(!vis[j]&&graph[j]>d[idx][j])
				graph[j]=d[idx][j];
		}
	}
	return sum;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&ball[i].cer.x,&ball[i].cer.y,&ball[i].cer.z,&ball[i].r);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j) dist[i][j]=ball[i].cer.Distance(ball[j].cer)-ball[i].r-ball[j].r;
			}
		}
		memset(num,-1,sizeof(num));
		tot=0;
		for(int i=0;i<n;i++){
			if(num[i]==-1){
				dfs(i);
				tot++;
			}
		}
		if(tot==1) printf("0.000\n");
		else{
			for(int i=0;i<tot;i++)
				for(int j=0;j<tot;j++)
					d[i][j]=1e20;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					d[num[i]][num[j]]=min(d[num[i]][num[j]],dist[i][j]);
			}
			printf("%.3f\n",prime(0));
		}
	}
	return 0;
}