#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 505;
char str[N][N];
int n , m , t;
int left_up[N][N] , right_up[N][N] , left_down[N][N] , right_down[N][N];
int dp_left_up[N][N] , dp_left_down[N][N] , dp_right_up[N][N] , dp_right_down[N][N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n, &m);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%s" , str[i] + 1);
        }
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                left_up[i][j] = left_down[i][j] = right_down[i][j] = right_up[i][j] = 1;
                for (int k = 1 ; i - k > 0 && j - k > 0 ; k ++) {
                    if (str[i - k][j] != str[i][j - k]) break;
                    left_up[i][j] ++;
                }
                for (int k = 1 ; i - k > 0 && j + k <= m ; k ++) {
                    if (str[i - k][j] != str[i][j + k]) break;
                    right_up[i][j] ++;
                }
                for (int k = 1 ; i + k <= n && j - k > 0 ; k ++) {
                    if (str[i + k][j] != str[i][j - k]) break;
                    left_down[i][j] ++;
                }
                for (int k = 1 ; i + k <= n && j + k <= m ; k ++) {
                    if (str[i + k][j] != str[i][j + k]) break;
                    right_down[i][j] ++;
                }
            }
        }
        memset (dp_right_down , 0 , sizeof(dp_right_down));
        memset (dp_right_up , 0 , sizeof (dp_right_up));
        memset (dp_left_down , 0 , sizeof (dp_left_down));
        memset (dp_left_up , 0 , sizeof (dp_left_up));
        int ans = 1;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                dp_left_up[i][j] = min (left_up[i][j] , dp_left_up[i - 1][j - 1] + 2);
                ans = max (ans , dp_left_up[i][j]);
            }
        }
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = m ; j > 0 ; j --) {
                dp_right_up[i][j] = min (right_up[i][j] , dp_right_up[i - 1][j + 1] + 2);
                ans = max (ans , dp_right_up[i][j]);
            }
        }
        for (int i = n ; i > 0 ; i --) {
            for (int j = 1 ; j <= m ; j ++) {
                dp_left_down[i][j] = min (left_down[i][j] , dp_left_down[i + 1][j - 1] + 2);
                ans = max (ans , dp_left_down[i][j]);
            }
        }
        for (int i = n ; i > 0 ; i --) {
            for (int j = m ; j > 0 ; j --) {
                dp_right_down[i][j] = min (right_down[i][j] , dp_right_down[i + 1][j + 1] + 2);
                ans = max (ans , dp_right_down[i][j]);
            }
        }
        printf ("%d\n" , ans * (ans + 1) / 2);
    }
    return 0;
}