#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,t;
	vector<int>a;
	while(scanf("%d",&n)!=EOF&&n){
		a.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			a.push_back(t);
		}
		sort(a.begin(),a.end());
		bool flag=false;
		for(int i=1;i<a.size();i+=2)
			if(a[i]!=a[i-1])
				flag=true;
		if(flag||n%2)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}