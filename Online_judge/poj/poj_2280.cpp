#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#define lson step<<1
#define rson step<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int N = 1005;
struct Point{
	int x,y,k;
	double ang;
	bool operator<(const Point &p)const{
		return ang<p.ang;
	}
}p[N],t[N];
int n;
int xmul(Point p1,Point p2,Point p){
	return (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
}
int main(){
	// freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].k);
			t[i]=p[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				p[j]=t[j];
				if(p[j].k){
					p[j].x=2*t[i].x-p[j].x;
					p[j].y=2*t[i].y-p[j].y;
				}
				p[j].ang=atan2(p[j].y-t[i].y+0.0,0.0+p[j].x-t[i].x);
			}
			swap(p[0],p[i]);
			sort(p+1,p+n);
			for(int s=1,e=2;s<n&&p[s].ang<1e-8;s++){
				int on=2;
				while(e<n&&xmul(p[s],p[e],p[0])>=0){
					if(xmul(p[s],p[e],p[0])==0) on++;
					e++;
				}
				ans=max(ans,max(e-s+1,n-(e-s+1)+on));
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}