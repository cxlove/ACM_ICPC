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
string s;
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int n;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0 ; i < n ; i ++) {
		if (s[i] != '.') continue;
		int l = 0 , r = 0;
		for (int j = i - 1 ; j >= 0 ; j --) {
			if (s[j] == 'R') {
				l = i - j;
				break;
			}
			if (s[j] != '.') break;
		}
		for (int j = i + 1 ; j < n ; j ++) {
			if (s[j] == 'L') {
				r = j - i;
				break;
			}
			if (s[j] != '.') break;
		}
		if (l == r) ans ++;
	}
	cout << ans << endl;
	return 0;
}