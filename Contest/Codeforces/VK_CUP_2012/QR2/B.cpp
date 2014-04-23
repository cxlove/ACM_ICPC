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
const int N = 100005;
const int inf = N * 10;
int n , m;
vector <int> a[N] , b[N];
map <int , int> mymap;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++) {
        int u , v;
        cin >> u >> v;
        a[v].push_back (u);
    }
    for (int i = 0 ; i < m ; i ++) {
        int u , v;
        cin >> u >> v;
        b[v].push_back (u);
    }
    int ans = 0 , ret = 0;
    for (int i = 1 ; i <= 1000 ; i ++) {
        ans += min (a[i].size() , b[i].size ());
        mymap.clear ();
        for (int j = 0 ; j < a[i].size() ; j ++) {
            mymap[a[i][j]] ++;
        }
        for (int j = 0 ; j < b[i].size() ; j ++) {
            if (mymap.find (b[i][j]) == mymap.end ()) continue;
            if (mymap[b[i][j]] > 0) ret ++;
            mymap[b[i][j]] --;
        }
    }
    cout << ans << " " << ret << endl;
    return 0;
}