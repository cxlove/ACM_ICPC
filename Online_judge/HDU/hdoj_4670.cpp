#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 50005;
struct Edge {  
    int v , next;  
}e[N << 1];  
int n , k;
LL val[N] , prime[N] , hash[N];
int tot , start[N];  
int del[N] , size[N];  
void _add (int u , int v) {  
    e[tot].v = v; e[tot].next = start[u];  
    start[u] = tot ++;  
}  
void add (int u , int v) {  
    _add (u , v);  
    _add (v , u);  
}  
void cal (int u , int pre) {  
    size[u] = 1;  
    for (int i = start[u] ; i != -1 ; i = e[i].next) {  
        int v = e[i].v;  
        if (v == pre || del[v]) continue;  
        cal (v , u);  
        size[u] += size[v];  
    }  
}  
int newroot , maxsize , totalsize;  
void dfs (int u , int pre) {  
    int mx = 0 , sum = 1;  
    for (int i = start[u] ; i != -1 ; i = e[i].next) {  
        int v = e[i].v;  
        if (v == pre || del[v]) continue;  
        dfs (v , u);  
        mx = max (mx , size[v]);  
    }  
    mx = max (mx , totalsize - size[u]);  
    if (mx < maxsize) maxsize = mx , newroot = u;  
}  
int search (int r) {  
    cal (r , -1);  
    totalsize = size[r];  
    maxsize = 1 << 30;newroot = -1;  
    dfs (r , -1);  
    return newroot;  
}  
int idx;
vector <LL> all , sub[N];
LL ans = 0 , dist[N];
LL add (LL a , LL b) {
    int c[30];
    for (int i = 0 ; i < k ; i ++) {
        c[i] = (a % 3 + b % 3) % 3;
        a /= 3; b /= 3;
    }
    LL ret = 0;
    for (int i = k - 1 ; i >= 0 ; i --)
        ret = ret * 3 + c[i];
    return ret;
}
LL subtract (LL a , LL b) {
    int c[30];
    for (int i = 0 ; i < k ; i ++) {
        c[i] = (a % 3 - b % 3 + 3) % 3;
        a /= 3; b /= 3;
    }
    LL ret = 0;
    for (int i = k - 1 ; i >= 0 ; i --)
        ret = ret * 3 + c[i];
    return ret;
}
void gao (int u , int pre) {  
    all.push_back (dist[u]);  
    sub[idx].push_back (dist[u]);  
    for (int i = start[u] ; i != -1 ; i = e[i].next) {  
        int v = e[i].v;  
        if (v == pre || del[v]) continue;  
        dist[v] = add (dist[u] , hash[v]);  
        gao (v , u);  
    }  
}
map <LL , int> mymap;  
LL fuck (vector <LL> &v , LL root) {
    mymap.clear ();
    for (int i = 0 ; i < v.size () ; i ++) {
        mymap[v[i]] ++;
    }
    LL ret = 0;
    for (int i = 0 ; i < v.size() ; i ++) {
        LL t = subtract (subtract (0 , root) , v[i]);
        if (v[i] == t) ret --;
        ret += mymap[t]; 
    }
    ret /= 2;
    return ret + mymap[subtract (0 , root)];
}
LL cao (vector <LL> &v , LL root) {
    mymap.clear ();
    for (int i = 0 ; i < v.size () ; i ++) {
        mymap[v[i]] ++;
    }
    LL ret = 0;
    for (int i = 0 ; i < v.size() ; i ++) {
        LL t = subtract (subtract (0 , root) , v[i]);
        if (v[i] == t) ret --;
        ret += mymap[t]; 
    }
    // cout << "ret :" << ret << endl;
    return ret / 2;
}
void solve (int root) {  
    root = search (root);  
    del[root] = 1;  
    if (hash[root] == 0) ans ++;
    if (totalsize == 1) return ;
    idx = 0 ; all.clear();  
    for (int i = start[root] ; i != - 1 ; i = e[i].next) {  
        int v = e[i].v;  
        if (del[v]) continue;  
        sub[idx].clear();  
        dist[v] = hash[v];  
        gao (v , -1);  
        idx ++;  
    }  
    // cout << "root : " << root << endl;
    // cout << ans << endl;
    // all.push_back (hash[root]);
    ans += fuck (all , hash[root]);  
    // cout << ans << endl;
    for (int i = 0 ; i < idx ; i ++) {  
        ans -= cao (sub[i] , hash[root]);  
    }  
    // cout << ans << endl;
    // cout << "root :" << root << endl;
    // for (int i = 0 ; i < all.size() ; i ++)
    //     cout << all[i] << " " ; cout << endl;
    for (int i = start[root] ; i != -1 ; i = e[i].next) {  
        int v = e[i].v;  
        if (del[v]) continue;  
        solve (v);  
    }  
}  
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("1005.in" , "r" , stdin);
        freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF) {
        tot = 0;
        memset (start , -1 , sizeof(start));
        memset (del , 0 , sizeof(del));
        scanf ("%d" , &k);
        for (int i = 0 ; i < k ; i ++)
            scanf ("%I64d" , &prime[i]);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%I64d" , &val[i]);
            hash[i] = 0;
            for (int j = 0 ; j < k ; j ++) {
                int cnt = 0;
                while (val[i] % prime[j] == 0) {
                    val[i] /= prime[j];
                    cnt = (cnt + 1) % 3;
                }
                hash[i] = hash[i] * 3LL + cnt;
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            add (u , v);
        }
        ans = 0LL;
        solve (1);
        printf ("%I64d\n" , ans);
    }
    return 0;    
}