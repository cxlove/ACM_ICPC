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
const int MOD = 1000000007;
int n , k , h , m[N] , v[N] , id[N];
vector <int> ans ,  tmp;
const double eps = 1e-10;
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
bool cmp (int i , int j) {
    return m[i] != m[j] ? m[i] < m[j] : v[i] < v[j];
}
bool check (double t) {
    tmp.clear ();
    int i , j ;
    for (i = 1 , j = 0 ; i <= k && j < n ; j ++) {
        int p = id[j];
        if (dcmp (1.0 * i * h - v[p] * t) <= 0) {
            tmp.push_back (p);
            i ++;
        }
    }
    if (i <= k) return  false;
    return true;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> k >> h;
    for (int i = 0 ; i < n ; i ++) {
        id[i] = i;
        cin >> m[i];
    }
    for (int i = 0 ; i < n ; i ++) {
        cin >> v[i];
    }
    sort (id , id + n , cmp);
    double low = 0.0 , high = 1e18 , mid;
    int step = 200;
    while (step --) {
        mid = (low + high) / 2.0;
        if (check (mid)) {
            ans = tmp;
            high = mid;
        }
        else low = mid;
    }
    for (int i = 0 ; i < k ; i ++) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}