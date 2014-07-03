#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 5000005;
int flag[N];
void Init () {
    flag[1] = 1;flag[0] = 1;
    for (int i = 2 ; i < N ; i ++) {
        if (flag[i]) continue;
        for (int j = 2 ; j * i < N ; j ++)
            flag[i * j] = 1;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d" , &t);
    Init ();
    while (t --) {
        int n;
        scanf ("%d" , &n);
        if (n >= 0) {
            for (int i = n ; ; i ++) {
                if (flag[i] == 0 && flag[i - n] == 0) {
                    printf ("%d %d\n" , i , i - n);
                    break;
                }
            }
        }
        else {
            n = -n;
            for (int i = n + 2 ; ; i ++) {
                if (flag[i] == 0 && flag[i - n] == 0) {
                    printf ("%d %d\n" , i - n , i);
                    break;
                }
            }
        }
    }
    return 0;
}