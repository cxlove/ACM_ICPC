#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int N = 4005;
const int inf = N * 10;
int n , d;
string a[N] , b[N];
int t[N];
set <pair <string , string> > s;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> d;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i] >> b[i] >> t[i];
    }

    
    for (int i = 0 ; i < n ; i ++) {
        for (int j = i + 1 ; j < n ; j ++) {
            if (abs (t[j] - t[i]) <= d && t[j] != t[i]) {
                if (a[i] == b[j] && b[i] == a[j]) {
                    string A = a[i] , B = a[j];
                    if (A > B) swap (A , B);
                    s.insert (make_pair (A , B));
                }
            }
        }
    }
    cout << s.size() << endl;
    for (set <pair <string , string> > :: iterator it = s.begin () ; it != s.end () ; it ++) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}