#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf  1<<30
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
bool flag[1000005]={0};
int prime[1000005],cnt=0;
int n,eular[1000005];
LL farey[1000005];
void Prime(){
	for(int i=2;i<=1000000;i++){
		if(flag[i])
			continue;
		eular[i]=i-1;
		prime[cnt++]=i;
		for(int j=2;j*i<=1000000;j++){
			if(flag[i*j]==false){
		    	flag[i*j]=true;
				eular[i*j]=i*j;
			}
			eular[i*j]=eular[i*j]/i*(i-1);
		}
	}
	farey[1]=0;
	for(int i=2;i<=1000000;i++)
		farey[i]=farey[i-1]+eular[i];
}
int main(){
	Prime();
	while(scanf("%d",&n)!=EOF&&n)
		printf("%lld\n",farey[n]);
	return 0;
}
