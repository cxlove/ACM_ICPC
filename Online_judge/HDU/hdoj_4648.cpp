#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100005;
int n , m , a[N] , sum[N] = {0} , last[N];
int main () {
    while (scanf ("%d %d" , &n , &m) != EOF) {
        memset (last , -1 , sizeof(last));
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
            sum[i] = ((sum[i - 1] + a[i]) % m + m) % m;
            last[sum[i]] = i;
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            ans = max (last[sum[i - 1]] - i + 1 , ans);
        }
        printf ("%d\n" , ans);
    }
    return 0;
}        