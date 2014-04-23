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
const int N = 100000;
int flag[N] , s[5][5] , n;
vector <int> a[6][N];
void init () {
	for (int i = 2 ; i < N ; i ++) {
		if (flag[i]) continue;
		for (int j = i + i ; j < N ; j += i) 
			flag[j] = 1;
		int t = i;
		for (int j = 1 ; j < 5 ; j ++) {
			t /= 10;
			a[j][t].push_back (i);
		}
	}
}
int dfs (int i) {
	int num = 0;
	for (int j = 0 ; j < i ; j ++) {
		num = num * 10 + s[i][j];
	}
	if (i == n - 1) return a[1][num].size ();
	int ret = 0;
	for (int j = 0 ; j < a[n - i][num].size() ; j ++) {
		int p = a[n - i][num][j];
		for (int k = n - 1 ; k >= i ; k --) {
			s[i][k] = s[k][i] = p % 10;
			p = p / 10;
		}
		ret += dfs (i + 1);
	}
	return ret;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    init ();
    int t;scanf ("%d" , &t);
    while (t --) {
    	char str[10];scanf ("%s" , str);
    	n = strlen (str);
    	for (int i = 0 ; i < n ; i ++) {
    		s[i][0] = s[0][i] = str[i] - '0';
    	}
    	printf ("%d\n" , dfs (1));
    }
    return 0;
}