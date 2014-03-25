#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n , m , val = -1;LL cnt = 0;
map <int , int> mymap[2];
vector <int> a[2];
LL cal (int n , int k) {
	if (k == 2) return n * (n - 1LL) / 2;
	return n * (n - 1LL) * (n - 2LL) / 6;
}
void update (int a , LL b) {
	if (b <= 0) return;
	if (a > val) val = a , cnt = b;
	else if (a == val) cnt += b;
}
void cal (vector <int> &v , map<int , int> &m) {
	if (v.size() < 3) return ;
	int l = v[0] , r = v[v.size () - 1];
	int c1 = m[l] , c2 = m[r] , c3 = v.size() - c1 - c2;
	LL cnt;
	if (l == r) cnt = cal (c1 , 3);
	else cnt = 1LL * c1 * c2 * c3 + 1LL * cal (c1 , 2) * c2 + 1LL * cal (c2 ,2) * c1;
	update ((r - l) * 2 , cnt);
}
void cal (vector <int> &a , vector <int> &b , map<int , int> &m) {
	if (a.size() < 1 || b.size() < 2) return ;
	for (int i = 0 ; i < a.size() ; i ++) {
		int p = lower_bound (b.begin () , b.end () , a[i]) - b.begin ();
		// a <= b < c
		if (p > 1) {
			int B = b[p - 1];
			int c1 = m[B] , c2 = p - c1;
			update (2 * n - 2 * a[i] + 2 * B , cal (c1 + c2 , 2) - cal (c2 , 2)); 
		}
		// a < c <= b
		if  (p > 0) {
			int c1 = p , c2 = b.size() - p;
			update (2 * n , 1LL * c1 * c2); 
		}
		// c <= a <= b
		if (p + 1 < b.size()) {
			int c1 = m[b[p]] , c2 = b.size() - p - c1;
			update (2 * n - 2 * b[p] + 2 * a[i] , cal (c1 + c2 , 2) - cal (c2 , 2));
		}
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	cin >> n >> m;
	for (int i = 0 ; i < m ; i ++) {
		int s , f;
		cin >> s >> f;
		a[s].push_back (f);
		mymap[s][f] ++;
	}
	sort (a[0].begin () , a[0].end ());
	sort (a[1].begin () , a[1].end ());
	cal (a[0] , mymap[0]);
	cal (a[1] , mymap[1]);
	cal (a[0] , a[1] , mymap[1]);
	cal (a[1] , a[0] , mymap[0]);
	cout << cnt << endl;
	return 0;
}