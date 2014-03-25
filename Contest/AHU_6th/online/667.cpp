#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main () {
    string s[8];
    int ans = 0;
    for (int i = 0 ; i < 8 ; i ++) {
        cin >> s[i];
        for (int j = 0 ; j < 8 ; j ++) {
            if ((i + j) % 2 == 0 && s[i][j] == 'F')
                ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}