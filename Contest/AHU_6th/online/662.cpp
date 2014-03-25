#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
struct Matrix {
    int m[3][3];
    void init () {
        memset (m , 0 , sizeof (m));
    }
}A , B;
Matrix mut (Matrix a , Matrix b) {
    Matrix c;
    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++) {
            c.m[i][j] = 0;
            for (int k = 0 ; k < 3 ; k ++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}
Matrix powmod (Matrix a , long long b) {
    Matrix c;
    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++)
            c.m[i][j] = i == j;
    }
    while (b) {
        if (b & 1) c = mut (c , a);
        a = mut (a , a);
        b >>= 1;
    }
    return c;
}
int main () {
    int t;
    std::cin >> t;
    while (t --) {
        int x , y , a , b;
        long long m;
        std::cin >> x >> y >> a >> b >> m;
        if (m == 0) {
            std::cout << 0 << std::endl;
        }
        else {
            A.init ();B.init ();
            A.m[0][0] = b;A.m[0][1] = 1;
            A.m[1][0] = a;A.m[1][2] = 1;
            A.m[2][2] = 1;
            B.m[0][0] = y;B.m[0][1] = x;
            Matrix C = mut (B , powmod (A , m));
            std::cout << C.m[0][2] << std::endl;
        }
    }
    return 0;
}