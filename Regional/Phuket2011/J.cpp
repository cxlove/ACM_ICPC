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
#include <map>
#include <cmath>
using namespace std;
const int N = 25;
const long long inf = (long long)2e18;
struct Node {
    int x , y ;
    int w , h;
    Node () {}
    Node (int _x , int _y , int _w , int _h) :w(_w),h(_h),x(_x),y(_y) {}
};
vector <Node> v;
int vis[N][N] , used[N] , ans;
pair <int , int> place[N];
char str[N][N];
void dfs (int cnt) {
    if (cnt == v.size()) {
        for (int x = 0 ; x < 16 ; x ++) {
            for (int y = 0 ; y < 16 ; y ++) {
                int ret = 0;
                for (int i = 0 ; i < v.size() ; i ++) {
                    ret += abs(x + place[i].first - v[i].x) + abs (y + place[i].second - v[i].y);
                }
                ans = min (ans , ret);
            }
        }
        return ;
    }

    for (int i = 0 ; i < 5 ; i ++) {
        for (int j = 0 ; j < 5 ; j ++) {
            if (vis[i][j] == 0) {
                for (int k = 0 ; k < v.size() ; k ++) {
                    if (v[k].h + i > 5 || v[k].w + j > 5 || used[k]) continue;
                    int ok = 1;
                    for (int p = 0 ; p < v[k].h ; p ++) {
                        for (int q = 0 ; q < v[k].w ; q ++) {
                            if (vis[i + p][j + q]) ok = 0;
                        }
                    }
                    // if (cnt == 3) cout << ok << endl; 
                    if (ok) {
                        for (int p = 0 ; p < v[k].h ; p ++) {
                            for (int q = 0 ; q < v[k].w ; q ++) {
                                vis[i + p][j + q] = 1;
                            }
                        }
                        place[k] = make_pair (i , j);
                        used[k] = 1;
                        dfs (cnt + 1);
                        used[k] = 0;
                        for (int p = 0 ; p < v[k].h ; p ++) {
                            for (int q = 0 ; q < v[k].w ; q ++) {
                                vis[i + p][j + q] = 0;
                            }
                        }
                    }
                }
                return ;
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        for (int i = 0 ; i < 20 ; i ++) {
            scanf ("%s" , str[i]);
        }
        v.clear ();
        int ok = 1;
        for (int i = 0 ; i < 20 ; i ++) {
            for (int j = 0 ; j < 20 ; j ++) {
                if (str[i][j] == 'x') {
                    int w = 0 , h = 0;
                    while (str[i][j + w] == 'x') w ++;
                    while (str[i + h][j] == 'x') h ++;
                    v.push_back (Node(i , j , w , h));
                    if (w > 5 || h > 5) ok = 0;
                    for (int p = 0 ; p < w ; p ++) {
                        for (int q = 0 ; q < h ; q ++) {
                            str[i + q][j + p] = '.';
                        }
                    }
                }
            }
        }
        printf ("Case %d: " , ++ cas);
        if (!ok) {
            puts ("invalid data");
            continue;
        }
        memset (vis , 0 , sizeof (vis));
        memset (used , 0 , sizeof (used));
        ans = 1 << 30;
        dfs (0);
        if (ans >= (1 << 30)) puts ("invalid data");
        else printf ("%d\n" , ans);
    }
    return 0;
}