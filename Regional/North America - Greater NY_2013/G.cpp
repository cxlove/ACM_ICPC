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
vector <pair <int , pair <int , int> > > ans;
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	
	int t;scanf ("%d" , &t);
	while (t --) {
		ans.clear ();
		int id , n , a[N];
		scanf ("%d %d" , &id , &n);
		for (int i = 0 ; i < n ; i ++) {
			scanf ("%d" , &a[i]);
		}
		int ok = 1;
		for (int cnt = 1 ; cnt <= n - 2 ; cnt ++) {
			int A = -1 , B = -1 , C = -1;
			for (int j = 0 ; j < n ; j ++) {
				if (a[j] == 1) {
					A = j;
					break;
				}
			}
			for (int j = 1 ; j < n ; j ++) {
				int id = (A - j + n) % n;
				if (a[id] > 0) {
					B = id;
					break;
				}
			}
			for (int j = 1 ; j < n ; j ++) {
				int id = (A + j + n) % n;
				if (a[id] > 0) {
					C = id;
					break;
				}
			}
			if (A != B && A != C && B != C && A >= 0 && B >= 0 && C >= 0) {
				a[A]--;a[B]--;a[C]--;
				if (A > B) swap (A , B);
				if (A > C) swap (A , C);
				if (B > C) swap (B , C);
				ans.push_back (make_pair (A + 1 , make_pair (B + 1 , C + 1)));
			}
			else ok = 0;
		}
		printf ("%d %s\n" , id , ok ? "Y" : "N");
		if (ok) {
			sort (ans.begin () , ans.end ());
			for (int i = 0 ; i < ans.size() ; i ++)
				printf ("%d %d %d\n" , ans[i].first , ans[i].second.first , ans[i].second.second);
		}
	}
	return 0;
}