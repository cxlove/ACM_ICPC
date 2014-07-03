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
const int N = 25;
const int M = 100000;
const double eps = 1e-8;
struct Point {
    double x , y;
}p[N];
int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
int main () {
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        int cas , n , m , s ;double ang;
        scanf ("%d %d %d %d %lf" , &cas , &n , &m , &s , &ang);
        for (int i = 1 ; i <= n ; i ++) {
            int id;double x , y;
            scanf ("%d" , &id);
            scanf ("%lf %lf" , &p[id].x , &p[id].y);
        }
        printf ("%d" , cas);
        while (m --) {
            vector <pair <double , int> > v;v.clear ();
            for (int i = 1 ; i <= n ; i ++) {
                if (i == s) continue;
                double d = atan2 (p[s].y - p[i].y , p[s].x - p[i].x) * 180 / acos (-1.0);
                if (dcmp (d) < 0) d += 180;
                if (dcmp (d - ang) <= 0) d += 180;
                v.push_back (make_pair (d , i));
            }
            sort (v.begin () , v.end());
            s = v[0].second;
            ang = v[0].first;
            printf (" %d" , s);
            if (dcmp (ang - 180) >= 0) ang -= 180;
            ang = fabs (ang);
        }
        puts ("");
    }
    return 0;
}