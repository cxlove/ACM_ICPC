
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define N 1000000000
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define eps 1e-7
#define pb(a) push_back(a)
#define ub(v,a) upper_bound(v.begin(),v.end(),a)
using namespace std;
set<int>s;
int n,m,k,x,y;
LL Pow(LL a,LL b){
    LL ret=1;
    a=a%MOD;
    while(b){
        if(b&1)
            ret=((LL)ret*a)%MOD;
        a=((LL)a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        s.clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            x++;y++;
            if(x>(n+1)/2)  x=n+1-x;
            if(y>(n+1)/2)  y=n+1-y;
            if(x>y)   swap(x,y);
            int hash=x*10000+y;
            s.insert(hash);
        }
        printf("%I64d\n",Pow(k,(LL)((n+1)/2)*((n+3)/2)/2-s.size()));
    }
    return 0;
}

