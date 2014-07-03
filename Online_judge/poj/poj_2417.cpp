#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL __int64
#define N 1000000
using namespace std;
struct Node{
	int idx;
	LL val;
}baby[N];
bool cmp(Node n1,Node n2){
	return n1.val!=n2.val?n1.val<n2.val:n1.idx<n2.idx;
}
LL PowMod(LL a,LL b,LL MOD){
	LL ret=1;
	a%=MOD;
	while(b){
		if(b&1)
			ret=((LL)ret*a)%MOD;
		a=((LL)a*a)%MOD;
		b>>=1;
	}
	return ret;
}
//二分查找
int BinSearch(int m,LL num){
	int low=0,high=m-1,mid;
	while(low<=high){
		mid=(low+high)>>1;
		if(baby[mid].val==num)
			return baby[mid].idx;
		if(baby[mid].val<num)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main(){
	LL p,b,n;
	while(scanf("%lld%lld%lld",&p,&b,&n)!=EOF){
		int m = (int)ceil(sqrt((double)(p - 1)));
		baby[0].idx=0;baby[0].val=1;
		for(int i=1;i<m;i++){
			baby[i].idx=i;     
			baby[i].val=((LL)baby[i-1].val*b)%p;   //b^i
		}
		sort(baby,baby+m,cmp);
		int cnt=1;
		//去年余数相同但是标号大的
		for(int i=1;i<m;i++)
			if(baby[i].val!=baby[cnt-1].val)
				baby[cnt++]=baby[i];
		LL bm=PowMod(PowMod(b,p-2,p),m,p);//先求逆元，再求b^(-m)
		int ans=-1;
		LL tmp=n;
		for(int j=0;j<m;j++){
			//查找(b^(-m))^j
			int pos=BinSearch(cnt,tmp);
			if(pos!=-1){
				ans=j*m+pos;
				break;
			}
			tmp=((LL)tmp*bm)%p;
		}
		if(ans<0)
			puts("no solution");
		else
			printf("%d\n",ans);
	}
	return 0;
}
