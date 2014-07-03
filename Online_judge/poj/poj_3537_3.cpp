#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sg[2005];
int getsg(int n){
	if(sg[n]!=-1)
		return sg[n];
	if(n<0) return 0;
	int vis[2005];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		vis[getsg(i-3)^getsg(n-i-2)]=1;
	for(int i=0;;i++)
		if(vis[i]==0)
			return sg[n]=i;
}
int main(){
	int n;
	memset(sg,-1,sizeof(sg));
	while(cin>>n){
		if(n&1)
			printf("1\n");
		else
			printf("%d\n",getsg(n)?1:2);
	}
	return 0;
}