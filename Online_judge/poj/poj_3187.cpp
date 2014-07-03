#include<iostream>
#include<cstring>
using namespace std;
int n,sum;
int c[11],ans[11];
bool flag=false,vis[11];
int C(int a,int b){
	int ans=1,i=a,j=1;
	while(j<=b){
		ans=ans*i/j;
		i--;j++;
	}
	return ans;
}
void dfs(int m,int total){
	if(total>sum)  return ;
	if(m==n){
		if(total==sum&&!flag){
			flag=true;
			for(int i=0;i<n-1;i++)
				cout<<ans[i]<<" ";
			cout<<ans[n-1]<<endl;
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			ans[m]=i;
			dfs(m+1,total+c[m]*ans[m]);
			vis[i]=false;
		}
}
int main()
{
	cin>>n>>sum;
	for(int i=0;i<n;i++)
		c[i]=C(n-1,i);
	memset(vis,false,sizeof(vis));
	dfs(0,0);
//	system("pause");
	return 0;
}

	