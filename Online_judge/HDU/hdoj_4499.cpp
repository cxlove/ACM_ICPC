#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 10;
int n , m , q , ans;
int have[N][N] , cannot[N][N];
int cannon[N][N];
void dfs (int row , int col , int cnt) {
    if (row == n) {
        ans = max (ans , cnt);
        return ;
    }
    if (col == m) {
        dfs (row + 1 , 0 , cnt);
        return ;
    }
    if (have[row][col]) {
        dfs (row , col + 1 , cnt);
        return ;
    }
    if (cannot[row][col]) {
        dfs (row , col + 1 , cnt);
        return ;
    }
    dfs (row , col + 1 , cnt);
    vector <pair<int ,int> > v;
    cannon[row][col] = 1;
    int havecon = 0 , idx = -1;
    for (int j = col - 1 ; j >= 0 ; j --) {
        if (have[row][j]) break;
        if (cannon[row][j]) {
            havecon = 1;
            idx = j;
            break;
        }
    }
    if (havecon) {
        for (int j = col + 1 ; j < m ; j ++) {
            if (have[row][j]) break;
            if (cannot[row][j]) continue;
            cannot[row][j] = 1;
            v.push_back (make_pair (row , j));
        }
    }
    havecon = 0 , idx = -1;
    for (int j = row - 1 ; j >= 0 ; j --) {
        if (have[j][col]) break;
        if (cannon[j][col]) {
            havecon = 1;
            idx = j;
            break;
        }
    }
    if (havecon) {
        for (int j = row + 1 ; j < n ; j ++) {
            if (have[j][col]) break;
            if (cannot[j][col]) continue;
            v.push_back (make_pair (j , col));
            cannot[j][col] = 1;
        }
    }
    havecon = 0 , idx = -1;
    for (int j = row + 1 ; j < n ; j ++) {
        if (have[j][col]) {
            havecon = 1;
            idx = j;
            break;
        }
    }
    if (havecon) {
        for (int j = idx + 1 ; j < n ; j ++) {
            if (have[j][col]) break;
            if (cannot[j][col]) continue;
            v.push_back (make_pair (j , col));
            cannot[j][col] = 1;
        }
    }
    havecon = 0 , idx = -1;
    for (int j = col + 1 ; j < m ; j ++) {
        if (have[row][j]) {
            havecon = 1;
            idx = j;
            break;
        }
    }
    if (havecon) {
        for (int j = idx + 1 ; j < m ; j ++) {
            if (have[row][j]) break;
            if (cannot[row][j]) continue;
            cannot[row][j] = 1;
            v.push_back (make_pair (row , j));
        }
    }
    dfs (row , col + 1 , cnt + 1);
    cannon[row][col] = 0;
    for (int i = 0 ; i < v.size() ; i ++)
        cannot[v[i].first][v[i].second] = 0;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d %d" , &n , &m , &q) != EOF) {
        memset (have , 0 , sizeof(have));
        memset (cannot , 0 , sizeof(cannot));
        memset (cannon , 0 , sizeof(cannon));
        ans = 0;
        for (int i = 0 ; i < q ; i ++) {
            int u , v ;
            scanf ("%d %d" , &u , &v);
            have[u][v] = 1;
        }
        dfs (0 , 0 , 0);
        printf ("%d\n" , ans);
    }
    return 0;
}

