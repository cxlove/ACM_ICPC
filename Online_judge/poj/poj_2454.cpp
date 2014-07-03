#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int N =  60*3;
int k,a[N],b[N];
bool cmp(int i,int j){
	return a[i]>a[j];
}
int main(){
	// freopen("input.txt","r",stdin);
	scanf("%d",&k);
	for(int i=0;i<3*k;i++){
		scanf("%d",&a[i]);
		b[i]=i;
	}
	sort(b,b+3*k,cmp);
	int one=0,two=0;
	for(int i=0;i<k;i++) one+=a[b[i]];
	for(int i=k;i<2*k;i++) two+=a[b[i]];
	while(true){
		if(one>k*500&&two>k*500) break;
		int i=rand()%k,j=rand()%k+k;
		one-=a[b[i]];one+=a[b[j]];
		two-=a[b[j]];two+=a[b[i]];
		swap(b[i],b[j]);
	}
	for(int i=0;i<3*k;i++)
		printf("%d\n",b[i]+1);
	return 0;
}