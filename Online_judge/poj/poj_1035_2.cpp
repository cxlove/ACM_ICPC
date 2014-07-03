#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string>v;
set<string>myset;
bool check(string a,string b){
    if(a.size()>b.size()) swap(a,b);
    int i,j;
    for(i=0,j=0;i<a.size()&&j<b.size();){
        if(a[i]==b[j]){
            i++;j++;
        }
        else j++;
    }
    if(i==a.size()) return true;
    return false;
}
int main(){
    string s;
    while(cin>>s&&s[0]!='#'){
        v.push_back(s);
        myset.insert(s);
    }
    while(cin>>s&&s[0]!='#'){
        if(myset.find(s)!=myset.end())
            cout<<s<<" is correct"<<endl;
        else{
            cout<<s<<":";
            for(int i=0;i<v.size();i++){
                if(v[i].size()==s.size()){
                    int c=0;
                    for(int j=0;j<v[i].size();j++)
                        c+=(v[i][j]!=s[j]);
                    if(c==1) cout<<" "<<v[i];
                }
                else if(abs((int)v[i].size()-(int)s.size())==1&&check(v[i],s))
                    cout<<" "<<v[i];
            }
            cout<<endl;
        }
    }
    return 0;
}