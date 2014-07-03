#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#include<map>
long long Left,Right,x,y,ans,ret,t;
using namespace std;
int main(){
    cin>>t;
    while(t--){
        cin>>Left>>Right;
        if(Right<=5){
            cout<<0<<endl;
            continue;
        }
        if(Left<=5) Left=6;
        if(!(Left&1))
             ans=(Right-Left)/2+1;
        else
             ans=(Right-Left+1)/2;
        x=(long long)sqrt(Left),y=(long long)sqrt(Right);
        if(x*x<Left)
            x++;
        if(x>y){
            cout<<ans<<endl;
            continue;
        }
        if(!(x&1))
             ret=(y-x)/2+1;
        else
             ret=(y-x+1)/2;
        cout<<ans-ret+(y-x+1-ret)<<endl;
    }
    return 0;
}
