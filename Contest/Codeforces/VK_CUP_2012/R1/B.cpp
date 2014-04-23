#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 100005;
const int inf = 2000000007;
vector <pair <int , int> > tool , pencil;
vector <int> ans[N];
int n , k;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    long long sum = 0;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        int u , v;
        cin >> u >> v;u *= 2;
        sum += u;
        if (v == 1) tool.push_back (make_pair (u , i + 1));
        else pencil.push_back (make_pair (u , i + 1));
    }
    sort (tool.begin () , tool.end ());
    sort (pencil.begin () , pencil.end ());
    for (int i = 0 ; i < k ; i ++) {
        if (i < k - 1) {
            int ok = 0 , mn;
            if (tool.size()) ok = 1 , mn = tool.back().first , ans[i].push_back (tool.back().second) , tool.pop_back ();
            if (ok) {
                sum -= mn / 2;
            }
            else {
                while (pencil.size()) {
                    ans[i].push_back (pencil.back ().second);
                    pencil.pop_back ();
                    break;
                }
            }
        }
        else {
            int mn = inf , ok = 0;
            while (tool.size()) {
                ok = 1;
                ans[i].push_back (tool.back ().second);
                mn = min (mn , tool.back ().first);
                tool.pop_back ();
            }
            while (pencil.size()) {
                ans[i].push_back (pencil.back ().second);
                mn = min (mn , pencil.back ().first);
                pencil.pop_back ();
            }
            if (ok) sum -= mn / 2;
        }
    }
    if (sum & 1) cout << sum / 2 << ".5" << endl;
    else cout << sum / 2 << ".0" << endl;
    for (int i = 0 ; i < k ; i ++) {
        cout << ans[i].size() << " ";
        for (int j = 0 ; j < ans[i].size() ; j ++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}