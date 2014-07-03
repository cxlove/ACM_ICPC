#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
const int N = 2000005;
struct Node {
    int data;
    Node *pre , *next;
}r[N];
int q , a[N] , s[N] , m[N] , idx; 
Node *newnode () {
    Node *t = &r[idx ++];
    t -> data = -1;
    t -> pre = NULL;
    t -> next = NULL;
    return t;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("ouput.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &q) != EOF) {
        idx = 0;
        int pos = 0 , tot = 0;
        Node *now = newnode();
        m[0] = -1000000009;
        s[0] = 0;
        while (q --) {
            char str[5];
            scanf ("%s" , str);
            if (str[0] == 'I') {
                int k ;
                scanf ("%d" , &k);
                Node *t = newnode();
                t -> data = k;
                t -> next = now -> next;
                if (now -> next) now -> next -> pre = t;
                now -> next = t;
                t -> pre = now;
                pos ++;
                tot ++;
                s[pos] = s[pos - 1] + k;
                m[pos] = max (m[pos - 1] , s[pos]);
                now = now -> next;
            }
            else if (str[0] == 'L') {
                if (pos) {
                    pos --;
                    now = now -> pre;
                }
            }
            else if (str[0] == 'R') {
                if (pos != tot) {
                    pos ++;
                    now = now -> next;
                    s[pos] = s[pos - 1] + now -> data;
                    m[pos] = max (m[pos - 1] , s[pos]);
                }
            }
            else if (str[0] == 'D') {
                if (now -> pre == NULL) continue;
                pos --;
                tot --;
                now = now -> pre;
                now -> next = now -> next -> next;
                if (now -> next != NULL) now -> next -> pre = now;
            }
            else {
                int k ;
                scanf ("%d" , &k);
                printf ("%d\n" , m[min(pos , k)]);
            }
        }
    }
    return 0;
}        