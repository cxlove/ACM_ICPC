#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = (1 << 16) + 1;
LL GCD , LCM;
int flag[N] , prime[N] , cnt = 0;
vector <pair<LL , int> > v;
void init () {
    for (int i = 2 ; i < N ; i ++) {
        if (flag[i]) continue;
        prime[cnt ++] = i;
        for (int j = 2 ; j * i < N ; j ++)
            flag[i * j] = 1;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d" , &t);
    init ();
    while (t --) {
        scanf ("%I64d %I64d" , &GCD , &LCM);
        if (LCM % GCD) {
            puts ("0");
            continue;
        }
        v.clear();
        LCM = LCM / GCD;
        for (int i = 0 ; i < cnt && (LL)prime[i] * prime[i] <= LCM ; i ++) {
            if (LCM % prime[i] == 0) {
                int cnt = 0;
                while (LCM % prime[i] == 0) {
                    cnt ++;
                    LCM /= prime[i];
                }
                v.push_back (make_pair (prime[i] , cnt));
            }
        }
        if (LCM > 1) v.push_back (make_pair (LCM , 1));
        LL ans = 1LL;
        for (int i = 0 ; i < v.size() ; i ++) {
            ans = ans * (6LL * v[i].second);
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}