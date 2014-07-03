#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a , b)
#define lowbit(x) (x & (-x))
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 110005;
char str[N] , s[N];
int n , p[N] , c[N] , next[N];
char word[N];
bool cmp (int i , int j) {
    if (str[i] == str[j]) return i < j;
    return str[i] < str[j];
}
void get_next (char *s , int l) {
    next[0] = -1;
    int i = 0 , j = -1;
    while (i < l) {
        if (j == -1 || s[i] == s[j]) {
            i ++; j ++;
            next[i] = j;
        }
        else j = next[j];
    }
}
bool kmp (char *s , int ls , char *p , int lp) {
    int i = 0 , j = 0;
    while (i < ls && j < lp) {
        if (i == -1 || s[i] == p[j]) {
            i ++; j ++;
            if (i == ls) return true;
        }
        else i = next[i];
    }
    return false;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%s" , str) != EOF) {
        int l = strlen(str) - 1;
        for (int i = 0 ; i <= l ; i ++)
            p[i] = i;
        sort (p , p + l + 1 , cmp);
        for (int i = 0 ; i <= l ; i ++)
            c[p[i]] = i;
        for (int i = 0 , j = 0 ; i < l ; i ++) {
            s[l - 1 - i] = str[j];
            j = c[j];
        }
        s[l] = '\0';
        // puts(s);
        scanf ("%d" , &n);
        while (n --) {
            scanf ("%s" , word);
            get_next (word , strlen(word));
            puts (kmp(word , strlen(word) , s , l) ? "YES" : "NO");
        }
    }
    return 0;
}