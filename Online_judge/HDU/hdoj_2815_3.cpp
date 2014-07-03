#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LL long long
#define nmax 5000005
typedef struct node {
    int num, ii;
} node;
node Node[nmax];
int x, y;
int cmp(const void *n, const void *m) {
    node *a = (node *) n;
    node *b = (node *) m;
    if (a->num == b->num) {
        if (a->ii > b->ii) {
            return 1;
        }
        return -1;
    }
    if (a->num > b->num) {
        return 1;
    }
    return -1;
}
int gcd(int a, int b) {
    int te;
    if (a < b) {
        te = a, a = b, b = te;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int ext_gcd(int a, int b) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = ext_gcd(b, a % b);
    int tx = x;
    x = y, y = tx - a / b * y;
    return d;
}
int inval(int a, int b, int n) {
    int e;
    ext_gcd(a, n);
    e = (LL) x * b % n;
    return e < 0 ? e + n : e;
}
int modular_exp(int a, int b, int c) {
    LL ret = 1 % c, te = a % c;
    while (b) {
        if (b & 1) {
            ret = ret * te % c;
        }
        te = te * te % c;
        b >>= 1;
    }
    return (int) ret;
}
int bsearchn(int x, int n) {
    int left, mid, right;
    left = 0, right = n + 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (Node[mid].num == x) {
            return Node[mid].ii;
        } else if (Node[mid].num > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int baby_step_giant_step(int a, int b, int c) {
    int i, j, d, tep, m, K, tem, k;
    LL D, buf;
    for (i = 0, buf = 1 % c, D = buf; i < 100; i++, buf = buf * a % c) {
        if (buf == b) {
            return i;
        }
    }
    d = 0;
    while ((tep = gcd(a, c)) != 1) {
        if (b % tep) {
            return -1;
        }
        ++d;
        c /= tep, b /= tep;
        D = D * a / tep % c;
    }
    m = (int) (ceil(sqrt((double) c)));
    for (i = 0, buf = 1 % c; i <= m; i++, buf = buf * a % c) {
        Node[i].num = (int) buf;
        Node[i].ii = i;
    }
    qsort(Node, m + 1, sizeof(Node[0]), cmp);
    for (i = 0, j = 0, k = -1; i <= m; i++) {
        if (k != Node[i].num) {
            Node[j++] = Node[i];
            k = Node[i].num;
        }
    }
    m = j;
    K = modular_exp(a, m, c);
    for (i = 0; i <= m; i++, D = D * K % c) {
        tem = inval((int) D, b, c);
        if (tem >= 0) {
            if ((j = bsearchn(tem, m)) != -1) {
                return i * m + j + d;
            }
        }
    }
    return -1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("t.txt", "r", stdin);
#endif
    int k, p, n, res;
    while (scanf("%d %d %d", &k, &p, &n) != EOF) {
        if (n >= p) {
            puts("Orz,I can’t find D!");
            continue;
        }
        res = baby_step_giant_step(k, n, p);
        if (res == -1) {
            puts("Orz,I can’t find D!");
            continue;
        }
        printf("%d\n", res);
    }
    return 0;
}
