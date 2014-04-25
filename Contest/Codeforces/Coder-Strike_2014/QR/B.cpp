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
typedef  long long LL;          
const int N = 105;
int n , m , k;
int a[N][N] , cnt[N];
int ans[N] , can[N];
int main () {
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++)
            cin >> a[i][j];
    }
    for (int i = 1 ; i <= m ; i ++) {
        memset (cnt , 0 , sizeof (cnt)); 
        for (int j = 1 ; j <= n ; j ++) {
            if (can[a[j][i]]) {
                if (ans[j] == 0) ans[j] = i;
            }
            else if (!ans[j])
                cnt[a[j][i]] ++;
        }
        for (int j = 1 ; j <= k ; j ++) {
            if (cnt[j] > 1) {
                can[j] = 1;
                for (int r = 1 ; r <= n ; r ++) {
                    if (a[r][i] == j && !ans[r]) {
                        ans[r] = i;
                    }
                }
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << endl;
    return 0;
}