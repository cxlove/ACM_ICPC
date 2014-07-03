#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 105;
int t  , cas = 0;
int n , m;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &m , &n);
        printf ("Case #%d: " , ++ cas);
        if (m == 1) {
            for (int i = 0 ; i < n ; i ++)
                putchar ('a');
            puts ("");
        }
        else if (m == 2) {
            if (n == 1) puts("a");
            else if(n == 2) puts("ab");
            else if (n == 3) puts ("aab");
            else if (n == 4) puts ("aabb");
            else if (n == 5) puts ("aaaba");
            else if (n == 6) puts ("aaabab");
            else if (n == 7) puts ("aaababb");
            else if (n == 8) puts ("aaababbb");
            else {
                printf("aaaa");
                int l = (n - 4) / 6 , r = (n - 4) % 6;
                for (int i = 0 ; i < l ; i ++)
                    printf("babbaa");
                if (r == 1) puts ("a");
                else if (r == 2) puts ("aa");
                else if (r == 3) puts ("bab");
                else if (r == 4) puts ("babb");
                else if (r == 5) puts ("babba");
                else if ( r== 0) puts ("");
            }
        }
        else {
            for (int i = 0 ; i < n ; i ++) {
                putchar ('a' + i % 3);
            }
            puts ("");
        }
    }
    return 0;
}       