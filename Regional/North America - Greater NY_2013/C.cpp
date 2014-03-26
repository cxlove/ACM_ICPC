#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1005;
const int INF = 100000007;
vector <int> edge[N] , pre[N];
int in[N] , order[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;scanf ("%d" , &t);
	while (t --) {
		int id , n , m;
		scanf ("%d %d %d" , &id , &n , &m);
		for (int i = 1 ; i <= n ; i ++) {
			edge[i].clear ();
			pre[i].clear ();
			in[i] = 0;
		}
		while (m --) {
			int u , v;scanf ("%d %d" , &u , &v);
			edge[u].push_back (v);
			pre[v].push_back (u);
			in[v] ++;
		}
		queue <int> que;
		for (int i = 1 ; i <= n ; i ++) {
			if (in[i] == 0)
				que.push (i); 
		}
		int ans = 1;
		while (!que.empty ()) {
			int u = que.front ();que.pop ();
			if (pre[u].size() == 0) {
				order[u] = 1;
			}
			else {
				int mx = 0 , cnt = 0;
				for (int i = 0 ; i < pre[u].size() ; i ++) {
					if (order[pre[u][i]] > mx) {
						mx = order[pre[u][i]];
						cnt = 1;
					}
					else if (order[pre[u][i]] == mx) 
						cnt ++;
				}
				if (cnt == 1) order[u] = mx;
				else order[u] = mx + 1;
			}
			ans = max (ans , order[u]);
			for (int i = 0 ; i < edge[u].size() ; i ++) {
				int v = edge[u][i];
				if (-- in[v] == 0) {
					que.push (v);
				}
			}
		}
		printf ("%d %d\n" , id , ans);
	}
	return 0;
}