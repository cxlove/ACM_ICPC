#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define Key_value ch[ch[root][1]][0] 
#define pii pair<pair<int,int>,int>
using namespace std;
typedef long long LL;
const int N = 100005;
const int S = 30;
int n , k , s;
int a[N] , rank[N];
int r[N] , LESS[N] , nonbig[N];
int next[N] , ans ;
    void add (int x , int val) {
        if (x == 0) return ;
        for (int i = x ; i <= S ; i += lowbit(i)){
            r[i] += val;
        }
    }
    int sum (int x) {
        int ret = 0;
        for (int i = x ; i > 0 ; i -= lowbit(i)) {
            ret += r[i];
        }
        return ret;
    }
    void get_next (int s[] , int l) {
        next[0] = -1;
        int i = 0 , j = -1;
        while (i < l) {
            if (j == -1 || (sum(s[i]) == nonbig[j] && sum(s[i] - 1) == LESS[j])) {
                i ++ ; j ++ ;
                next[i] = j;
                if (i == l) return ;
                add (s[i] , 1);
            }
            else {
                for (int k = i - j ; k < i - next[j] ; k ++)
                    add (s[k] , -1);
                j = next[j];
            }
        }
    }
    void kmp (int *a , int ls , int *p , int lp) {
        int i = 0 , j = 0 ;
        add (a[0] , 1);
        while (i < ls && j < lp) {
            if (j == -1 || (sum(a[i]) == nonbig[j] && sum(a[i] - 1) == LESS[j])) {
                i ++ ; j ++ ;
                add (a[i] , 1);
            }
            else {
                for (int k = i - j ; k < i - next[j] ; k ++)
                    add (a[k] , -1);
                j = next[j];
            }
            if (j == lp) {
                ans ++;
                for (int k = i - j ; k < i ; k ++)
                    add (a[k] , -1);
                j = 0;
            }
        }
    }
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d %d" , &n , &k , &s) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
        }
        memset (r , 0 , sizeof(r));
        for (int i = 0 ; i < k ; i ++) {
            scanf ("%d" , &rank[i]);
            add (rank[i] , 1);
            LESS[i] = sum (rank[i] - 1);
            nonbig[i] = sum (rank[i]);
        }
        memset (r , 0 , sizeof(r));
        get_next (rank , k);
        memset (r , 0 , sizeof(r));
        ans = 0;
        kmp (a , n , rank , k);
        printf ("%d\n" , ans);
    }
    return 0;
}       
