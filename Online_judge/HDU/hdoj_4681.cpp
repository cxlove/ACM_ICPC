#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1005;
char a[N] , b[N] , c[N];
int pa[N] , pb[N];
int pre[N][N] , aft[N][N];
int la , lb , lc;
int gao (int i , int j) {
    if (i < 0 || j < 0) return 0;
    return pre[i][j];
}
int cao (int i , int j) {
    if (i >= la || j >= lb) return 0;
    return aft[i][j];
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s %s %s" , a , b , c);
        la = strlen (a) , lb = strlen (b) , lc = strlen (c);
        memset (pa , -1 , sizeof(pa));
        memset (pb , -1 , sizeof(pb));
        for (int i = 0 ; a[i] ; i ++) {
            int l = i , r = 0;
            while (l < la && r < lc) {
                if (a[l] == c[r]) l ++ , r ++;
                else l ++;
            }
            if (r == lc) pa[i] = l;
            else pa[i] = -1; 
        }
        for (int i = 0 ; b[i] ; i ++) {
            int l = i , r = 0;
            while (l < lb && r < lc) {
                if (b[l] == c[r]) l ++ , r ++;
                else l ++;
            }
            if (r == lc) pb[i] = l;
            else pb[i] = -1; 
        }
        memset (pre , 0 , sizeof(pre));
        memset (aft , 0 , sizeof(aft));
        pre[0][0] = (a[0] == b[0]);
        for (int i = 1 ; i < la ; i ++)
            pre[i][0] = pre[i - 1][0] | (a[i] == b[0]);
        for (int i = 1 ; i < lb ; i ++)
            pre[0][i] = pre[0][i - 1] | (a[0] == b[i]);
        for (int i = 1 ; i < la ; i ++) {
            for (int j = 1 ; j < lb ; j ++) {
                pre[i][j] = max (pre[i - 1][j] , pre[i][j - 1]);
                if (a[i] == b[j]) pre[i][j] = max (pre[i][j] , pre[i - 1][j - 1] + 1);
            }
        }
        aft[la - 1][lb - 1] = (a[la - 1] == b[lb - 1]);
        for (int i = la - 2 ; i >= 0 ; i --) 
            aft[i][lb - 1] = aft[i + 1][lb - 1] | (a[i] == b[lb - 1]);
        for (int i = lb - 2 ; i >= 0 ; i --) 
            aft[la - 1][i] = aft[la - 1][i + 1] | (a[la - 1] == b[i]);
        for (int i = la - 2 ; i >= 0 ; i --) {
            for (int j = lb - 2 ; j >= 0 ; j --) {
                aft[i][j] = max (aft[i + 1][j] , aft[i][j + 1]);
                if (a[i] == b[j]) aft[i][j] = max (aft[i][j] , aft[i + 1][j + 1] + 1);
            }
        }
        int ans = 0;
        for (int i = 0 ; i < la ; i ++) {
            if (pa[i] == -1) continue;
            for (int j = 0 ; j < lb ; j ++) {
                if (pb[j] == -1) continue;
                ans = max (ans , lc + gao (i - 1 , j - 1) + cao (pa[i] , pb[j]));
            }
        }
        printf ("Case #%d: %d\n" , ++cas , ans);
    }
    return 0;
}