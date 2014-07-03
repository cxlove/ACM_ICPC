#include <stdio.h>
#include <stdlib.h>
 
const int maxn = 71, maxsum = 2103, INF = 0xFFFFFF;
int n, data[maxn][2], dp[maxsum][maxsum], answer;
 
int input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &data[i][0], &data[i][1]);
	return 0;
}
 
int comp(int x[], int y[]) {
	return y[0] - x[0];
}
 
int max(int a, int b, int c) {
	int res = a > b ? a : b;
	return res > c ? res : c;
}
 
int work() {
	qsort(data, n, sizeof(int) << 1, (int(*) (const void*, const void*)) comp);
	int tsum = 0, tmax = 0, h, t;
	for (int i = 0; i < n; ++i)
		tsum += data[i][1];
	for (int j = 0; j <= tsum; ++j)
		for (int k = 0; k <= tsum; ++k)
			dp[j][k] = INF;
	dp[0][0] = 0;
	for (int i = 1; i < n; ++i) {
		h = data[i][0], t = data[i][1];
		tmax += t;
		for (int j = tmax, jj = tmax - t; j >= 0; --j, --jj)
			for (int k = tmax, kk = tmax - t; k >= 0; --k, --kk) {
				if (jj > 0 && dp[jj][k] < dp[j][k])
					dp[j][k] = dp[jj][k];
				if (!jj && dp[0][k] + h < dp[j][k])
					dp[j][k] = dp[0][k] + h;
				if (kk > 0 && dp[j][kk] < dp[j][k])
					dp[j][k] = dp[j][kk];
				if (!kk && dp[j][0] + h < dp[j][k])
					dp[j][k] = dp[j][0] + h;
			}
	}
	answer = 0x7FFFFFFF;
	for (int j = 1; j <= tmax; ++j)
		for (int k = 1; k <= tmax; ++k)
			if (dp[j][k] < INF) {
				int x = (data[0][0] + dp[j][k]) * max(j, k, tsum - j - k);
				answer = x < answer ? x : answer;
			}
	return 0;
}
 
int output() {
	printf("%d\n", answer);
	return 0;
}
 
int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		input();
		work();
		output();
	}
	return 0;
} 