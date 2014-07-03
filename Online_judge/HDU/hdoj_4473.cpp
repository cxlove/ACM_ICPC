#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 100000005
#define M 200005
#define N 125
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 12345
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
LL n;
int fuck1(LL n)
{
    int m=pow(n,0.5);
    if((LL)(m*m)>n) m--;
    if((LL)(1+m)*(m+1)<=n) m++;
    return m;
}
int fuck2(LL n)
{
    int m=pow(n,1.0/3);
    if((LL)(eps+m*m*m)>n) m--;
    if((LL)(m+1)*(1+m)*(m+1)<=n) m++;
    return m;
}
int main()
{
    int cas=0;
    while(cin>>n)
    {
        int m=fuck2(n);
        LL ans=m;
      //  cout<<m<<endl;
        for(int i=1;i<=m;i++)
        {
            int k=fuck1(n/i);
            ans+=(n/i/i-i+k-i)*3;
        //    cout<<n/i<<" "<<k<<endl;
            for(int j=i+1;j<=k;j++) ans+=6*(n/i/j-j);
        }
        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }
    return 0;

}


