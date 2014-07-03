#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#define error {puts("-1");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 200005;
struct Node {
    int a , b , c;
    void input () {
        scanf ("%d %d %d" , &a , &b , &c);
    }
}a[N];
int n;
bool cmpab (Node a , Node b) {
    return a.a - a.b < b.a - b.b;
}
bool cmpbc (Node a , Node b) {
    return a.b - a.c < b.b - b.c;
}
bool cmpca (Node a , Node b) {
    return a.c - a.a < b.c - b.a;
}
int main () {
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++)
            a[i].input ();
        LL ans = 0;
        sort (a , a + n , cmpab);
        for (int i = 1 ; i < n ; i ++) {
            LL t = (a[i].a - a[i].b) - (a[i - 1].a - a[i - 1].b);
            ans += t * 1LL * i * (n - i);
        }
        sort (a , a + n , cmpbc);
        for (int i = 1 ; i < n ; i ++) {
            LL t = (a[i].b - a[i].c) - (a[i - 1].b - a[i - 1].c);
            ans += t * 1LL * i * (n - i);
        }
        sort (a , a + n , cmpca);
        for (int i = 1 ; i < n ; i ++) {
            LL t = (a[i].c - a[i].a) - (a[i - 1].c - a[i - 1].a);
            ans += t * 1LL * i * (n - i);
        }
        printf ("%lld\n" , ans / 2);
    }
    return 0;
}