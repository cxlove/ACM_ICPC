#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define HASH 1000000007LL
using namespace std;
const int N = 200105;
typedef long long LL;
typedef pair<LL , int> pli;
char s[N] , str[N];
int p[N];
set <pli> myset;
LL hash[N] , fac[N];
int Manacher (char *s , int n) {  
    p[0] = p[1] = 1;  
    int mx = 1 , id = 1 , ans = 1;  
    for (int i = 2 ; i < n ; i ++) {  
        if (mx > i) p[i] = min (p[2 * id - i] , mx - i);  
        else p[i] = 1;  
        for( ; s[i - p[i]] == s[i + p[i]] ; p[i] ++);  
        if(i + p[i] > mx){  
            mx = i + p[i];  
            id = i;  
        }  
        ans = max (ans , p[i]);  
    }  
} 
LL get_hash (int l , int r) {
    return hash[r] - hash[l - 1] * fac[r - l + 1];
}    
int main(){ 
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    fac[0] = 1;
    for (int i = 1 ; i < N ; i ++)
        fac[i] = fac[i - 1] * HASH;
    scanf ("%d" , &t);
    while (t --) {
        myset.clear ();
        scanf ("%s" , s);
        int l = strlen (s);
        str[0] = '@';
        for (int i = 0 ; i < l ; i ++) {
            str[2 * i + 1] = '#';
            str[2 * i + 2] = s[i];
        }
        str[2 * l + 1] = '#';
        str[2 * l + 2] = '\0';
        // puts (str);
        Manacher (str , 2 * l + 2);
        // for (int i = 2 ; i < 2 * l + 2 ; i ++)
        //     cout << i << " " << p[i] << endl;
        hash[0] = 0;
        for (int i = 1 ; i <= l ; i ++) {
            hash[i] = hash[i - 1] * HASH + s[i - 1];
        }
        for (int i = 2 ; i < 2 * l + 2 ; i ++) {
            if (i & 1) {
                int l = p[i] - 1; l /= 2;
                int pos = i / 2 - l + 1;
                while (l > 0) {
                    LL tmp = get_hash (pos , pos + l * 2 - 1);
                    pli gao = make_pair (tmp , 2 * l);
                    if (myset.find (gao) != myset.end ()) break;
                    myset.insert (gao);
                    pos ++; l --;
                }
            }
            else {
                int l = p[i] - 1; l = (l + 1) / 2;
                int pos = i / 2 - l + 1;
                while (l > 0) {
                    LL tmp = get_hash (pos , pos + l * 2 - 2);
                    pli gao = make_pair (tmp , 2 * l - 1);
                    if (myset.find (gao) != myset.end ()) break;
                    myset.insert (gao);
                    pos ++; l --;
                }
            }
        }
        printf ("Case #%d: %d\n" , ++cas , myset.size());
    } 
    return 0;  
}  