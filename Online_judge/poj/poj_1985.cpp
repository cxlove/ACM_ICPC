#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 40001;
bool v[MAXN];
int ans, p;
vector<pair<int, int> > e[MAXN];
void dfs(int u, int d)
{
    if (d > ans)
    {
        ans = d;
        p = u;
    }
    v[u] = 1;
    for (int k = 0; k < e[u].size(); ++ k)
        if (!v[e[u][k].first])
            dfs(e[u][k].first, d + e[u][k].second);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m --)
    {
        int x, y, w;
        scanf("%d%d%d %*c", &x, &y, &w);
        e[x].push_back(make_pair(y, w));
        e[y].push_back(make_pair(x, w));
    }
    ans = 0;
    memset(v, 0, sizeof v);
    dfs(1, 0);
    ans = 0;
    memset(v, 0, sizeof v);
    dfs(p, 0);
    printf("%d\n", ans);
    return 0;
}


