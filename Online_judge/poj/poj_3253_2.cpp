#include<iostream>
#include<cstdio>
#define inf 1<<30
using namespace std;
int m,a[20001];
void heap(int root,int n){
	int j=1,k=a[root];
	while(j!=inf){
		int i=a[root];j=inf;
		if(2*root<=n&&a[2*root]<i){
			i=a[2*root];
			j=2*root;
		}
		if(2*root+1<=n&&a[2*root+1]<i){
			i=a[2*root+1];
			j=2*root+1;
		}
		if(j!=inf){
			a[root]=i;
			root=j;
		}
		a[root]=k;
	}
}
void bulidheap(int n){
	for(int i=n/2;i>=1;i--)
		heap(i,n);
}
int main(){
	long long ans=0;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	bulidheap(m);
	while(m!=1){
		int temp=a[1];
		a[1]=a[m];
		a[m]=temp;
		heap(1,m-1);
		m--;
		temp=a[1];
		a[1]=a[m];
		a[m]=temp;
		heap(1,m-1);
		a[m]+=a[m+1];
		ans+=a[m];
	}
	cout<<ans<<endl;
	return 0;
}




