#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a,b,s[1000]={0},m;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>m;
            s[i+1]=s[i]+m;
        }
        cin>>a>>b;
        cout<<s[b]-s[a]<<endl;
    }
    return 0;
}