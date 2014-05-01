#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <map>
#include <cmath>
using namespace std;
const int N = 100005;
const long long inf = (long long)2e18;
bool is (int n) {
    for (int i = 2 ; i * i <= n ; i ++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void gao () {
    for (int i = 8001 ; ; i ++) {
        if (is (i) && is (i + 2)) {
            cout << i << endl;
            break;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    // gao ();
    srand (time (0));
    int a , b;
    while (cin >> a >> b) {
        if (!a && !b) break;
        cout << 1;
        for (int i = 2 ; i < a ; i ++) {
            cout << rand () % 10;
        }
        cout << 1 << endl;
    }
    return 0;
}