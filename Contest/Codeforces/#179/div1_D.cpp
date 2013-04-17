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
LL f[2005][2005],g[2005][2005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        LL sum=0;
        for(int j=2;j<=m;j++){
            f[i][j]=(f[i][j]+g[i-1][j]+1)%MOD;
            sum=(sum+f[i][j])%MOD;
            g[i][j]=(g[i][j]+g[i][j-1]+sum)%MOD;
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            ans=(ans+((LL)f[i][j]*(m-j+1)%MOD)*(g[n-i][j]-f[n-i][j]+1)%MOD)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
