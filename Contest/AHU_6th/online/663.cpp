#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int main () {
    int t;scanf ("%d" , &t);
    while (t --) {
        int n , a[3];memset (a , 0 , sizeof (a));
        scanf ("%d" , &n);
        while (n --) {
            int k;scanf ("%d" , &k);
            k --;
            a[k] ++;
        }
        int ans = 0;
        for (int i = 0 ; i < 3 ; i ++) {
            int win = a[(i + 1) % 3] , lose = a[(i + 2) % 3];
            if (win > lose) {
                ans = i + 1;
                break;
            }
        }
        printf ("%d\n" , ans);
    }
    return 0;
}
