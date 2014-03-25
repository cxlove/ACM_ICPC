#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 1000005;
const int inf = 1000000007;
struct Trie {
    Trie *next[26];
    int cnt , mx;
    char ans[11];
}s[M] , *root;
int tot;
Trie *newnode () {
    Trie *p = &s[tot ++];
    memset (p -> next , 0 , sizeof (p -> next));
    p -> cnt = p -> mx = 0;
    return p;
}
int insert (Trie *p , char *s , int now) {
    if (p == NULL) return -1;
    if (s[now] == '\0') {
        if (p -> cnt >= p -> mx) puts (s);
        else puts (p -> ans);
        p -> cnt ++;
        if (p -> cnt >= p -> mx) {
            strcpy (p -> ans , s);
        }
        return p -> cnt;
    }
    int c = s[now] - 'a';
    if (p -> next[c] == NULL) p -> next[c] = newnode ();
    int cnt = insert (p -> next[c] , s , now + 1);
    if (cnt > p -> mx) {
        p -> mx = cnt;
        strcpy (p -> ans , s);
    }
    else if (cnt == p -> mx && strcmp (s , p -> ans) < 0) {
        strcpy (p -> ans , s);
    }
    return cnt;
}
int main () {
#ifndef ONLINE_JUDGE
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    tot = 0;root = newnode ();
    int n;scanf ("%d" , &n);
    while (n --) {
        char str[11];scanf ("%s" , str);
        insert (root , str , 0);
    }
    return 0;
}