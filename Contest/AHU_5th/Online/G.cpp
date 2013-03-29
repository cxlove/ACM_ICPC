#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;
string s;
int t;
int main(){
    cin>>t;
    while(t--){
        cin>>s;
        string ans="";
        int pos=s.find(".");
        if(pos==string::npos) ans=s;
        else{
            if(s[pos-1]!='9'&&s[pos+1]>='5')
                s[pos-1]++;
            ans=s.substr(0,pos);
        }
        bool flag=false;
        for(int i=0;i<ans.size();i++)
            if(ans[i]!='0'){
                ans=ans.substr(i,ans.size()-i);
                flag=true;
                break;
            }
        if(!flag) cout<<"0"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}