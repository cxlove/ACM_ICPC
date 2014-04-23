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
int n , m , c[N] , s[N] , cnt[N] , p[N] , a[N] , id[N];
vector <pair <int , int> > v[N];
vector <long long> sum[N];
int best[N];
bool cmp (int i , int j) {
    return cnt[i] < cnt[j];
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d" , &n);
    for (int i = 0 ; i < n ; i ++) {
        scanf ("%d %d" , &c[i] , &s[i]);
        a[i] = c[i];
    }
    sort (a , a + n);
    m = unique (a , a + n) - a;
    for (int i = 0 ; i < n ; i ++) {
        int col = lower_bound (a , a + m , c[i]) - a;
        cnt[col] ++;
    }
    for (int i = 0 ; i < m ; i ++) {
        id[i] = i;
    }
    sort (id , id + m , cmp);
    for (int i = 0 ; i < m ; i ++) {
        p[id[i]] = i;
    }
    for (int i = 0 ; i < n ; i ++) {
        int col = p[lower_bound (a , a + m , c[i]) - a];
        v[col].push_back (make_pair (s[i] , i + 1));
    }
    for (int i = 0 ; i < m ; i ++) {
        sort (v[i].begin () , v[i].end ());
        reverse (v[i].begin () , v[i].end ());
        sum[i].resize (v[i].size() + 5);
        for (int j = 1 ; j <= v[i].size() ; j ++) {
            sum[i][j] = sum[i][j - 1] + v[i][j - 1].first;
        }
        // for (int j = 0 ; j < v[i].size() ; j ++) {
        //     printf ("(%d , %d) " , v[i][j].first  , v[i][j].second);
        // } puts ("");
    }
    long long ans = -1;
    memset (best , -1 , sizeof (best));
    pair <int , int> one , two;
    for (int i = 0 ; i < m ; i ++) {
        int sz = v[i].size ();
        for (int j = 1 ; j <= sz ; j ++) {
            // j - 1
            if (j + j - 1 > 1 && best[j - 1] >= 0 && sum[best[j - 1]][j - 1] + sum[i][j] > ans) {
                ans = sum[best[j - 1]][j - 1] + sum[i][j];
                one = make_pair (best[j - 1] , j - 1);
                two = make_pair (i , j);
            }
            // j 
            if (j + j > 1 && best[j] >= 0 && sum[best[j]][j] + sum[i][j] > ans) {
                ans = sum[best[j]][j] + sum[i][j];
                one = make_pair (best[j] , j);
                two = make_pair (i , j);
            }
            // j + 1
            if (j + j + 1 > 1 && best[j + 1] >= 0 && sum[best[j + 1]][j + 1] + sum[i][j] > ans) {
                ans = sum[best[j + 1]][j + 1] + sum[i][j];
                one = make_pair (best[j + 1] , j + 1);
                two = make_pair (i , j);
            }
        }
        for (int j = 1 ; j <= sz ; j ++) {
            if (best[j] == -1 || sum[i][j] > sum[best[j]][j]) {
                best[j] = i;
            }
        }
    }
    printf ("%I64d\n" , ans);
    printf ("%d\n" , one.second + two.second);
    if (one.second < two.second) swap (one , two);
    for (int i = 0 , j = 0 , k = 0 ; i < one.second + two.second ; i ++) {
        if (i % 2 == 0) {
            printf ("%d " , v[one.first][j ++].second);
        }
        else printf ("%d " , v[two.first][k ++].second);
    }
    return 0;
}