#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#define Bug cout << "here\n";

using namespace std;
const int INF = 0x7fffffff;
const int N = 205;

int cap[N][N];
int level[N];
int n, m;
bool dinic_bfs() { // 对顶点进行标号，找出层次图
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    memset(level, 0, sizeof(level));
    Q.push(1);
    level[1] = 1;
    int u, v;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        for(v = 1; v <= n; v++) {
            if(!level[v] && cap[u][v] > 0) {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
    return level[n] != 0; // false 汇点是否在层次图中
}

int dinic_dfs(int u, int cp) { // 在层次图中寻找增广路径进行增广
    int tmp = cp;
    int v, t;
    if(u == n) return cp;
    for(v = 1; v <= n&&tmp; v++) {
        if(level[v] == level[u] + 1 && cap[u][v] > 0) {
            t = dinic_dfs(v, min(tmp, cap[u][v]));
            cap[u][v] -= t;
            cap[v][u] += t;
            tmp -= t;
        }
    }
    return cp - tmp;
}

int dinic() {
    int sum_f, tf;
    sum_f = tf = 0;
    while(dinic_bfs()) { // 汇点不在层次图中，算法终止
        while(tf = dinic_dfs(1, INF)) {
            sum_f += tf;
        }
    }
    return sum_f;
}

int main() {
    int i, u, v, cost;
    while(scanf("%d%d", &m, &n) == 2) { // m 是边 ， n 是顶点
        memset(cap, 0, sizeof(cap));
        for(i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            cap[u][v] += cost;
        }
        int f = dinic();
        printf("%d\n", f);
    }
    return 0;
}

