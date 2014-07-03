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
const int N = 1005;
struct Tree {
    int kind;
    int lson , rson;
    int w , h;
    char val;
    void init () {
        lson = rson = 0;
    }
}tree[N];
char str[N] , ans[N][N];
int tot , idx;
void width (int root , int w) {
    tree[root].w = w;
    if (tree[root].kind < 0) return ;
    int l = tree[root].lson , r = tree[root].rson;
    // vertical
    if (tree[root].kind) {
        int left = ceil (tree[l].w * 1.0 / (tree[l].w + tree[r].w) * w);
        width (l , left);
        width (r , w - left);
    }
    // horizontal
    else {
        width (l , w);
        width (r , w);
    }
}
void hight (int root , int h) {
    tree[root].h = h;
    if (tree[root].kind < 0) return ;
    int l = tree[root].lson , r = tree[root].rson;
    // vertical
    if (tree[root].kind) {
        hight (l , h);
        hight (r , h);
    }
    // horizontal
    else {
        int up = ceil (tree[l].h * 1.0 / (tree[l].h + tree[r].h) * h);
        hight (l , up);
        hight (r , h - up);
    }
}
int build () {
    int root = ++ tot;
    char ch = str[idx ++];
    tree[root].init ();
    if (ch >= 'A' && ch <= 'Z') {
        tree[root].kind = -1;
        tree[root].w = 2;
        tree[root].h = 2;
        tree[root].val = ch;
    }
    else {
        tree[root].lson = build ();
        tree[root].rson = build ();
        tree[root].kind = ch == '|';
        int l = tree[root].lson , r = tree[root].rson;
        if (ch == '-') {
            if (tree[l].w == tree[r].w) {
                tree[root].w = tree[l].w;
            }
            else {
                if (tree[l].w > tree[r].w) {
                    tree[root].w = tree[l].w;
                    width (r , tree[l].w);
                }
                else {
                    tree[root].w = tree[r].w;
                    width (l , tree[r].w);
                }
            }
            tree[root].h = tree[l].h + tree[r].h;
        }
        else {
            if (tree[l].h == tree[r].h) {
                tree[root].h = tree[l].h;
            }
            else {
                if (tree[l].h > tree[r].h) {
                    tree[root].h = tree[l].h;
                    hight (r , tree[l].h);
                }
                else {
                    tree[root].h = tree[r].h;
                    hight (l , tree[r].h);
                }
            }
            tree[root].w = tree[l].w + tree[r].w;
        }
    }
    return root;
}
void build (int root , int up , int left , int down , int right) {
    if (tree[root].kind < 0) {
        ans[up][left] = tree[root].val;
        return ;
    }
    int l = tree[root].lson , r = tree[root].rson;
    if (tree[root].kind) {
        int mid = left + tree[l].w;
        for (int i = up + 1 ; i < down ; i ++)
            ans[i][mid] = '|';
        ans[up][mid] = ans[down][mid] = '*';
        build (l , up , left , down , mid);
        build (r , up , mid , down , right);
    }
    else {
        int mid = up + tree[l].h;
        for (int i = left + 1 ; i < right ; i ++)
            ans[mid][i] = '-';
        ans[mid][left] = ans[mid][right] = '*';
        build (l , up , left , mid , right);
        build (r , mid , left , down , right);
    }
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s" , str);
        tot = idx = 0;
        int root = build ();
        int w = tree[root].w , h = tree[root].h;
        memset (ans , ' ' , sizeof(ans));
        for (int i = 0 ; i <= h ; i ++)
            ans[i][0] = ans[i][w] = '|';
        for (int i = 0 ; i <= w ; i ++)
            ans[0][i] = ans[h][i] = '-';
        ans[0][0] = ans[h][0] = ans[0][w] = ans[h][w] = '*';
        build (root , 0 , 0 , h , w);
        printf ("%d\n" , ++ cas);
        for (int i = 0 ; i <= h ; i ++) {
            for (int j = 0 ; j <= w ; j ++)
                putchar (ans[i][j]);
            putchar ('\n');
        }
    }
    return 0;
}