#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 505;
int doctor , start , arrive[N] , release[N] , id[N];
priority_queue <int , vector <int> , greater <int> > que;
vector <pair <int , int> > people[N];
bool cmp (int i , int j) {
    if (release[i] != release[j]) return release[i] < release[j];
    return i < j;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int cas = 0;
    while (scanf ("%d %d" , &doctor , &start) != EOF) {
        if (!doctor && !start) break;
        while (!que.empty ()) {
            que.pop ();
        }
        for (int i = 0 ; i < doctor ; i ++)
            que.push (start);
        int patient = 0;
        while (scanf ("%d" , &arrive[patient]) != EOF && arrive[patient] != -1) {
            release[patient] = arrive[patient];
            int p , c;
            while (scanf ("%d %d" , &p , &c) != EOF) {
                if (!p && !c) break;
                people[patient].push_back (make_pair (p , c));
            }
            reverse (people[patient].begin () , people[patient].end ());
            patient ++;
        }
        while (true) {
            int t = que.top ();
            que.pop ();
            int ok = 0;
            int before = -1 , idx;
            int after = 1 << 30 , tot;
            for (int i = 0 ; i < patient ; i ++) {
                if (people[i].size() == 0) continue;
                ok = 1;
                int can = max (release[i] , arrive[i]);
                if (can <= t) {
                    if (people[i].back().first > before) {
                        before = people[i].back().first;
                        idx = i;
                    }
                    else if (people[i].back().first == before && arrive[i] < arrive[idx]) {
                        before = people[i].back().first;
                        idx = i;
                    }
                }
                else {
                    if (can < after) {
                        after = can;
                        tot = i;
                    }
                    else if (can == after && people[i].back().first > people[tot].back().first) {
                        after = can;
                        tot = i;
                    }
                    else if (can == after && people[i].back().first == people[tot].back().first && arrive[i] < arrive[tot]) {
                        after = can;
                        tot = i;
                    }
                }
            }
            if (!ok) break;
            if (before != -1) {
                que.push (t + people[idx].back().second);
                release[idx] = t + people[idx].back().second;
                people[idx].pop_back ();
            }
            else {
                que.push (after + people[tot].back().second);
                release[tot] = after + people[tot].back().second;
                people[tot].pop_back ();
            }
        }
        for (int i = 0 ; i < patient ; i ++) {
            id[i] = i;
        }
        sort (id , id + patient , cmp);
        printf ("Case %d:\n" , ++ cas);
        for (int i = 0 ; i < patient ; i ++) {
            printf ("Patient %d released at clock = %d\n" , arrive[id[i]] , release[id[i]]);
        }
    }
    return 0;
}