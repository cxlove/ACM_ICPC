#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1005];
int main () {
    int t;
    scanf ("%d" ,  &t);
    while (t --) {
        scanf ("%s" , str);
        int maohao = -1 , url = 0;
        for (int i = 0 ; str[i] ; i ++)
            if (str[i] == ':') {
                maohao = i;
                if ((str[i + 1] == '\\' || str[i + 1] == '/') && (str[i + 2] == '\\' || str[i + 2] == '/'))
                    url = 1;
            }
        if (maohao == -1) {
            puts ("It's a path in Unix-like systems!");
            for (int i = 0 ; str[i] ; i ++)
                if (str[i] == '\\')
                    str[i] = '/';
        }
        else if (url) {
            puts ("It's a URL!");
            for (int i = 0 ; str[i] ; i ++)
                if (str[i] == '\\')
                    str[i] = '/';
        }
        else {
            puts ("It's a path in Windows system!");
            for (int i = 0 ; str[i] ; i ++)
                if (str[i] == '/')
                    str[i] = '\\';
        }
        puts (str);
    }
    return 0;
}        