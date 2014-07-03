#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL ;
int main () {
    int t;
    scanf ("%d" , &t);
    while (t--) {
        int n , m ,k;
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i< n ; i ++)
            for (int j = 0 ; j< m ;j ++)
                scanf ("%d" , &k);
        puts(k ? "Alice" : "Bob");
    }
    return 0;
}        