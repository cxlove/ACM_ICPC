#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define MOD 1000000007
#define inf 2000000000LL
#define Key_value ch[ch[root][1]][0]  
using namespace std;
int n;
LL fac[200005]={1};
char s[100005],t[100005];
int main(){
    cin>>n>>s>>t;
    for(int i=1;i<=2*n;i++)
        fac[i]=(LL)fac[i-1]*10%MOD;
    int cnt=0,tot=0,ret=1;
    for(int i=0;i<n;i++){
        cnt+=s[i]=='?',cnt+=t[i]=='?',tot+=(t[i]==s[i]&&s[i]=='?');
        if(t[i]!='?'&&s[i]!='?'&&t[i]!=s[i]) ret=0;
    }
    LL small=1,big=1;
    for(int i=0;i<n;i++){
        if(s[i]!='?'&&t[i]!='?'){
            if(s[i]>t[i]){
                small=0;
                break;
            }
        }
        else if(s[i]!='?')
            small=(LL)small*('9'-s[i]+1)%MOD;
        else if(t[i]!='?')
            small=(LL)small*(t[i]-'0'+1)%MOD;
        else
            small=(LL)small*55%MOD;
    }
    for(int i=0;i<n;i++){
        if(s[i]!='?'&&t[i]!='?'){
            if(s[i]<t[i]){
                big=0;
                break;
            }
        }
        else if(s[i]!='?')
            big=(LL)big*(s[i]-'0'+1)%MOD;
        else if(t[i]!='?')
            big=(LL)big*('9'-t[i]+1)%MOD;
        else
            big=(LL)big*55%MOD;
    }
    //cout<<fac[cnt]<<" "<<big<<" "<<small<<endl;
    cout<<((fac[cnt]-big-small+(ret?(tot==0?0:fac[tot]):0))%MOD+MOD)%MOD<<endl;
    return 0;
}
