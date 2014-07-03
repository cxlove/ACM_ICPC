#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#include<stack>  
#define eps 1e-6
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
const int N = 20;
const int M = 40005;
LL dp[N][N][2];
int bit[N] , len;
LL dfs (int p , int c , int f , int limit) {
	if (p == -1) {
		return f;
	}
	if (!limit && dp[p][c][f] != -1) return dp[p][c][f];
	int up = limit ? bit[p] : 9;
	LL ret = 0;
	for (int i = 0 ; i <= up ; i ++) {
		int cc = i == 6 ? c + 1 : 0;
		ret += dfs (p - 1 , cc , f | (cc >= 3) , limit && (i == up));
	}
	if (!limit) dp[p][c][f] = ret;
	return ret;
}
LL check (LL n) {
	len = 0;
	while (n) {
		bit[len ++] = n % 10;
		n /= 10;
	}
	return dfs (len - 1 , 0 , 0 , 1);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen ("input.txt" , "r" , stdin);
	#endif
	memset (dp , -1 , sizeof(dp));
	int t;
	scanf ("%d" , &t);
	while (t --) {
		LL n;
		scanf ("%I64d" , &n);
		LL low = 666 , high = 200000000000LL , mid , ans = -1;
		while (low <= high) {
			mid = (0LL + low + high) / 2;
			// cout << mid << " " << check (mid) << " " << n << endl;
			if (check (mid) >= n) ans = mid , high = mid - 1;
			else low = mid + 1;
		}
		printf ("%I64d\n" , ans);
	}
	return 0;
}
