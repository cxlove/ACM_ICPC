#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int n, m, k;
long long ans;
const int MAX_N = 50000 + 10;
struct State {
State*suf, *go[26];
int val, sc, c;
void clear() {
suf = 0;
sc = 0;
val = 0;
c = 0;
memset(go, 0, sizeof go);
}
int calc() {
if (suf == 0)
return 0;
return val - suf->val;
}
}*root, *last;
State statePool[MAX_N * 10], *cur;

void init() {
    ans = 0;
cur = statePool;
root = last = cur++;
root->clear();
}

void extend(int w) {
State*p = last, *np = cur++;
np->clear();
np->val = p->val + 1;
np->sc = 1;
if(k == 1) {
        ans++;
        np->c = 1;
}
while (p && !p->go[w])
p->go[w] = np, p = p->suf;
if (!p) {
np->suf = root;
} else {
State*q = p->go[w];
if (p->val + 1 == q->val) {
np->suf = q;
State *tmp = q;
while(tmp != root) {
                if(tmp->c == 1) break;
                tmp->sc++;
                if(tmp->sc >= k) {
                    ans += tmp->calc();
                    tmp->c = 1;
                }
                tmp = tmp->suf;
}
} else {
State*nq = cur++;
nq->clear();
memcpy(nq->go, q->go, sizeof q->go);
nq->val = p->val + 1;
nq->c = q->c;
nq->sc = q->sc;
nq->suf = q->suf;
q->suf = nq;
np->suf = nq;
while (p && p->go[w] == q)
p->go[w] = nq, p = p->suf;
State *tmp = nq;
while(tmp != root) {
                if(tmp->c == 1) break;
                tmp->sc++;
                if(tmp->sc >= k) {
                    ans += tmp->calc();
                    tmp->c = 1;
                }
                tmp = tmp->suf;
}
}
}
last = np;
}

char s[MAX_N];
void work() {
scanf("%s", s);
int l = strlen(s);
    init();
for (int i = 0; i < l; ++i) {
        extend(s[i] - 'a');
}
    char sss[5];
    for(int i = 0; i < m; i++) {
        int cc;
        scanf("%d", &cc);
        if(cc == 1) {
            scanf("%s", sss);
            extend(sss[0] - 'a');
        } else printf("%I64d\n", ans);
    }
}

int main() {
    // freopen ("input.txt" , "r"  , stdin);
while(1) {
        if(scanf("%d%d%d", &n, &m, &k) == EOF) return 0;
        work();
}

return 0;
}