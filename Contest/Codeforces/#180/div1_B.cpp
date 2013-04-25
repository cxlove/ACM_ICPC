#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
    for(int i=0;i<t.size();i++)#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#define pb(a) push_back(a)
#define LL long long
#define test puts("OK");
using namespace std;
struct Node{
    int val,cnt;
    Node(){}
    Node(int v,int c):val(v),cnt(c){}
    bool operator<(const Node n)const{
        return val>n.val;
    }
};
vector<Node>v; 
map<int,int>s;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s[t]++;
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        s[t]--;
    }
    for(map<int,int>::iterator it=s.begin();it!=s.end();it++){
        if(it->second)
            v.pb(Node(it->first,it->second));
    }
    sort(v.begin(),v.end());
    int c=0;
    bool flag=false;
    for(int i=0;i<v.size()&&!flag;i++){
        if(v[i].cnt>0){
            if(v[i].cnt>c) flag=true;
            else c-=v[i].cnt;
        }
        else c+=-v[i].cnt;
    }
    puts(flag?"YES":"NO");
    return 0;
}

        c2+=t[i]-'0';
    if(c1&1) c1++;
    if(c1<c2) puts("NO");
    else puts("YES");
    return 0;
}