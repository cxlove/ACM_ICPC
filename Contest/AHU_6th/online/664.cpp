#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
const int N = 45;
using namespace std;
struct Node {
    int x , y , z , v , step;
    Node () {}
    Node (int _x , int _y , int _z , int _v , int _s) {
        x = _x;y = _y;z = _z;v = _v;step = _s;
    }
};
queue <Node> que;
int c[N * N * N] , a[N][N][N] , n , m;
int way[6][3] = {0 , 0 , 1 , 0 , 0 , -1 , 1 , 0 , 0 , -1 , 0 , 0 , 0 , 1 , 0 , 0 , -1 , 0};
void bfs () {
    while (!que.empty ()) {
        Node u = que.front ();que.pop ();
        for (int i = 0 ; i < 6 ; i ++) {
            Node v = u;v.step ++;
            v.x += way[i][0];v.y += way[i][1];v.z += way[i][2];
            if (v.x >= 0 && v.y >= 0 && v.z >= 0 && v.x <  n && v.y < n && v.z < n) {
                if (a[v.x][v.y][v.z] == 0) {
                    a[v.x][v.y][v.z] = u.v;
                    c[u.v] ++;
                    que.push (v);
                }
            }
        }
    }
}
int main () {
    int t;scanf ("%d" , &t);
    while (t --) {
        memset (a , 0 , sizeof (a));
        while (!que.empty ()) que.pop();
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= m ; i ++) {
            int x , y , z;
            scanf ("%d %d %d" , &x , &y , &z);
            que.push (Node (x , y , z , i , 0));
            a[x][y][z] = i;
            c[i] = 1;
        }
        bfs ();
        for (int i = 1 ; i <= m ; i ++)
            printf ("%d%s" , c[i] , (i == m ? "\n" : " "));
    }
    return 0;
}