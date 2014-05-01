#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <map>
#include <cmath>
using namespace std;
const int N = 4205;
const double pi = acos (-1.0);
const long long inf = (long long)2e18;
// E:来不及了，只能卖萌了，似乎是有循环节的
// 暴力SG找出循环节？
int sg[26][N];
int way[3][2] = {0 , -1 , -1 , 0 , -1 , -1};
int getsg (int x , int y) {
	if (sg[x][y] != -1) return sg[x][y];
	int vis[5000];
	memset (vis , 0 , sizeof (vis));
	for (int i = 0 ; i < 3 ; i ++) {
		int X = x + way[i][0] , Y = y + way[i][1];
		while (X >= 1 && Y >= 1) {
			vis[getsg (X , Y)] = 1;
			X += way[i][0];Y += way[i][1];
		}
	}
	for (int i = 0 ; ; i ++) {
		if (vis[i] == 0) {
			return sg[x][y] = i;
		}
	}
}
int cir[N];
int f[N] = {0,1,3,3,6,12,24,12,24,24,24,24,48,48,96,96,96,192,192,384,384,384,768,768,768,768};
long long get (long long x , long long y) {
	if (y < N) return sg[x][y];
	long long p = y % f[x];
	return sg[x][p + 768 * 4] + (y - p - 768 * 4);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    // memset (sg , -1 , sizeof (sg));
    // for (int i = 1 ; i <= 25 ; i ++) {
    // 	for (int j = 1 ; j < N ; j ++) {
    // 		getsg (i , j);
    // 	}
    // }
    // cout << "f[] = {0";
    // for (int i = 1 ; i <= 25 ; i ++) {
    // 	for (int p = 1 ; p <= 1000 ; p ++) {
    // 		int ok = 1;
    // 		for (int k = 3000 ; k < 4000  ; k ++) {
    // 			if (sg[i][k - p] + sg[i][k + p] != 2 * sg[i][k]) {
    // 				ok = 0;
    // 				break;
    // 			}
    // 		}
    // 		if (ok) {
    // 			cir[i] = p;
    // 			cout << "," << p;
    // 			break;
    // 		}
    // 	}
    // }
    // cout <<"};" << endl;
    memset (sg , -1 , sizeof (sg));
    for (int i = 1 ; i <= 25 ; i ++) {
    	for (int j = 1 ; j < N ; j ++) {
    		getsg (i , j);
    	}
    }
    int t;scanf ("%d" , &t);
    while (t --) {
    	int r , c , n;
    	long long ans = 0;
    	scanf ("%d %d %d" , &r , &c , &n);
    	for (int i = 0 ; i < n ; i ++) {
    		long long x , y;
    		scanf ("%lld  %lld" , &x , &y);
    		ans = ans ^ get (x , y);
    	}
    	puts (ans ? "YES" : "NO");
    }
    return 0;
}