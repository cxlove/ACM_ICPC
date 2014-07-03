#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 330;

bool flag;
int n, c[N], d[N];
char g[N][N];

void dfs(int i) {
    if (!flag) return;
    for (int j = 0; j < n; j++) if (g[i][j] == '1') {
        if (c[j] == -1) {
            c[j] = c[i] ^ 1;
            dfs(j);
        }
        else if (c[j] == c[i]) { flag = false; break; }
    }
}

int main() {
    int T;
    // freopen ("input.txt" , "r" , stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        flag = true;
        for (int i = 0; i < n; i++) c[i] = -1;
        for (int i = 0; i < n && flag; i++) if (c[i] == -1) {
            c[i] = 0;
            dfs(i);
        }

        if (!flag) puts("No");
        else {
            for (int i = 0; i < n; i++) if (c[i] == 1) {
                d[i] = 0;
                for (int j = 0; j < n; j++) if (g[i][j] == '1' && c[j] == 0) d[i]++;
                    // cout << i << " " << d[i] << endl;
            }
            for (int i = 0; i < n && flag; i++) if (c[i] == 1 && d[i] > 0) {
                for (int j = i + 1 ; j < n && flag; j++) if ( c[j] == 1 && d[j] > 0) {
                    int tmp = 0;
                    for (int k = 0; k < n; k++) if (c[k] == 0 && g[i][k] == '1' && g[j][k] == '1') tmp++;
                        // cout << i << " " << j << " " << d[i] << " " << d[j] << " " << tmp << endl;
                    if (d[i] - tmp > 0 && d[j] - tmp > 0) flag = false;
                }
            }
            if (flag) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}