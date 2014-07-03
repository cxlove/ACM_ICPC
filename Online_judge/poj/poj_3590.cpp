#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[30]={2,3,5,7,11,13,17,19,23,29,31,37,
	41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int cnt=25,mmax;
int a[105];
int b[105];
int len;
void dfs(int idx,int remain){
	if(remain<prime[idx]){
		int sum=1;
		for(int i=0;i<idx;i++)
			if(b[i])
				sum*=b[i];
		if(sum>mmax){
			mmax=sum;
			int k=0;
			for(int i=0;i<idx;i++)
				if(b[i])
					a[k++]=b[i];
			while(remain--)
				a[k++]=1;
			len=k;
		}
		return;
	}
	b[idx]=0;
	dfs(idx+1,remain);
	for(b[idx]=prime[idx];b[idx]<=remain;b[idx]*=prime[idx])
		dfs(idx+1,remain-b[idx]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		mmax=0;len=0;
		dfs(0,n);
		
		sort(a,a+len);
		printf("%d",mmax);
		int k=1;
		for(int i=0;i<len;i++){
			int tmp=k++;
			for(int j=1;j<a[i];j++)
				printf(" %d",k++);
			printf(" %d",tmp);
		}
		printf("\n");
	}
	return 0;
}