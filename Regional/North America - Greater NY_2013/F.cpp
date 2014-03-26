#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 101;
#define WIN 1
#define LOSE 0
int dp[N][N][N];
int dfs (int p , int q , int r) {
	if (dp[p][q][r] != -1) return dp[p][q][r];
	int ret = 0;
	for (int i = 1 ; i <= p ; i ++) {
		if (!dfs (p - i , q , r))
			ret = 1;
	}
	for (int i = 1 ; i <= q ; i ++) {
		if (!dfs (min (p , q - i) , q - i , r))
			ret = 1;
	}
	for (int i = 1 ; i <= r ; i ++) {
		if (!dfs (min (p , r - i) , min (q , r - i) , r - i))
			ret = 1;
	}
	return dp[p][q][r] = ret;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	memset (dp , -1 , sizeof (dp));
	dp[0][0][0] = WIN;
	int t;scanf ("%d" , &t);
	while (t --) {
		int id , q , p , r;
		scanf ("%d %d %d %d" , &id , &p , &q , &r);
		swap (p , r);
		dfs (p , q , r);
		printf ("%d %s" , id , dp[p][q][r] == WIN ? "W"  : "L");
		if (dp[p][q][r] == WIN) {
			int row , c;
			for (int i = 1 ; i <= p ; i ++) {
				if (!dfs (p - i , q , r))
					row = 3 , c = p - i + 1;
			}
			for (int i = 1 ; i <= q ; i ++) {
				if (!dfs (min (p , q - i) , q - i , r))
					row = 2 , c = q - i + 1;
			}
			for (int i = 1 ; i <= r ; i ++) {
				if (!dfs (min (p , r - i) , min (q , r - i) , r - i))
					row = 1 , c = r - i + 1;
			}
			printf (" %d %d\n" , c , row);
		}
		else puts ("");
	}
	return 0;
}