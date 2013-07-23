#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int MOD = 51123987;
const int N = 1005;
int n, m, y ,remain;
int x[N], k[N] ,id[N]; 
bool cmp(int i ,int j ){
    return (abs(x[i] * m - y * (k[i] + 1)) - abs(x[i] * m - y * k[i])) < (abs(x[j] * m - y * (k[j] + 1)) - abs(x[j] * m - y * k[j]));
}
int main() {
    scanf ("%d %d %d", &n, &m, &y);
    for (int i = 0 ; i < n ; i ++){
        scanf ("%d", &x[i]);
    }
    remain = m;
    for (int i = 0 ; i < n ; i ++){
        k[i] = floor(m * x[i] / y);
        remain -= k[i];
        id[i] = i;
    }
    sort(id, id + n, cmp);
    for (int i = 0 ; i < remain ; i ++){
        k[id[i]] ++;
    }
    for (int i = 0 ; i < n ; i ++){
        printf ("%d%c", k[i], i==n-1?'\n':' ');
    }
    return 0;
}
