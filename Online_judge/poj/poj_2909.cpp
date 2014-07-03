#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
bool flag[1000005]={0};
void prime(){
	for(int i=2;i<=1000;i++){
		if(flag[i]) continue;
		for(int j=2;j*i<=1000*1000;j++)
			flag[i*j]=true;
	}
}
int main(){
	prime();
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int cnt=0;
		flag[0]=flag[1]=true;
		for(int i=2;i<=n/2;i++)
			if(flag[i]==false&&flag[n-i]==false)
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}