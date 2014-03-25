#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int w , h , x , y;
    while (cin >> w >> h >> x >> y) {
        cout << min (min (x , y) , min (w - x , h - y)) << endl;
    }
    return 0;
}