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
char str[1000005];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;scanf ("%d" , &t);
    while (t --) {
        int id;scanf ("%d" , &id);getchar ();
        gets (str);
        // puts (str);
        int l = strlen (str);
        int n ;scanf ("%d" , &n);
        printf ("%d " , id);
        for (int i = 0 , pre = 0 ; i < n ; i ++) {
            int x;scanf ("%d" , &x);
            pre = ((pre + x) % l + l) % l;
            printf ("%c" , str[pre]);
        }
        puts ("");
    }
	return 0;
}