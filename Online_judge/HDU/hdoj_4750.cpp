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
#include <string>
#include <cstring>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

template <class T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template <class T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

struct Rec {
    int a, b, c;
    bool operator < (const Rec& x) const {
        return c < x. c;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 11000;
const int M = 500010;

int n, m, p, t, belong[N], num[N], w[M];
LL s[M];
Rec e[M];
map<int, int> g;

int find(int x) { return belong[x] == x ? x : belong[x] = find(belong[x]); }

int lowbit(int x) { return x & (-x);}

void update(int x, LL data) {
    while (x <= m) {
        // printf("%d %I64d\n", x, data);
        s[x] += data;
        x += lowbit(x);
    }
}

LL getsum(int x) {
    LL ret = 0;
    while (x > 0) {
        ret += s[x];
        x -= lowbit(x);
    }
    return ret;
}

int succh(int x) {
    int ret = m + 1;
    for (int l = 1, r = m; l <= r;) {
        int mid = (l + r) >> 1;
        // printf("%d %d %d\n", l, mid, r);
        if (w[mid] >= x) { ret = mid, r = mid - 1; }
        else l = mid + 1;
    }
    return ret;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
            w[i + 1] = e[i].c;
        }
        sort(e, e + m);
        sort(w + 1, w + m + 1);
        g.clear();
        for (int i = 1; i <= m; i++) g[w[i]] = i;

        for (int i = 0; i <= m; i++) s[i] = 0;
        for (int i = 0; i < n; i++) belong[i] = i, num[i] = 1;

        for (int i = 0; i < m; i++) {
            int u = e[i].a, v = e[i].b, w = e[i].c;
            int fu = find(u), fv = find(v);
            if (fu == fv) continue;
            update(g[w], num[fu] * 1ll * num[fv]);
            belong[fv] = fu; num[fu] += num[fv];
        }

        scanf("%d", &p);
        LL tot = getsum(m);
        while (p--) {
            scanf("%d", &t);
            if (t <= w[1]) { printf("%I64d\n", tot * 2); continue; }
            int k = succh(t);
            printf("%I64d\n", (tot - getsum(k - 1)) * 2);
        }
    }
    return 0;
}