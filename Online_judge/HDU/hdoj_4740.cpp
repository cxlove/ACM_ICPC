#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 1005;
int way[4][2] = {0 , 1 , 1 , 0 , 0 , -1 , -1 , 0};
int a[N][N] , b[N][N];
int n;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        int xa , xb , ya , yb , da , db;
        scanf ("%d %d %d %d %d %d" , &xa , &ya , &da , &xb , &yb , &db);
        memset (a , 0 , sizeof(a));
        memset (b , 0 , sizeof(b));
        bool flag = false;
        bool aa = true , bb = true;
        a[xa][ya] = 1;b[xb][yb] = 1;
        if (xa == xb && ya == yb) {
            printf ("%d %d\n" , xa , xb);
            continue;
        }
        while (aa || bb) {
            int xx , yy;
            if (aa) {
                xx = xa + way[da][0];
                yy = ya + way[da][1];
                if (xx < 0 || yy < 0 || xx >= n || yy >= n || a[xx][yy]) {
                    da = (da + 1) % 4;
                    xx = xa + way[da][0];
                    yy = ya + way[da][1];
                }
                if (xx >= 0 && yy >= 0 && xx < n && yy < n && !a[xx][yy]) {
                    xa = xx;
                    ya = yy;
                    a[xx][yy] = 1;
                }
                else aa = false;
            }
            if (bb) {
                xx = xb + way[db][0];
                yy = yb + way[db][1];
                if (xx < 0 || yy < 0 || xx >= n || yy >= n || b[xx][yy]) {
                    db = (db + 3) % 4;
                    xx = xb + way[db][0];
                    yy = yb + way[db][1];
                }
                if (xx >= 0 && yy >= 0 && xx < n && yy < n && !b[xx][yy]) {
                    xb = xx;
                    yb = yy;
                    b[xx][yy] = 1;
                }
                else bb = false;
            }
            // cout << xa << " " << xb << " " << ya << " " << yb << endl;
            if (xa == xb && ya == yb) {
                printf ("%d %d\n" , xa , ya);
                flag = true;
                break;
            }
        }
        if (!flag) puts ("-1");
    }
    return 0;
}