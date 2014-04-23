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
int n , m , x , y , a[N] , b[N];
vector <pair <int , int> > ans;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> m >> x >> y;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
    sort (a , a + n);
    for (int i = 0 ; i < m ; i ++)
        cin >> b[i];
    sort (b , b + m);
    for (int i = 0 , j = 0 ; i < n && j < m ;) {
        if (b[j] >= a[i] - x  && b[j] <= a[i] + y) {
            ans.push_back (make_pair (i + 1 , j + 1));
            i ++;j ++;
        }
        else if (a[i] < b[j]) i ++;
        else j ++;
    }
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i ++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}