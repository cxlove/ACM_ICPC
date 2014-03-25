#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
const int N = 15;
int m;
map <string , int> mymap;
double dp[N][N];
void update (int u , int v , double d) {
	if (d == 0) return;
	if (dp[u][v] == 0) dp[u][v] = d;
	return ;
}
void floyd () {
	for (int k = 0 ; k < m ; k ++) {
		for (int i = 0 ; i < m ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				if (i == j) continue;
				update (i , j , dp[i][k] * dp[k][j]);
			}
		}
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
#endif
	int n;
	int cas = 0;
	while (cin >> n && n) {
		//cout << n << endl;
		for (int i = 0 ; i < N ; i ++) {
			for (int j = 0 ; j < N ; j ++) {
				dp[i][j] = 0.0;
			}
		}
		mymap.clear ();m = 0;
		for (int i = 0 ; i < n ; i ++ ) {
			string u , p , v;
			int a , b;
			cin >> a >> u >> p >> b >> v;
			if (mymap.count (v) == 0) mymap[v] = m ++;
			if (mymap.count (u) == 0)  mymap[u] = m ++;
			update (mymap[u] , mymap[v] , b * 1.0 / a);
			update (mymap[v] , mymap[u] , a * 1.0 / b);
			floyd ();
		}
		//cout << m << endl;
		string init;int cnt ,  id;
		cin >> cnt >> init;
		id = mymap[init];
		double bestdiff = 1e60;
		double bestidx , bestcnt;
		for (int i = 0 ; i < m ; i ++) {
			if (dp[id][i] != 0) {
				int num = (int)(cnt * dp[id][i]);
				if (fabs(num - cnt *dp[id][i]) > 0.0000001)
				    num ++;
				if (num > 100000) continue;
				double diff = num * dp[i][id] - cnt;
				if (diff <= bestdiff) {
					bestdiff = diff;
					bestidx = i;
					bestcnt = num;
				}
			}
		}
		cout << "Case " << ++ cas << ": " << bestcnt << " ";
		for (map <string , int> :: iterator it = mymap.begin () ; it != mymap.end () ; it ++) {
			if (it -> second == bestidx) {
				cout << it -> first << endl;
				break;
			}
		}


	}
	return 0;
}