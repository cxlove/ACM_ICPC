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
const int N = 100005;
const long long inf = (long long)2e18;
int n , m;
int v[N] , ans;
bool gao (int black , int white) {
    for (int i = 0 ; i < m ; i ++) {
        if ((black & v[i]) == v[i])
            return false;
        if ((white & v[i]) == v[i])
            return false;
    }
    return true;
}
void dfs (int idx , int black , int white) {
    if (idx == n) {
        ans = 1;
        return ;
    }
    if (ans) return;
    if (gao (black | (1 << idx) , white)) {
        dfs (idx + 1 , black | (1 << idx) , white);
    }
    if (ans) return;
    if (gao (black , white | (1 << idx))) {
        dfs (idx + 1 , black , white| (1 << idx));
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);getchar ();
        for (int i = 0 ; i < m ; i ++) {
            v[i] = 0;
            char s[1000];gets (s);
            stringstream input (s);
            int num;
            while (input >> num) {
                num --;
                v[i] |= (1 << num);
            }
        }
        ans = 0;
        dfs (0 , 0 , 0);
        if (ans) putchar ('Y');
        else putchar ('N');
    }
    // puts ("");
    return 0;
}
