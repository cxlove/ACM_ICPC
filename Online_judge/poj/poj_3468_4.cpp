#include<iostream>
#include<cstdio>
using namespace std;
struct line{
	int left,right,mid;
	int add;
	long long sum;
}L[500005];
long long a[500005],n;
long long bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].add=0;
	if(l==r)
		return L[step].sum=a[l];
	return L[step].sum=bulid(2*step,l,(l+r)/2)+bulid(2*step+1,(l+r)/2+1,r);
}
void  update(int step,long long  x,long long  y,long long  z){
	if(x <= L[step].left && y >= L[step].right) {
		L[step].add += z;
		L[step].sum += (long long )(L[step].right-L[step].left+1)*z;
		return ;
	}
	if(L[step].add) {
		L[2*step].sum += (long long )(L[step].mid-L[step].left+1)*L[step].add;
		L[2*step+1].sum+=(long long )(L[step].right-L[step].mid)*L[step].add;
		L[2*step].add += L[step].add;
		L[2*step+1].add+=L[step].add;
		L[step].add = 0;
	}
	if(x <= L[step].mid) update(2*step,x,y,z);
	if(L[step].mid<y)	update(2*step+1,x,y,z);
	L[step].sum=L[2*step].sum +L[2*step+1].sum;
}
long long query(int step,long long  x,long long  y){
	if(L[step].left==x&&L[step].right==y)
		return L[step].sum;
	if(L[step].add) {
		L[2*step].sum += (long long )(L[step].mid-L[step].left+1) * L[step].add;
		L[2*step+1].sum += (long long )(L[step].right-L[step].mid) * L[step].add;
		L[2*step].add+=L[step].add;
		L[2*step+1].add+=L[step].add;
		L[step].add=0;
	}
	if(L[step].mid<x)
		return query(2*step+1,x,y);
	else
		if(L[step].mid>=y)
			return query(2*step,x,y);
		else
			return query(2*step,x,L[step].mid)+query(2*step+1,L[step].mid+1,y);
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	char str[5];
	bulid(1,1,n);
	while(m--){
		scanf("%s",str);
		if(str[0]=='C'){
			long long  x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			update(1,x,y,z);
		}
		else
		{
			long long  x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
//	system("pause");
	return 0;
}


	
