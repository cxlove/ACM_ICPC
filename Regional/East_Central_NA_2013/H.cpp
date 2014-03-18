#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;
int dp[N][8][8] , n , a[3][N];

bool check (int one , int two , int three) {
	for (int i = 0 ; i < 3 ; i ++) {
		if (!((1 << i) & two) && !((1 << i) && three))
			return false;
	}
	if (!(two & 1) && !(two & 2)) return false;
	if (!(two & 2) && !(two & 4)) return false;
	return true;
}
void dfs (int row , int one , int two , int col , int newone , int now , int val) {
	if (col == 3) {
		if (!check (now , newone , two)) return ;
		dp[row + 1][now][one] = max (dp[row + 1][now][one] , dp[row][one][two] + val);
		return ;
	}
	if (!(one & (1 << col))) {
		dfs (row , one , two , col + 1 , newone | (1 << col) , now | (1 << col) , val + a[col][row] * a[col][row + 1]);
	}
	if (col < 2) {
		dfs (row , one , two , col + 2 , newone , now | (1 << col) | (1 << (col + 1)) , val + a[col][row + 1] * a[col + 1][row + 1]);
	}
	dfs (row , one , two , col + 1 , newone , now , val);
}
int main () {
#ifndef ONLINE_JUDGE 
	// freopen ("input.txt" , "r" , stdin);
#endif
	int cas = 0;
	while (scanf ("%d" , &n) != EOF && n) {
		for (int i = 0 ; i < 3 ; i ++) {
			for (int j = 1 ; j <= n ; j ++) {
				scanf ("%d" , &a[i][j]);
			}
		}
		memset (dp , -1 , sizeof (dp));
		dp[0][7][7] = 0;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < 8 ; j ++) {
				for (int k = 0 ; k < 8 ; k ++) {
					if (dp[i][j][k] != -1)
						dfs (i , j , k , 0 , j , 0 , 0);
				}
			}
		}
		int ans = 0;
		for (int i = 0 ; i < 8 ; i ++) {
			if (i == 0 || i == 1 || i == 4) continue;
			for (int j = 0 ; j < 8 ; j ++) {
				ans = max (ans , dp[n][i][j]);
			}
		}
		printf ("Case %d: %d\n" , ++cas , ans);
	}
	return 0;
}