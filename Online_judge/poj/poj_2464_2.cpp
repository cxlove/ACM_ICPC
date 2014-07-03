/*
ID:cxlove
PROB:Brownie Points II 
DATA:2012.2.23
HINT:线段树+扫描
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX 200000
using namespace std;
class{
private:
	struct line{
		int left,right,mid;
		int sum;
	}L[3*MAX+10];
public:
	void bulid(int step,int l,int r){
		L[step].left=l;
		L[step].right=r;
		L[step].mid=(l+r)/2;
		L[step].sum=0;
		if(l==r)
			return;
		bulid(2*step,l,(l+r)/2);
		bulid(2*step+1,(l+r)/2+1,r);
	}
	void update(int step,int pos,int kind){
		if(L[step].left==L[step].right){
			L[step].sum+=kind; 
    		return;
		}
		if(pos<=L[step].mid)
			update(2*step,pos,kind);
		else
			update(2*step+1,pos,kind);
		L[step].sum=L[2*step].sum+L[step*2+1].sum;
	}
	int query(int step,int l,int r){
		if(L[step].left==l&&L[step].right==r)
			return L[step].sum;
		if(r<=L[step].mid)
			return query(2*step,l,r);
		else if(l>L[step].mid)
			return query(2*step+1,l,r);
		else
			return query(2*step,l,L[step].mid)+query(2*step+1,L[step].mid+1,r);
	}
}Left,Right;
struct Point{
	int x,y;
}p[MAX+10];
int y[MAX+10],ycount;
vector<int>ans;
bool cmp(Point p1,Point p2){
	return p1.x<p2.x;
}
int bin(int yy){
	int low=1,high=ycount-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(y[mid]==yy)
			return mid;
		if(y[mid]<yy)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(!n) break;
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			y[i+1]=p[i].y;
		}
		sort(p,p+n,cmp);
		sort(y+1,y+n+1);
		ycount=1;
		for(int i=1;i<=n;i++)
			if(i==1||y[i]!=y[i-1])
				y[ycount++]=y[i];
		Left.bulid(1,0,ycount);
		Right.bulid(1,0,ycount);
		for(int i=0;i<n;i++)
			Right.update(1,bin(p[i].y),1);	
		int start=0;
		int best=0;
		ans.clear();
		for(int i=1;i<=n;i++){
			if(i==n||p[i].x!=p[i-1].x){
				for(int j=start;j<i;j++)
					Right.update(1,bin(p[j].y),-1);
				int ollie=-1;
				int stan=-1;
				for(int j=start;j<i;j++){
					int yy=bin(p[j].y);
					int a=Left.query(1,0,yy-1)+Right.query(1,yy+1,ycount);
					int b=Right.query(1,0,yy-1)+Left.query(1,yy+1,ycount);
					if(b==ollie)
						stan=min(stan,a);
					else if(b>ollie){
						ollie=b;
						stan=a;
					}
				}
				if(stan>best){
					best=stan;
					ans.clear();
				}
				if(stan==best)
					ans.push_back(ollie);
				for(int j=start;j<i;j++)
					Left.update(1,bin(p[j].y),1);
				start=i;
			}
		}
		printf("Stan: %d; Ollie:",best);
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
			if(i==0||ans[i]!=ans[i-1])
		    	printf(" %d",ans[i]);
		printf(";\n");
	}
	return 0;
}
/*
11
3 2
3 3
3 4
3 6
2 -2
1 -3
0 0
-3 -3
-3 -2
-3 -4
3 -7
*/




