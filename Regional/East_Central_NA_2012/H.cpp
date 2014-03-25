#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 55;
const int INF = 100000007;
int mp[maxn][maxn],match[maxn],ly[maxn],lx[maxn],slack[maxn];
int n,m,a[maxn][maxn] , b[maxn][maxn];
bool visx[maxn],visy[maxn];
int people[maxn] , first[maxn];
int p[maxn] , second[maxn];
bool dfs(int x) {
	visx[x] = true;
	for(int y = 0;y < n;y ++){
		if(!visy[y]){
			int t = lx[x] + ly[y] - mp[x][y];
			if(t == 0){
				visy[y] = true;
				int tmp = match[y];
				match[y] = x;
				if(tmp == -1 || dfs(tmp)) return true;
				match[y] = tmp;
			}
			else if(t < slack[y]) slack[y] = t;
		}
	}
	return false;
}
int km() {
	memset(match,-1,sizeof(match));
	memset(ly,0,sizeof(ly));
	memset(lx,0,sizeof(lx));
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)
			if(mp[i][j] > lx[i]) lx[i] = mp[i][j];
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < n;j ++)
			slack[j] = INF;
		while(1){
			int d = INF;
			memset(visx,false,sizeof(visx));
			memset(visy,false,sizeof(visy));
			if(dfs(i)) break;
			for(int j = 0;j < n;j ++)
				if(!visy[j] && slack[j] < d) d = slack[j];
			for(int j = 0 ;j < n;j ++)
				if(visx[j]) lx[j] -=d;
			for(int j = 0;j < n;j ++){
				if(visy[j]) ly[j] +=d;
				else slack[j] -= d;
			}
		}
	}
	int ret = 0;
	for(int i = 0;i < n;i ++)
		ret += mp[match[i]][i];
	return ret;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int cas = 0;
	while (scanf ("%d" , &n) != EOF && n) {
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				scanf ("%d" , &a[i][j]);
				mp[i][j] = 10000 - a[i][j];
			}
		}
		km ();
		for (int i = 0 ; i < n ; i ++) {
			people[match[i]] = i;
			first[i] = match[i];
		}
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				scanf ("%d" , &b[i][j]);
				mp[i][j] = 10000 - (b[i][j] + max (a[i][people[i]] , a[first[j]][j]));
			}
		}
		km ();
		for (int i = 0 ; i < n ; i ++) {
			p[match[i]] = i;
			second[i] = match[i];
		}
		printf ("Case %d:\n" , ++ cas);
		int add = 0;
		for (int i = 0 ; i < n ; i ++) {
			printf ("Worker %d: %d %d %d\n" , i + 1 , people[i] + 1 , p[i] + 1 , a[i][people[i]] + b[i][p[i]] + max (0 , a[first[p[i]]][p[i]] - a[i][people[i]]));
			add += max (0 , a[first[p[i]]][p[i]] - a[i][people[i]]);
		}
		printf ("Total idle time: %d\n" , add);
	}
	return 0;
}