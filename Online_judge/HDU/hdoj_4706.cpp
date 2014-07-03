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

char str[1005][1005];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int c = 0;
    for (int i = 3 ; i <= 10 ; i ++) {
        memset (str , ' ' , sizeof(str));
        for (int j = 0 ; j < i ; j ++) {
            str[j][0] = c + 'a';
            c = (c + 1) % 26;
        }
        for (int j = i - 2 ; j > 0 ; j --) {
            str[j][i - j - 1] = c + 'a';
            c = (c + 1) % 26;
        }
        for (int j = 0 ; j < i ; j ++) {
            str[j][i - 1] = c + 'a';
            c = (c + 1) % 26;
        }
        for (int j = 0 ; j < i ; j ++) {
            for (int k = 0 ; k < i ; k ++) {
                putchar (str[j][k]);
            }
            puts("");
        }
    }
    return 0;
}