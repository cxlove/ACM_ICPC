#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 65;
int n , m , k , l;
int a[N][N][N] , can[N][N][N];
int way[6][3] = {0 , 0 , 1 , 0 , 0 , -1 , 0 , 1 , 0 , 0 , -1 , 0 , 1 , 0 , 0 , -1 , 0 , 0 };
pair <int , pair <int , int> > mp (int x , int y , int z) {
    return make_pair (x , make_pair (y , z));
}
bool check (pair <int , pair <int , int> > v) {
    int x = v.first , y = v.second.first , z = v.second.second;
    return x >= 1 && x <= n && y >= 1 && y <= m && z >= 1 && z <= k && !can[x][y][z];
}
void bfs () {
    memset (can , 0 , sizeof(can));
    queue <pair <int , pair <int , int> > > que;
    for (int x = 0 ; x <= n + 1 ; x ++) {
        for (int y = 0 ; y <= m + 1 ; y ++) {
            for (int z = 0 ; z <= k + 1 ; z ++) {
                if (x == 0 || y == 0 || z == 0 || x == n + 1 || y == m + 1 || z == k + 1) {
                    que.push(mp (x , y , z));
                    can[x][y][z] = 1;
                }
            }
        }
    }
    while (!que.empty ()) {
        pair <int , pair <int , int> > u , v;
        u = que.front ();que.pop ();
        for (int i = 0 ; i < 6 ; i ++) {
            v = u;
            v.first += way[i][0];
            v.second.first += way[i][1];
            v.second.second += way[i][2];
            if (check (v)) {
                can[v.first][v.second.first][v.second.second] = 1;
                if (a[v.first][v.second.first][v.second.second]) continue;
                que.push (v);
            }
        }
    }
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
    while (scanf ("%d %d %d %d" , &n , &m , &k , &l) != EOF && n + m + k + l){
        memset (a , 0 , sizeof(a));
        for (int i = 1 ; i <= l ; i ++) {
            int r;scanf ("%d" , &r);
            int z = r / (n * m);
            int y = (r % (n * m)) / n;
            int x = r % n;
            // cout << x + 1 << " " << y + 1 << " " << z + 1 << endl;
            a[x + 1][y + 1][z + 1] = 1;
        }
        bfs ();
        int ans = l * 6;
        for (int x = 1 ; x <= n ; x ++) { 
            for (int y = 1 ; y <= m ; y ++) {
                for (int z = 1 ; z <= k ; z ++) {
                    if (!a[x][y][z]) continue;
                    if (!can[x][y][z]) {
                        ans -= 6;
                        continue;
                    }
                    for (int dir = 0 ; dir < 6 ; dir ++) {
                        int X = x + way[dir][0];
                        int Y = y + way[dir][1];
                        int Z = z + way[dir][2];
                        if ((a[x][y][z] && a[X][Y][Z]) || (a[x][y][z] && !can[X][Y][Z]))
                            ans --;
                    }
                }
            }
        }
        printf ("The number of faces needing shielding is %d.\n" , ans);
    }
    return 0;
}