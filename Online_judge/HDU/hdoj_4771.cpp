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
const int N = 105;
struct Node {
    int x , y , s , t;
}s;
int n , m , k;
char str[N][N];
int flag[N][N][1 << 4];
int way[4][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0};
void bfs () {
    memset (flag , 0 , sizeof(flag));
    queue <Node> que;
    que.push(s);
    flag[s.x][s.y][s.s] = 1;
    while (!que.empty ()) {
        Node u = que.front () , v ;
        que.pop ();
        for (int i = 0 ; i < 4 ; i ++) {
            v = u;
            v.x += way[i][0];
            v.y += way[i][1];
            if (str[v.x][v.y] == '#') continue;
            if (str[v.x][v.y] >= '1' && str[v.x][v.y] <= '9') {
                v.s |= 1 << (str[v.x][v.y] - '1');
            }
            v.t ++;
            // cout << v.x << " " << v.y << " " << v.s << " " << v.t << endl;
            if (v.s == ((1 << k) - 1)) {
                printf ("%d\n" , v.t);
                return ;
            }
            if (flag[v.x][v.y][v.s] == 0) {
                flag[v.x][v.y][v.s] = 1;
                que.push(v);
            }
        }
    }
    puts ("-1");
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        if (n == 0 && m == 0) break;
        memset (str , '#' , sizeof(str));
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%s" , str[i] + 1);
            str[i][m + 1] = '#';
            for (int j = 1 ; j <= m ; j ++) {
                if (str[i][j] == '@') {
                    s.x = i;
                    s.y = j;
                    s.s = 0;
                    s.t = 0;
                }
            }
        }
        scanf ("%d" , &k);
        for (int i = 0 ; i < k ; i ++) {
            int x , y;
            scanf ("%d %d" , &x , &y);
            str[x][y] = '1' + i;
        }
        bfs ();
    }
    return 0;
}