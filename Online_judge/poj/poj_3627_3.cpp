#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,a[20005];
	ll b,sum;
	scanf("%d%lld",&n,&b);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	sum=0;
	int i;
	for( i=0;i<n;i++){
		sum+=a[i];
		if(sum>=b)
			break;
	}
	printf("%d\n",i+1);
//	system("pause");
	return 0;
}