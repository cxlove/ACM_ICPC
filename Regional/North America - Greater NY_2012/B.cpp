#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef unsigned long long LL;
char str[10000005];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;scanf ("%d" , &t);
    while (t --) {
        int id , b;
        scanf ("%d %d %s" , &id , &b , str);
        int ans = 0;
        for (int i = 0 ; str[i] ; i ++) {
            ans = (ans * b + str[i] - '0') % (b - 1);
        }
        printf ("%d %d\n" , id , ans);
    }
	return 0;
}