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
int k (int m) {
	if (m == 2) return 3;
	int a = 1 , b = 1;
	int step = 2;
	while (true) {
		int c = (a + b) % m , d = (b + c) % m;
		// cout << a << " " << b << " " << c << " " << d << " ";     
		step += 2;
		if (c == 1 && d == 0) return step;
		a = c;b = d;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;
	scanf ("%d" , &t);
	while (t --) {
		int id , m;
		scanf ("%d %d" , &id , &m);
		printf ("%d %d\n" , id , k (m));
	}
	return 0;
}