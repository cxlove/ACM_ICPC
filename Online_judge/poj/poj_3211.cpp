#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<25
using namespace std;
int n,m;
string col[10];
vector<int>a[10];
int sum[10];
int find(string s){
	for(int i=0;i<n;i++)
		if(s==col[i])
			return i;
	return -1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		for(int i=0;i<n;i++){
			cin>>col[i];
			a[i].clear();
		}
		memset(sum,0,sizeof(sum));
		for(int i=0;i<m;i++){
			int val;
			string s;
			cin>>val>>s;
			a[find(s)].push_back(val);
			sum[find(s)]+=val;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int dp[100005];
			memset(dp,0,sizeof(dp));
			for(int j=0;j<a[i].size();j++)
				for(int k=sum[i]/2;k>=a[i][j];k--)
					dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
			ans+=sum[i]-dp[sum[i]/2];
		}
		cout<<ans<<endl;
	}
	return 0;
}