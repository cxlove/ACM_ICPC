#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef  long long LL;          
const int N = 105;
int a[4][2];
int main () {
    for (int i = 0 ; i < 4 ; i ++)
        cin >> a[i][0] >> a[i][1];
    int A = 0 , B = 0;
    for (int i = 0 ; i < 2 ; i ++) {
        int a1 = a[i][0] , b1 = a[i ^ 1][1];
        int win = 0;
        for (int j =  0 ; j < 2 ; j ++) {
            int a2 = a[j + 2][0] , b2 = a[(j ^ 1) + 2][1];
            if (b1 > a2 && a1 > b2) {
                win ++;
            }
            else if (b1 < a2 && a1 < b2) {
                if (i == 0) A = 1;
                else B = 1;
            }
        }
        if (win == 2) {
            puts ("Team 1");
            return 0;
        }
    }
    if (A && B) {
        puts ("Team 2");
        return 0;
    }
    puts ("Draw");
    return 0;
}