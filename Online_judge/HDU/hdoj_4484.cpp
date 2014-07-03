#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100000000;
const int M = 100000;
map <int , int> mymap;
int a[N];
int dfs (int u) {
    // cout << u << endl;
    if (mymap.find (u) != mymap.end ()) return mymap[u];
    mymap[u] = max (u , dfs (u % 2 == 0 ? u / 2 : u * 3 + 1));
}
int main () {
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
        mymap.clear ();
    mymap[1] = 1;
    for (int i = 2 ; i <= M ; i ++) {
        if (mymap.find (i) == mymap.end ())
            dfs (i);
    }
    int t , cas , n;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &cas , &n);
        printf ("%d %d\n" , cas , mymap[n]);
    }
    return 0;
}