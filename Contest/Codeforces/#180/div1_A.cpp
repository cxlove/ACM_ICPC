#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define LL long long
#define test puts("OK");
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int c1=0,c2=0;
    for(int i=0;i<s.size();i++)
        c1+=s[i]-'0';
    for(int i=0;i<t.size();i++)
        c2+=t[i]-'0';
    if(c1&1) c1++;
    if(c1<c2) puts("NO");
    else puts("YES");
    return 0;
}