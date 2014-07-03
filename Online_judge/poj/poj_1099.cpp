#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1005;
int n  , a[N][N];
char str[N][N];
int main () {
    int  cas = 0;
    // freopen ("input.txt" , "r" , stdin);
    while (scanf ("%d" , &n) != EOF && n) {
        if (cas) {
            puts ("");
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                scanf ("%d" , &a[i][j]);
            }
        }
        memset (str , ' ' , sizeof(str));
        for (int i = 0 ; i < n ; i ++) {
            int x = i * 4 , y = 2;
            for (int j = 0 ; j < n ; j ++ , y += 4) {
                str[x][y] = 'O';
                if (a[i][j] == 1) {
                    str[x][y - 1] = str[x][y + 1] = '-';
                    str[x][y - 2] = str[x][y + 2] = 'H';
                }
                else if (a[i][j] == -1) {
                    str[x - 1][y] = str[x + 1][y] = '|';
                    str[x - 2][y] = str[x + 2][y] = 'H'; 
                }
                else {
                    if (str[x][y - 2] == 'H') {
                        str[x][y + 1] = '-';
                        str[x][y + 2] = 'H';
                    }
                    else {
                        str[x][y - 1] = '-';
                        str[x][y - 2] = 'H';
                    }
                    if (x == 0 || str[x - 2][y] == 'H') {
                        str[x + 1][y] = '|';
                        str[x + 2][y] = 'H';
                    }
                    else {
                        str[x - 1][y] = '|';
                        str[x - 2][y] = 'H';
                    }
                }
            }
        }
        printf ("Case %d:\n\n" , ++cas);
        int r = n * 4 - 3 , c = n * 4 + 1;
        for (int i = 0 ; i < c + 2 ; i ++)
            putchar ('*');puts ("");
        for (int i = 0 ; i < r ; i ++) {
            str[i][c] = '\0';
            putchar ('*');
            printf ("%s" , str[i]);
            putchar ('*');puts ("");
        }
        for (int i = 0 ; i < c + 2 ; i ++)
            putchar ('*');puts ("");
        
    } 
    return 0;
}