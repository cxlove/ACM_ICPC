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
int n , a[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
		cin >> a[i];
	sort (a ,a + n);
	for (int i = 0 ; i < n ; i ++)
		cout << a[i] << " " ;
	return 0;
}