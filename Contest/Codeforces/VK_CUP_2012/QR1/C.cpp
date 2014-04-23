#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 200005;
const int inf = N * 10;
int q , top = 0;
string str;
string s[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> q;
    while (q --) {
        cin >> str;
        if (str == "pwd") {
            cout << "/";
            for (int i = 0 ; i < top ; i ++)
                cout << s[i] << "/";
            cout << endl;
        }
        else {
            cin >> str;
            if (str[0] == '/') {
                top = 0;
                str = str.substr (1 , str.size() - 1);
            }
            string t = "";
            str = str + "/";
            // cout << str << endl;
            for (int i = 0 ; i < str.size() ; i ++) {
                if (str[i] == '/') {
                     if (t == "..") top = max (top - 1 , 0);
                    else s[top ++] = t;
                    t = "";
                }
                else t = t + str[i];
            }
        }
    }
    return 0;
}