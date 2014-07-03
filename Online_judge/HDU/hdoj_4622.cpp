#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 2005;
struct SAM {
    SAM * pre , * son[26];
    int len;
}*root , *tail , que[N << 2];
struct Query {
    int l , r , id;
    void input(int i) {
        scanf ("%d %d", &l , &r);
        l --; r --;
        id = i;
    }
    bool operator < (const Query &q) const {
        return l != q.l ? l < q.l : r < q.r;
    }
}a[10005];
int tot , q , ans[10005];
char str[N];
void init () {
    for (int i = 0 ; i < tot ; i ++){ 
        que[i].pre = NULL;
        for (int j = 0 ; j < 26 ; j ++)
            que[i].son[j] = NULL;
        que[i].len = 0;
    }
    tot = 0 ;
    root = tail = &que[tot ++];
}
int gao () {
    int ret = 0;
    for (int i = tot - 1 ; i ; i --) {
        if (que[i].pre != NULL)
        ret += que[i].len - que[que[i].pre - que].len;
    }
    return ret;
}
void add (int c , int l) {
    SAM *p = tail , *np = &que[tot ++];
    np -> len = l;
    while (p && p -> son[c] == NULL) p -> son[c] = np , p = p -> pre;
    if (p == NULL) np -> pre = root;
    else {
        SAM *q = p -> son[c];
        if (p -> len + 1 == q -> len) np -> pre = q;
        else {
            SAM *nq = &que[tot ++];
            *nq = *q;
            nq -> len = p -> len + 1;
            np -> pre = q -> pre = nq;
            while (p && p -> son[c] == q) p -> son[c] = nq , p = p -> pre;
        }
    }
    tail = np;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s %d" ,str , &q);
        a[0].l = - 1;
        for (int i = 1 ; i <= q ; i ++) {
            a[i].input(i);
        }
        sort (a + 1 , a + q + 1);
        for (int i = 1 ; i <= q ; i ++) {
            if (a[i].l != a[i - 1].l) {
                init ();
                for (int j = a[i].l ; j <= a[i].r ; j ++) {
                    add (str[j] - 'a' , j - a[i].l + 1);
                }
                ans[a[i].id] = gao ();
            }
            else {
                for (int j = a[i - 1].r + 1 ; j <= a[i].r ; j ++) {
                    add (str[j] - 'a' , j - a[i].l + 1);
                }
                ans[a[i].id] = gao();
            }
        } 
        for (int i = 1 ; i <= q ; i ++)
            printf ("%d\n" , ans[i]);
    }
    return 0;
}