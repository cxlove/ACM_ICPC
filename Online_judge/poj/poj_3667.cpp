#include<iostream>
#include<cstdio>
using namespace std;
struct line{
	int left,right,mid;
	int flag;
	int val,lx,rx;
	void done(){val=lx=rx=flag?0:dis();}
	int dis(){return right-left+1;}
}L[150010];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].flag=0;
	L[step].done();
	L[step].flag=-1;
	if(l==r) return;
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int mark){
	if(l<=L[step].left&&r>=L[step].right){
		L[step].flag=mark;
		L[step].done();
		return ;
	}
	if(L[step].flag!=-1){
		L[2*step].flag=L[2*step+1].flag=L[step].flag;
		L[2*step].done();
		L[2*step+1].done();
		L[step].flag=-1;
	}
	if(l<=L[step].mid)
		update(2*step,l,r,mark);
	if(r>L[step].mid) 
		update(2*step+1,l,r,mark);
	L[step].val=max(max(L[2*step].val,L[2*step+1].val),L[2*step].rx+L[2*step+1].lx);
	L[step].lx=L[2*step].lx+(L[2*step].dis()==L[2*step].lx?L[2*step+1].lx:0);
	L[step].rx=L[2*step+1].rx+(L[2*step+1].rx==L[2*step+1].dis()?L[2*step].rx:0);
}
int query(int step,int d){
	if(L[step].left==L[step].right&&d==1)
		return L[step].left;
	if(L[step].flag!=-1){
		L[2*step].flag=L[2*step+1].flag=L[step].flag;
		L[2*step].done();
		L[2*step+1].done();
		L[step].flag=-1;
	}
	if(L[2*step].val>=d)
		return query(2*step,d);
	else if(L[2*step].rx+L[2*step+1].lx>=d)
		return L[2*step].right-L[2*step].rx+1;
	else if(L[1+2*step].val>=d)
		return query(2*step+1,d);
	else
		return 0;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	bulid(1,1,n);
	while(m--){
		int a,x,d;
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&x);
			int ans=query(1,x);
			printf("%d\n",ans);
			if(ans)
				update(1,ans,ans+x-1,1);
		}
		else{
			scanf("%d%d",&x,&d);
			update(1,x,x+d-1,0);
		}
	}
//	system("pause");
	return 0;
}


