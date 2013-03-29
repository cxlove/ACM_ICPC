#include<iostream>
#include<cstdio>
using namespace std;
int a[10]={0};
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){int m;cin>>m;a[m]++;}
	for(int i=0;i<10;i++) if(a[i]%k) {puts("No");return 0;}
	puts("Yes");
	return 0;
}