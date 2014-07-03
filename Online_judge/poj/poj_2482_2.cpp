#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N = 10005;
struct Point{
	int x,y,c;
	bool operator<(const Point p)const{
		return x!=p.x?x<p.x:y<p.y;
	}
}p[N];
struct Seg{
	int left,right;
	int mx,lazy;
}L[N<<2];
int n,w,h,y[N],m;
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mx=L[step].lazy=0;
	if(l==r) return ;
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
}
void push_up(int step){
	L[step].mx=max(L[lson].mx,L[rson].mx);
}
void modify(int step,int l,int r,int c);
void push_down(int step){
	int l=L[step].left,r=L[step].right,m=(l+r)>>1;
	if(L[step].lazy){
		modify(lson,l,m,L[step].lazy);
		modify(rson,m+1,r,L[step].lazy);
		L[step].lazy=0;
	}
}
void modify(int step,int l,int r,int c){
	if(L[step].left==l&&L[step].right==r){
		L[step].lazy+=c;
		L[step].mx+=c;
		return ;
	}
	push_down(step);
	int m=(L[step].left+L[step].right)>>1;
	if(r<=m) modify(lson,l,r,c);
	else if(l>m) modify(rson,l,r,c);
	else{
		modify(lson,l,m,c);
		modify(rson,m+1,r,c);
	}
	push_up(step);
}
void update(int pos,int c){
	int l=lower_bound(y,y+m,pos-h+1)-y;
	int r=lower_bound(y,y+m,pos)-y;
	modify(1,l,r,c);
}
int main(){
	while(scanf("%d%d%d",&n,&w,&h)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].c);
			y[i]=p[i].y;
		}
		sort(p,p+n);
		sort(y,y+n);
		m=unique(y,y+n)-y;
		bulid(1,0,m-1);
		int ans=0;
		for(int i=0,j=0;i<n;i++){
			while(p[i].x-p[j].x>=w){
				update(p[j].y,-p[j].c);
				j++;
			}
			update(p[i].y,p[i].c);
			ans=max(ans,L[1].mx);
		}
		printf("%d\n",ans);
	}
	return 0;
}