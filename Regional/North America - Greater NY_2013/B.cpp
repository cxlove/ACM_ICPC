#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55;
const int INF = 100000007;
int n , a[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;scanf ("%d" , &t);
	while (t --) {
		int id;scanf ("%d" , &id);
		double d , a , b , c;
		scanf ("%lf %lf %lf %lf" , &d , &a , &b , &c);
		printf ("%d %.2f\n" , id , d / (a + b) * c);
	}
	return 0;
}