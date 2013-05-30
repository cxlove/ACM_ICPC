#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const int N = 100002;

int n;
double ans, s1[N], w1[N], s2[N];
vi e[N];

void dfs(int u, int fa) {
    s1[u] = 0;
    w1[u] = 1.0;
    int du = e[u].size();
    for (int i = 0; i != du; i++) {
        int v = e[u][i];
        int dv = e[v].size();
        if (v == fa) continue;
        dfs(v, u);
        s1[u] += w1[v]/dv;
        if (dv == 1) s1[u] += s1[v];
        else s1[u] += s1[v]/(dv-1);
    }
    // printf("dfs1 %d : %.3f\n", u+1, s1[u]);
}

void dfs2(int u, int fa) {
    // printf("dfs2 %d : %.3f\n", u+1, s2[u]);
    int du = e[u].size();
    for (int i = 0; i != du; i++) {
        int v = e[u][i];
        int dv = e[v].size(); //printf("%d %d\n", v, dv);
        if (v == fa) continue;
        s2[v] = s2[u]/(du-1) + w1[u]/du;
        double tmp = s1[u] - w1[v]/dv;
        if (dv == 1) tmp -= s1[v];
        else tmp -= s1[v]/(dv-1);
        s2[v] += tmp/(du-1);
        if (dv == 1) ans = max(ans, s2[v]);
        else dfs2(v, u);
    }
}

int main() {
    while (scanf("%d", &n)!= EOF && n != 0) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            e[u].pb(v);
            e[v].pb(u);
        }
        int rt = 0;
        while (e[rt].size() == 1) rt++;
        dfs(rt, -1);
        s2[rt] = 0;
        ans = -1;
        dfs2(rt, -1);
        printf("%.3f\n", ans);
    }
    return 0;
}