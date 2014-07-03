#include<iostream>
#include<cstdio>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
#define lson step<<1
#define rson step<<1|1
#define LL long long 
using namespace std;
bool flag[105];
int n,m;
int main(){
    int t;
    cin>>t;
    while(t--){
        mem(flag,false);
        int mx=0;
        cin>>n;
        int ans=n;
        for(int i=0;i<n;i++){
            cin>>m;
            if(!flag[m]) flag[m]=true,ans+=5;
            mx=max(m,mx);
        }
        ans+=mx*10;
        cout<<ans<<endl;
    }
}