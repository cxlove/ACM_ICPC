#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
const int N = 10000005;
char s[N] , e[N] , a[5][5];
int x[26] , y[26];
void out (int one , int two) {
    // cout << one << " " << two << endl;  
    if (x[one] == x[two]) {
        int x1 = x[one];
        int y1 = (y[one] + 1) % 5 , y2 = (y[two] + 1) % 5;
        printf ("%c%c" , a[x1][y1] , a[x1][y2]);
        return ;
    }
    if (y[one] == y[two]) {
        int x1 = (x[one] + 1) % 5 , x2 = (x[two] + 1) % 5;
        int y1 = y[one];
        printf ("%c%c" , a[x1][y1] , a[x2][y1]);
        return ;
    }
    int x1 = x[one] , y1 = y[two];
    int x2 = x[two] , y2 = y[one];
    printf ("%c%c" , a[x1][y1] , a[x2][y2]);
}
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);getchar ();
    while (t --) {
        memset (x , -1 , sizeof (x));
        gets (s);gets (e);
        for (int i = 0 ; s[i] ; i ++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
        }
        for (int i = 0 ; e[i] ; i ++) {
            if (e[i] >= 'a' && e[i] <= 'z')
                e[i] = e[i] - 'a' + 'A';
        }
        int ls = strlen (s) , le = 0;
        int r = 0 , c = 0;
        for (int i = 0 ; i < ls ; i ++) {
            if (isalpha (s[i])) {
                if (x[s[i] - 'A'] != -1) continue;
                a[r][c] = s[i];
                x[s[i] - 'A'] = r;y[s[i] - 'A'] = c;
                c ++;
                if (c == 5) r ++ , c = 0;
            }
        }
        for (int i = 0 ; i < 26 ; i ++) {
            if (x[i] == -1 && (i + 'A') != 'J') {
                a[r][c] = 'A' + i;
                x[i] = r;y[i] = c;
                c ++;
                if (c == 5) r ++ , c = 0;
            }
        }
        for (int i = 0 ; e[i] ; i ++) {
            if (isalpha(e[i])) {
                if (e[i] == 'J') e[i] = 'I';
                e[le ++] = e[i];
            }
        }
        e[le] = '\0';
        int add = 0;
        printf ("Case %d: " , ++ cas);
        for (int i = 0 ; i < le ; i ++) {
            if (i + 1 == le || e[i] == e[i + 1]) {
                int now = e[i] - 'A';
                while (add == now || add == 9) add = (add + 1) % 26;
                out (now , add);
                add = (add + 1) % 26;
            }
            else {
                out (e[i] - 'A' , e[i + 1] - 'A');
                i ++;
            }
        }
        puts ("");
    }
    return 0;
}