#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <queue>
#define error {puts("-1");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 100005;
int n , x , y , own_hp , mas_hp;
int att[N];
priority_queue <int> que;
int main () {  
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d %d %d %d" , &n , &x , &y , &own_hp , &mas_hp) != EOF) {
        while (!que.empty ()) que.pop();
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &att[i]);
        int t , ans = 0 , hp = mas_hp;
        for (t = 1 ; t <= n ; t ++) {
            mas_hp -= x;
            ans = max (ans , hp - mas_hp);
            if (mas_hp <= 0) break;
            own_hp -= att[t];
            que.push (max (att[t] , y));
            while (own_hp <= 0 && !que.empty ()) {
                own_hp += que.top();
                que.pop();
                mas_hp += x;
            }
            if (own_hp <= 0) t = n;
        }
        if (t <= n) printf ("Win\n%d\n" , t);
        else printf ("Lose\n%d\n" , ans);
    }
    return 0;
}