#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2000005;
int n;
string s,t;
int main(){
    cin>>n>>s>>t;
    int all=0,one=0,two=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'&&t[i]=='1') all++;
        else if(s[i]=='1') one++;
        else if(t[i]=='1') two++;
    }
    one+=(all+1)/2;
    two+=all/2;
    //cout<<one<<" "<<two<<endl;
    if(min(one,two)>=n||one==two||two-one==1) cout<<"Draw"<<endl;
    else if(one>two) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}