#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int sum[432][432]={0},cnt[432][432]={0},count=0;
bool flag[450]={0};
void Prime(){
	for(int i=2;i<=431;i++){
		if(flag[i]) continue;
		cnt[i][count]=1;
		for(int j=2;j*i<=431;j++){
			flag[i*j]=true;
			cnt[i*j][count]=cnt[j][count]+1;
		}
		count++;
	}
}
void Init(){
	for(int i=1;i<=431;i++)
		for(int j=0;j<count;j++)
			sum[i][j]=sum[i-1][j]+cnt[i][j];
}
int main(){
	int n,k;
	Prime();
	Init();
	while(scanf("%d%d",&n,&k)!=EOF){
		LL ans=1;
		for(int i=0;i<count;i++)
			ans=ans*(sum[n][i]-sum[k][i]-sum[n-k][i]+1);
		printf("%I64d\n",ans);
	}
	return 0;
}