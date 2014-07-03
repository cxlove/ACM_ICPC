#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
int n,a[25];
string s;
int main(){
    int t;
    cin>>t;
    while(t--){
        s="";
        a[0]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=a[i-1]+1;j<=a[i];j++)
                s+="(";
            s+=")";
        }
        for(int i=s.size();i<2*n;i++)
            s+=")";
        for(int j=0,i=0;i<2*n;i++){
            if(s[i]==')'){
                int k,cnt,top;
                for(k=i-1,cnt=1,top=1;;k--){
                    if(s[k]=='('){
                        top--;
                        if(top==0) break;
                    }
                    else top++,cnt++;
                }
                a[++j]=cnt;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<(i==n?'\n':' ');
    }
    return 0;
}