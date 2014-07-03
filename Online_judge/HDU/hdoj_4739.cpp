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
const int N = 20;
const int M = 105;
struct Point {
    int x , y;
    void input () {
        scanf ("%d %d" , &x , &y);
    }
}p[N];
int mat[M][M] , ans , n;
void dfs (int ret) {
    ans = max (ret , ans);
    for (int i = 0  ; i < n ; i ++) {
        if (!mat[p[i].x][p[i].y]) continue;
        for (int j = i + 1 ; j < n ; j ++) {
            if (mat[p[j].x][p[j].y]) {
                if (p[i].x != p[j].x && abs (p[i].x - p[j].x) == abs (p[i].y - p[j].y)) {
                    if (mat[p[i].x][p[j].y] && mat[p[j].x][p[i].y]) {
                        mat[p[i].x][p[i].y] --;
                        mat[p[j].x][p[j].y] --;
                        mat[p[i].x][p[j].y] --;
                        mat[p[j].x][p[i].y] --;
                        
                        dfs (ret + 1);

                        mat[p[i].x][p[i].y] ++;
                        mat[p[j].x][p[j].y] ++;
                        mat[p[i].x][p[j].y] ++;
                        mat[p[j].x][p[i].y] ++;
                        
                    }
                } 
            }
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF && n != -1) {
        memset (mat , 0 , sizeof(mat));
        for (int i = 0 ; i < n ; i ++) {
            p[i].input ();
            mat[p[i].x][p[i].y] ++;
        }
        ans = 0;
        dfs (0);
        printf ("%d\n" , ans * 4);
    }
    return 0;
}