#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void slove(long long n,long long *a,long long times){
	if(n<=0)
		return;
	for(int i=1;i<=n%10;i++)
		a[i]+=times;
	long long p=n/10;
	while(p>0){
		a[p%10]+=(n%10+1)*times;
		p=p/10;
	}
	for(int i=0;i<=9;i++)
		a[i]+=times*(n/10);
	times*=10;
	slove(n/10-1,a,times);
}
int main(){
	long long a,b;
	long long dig1[10],dig2[10];
	while(scanf("%lld%lld",&a,&b)!=EOF&&(a!=-1||b!=-1)){
		if(a>b)
			swap(a,b);
		memset(dig1,0,sizeof(dig1));
		memset(dig2,0,sizeof(dig2));
		slove(b,dig1,1);
		if(a!=0)
			slove(a-1,dig2,1);
		else
			dig1[0]++;
		printf("%I64d\n",dig1[0]-dig2[0]);
	}
	return 0;
}