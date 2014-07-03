#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t,n,a[100];
	cin>>t;
	while(t--){
		cin>>n;
		int flag=0,ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans^=a[i];
			if(a[i]>1)
				flag=1;
		}
		if(!flag){
			if(n&1)
				cout<<"Brother"<<endl;
			else
				cout<<"John"<<endl;
		}
		else{
			if(ans==0)
				cout<<"Brother"<<endl;
			else
				cout<<"John"<<endl;
		}
	}
	return 0;
}