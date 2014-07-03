#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007LL;
struct Matrix {
    LL m[5][5];
    Matrix operator * (Matrix &a) const {
        Matrix ans ;
        for (int i = 0 ; i < 5 ; i ++) {
            for (int j = 0 ; j < 5 ; j ++) {
                ans.m[i][j] = 0LL;
                for (int k = 0 ; k < 5 ; k ++) {
                    ans.m[i][j] = (ans.m[i][j] + (LL)m[i][k] * a.m[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
}init;
void debug (Matrix a) {
    for (int i = 0 ; i < 5 ; i ++) {
        for (int j = 0 ; j < 5 ; j ++)
            cout << a.m[i][j] << " ";
        cout << endl;
    }
}
Matrix PowMod (Matrix a , LL b) {
    Matrix ans;
    for (int i = 0 ; i < 5 ; i ++)
        for (int j = 0 ; j < 5 ; j ++)
            ans.m[i][j] = (i == j ? 1LL : 0LL);
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    LL n , a0 , ax , ay;
    LL b0 , bx , by;
    while (scanf ("%I64d" , &n) != EOF) {
        scanf ("%I64d %I64d %I64d" , &a0 , &ax , &ay);
        scanf ("%I64d %I64d %I64d" , &b0 , &bx , &by);
        memset (init.m , 0 , sizeof(init.m));
        init.m[0][0] = 1LL;
        init.m[0][1] = ay;init.m[1][1] = ax % MOD;
        init.m[0][2] = by;init.m[2][2] = bx % MOD;
        init.m[0][3] = ay * by % MOD;init.m[1][3] = ax * by % MOD;
        init.m[2][3] = bx * ay % MOD;init.m[3][3] = ax * bx % MOD;
        init.m[3][4] = 1LL;
        init.m[4][4] = 1LL;
        // debug (init);
        init = PowMod (init , n);
        // debug (init);
        printf ("%I64d\n" , (init.m[0][4] + init.m[1][4] * a0 % MOD + init.m[2][4] * b0 % MOD + (a0 * b0 % MOD) * init.m[3][4] % MOD) % MOD);
    }
    return 0;
}        

