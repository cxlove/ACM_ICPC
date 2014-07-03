#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
struct Time {
    int h , m , s;
    int id;
    Time () {}
    Time (int _h , int _m , int _s , int i):h(_h) ,m(_m) , s(_s),id(i){}
    int operator - (const Time &t) const {
        return (h - t.h) * 3600 + (m - t.m) * 60 + (s - t.s);
    }
    bool operator < (const Time &t) const {
        if (h != t.h) return h < t.h;
        if (m != t.m) return m < t.m;
        return s < t.s;
    }
}l , r;
vector <Time> v;
int n , cnt[10];
void gao (int h , int m , int s , int i) {
    for (int j = 0 ; j < 60 ; j ++) {
        int hh = (h + j + 60) % 60;
        int mm = (m + j + 60) % 60;
        int ss = (s + j + 60) % 60;
        if (hh % 5 == mm / 12) v.push_back(Time (hh / 5 , mm , ss , i));
    }
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        v.clear ();memset (cnt , 0 , sizeof(cnt));
        for (int i = 0 ; i < n ; i ++) {
            int h , m , s;
            scanf ("%d %d %d" , &h , &m , &s);
            gao (h , m , s , i);gao (h , s , m , i);
            gao (m , h , s , i);gao (m , s , h , i);
            gao (s , m , h , i);gao (s , h , m , i);
        }
        sort (v.begin () , v.end());
        int tot = 0 , ans = 3600 * 3600;
        for (int i = 0 , j = 0 ; i < v.size() ; i ++) {
            while (j < v.size() && tot < n) {
                if (cnt[v[j].id] == 0) tot ++;
                cnt[v[j ++].id] ++;
            }
            if (tot == n) {
                if (v[j - 1] - v[i] < ans) 
                    l = v[i] , r = v[j - 1] , ans = v[j - 1] - v[i];
            }
            cnt[v[i].id] --;
            if (cnt[v[i].id] == 0) tot --;
        }
        printf("%02d:%02d:%02d %02d:%02d:%02d\n" , l.h , l.m , l.s , r.h , r.m , r.s);
    }
    return 0;
}       

