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
const int N = 100000;
int n , a , b , c[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    string s , e;
    cin >> s >> e;
    sort (e.rbegin () , e.rend ());
    for (int i = 0 , j = 0 ; i < s.size() && j < e.size() ; i ++) {
    	if (e[j] > s[i]) {
    		s[i] = e[j];
    		j ++;
    	}
    }
    cout << s << endl;
    return 0;
}