#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int s[105],sg[N],k;
int get_sg(int m){
	if(sg[m]!=-1)
		return sg[m];
	int vis[100];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<k&&s[i]<=m;i++){
		sg[m-s[i]]=get_sg(m-s[i]);
		vis[sg[m-s[i]]]=1;
	}
	int i=0;
	for(;;i++)
		if(vis[i]==0)
			return i;
}
int main(){
	while(scanf("%d",&k)!=EOF&&k){
		for(int i=0;i<k;i++)
			scanf("%d",&s[i]);
		sort(s,s+k);
		memset(sg,-1,sizeof(sg));
		int q;
		scanf("%d",&q);
		while(q--){
			int n,m,ans=0;
			scanf("%d",&n);
			while(n--){
				scanf("%d",&m);
				if(sg[m]==-1)
					sg[m]=get_sg(m);
				ans^=sg[m];
			}
			if(ans==0)
				putchar('L');
			else
				putchar('W');
		}
		putchar('\n');
	}
	return 0;
}