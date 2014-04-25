#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 100005;
const int inf = 2000000007;
int a[N] , n , m , b[N] , c[N];
char s[N][5];int k[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int  cnt = 0;
    scanf ("%d %d" , &n , &m);
    for (int i = 0 ; i < m ; i ++) {
        scanf ("%s %d" , s[i] , &k[i]);
        if (a[k[i]] == 0) {
            if (s[i][0] == '-') a[k[i]] = -1 , cnt ++;
            else a[k[i]] = 1;
        }
    }
    int other = -1 , all = 1;
    for (int i = 0 ; i < m ; i ++) {
        if (s[i][0] == '-') a[k[i]] -= 2 , cnt --;
        else a[k[i]] += 2 , cnt ++;
        if (s[i][0] == '+' && cnt == 1) {
            if (other != -1 && other != k[i]) all = 0;
            other = k[i];
        }
        if (s[i][0] == '-' && cnt == 0) {
            if (other != -1 && other != k[i]) all = 0;
            other = k[i];
        }
        if (s[i][0] == '-' && cnt > 0) {
            c[k[i]] = -1;
        } 
        else if (s[i][0] == '+' && cnt > 1) {
            c[k[i]] = -1;
        }
    }
    vector <int> ans;
    for (int i = 1 ; i <= n ; i ++) {
        if (a[i] == 0) {
            ans.push_back (i);
        }
        else if (all) {
            if (other != -1 && i != other) continue;
            if (c[i] != -1) 
            ans.push_back (i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i ++)
        cout << ans[i] << " " ;

    return 0;
}