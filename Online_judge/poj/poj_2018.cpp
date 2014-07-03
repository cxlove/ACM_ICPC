#include <stdio.h>

#define MAX_N 100032

double S[MAX_N], A[MAX_N];
int N, F;

int check(double val)
{
    double cur, pre;
    int i;

    pre = S[F - 1] - val * (F - 1);
    for (i = F; i <= N; i++) {
        cur = S[i] - S[i - F] - val * F;
        pre = pre + A[i] - val;
        if (cur > pre)
            pre = cur;
        if (pre > -1e-6)
            return 1;
    }

    return 0;
}

int main()
{
    int i;
    double l, r, m;

   // freopen("e:\\test\\in.txt", "r", stdin);

    scanf("%d%d", &N, &F);
    l = 1e50;
    r = 0;
    A[0] = S[0] = 0;
    for (i = 1; i <= N; i++) {
        scanf("%lf", &A[i]);
        if (A[i] > r)
            r = A[i];
        if (A[i] < l)
            l = A[i];
        S[i] = S[i - 1] + A[i];
    }

    while (r - l >= 1e-6) {
        m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }

    printf("%d\n", (int)(r * 1000));

    return 0;
}
