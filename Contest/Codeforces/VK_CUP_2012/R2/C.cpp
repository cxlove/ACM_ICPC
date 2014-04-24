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
const int N = 400005;
const double eps = 1e-9;
int n , m , cnt[N];
double len , v1 , v2 , p[N] , x[N] , ans[N];
vector <pair <double , double> > v;
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d %lf %lf %lf" , &n , &len , &v1 , &v2);
    for (int i = 0 ; i < n ; i ++) {
        scanf ("%lf" , &p[i]);
        double pos = len * v2 / (v1 + v2);
        if (dcmp (p[i] - pos) >= 0) {
            v.push_back (make_pair (2.0 * len - p[i] , pos + 2 * len - p[i]));
        }
        else {
            v.push_back (make_pair (0 , -p[i] + pos));
            v.push_back (make_pair (2.0 * len - p[i] , 2.0 * len));
        }
    }
    for (int i = 0 ; i < v.size() ; i ++) {
        x[m ++] = v[i].first;
        x[m ++] = v[i].second;
    }
    sort (x , x + m);
    m = unique (x , x + m) - x;
    for (int i = 0 ; i < v.size() ; i ++) {
        int L = lower_bound (x , x + m , v[i].first) - x + 1;
        int R = lower_bound (x , x + m , v[i].second) - x + 1;
        cnt[L] ++;cnt[R] --;
    }
    for (int i = 2 ; i <= m ; i ++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1 ; i < m ; i ++) {
        ans[cnt[i]] += x[i] - x[i - 1];
    }
    ans[0] = 2 * len;
    for (int i = 1 ; i <= n ; i ++) {
        ans[0] -= ans[i];
    }
    for (int i = 0 ; i <= n ; i ++) {
        printf ("%.10f\n" , ans[i] / (2 * len));
    }
    return 0;
}