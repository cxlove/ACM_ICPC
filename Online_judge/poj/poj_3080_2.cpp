#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Node{
    string s;
    Node(){}
    Node(string _s):s(_s){}
    bool operator<(const Node n)const{
        return s.size()!=n.s.size()?s.size()>n.s.size():s<n.s;
    }
};
string s[1000];
int n;
vector<Node>v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<s[0].size();i++){
            for(int j=i;j<s[0].size();j++){
                if(j-i+1<3) continue;
                string tmp=s[0].substr(i,j-i+1);
                bool flag=true;
                for(int k=1;k<n;k++)
                    if(s[k].find(tmp)==string::npos)
                        flag=false;
                if(flag) v.push_back(Node(tmp));
            }
        }
        sort(v.begin(),v.end());
        if(v.size()==0) puts("no significant commonalities");
        else cout<<v[0].s<<endl;
    }
    return 0;
}