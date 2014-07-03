#include<iostream>
#include<cstdio>
using namespace std;
int slove(int a,int b ,int c){
	int temp=a*b,t=temp;
	while(1){
		if(temp%c==1)
			return temp;
		else
			temp+=t;
	}
}
int main(){
	int a,b,c,d,tt=0;
	while(cin>>a>>b>>c>>d){
		if(a==-1&&b==-1&&c==-1&&d==-1)
			break;
		int ans=(slove(28,23,33)*c+slove(23,33,28)*b+slove(33,28,23)*a-d+21252)%21252;
		if(ans==0) ans=21252;
		cout<<"Case "<<++tt<<": the next triple peak occurs in "<<ans<<" days.\n";
	}
	return 0;
}