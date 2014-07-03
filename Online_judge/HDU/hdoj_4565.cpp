#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 50005;
LL a , b , n , MOD;
struct Matrix {
    LL m[2][2];
    Matrix operator * (const Matrix &a) const {
        Matrix ans;
        for (int i = 0 ; i < 2 ; i ++)
            for (int j = 0 ; j < 2 ; j ++) {
                ans.m[i][j] = 0;
                for (int k = 0 ; k < 2 ; k ++)
                    ans.m[i][j] = (ans.m[i][j] + 1LL * m[i][k] * a.m[k][j]) % MOD;
            }
        return ans;
    }
}init , unit;
Matrix powmod (Matrix a , int b) {
    Matrix ans;
    for (int i = 0 ; i < 2 ; i ++)
        for (int j = 0 ; j < 2 ; j ++)
            ans.m[i][j] = i == j;
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
    while (cin >> a >> b >> n >> MOD) {
        init.m[0][0] = 2 * a % MOD;init.m[1][0] = ((b - a * a) % MOD + MOD) % MOD; 
        init.m[0][1] = 1LL;init.m[1][1] = 0LL;
        if (n == 1) {
            cout << 2 * a % MOD << endl;
        }
        else if (n == 2) {
            cout << (2LL * a * a + 2LL * b) % MOD << endl;
        }
        else {
            unit = powmod (init , n - 2);
            cout << (unit.m[1][0] * 2LL * a + unit.m[0][0] * (2LL * a * a + 2LL * b)) % MOD << endl;
        }
    }
    return 0;
}