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
const int N = 1000005;
const double eps = 1e-9;
struct Trie {
    Trie *next[26] , *fail;
    int cnt;
}s[N] , *root , *que[N];
int tot , n , k , end[N];
vector <int > edge[N];
int idx = 1 , l[N] , r[N] , in[N] , id[N];
char str[N];
Trie *NewNode () {
    Trie *p = &s[tot ++];
    p -> cnt = 0;
    p -> fail = NULL;
    for (int i = 0 ; i < 26 ; i ++)
        p -> next[i] = NULL;
    return p;
}
void insert (char *str , int id) {
    Trie *p = root;
    for (int i = 0 ; str[i] ; i ++) {
        int c = str[i] - 'a';
        if (p -> next[c] == NULL) p -> next[c] = NewNode ();
        p = p -> next[c];
    }
    p -> cnt ++;
    end[id] = p - s;
}
void build_fail () {
    int head = 0 , tail = 0;
    que[tail ++] = root;
    while (head < tail) {
        Trie *u = que[head ++];
        for (int i = 0 ; i < 26 ; i ++) {
            if (u -> next[i]) {
                if (u == root) u -> next[i] -> fail = root;
                else {
                    Trie *p = u -> fail;
                    while (p) {
                        if (p -> next[i]) {
                            u -> next[i] -> fail = p -> next[i];
                            break;
                        }
                        p = p -> fail;
                    }
                    if (p == NULL) u -> next[i] -> fail = root;
                }
                u -> next[i] -> cnt += u -> next[i] -> fail -> cnt;
                que[tail ++] = u -> next[i];
            }
            else if (u == root) u -> next[i] = root;
            else u -> next[i] = u -> fail -> next[i];
        }
    }
}
void dfs (int u , int pre) {
    l[u] = idx ++;
    for (int i = 0 ; i < edge[u].size() ; i ++) {
        dfs (edge[u][i] , u);
    }
    r[u] = idx - 1;
}
long long num[N];
inline int lowbit (int x) {
    return x & (-x);
}
inline void add (int x , int val) {
    for (int i = x ; i <= tot ; i += lowbit (i)) {
        num[i] += val;
    }
}
inline long long ask (int x) {
    long long ret = 0;
    for (int i = x ; i > 0 ; i -= lowbit (i))
        ret += num[i];
    return ret;
}
inline void update (int l , int r , int val) {
    add (l , val);add (r + 1 , -val);
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d %d" , &n , &k);
    root = NewNode ();
    for (int i = 0 ; i < k ; i ++) {
        scanf ("%s" , str);
        insert (str , i + 1);
    }
    build_fail ();
    for (int i = 0 ; i < tot ; i ++) {
        if (s[i].fail) {
            edge[s[i].fail - s].push_back (i);
        }
    }
    dfs (0 , -1);
    for (int i = 1 ; i <= k ; i ++) {
        in[i] = 1;
        update (l[end[i]] , r[end[i]] , 1);
    }
    while (n --) {
        scanf ("%s" , str);
        if (str[0] == '?') {
            Trie *p = root;
            long long ans = 0;
            for (int i = 1 ; str[i] ; i ++) {
                int c = str[i] - 'a';
                p = p -> next[c];
                ans += ask (l[p - s]);
            }
            printf ("%I64d\n" , ans);
        }
        else {
            int d;sscanf (str + 1 , "%d" , &d);
            if (str[0] == '+') {
                if (in[d]) continue;
                update (l[end[d]] , r[end[d]] , 1);
            }
            else {
                if (!in[d]) continue;
                update (l[end[d]] , r[end[d]] , -1);
            }
            in[d] = 1 - in[d];
        }
    }
    return 0;
}