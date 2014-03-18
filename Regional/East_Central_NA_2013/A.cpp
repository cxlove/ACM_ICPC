#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long LL;
const int N = 12;
int row[N] , col[N];
int must[N][N][7] , maybe[N][N][7][N][N][7];
int place[N][N] , ans , most[N][5][4][3][2];
inline void init () {
    
    for (int i = 1 ; i <= 10 ; i ++) {
        for (int one = 4 ; one >= 0 ; one --) {
            for (int two = 3 ; two >= 0 ; two --) {
                for (int three = 2 ; three >= 0 ; three --) {
                    for (int four = 1 ; four >= 0 ; four --) {
                        if (i == 1) {
                            if (one || two || three || four) most[i][one][two][three][four] = 1;
                        }
                        if (i == 2 && two) most[i][one][two][three][four] = 2;
                        if (i == 3 && three) most[i][one][two][three][four] = 3;
                        if (i == 4 && four) most[i][one][two][three][four] = 4;
                         
                        if (one || two || three || four) {
                            if (one) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 2][one - 1][two][three][four] + 1);
                            if (two) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 2][one][two - 1][three][four] + 1);
                            if (three) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 2][one][two][three - 1][four] + 1);
                            if (four) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 2][one][two][three][four - 1] + 1);            
                        }
                        if (one) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 2][one - 1][two][three][four] + 1);
                        if (two && i >= 3) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 3][one][two - 1][three][four] + 2);
                        if (three && i >= 4) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 4][one][two][three - 1][four] + 3);
                        if (four && i >= 5) most[i][one][two][three][four] = max (most[i][one][two][three][four] , most[i - 5][one][two][three][four - 1] + 4);                      
                    }
                }
            }
        }
    }
}
inline bool check (int x1 , int y1 , int x2 , int y2) {
    for (int i = x1 - 1 ; i <= x2 + 1 ; i ++) {
        for (int j = y1 - 1 ; j <= y2 + 1 ; j ++) {
            if (place[i][j]) return false;
        }
    }
    for (int i = x1 ; i <= x2 ; i ++) {
        if (row[i] < y2 - y1 + 1) return false;
    }
    for (int i = y1 ; i <= y2 ; i ++) {
        if (col[i] < x2 - x1 + 1) return false;
    }
    return true;
}
inline void hor (int x , int y , int l) {
    for (int i = y ; i < y + l ; i ++) {
        place[x][i] = (i == y ? 2 : (i == y + l - 1 ? 4 : 1));
        row[x] --;col[i] --;
    }
}
inline void ver (int x , int y , int l) {
    for (int i = x ; i < x + l ; i ++) {
        place[i][y] = (i == x ? 3 : (i == x + l - 1 ? 5 : 1));
        row[i] --;col[y] --;
    }
}
inline void del (int x1 , int y1 , int x2 , int y2) {
    for (int i = x1 ; i <= x2 ; i ++) {
        for (int j = y1 ; j <= y2 ; j ++) {
            place[i][j] = 0;
            row[i] ++;col[j] ++;
        }
    }
}
inline void out () {
    for (int i = 1 ; i <= 10 ; i ++) {
        for (int j = 1 ; j <= 10 ; j ++) {
            cout << place[i][j];
        }
        cout << endl;
    }
    puts ("##############");
}
void dfs (int n , int m , int one , int two , int three , int four) {
    if (n == 11 || one + two + three + four == 0) {
        if (one + two + three + four) return ;
        for (int i = 1 ; i <= 10 ; i ++)  if (col[i]) return ; 
        ans ++;
        for (int i = 1 ; i <= 10 ; i ++) {
            for (int j = 1 ; j <= 10 ; j ++) {
                must[i][j][place[i][j]] ++;
            }
        }
        for (int i = 1 ; i <= 10 ; i ++) {
            for (int j = 1 ; j <= 10 ; j ++) {
                for (int x = 1 ; x <= 10 ; x ++) {
                    for (int y = 1 ; y <= 10 ; y ++) {
                        if (x != i || y != j) {
                            maybe[i][j][place[i][j]][x][y][place[x][y]] ++;
                        }
                    }
                }
            }
        }
        // out ();
        return ;
    }
    if (m >= 11) {
        if (row[n]) return ;
        dfs (n + 1 , 1 , one , two , three , four);
        return ;
    }
    if (row[n] == 0) {
        dfs (n + 1 , 1 , one , two , three , four);
        return ;
    }
    // if (row[n] > 11 - m) return ;
    if (row[n] > most[11 - m][one][two][three][four]) {
        return ;
    }
    // if (col[m] > 11 - n) return ;
    if (col[m] > most[11 - n][one][two][three][four]) {
        return ;
    }
    dfs (n , m + 1 , one , two , three , four);
    if (one) {
        if (check (n , m , n , m)) {
            place[n][m] = 6;row[n] --;col[m] --;
            dfs (n , m + 2 , one - 1 , two , three , four);
            place[n][m] = 0;row[n] ++;col[m] ++;
        }
    }
    if (two) {
        if (m < 10 && check (n , m , n , m + 1)) {
            hor (n , m , 2);
            dfs (n , m + 3 , one , two - 1 , three , four);
            del (n , m , n , m + 1);
        }
        if (n < 10 && check (n , m , n + 1 , m)) {
            ver (n , m , 2);
            dfs (n , m + 2 , one , two - 1 , three , four);
            del (n , m , n + 1 , m);
        }
    }
    if (three) {
        if (m < 9 && check (n , m , n , m + 2)) {
            hor (n , m , 3);
            dfs (n , m + 4 , one , two , three - 1 , four);
            del (n , m , n , m + 2);
        }
        if (n < 9 && check (n , m , n + 2 , m)) {
            ver (n , m , 3);
            dfs (n , m + 2 , one , two , three - 1 , four);
            del (n , m , n + 2 , m);
        }
    }
    if (four) {
        if (m < 8 && check (n , m , n , m + 3)) {
            hor (n , m , 4);
            dfs (n , m + 5 , one , two , three , four - 1);
            del (n , m , n , m + 3);
        }
        if (n < 8 && check (n , m , n + 3 , m)) {
            ver (n , m , 4);
            dfs (n , m + 2 , one , two , three , four - 1);
            del (n , m , n + 3 , m);
        }
    }
}
char s[7][5] = {"w" , "X" , "<" , "^" , ">" , "v" , "O"};
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif 
    init ();
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        ans = 0;
        memset (place , 0 , sizeof (place));
        for (int i = 1 ; i <= 10 ; i ++)
            scanf ("%d" , &row[i]);
        for (int i = 1 ; i <= 10 ; i ++)
            scanf ("%d" , &col[i]);
        memset (must , 0 , sizeof (must));
        memset (maybe , 0 , sizeof (maybe));
        dfs (1 , 1 , 4 , 3 , 2 , 1);
        printf ("Case %d: %d " , ++ cas , ans);
        if (ans == 1) {
            printf ("0\n");
        }
        else {
            int find = 0;
            for (int i = 1 ; i <= 10 && !find ; i ++) {
                for (int j = 1 ; j <= 10 && !find ; j ++) {
                    for (int k = 0 ; k < 7 && !find ; k ++) {
                        if (must[i][j][k] == 1) {
                            find = 1;
                            printf ("1 (%d,%d)=%s\n" , i , j , s[k]);
                        }
                    }
                }
            }
            if (find) continue;
            for (int i = 1 ; i <= 10 && !find ; i ++) {
                for (int j = 1 ; j <= 10 && !find ; j ++) {
                    for (int k = 0 ; k < 7 && !find ; k ++) {
                        for (int x = 1 ; x <= 10 && !find ; x ++) {
                            for (int y = 1 ; y <= 10 && !find ; y ++) {
                                for (int z = 0 ; z < 7 && !find ; z ++) {
                                    if (maybe[i][j][k][x][y][z] == 1) {
                                        find = 1;
                                        printf ("2 (%d,%d)=%s (%d,%d)=%s\n" , i , j , s[k] , x , y , s[z]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!find) {
                puts ("too ambiguous");
            }
        }
    }
    return 0;
}