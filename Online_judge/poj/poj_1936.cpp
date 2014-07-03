#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
string s,t;
bool check(){
    int i=0,j=0;
    for(;i<s.size()&&j<t.size();){
        if(s[i]==t[j]) i++,j++;
        else j++;
    }
    return i==s.size();
}
int main(){
    while(cin>>s>>t)
        puts(check()?"Yes":"No");
    return 0;
}