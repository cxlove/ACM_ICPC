#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n , m;
vector <int> e[N];
set <int> d[N];
int que[N] , head = 0 , tail = 0 , pre[N] , vis[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	scanf ("%d %d" , &n , &m);
	for (int i = 0 ; i < m ; i ++) {
		int u , v;
		scanf ("%d %d" , &u , &v);
		e[u].push_back (v);
		e[v].push_back (u);
		d[u].insert (v);
	}
	if (m & 1) {
		puts ("No solution");
		return 0;
	}
	que[tail ++] = 1;pre[1] = 0;vis[1] = 1;
	while (head <= tail) {
		int u = que[head ++];
		for (int i = 0 ; i < e[u].size() ; i ++) {
			int v = e[u][i];
			if (vis[v] == 0) {
				vis[v] = 1;
				que[tail ++] = v;
				pre[v] = u;
			}
		}
	}
	for (int i = n - 1 ; i >= 0 ; i --) {
		int u = que[i] , p = pre[u];
		int sz = d[u].size();
		if (sz & 1) {
			if (d[u].find (p) != d[u].end ()) {
				d[u].erase (p);
				d[p].insert (u);
			}
			else {
				d[p].erase (u);
				d[u].insert (p);
			}
		}
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (set <int> :: iterator it = d[i].begin () ; it != d[i].end () ; it ++) {
			int u = *it;it ++;
			int v = *it;
			printf ("%d %d %d\n" , u , i , v);
		}
	}
	return 0;
}