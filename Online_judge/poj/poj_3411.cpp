#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 10;
struct Node{
	int c,c1,c2;
	Node(){}
	Node(int _c,int _c1,int _c2):c(_c),c1(_c1),c2(_c2){}
};
vector<Node>road[N][N];
int dp[1<<N][N];
int in[1<<N][N];
int n,m;
int spfa(){
	memset(dp,0x11,sizeof(dp));
	memset(in,0,sizeof(in));
	queue<pair<int,int> >que;
	que.push(mp(1,0));
	in[1][0]=1;
	dp[1][0]=0;
	while(!que.empty()){
		pair<int,int>u=que.front(),v;
		que.pop();
		in[u.first][u.second]=0;
		for(int i=0;i<n;i++){
			if(i==u.second) continue;
			for(int j=0;j<road[u.second][i].size();j++){
				int c=road[u.second][i][j].c;
				int c1=road[u.second][i][j].c1;
				int c2=road[u.second][i][j].c2;
				v=u;
				int now=dp[u.first][u.second];
				now+=((1<<c)&v.first)?c1:c2;
				v.first|=(1<<i);
				v.second=i;
				if(dp[v.first][v.second]>now){
					dp[v.first][v.second]=now;
					if(!in[v.first][v.second]){
						que.push(v);
						in[v.first][v.second]=1;
					}
				}
			}
		}
	}
	int ans=0x11111111;
	for(int i=0;i<(1<<n);i++)
		ans=min(ans,dp[i][n-1]);
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				road[i][j].clear();
		for(int i=0;i<m;i++){
			int u,v,c,c1,c2;
			scanf("%d%d%d%d%d",&u,&v,&c,&c1,&c2);
			u--;v--;c--;
			road[u][v].push_back(Node(c,c1,c2));
		}
		int ans=spfa();
		if(ans==0x11111111) puts("impossible");
		else printf("%d\n",ans);
	}
	return 0;
}