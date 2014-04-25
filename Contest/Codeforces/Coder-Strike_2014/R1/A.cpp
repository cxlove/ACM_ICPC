#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    int n , k;
    string s;
    cin >> n >> k >> s;
    if (k - 1 > (n - k)) {
        while (k < n) {
            puts ("RIGHT");
            k ++;
        }
        while (k > 1) {
            printf ("PRINT %c\n" , s[k - 1]);
            k --;
            printf ("LEFT\n");
        }
        printf ("PRINT %c\n" , s[0]);
    }
    else {
        while (k > 1) {
            puts ("LEFT");
            k --;
        }
        while (k < n) {
            printf ("PRINT %c\n" , s[k - 1]);
            k ++;
            printf ("RIGHT\n");
        }
        printf ("PRINT %c\n" , s[n - 1]);
    }
    return 0;
}