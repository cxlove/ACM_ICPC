include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<ctime>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N=5005;
LL a[N],b[N],p[N];
int n,dp[N];
bool check(int i,int j){
    if(a[j]&1) return (a[i]%a[j]==0);
    if(b[i]%b[j]) return false;
    if(p[j]==p[i]+j-i||p[j]<=j-i-1) return true;
    else return false;  
}
int main(){
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
            while(b[i]%2==0) b[i]/=2,p[i]++;
        }
        int ret=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++)
                if(check(j,i))
                    dp[i]=max(dp[i],dp[j]+1);
            ret=max(ret,dp[i]);
        }
        cout<<n-ret<<endl;
    }
    return 0;
}