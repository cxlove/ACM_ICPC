#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 55;
int n , m , a[N][N];
vector <pair <int , pair <int , int> > > v;
LL dp[N][N];
int way[4][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0};
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        v.clear ();
        cin >> n >> m;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                cin >> a[i][j];
                v.push_back (make_pair (a[i][j] , make_pair (i , j)));
            }
        }
        memset (dp , 0 , sizeof (dp));
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                int ok = 1;
                for (int k = 0 ; k < 4 ; k ++) {
                    int x = i + way[k][0] , y = j + way[k][1];
                    if (x >= 1 && x <= n && y >= 1 && y <= m) {
                        if (a[x][y] > a[i][j])
                            ok = 0;
                    }
                }
                dp[i][j] = ok;
            }
        }
        sort (v.rbegin () , v.rend ());
        for (int i = 0 ; i < v.size() ; i ++) {
            int x = v[i].second.first , y = v[i].second.second; 
            for (int k = 0 ; k < 4 ; k ++) {
                int X = x + way[k][0];
                int Y = y + way[k][1];
                if (X >= 1 && X <= n && Y >= 1 && Y <= m && a[X][Y] < a[x][y]) {
                    dp[X][Y] += dp[x][y];
                }
            }
        }
        LL ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                int ok = 1;
                for (int k = 0 ; k < 4 ; k ++) {
                    int x = i + way[k][0] , y = j + way[k][1];
                    if (x >= 1 && x <= n && y >= 1 && y <= m) {
                        if (a[x][y] < a[i][j])
                            ok = 0;
                    }
                }
                if (ok) ans += dp[i][j];
            }
        }
        cout << "Case #" << ++ cas << ": " << ans << endl;
    }
    return 0;
}