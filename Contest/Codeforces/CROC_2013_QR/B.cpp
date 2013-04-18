#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
using namespace std;
char str[100005];
void solve(string s){
    s+=' ';
    string a="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ') a+=s[i];
        else{
            if(a!="") cout<<"<"<<a<<">"<<endl;
            a="";
        }
    }
}
int main(){
    gets(str);
    string s="";
    int t=0;
    for(int i=0;str[i];i++){
        if(str[i]=='"'){
            if(t==0){
                solve(s);
                t=1;
                s="";
            }
            else{
                cout<<"<"<<s<<">"<<endl;
                s="";
                t=0;
            }
        }
        else{
            s+=str[i];
        }
    }
    solve(s);
    return 0;
}