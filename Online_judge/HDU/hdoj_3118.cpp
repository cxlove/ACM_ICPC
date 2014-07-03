#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, u[330], v[330];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) scanf("%d%d", &u[i], &v[i]);

        int ans = m;
        int bits = 1 << n;
        for (int i = 0; i < bits; i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if ( ((i >> u[j]) & 1) == ((i >> v[j]) & 1) ) tmp++;
            }
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}    