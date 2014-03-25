#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int N = 10000005;
int main () {
#ifndef ONLINE_JUDGE 
    // freopen ("input.txt" , "r" , stdin);
#endif
    int n;
    while (scanf ("%d" , &n) != EOF) {
        string pre;cin >> pre;
        int found = 0;
        for (int i = 1 ; i <=n ; i ++) {
            string now;cin >> now;
            if (now == pre && found == 0) {
                cout << i << endl;
                found = 1;
            }
        }
        if (!found) cout << "Try Again" << endl;
    }
 
    return 0;
}