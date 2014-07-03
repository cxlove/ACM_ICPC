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
#define N 3005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n;
double p,q;
int main()
{
    int cas=0;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        double p1=log(p),p2=log(1-p);
        double c=0,ans=0;
        double s1=(n+1)*p1,s2=(n+1)*p2;
        for(int i=0;i<=n;i++)
        {
            ans+=(exp(c+s1)+exp(c+s2))*(n-i);
            c+=log(n+i+1)-log(i+1);
            s1+=p2;
            s2+=p1;
        }
        printf("Case %d: %.6f\n",++cas,ans);
    }
    return 0;
}

