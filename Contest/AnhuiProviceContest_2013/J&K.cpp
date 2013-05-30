#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull DP(ull a, ull b, ull c) {
    if (b%a==0) return b/a;
    return DP(b%a, a, b)+b/a;
}

int main() {
    ull a, b, c;
    while (cin >> a >> b >> c) {
        if ((a|b|c) == 0) break;
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        cout << DP(a, b, c) << endl;
    }
    return 0;
}