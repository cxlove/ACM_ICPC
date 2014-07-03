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
const int N = 40005;
struct Segtree{
	int left,right,cover;
	int len;
}L[N<<3];
struct Line{
	int y,x1,x2;
	int f;
	Line(){}
	Line(int _y,int _x1,int _x2,int _f=1):y(_y),x1(_x1),x2(_x2),f(_f){}
	bool operator<(const Line &l)const{
		return y<l.y;
	}
}l[N<<1];
int n,m;
int x[N<<1];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].cover=0;
	L[step].len=0;
	if(l==r) return;
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
}
void cal(int step){
	if(L[step].cover) L[step].len=x[L[step].right]-x[L[step].left-1];
	else if(L[step].left==L[step].right) L[step].len=0;
	else L[step].len=L[lson].len+L[rson].len;
}
void update(int step,int l,int r,int f){
	if(L[step].left==l&&L[step].right==r){
		L[step].cover+=f;
		cal(step);
		return ;
	}
	int m=(L[step].left+L[step].right)>>1;
	if(r<=m) update(lson,l,r,f);
	else if(l>m) update(rson,l,r,f);
	else{
		update(lson,l,m,f);
		update(rson,m+1,r,f);
	}
	cal(step);
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			int x1,y1,x2,y2,h;
			scanf("%d%d%d",&x1,&x2,&h);
			y1=0;y2=h;
			l[i<<1]=Line(y1,x1,x2);
			l[i<<1|1]=Line(y2,x1,x2,-1);
			x[i<<1]=x1;x[i<<1|1]=x2;
		}
		sort(x,x+(n<<1));
		m=unique(x,x+(n<<1))-x;
		sort(l,l+(n<<1));
		bulid(1,1,m-1);
		LL sum=0;
		for(int i=0;i<(n<<1);i++){
			int Left=lower_bound(x,x+m,l[i].x1)-x+1;
			int Right=lower_bound(x,x+m,l[i].x2)-x+1;
			if(i) sum+=(LL)L[1].len*(l[i].y-l[i-1].y);
			update(1,Left,Right-1,l[i].f);
		}
		printf("%lld\n",sum);
	}
	return 0;
}