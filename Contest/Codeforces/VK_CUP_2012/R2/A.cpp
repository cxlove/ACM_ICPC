#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 5005;
const int MOD = 1000000007;
int dp[N][N];
void add (int &a , int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    string s , e;
    cin >> s >> e;
    int ans = 0;
    for (int i = 0 ; i < s.size() ; i ++) {
    	for (int j = 0 ; j < e.size() ; j ++) {
    		if (s[i] == e[j]) {
    			add (dp[i][j] , 1);
    			if (i > 0 && j > 0)
    				add (dp[i][j] , dp[i - 1][j - 1]);
    		}
    		if (j > 0) {
    			add (dp[i][j] , dp[i][j - 1]);
    		}
    	}
    	add (ans , dp[i][e.size() - 1]);
    }
    cout << ans << endl;
    return 0;
}