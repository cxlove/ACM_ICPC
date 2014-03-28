#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef unsigned long long LL;
map <int , int> mymap;
int dfs (int n) {
    if (mymap.count (n)) return mymap[n];
    mymap[n] = max (n , dfs (n & 1 ? 3 * n + 1 : n / 2));
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
    mymap[1] = 1;
	int t;scanf ("%d" , &t);
    while (t --) {
        int id , n;
        scanf ("%d %d" , &id , &n);
        printf ("%d %d\n" , id , dfs (n));
    }
	return 0;
}