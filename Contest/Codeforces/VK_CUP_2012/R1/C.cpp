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
const int N = 31;
int len[N] , mid[N];
map <pair <pair <int , int> , pair <int , int> > , int> dp;
int gao (int l1 , int r1 , int l2 , int r2 , int k) {
    pair <pair <int , int> , pair <int , int> > p  = make_pair (make_pair (l1 , r1) , make_pair (l2 , r2));
    if (dp.find (p) != dp.end ()) return dp[p];
    int ans = max (0 , min (r1 , r2) - max (l1 , l2) + 1);
    if (k == 1) return ans;
    if (r1 > mid[k] && r2 > mid[k]) {
        ans = max (ans , gao (max (l1 , mid[k] + 1) - mid[k] ,  r1 - mid[k] , max (l2 , mid[k] + 1) - mid[k] , r2 - mid[k] , k - 1));
    }
    if (r1 > mid[k] && l2 < mid[k]) {
        ans = max (ans , gao (max (l1 , mid[k] + 1) - mid[k] ,  r1 - mid[k] , l2 , min (r2 , mid[k] - 1) , k - 1));
    }
    if (l1 < mid[k] && r2 > mid[k]) {
        ans = max (ans , gao (l1 , min (r1 , mid[k] - 1) , max (l2 , mid[k] + 1) - mid[k] , r2 - mid[k] , k - 1));
    }
    if (l1 < mid[k] && l2 < mid[k]) {
        ans = max (ans , gao (l1 , min (r1 , mid[k] - 1) , l2 , min (r2 , mid[k] - 1) , k - 1));
    }
    return dp[p] = ans;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    len[1] = 1;mid[1] = 1;
    for (int i = 2 ; i < N ; i ++) {
        len[i] = len[i - 1] * 2 + 1;
        mid[i] = len[i - 1] + 1;
    }
    int l1 , r1 , l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << gao (l1 , r1 , l2 , r2 , 30) << endl;
    return 0;
}