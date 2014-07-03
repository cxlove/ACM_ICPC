#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define Key_value ch[ch[root][1]][0]
using namespace std;
typedef long long LL;
const int N = 2005;
int n , a[N] , b[N] , flag;
void dfs (int k , int s , int e) {
    if (flag) return ;
    if (k == n / 2) {
        flag = 1;
        return ;
    }
    while (b[s] != -1) s ++;
    for (int i = e ; i < n ; i ++) {
        if (i == s || b[i] != -1) continue;
        if (a[s] == a[i]) {
            b[s] = 0;b[i] = 1;
            dfs (k + 1 , s + 1 , i + 1);
            if (flag) return ;
            b[s] = b[i] = -1;
        } 
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("ouput.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        flag = 0;
        memset (b , -1 , sizeof(b));
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , &a[i]);
        dfs (0 , 0 , 1);
        for (int i = 0 ; i < n ; i ++) 
            printf ("%d" , b[i]);
        puts ("");
    }
    return 0;
}