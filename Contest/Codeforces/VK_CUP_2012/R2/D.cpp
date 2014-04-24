#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 10005;
const double eps = 1e-9;
long long p[N] , a[N] , tp[N] , ta[N];
int t , n;
vector <long long> fac;
long long V;
void  gao (long long now , int idx) {
    if (now * 1.0 * now * now <= V + 0.1) {
        fac.push_back (now);
    }
    else return;
    if (idx == n) return;
    long long num = now;
    for (int j = 0 ; j <= a[idx] ; j ++) {
        if (num * 1.0 * num * num > V) return;
        gao (num , idx + 1);
        num = num * p[idx];
    }
}
void cao (long long A , long long B , int idx , long long lim , long long &TB) {
    if (B * 1.0 * B <= lim && B >= A) {
        TB = max (TB , B);
    }
    if (idx == n) return;
    long long num = B;
    for (int j = 0 ; j <= ta[idx] ; j ++) {
        if (num * 1.0 * num > lim) return;
        cao (A , num , idx + 1 , lim , TB);
        num = num * tp[idx];
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d" , &t);
    while (t --) {
        V = 1LL;
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%I64d %I64d" , &p[i] , &a[i]);
            for (int j = 0 ; j < a[i] ; j ++) {
                V = V * p[i];
            }
        }
        long long A = 1 , B = 1 , C = V , ans = 2LL * (A * B + B * C + A * C);
        fac.clear ();
        gao (1LL , 0);
        sort (fac.begin () , fac.end ());
        fac.resize (unique (fac.begin () , fac.end ()) - fac.begin ());
        for (int i = fac.size() - 1 ; i >= 0 ; i --) {
            long long TA = fac[i] , temp = TA , TB = -1;
            double tmp = sqrt (V * 1.0 / TA);
            double mx = 2.0 * (TA * tmp + tmp * tmp + TA * tmp);
            if (mx > ans) continue;
            for (int j = 0 ; j < n ; j ++) {
                tp[j] = p[j];ta[j] = a[j];
            }
            for (int j = 0 ; j < n ; j ++) {
                while (temp % tp[j] == 0) {
                    ta[j] --;
                    temp /= tp[j];
                }
            }
            if (temp != 1) {
                puts ("error");
                return 0;
            }
            cao (TA , 1LL , 0 , V / TA , TB);
            if (TB == -1) continue;
            long long TC = V / TA / TB;
            long long ret = 2 * (TA * TB + TB * TC + TA * TC);
            if (ret < ans) {
                ans = ret;
                A = TA;B = TB;C = TC;
            }
        }
        printf ("%I64d %I64d %I64d %I64d\n" , ans , A , B , C);
    }
    return 0;
}