#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef  long long LL;          
const int N = 15;
int main () {
    string s;
    cin >> s;
    int a = 0 , b = 0 , c = 0;
    for (int i = 0 ; i < s.size() ; i ++) {
        if (isdigit (s[i])) a = 1;
        else if (s[i] >= 'a' && s[i] <= 'z') b = 1;
        else if (s[i] >= 'A' && s[i] <= 'Z') c = 1;
    }
    if (a && b && c && s.size() >= 5) {
        cout << "Correct" << endl;
    }
    else cout << "Too weak" << endl;
    return 0;
}