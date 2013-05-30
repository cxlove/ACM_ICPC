#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define LL long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
vector<pair<LL,int> >fac;
int ans=0;
LL p[1005][1005];
void dfs(int idx,LL x,LL y,LL z){
    if(idx==fac.size()){
        LL t=x+y+z;
        if(t&1) return ;
        t/=2;
        LL a=t-x,b=t-y,c=t-z;
        if(a>0&&b>0&&c>0) ans++;
        return ;
    }
    //cout<<idx<<endl;
    int t=fac[idx].second;
    for(int i=0;i<=t;i++){
        for(int j=0;j+i<=t;j++){
            int k=t-i-j;
            dfs(idx+1,x*p[idx][i],y*p[idx][j],z*p[idx][k]);
        }
    }
}
int main(){
    LL n;
    scanf("%I64d",&n);
    //n=3*(a+b)*(b+c)*(a+c)
    if(n%3){
        printf("0\n");
        return 0;
    }
    n/=3;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0) n/=i,cnt++;
            fac.pb(mp(i,cnt));
        }
    }
    if(n>1) fac.pb(mp(n,1));
    for(int i=0;i<fac.size();i++){
        p[i][0]=1;
        for(int j=1;j<=fac[i].second;j++)
            p[i][j]=p[i][j-1]*fac[i].first;
    }
    dfs(0,1LL,1LL,1LL);
    printf("%d\n",ans);
    return 0;
}