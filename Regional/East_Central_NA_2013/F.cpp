#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int N = 205;
map <string , int> mymap;
int idx , a[N][N] , b[N][N] , n;
string name[N];
int main () {
#ifndef ONLINE_JUDGE 
	// freopen ("input.txt" , "r" , stdin);
#endif
	int cas = 0;
	while (cin >> n && n) {
		memset (a , 0 , sizeof (a));
		memset (b , 0 , sizeof (b));
		mymap.clear ();idx = 0;
		for  (int i = 0 ; i < n ; i ++) {
			string s , e;
			cin >> s >> e;
			if (mymap.count (s) == 0) name[idx] = s , mymap[s] = idx ++;
			if (mymap.count (e) == 0) name[idx] = e , mymap[e] = idx ++;
			a[mymap[s]][mymap[e]] = 1;
		}
		for (int k = 0 ; k < idx ; k ++) {
			for (int i = 0 ; i < idx ; i ++) {
				for (int j = 0 ; j < idx ; j ++) {
					if ((a[i][k] || b[i][k]) && (a[k][j] || b[k][j]))
						b[i][j] = 1;
				}
			}
		}
		vector <string> ans;
		for (int i = 0 ; i < idx ; i ++) {
			for (int j = 0 ; j < idx ; j ++) {
				if (a[i][j] && b[i][j]) {
					ans.push_back (name[i] + "," + name[j]);
				}
			}
		}
		sort (ans.begin () , ans.end ());
		printf ("Case %d: %d" , ++cas , (int)ans.size());
		for (int i = 0 ; i < ans.size() ; i ++)
			cout << " " << ans[i];
		cout << endl;
	}
	return 0;
}