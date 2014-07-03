#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<20
#define N 100005
#define pi acos(-1.0)
#define pb(a) push_back(a)
#define lson step<<1
#define  MAXN 1005
#define rson step<<1|1
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;
int b[1005],a[1000];
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF&&n+k)
        if(k>=n)  printf("1\n");
        else
        {
            int kk=0;
            for(int i=1; i<=k; i++)
            {
                int qd=n-n%k+i;
                if(qd>n) qd-=k;
                for(int j=qd; j>=1; j-=k){
                    a[kk+1]=0;
                    b[++kk]=j;
                }
            }
            LL ans=1;
            for(int i=1;i<=n;i++){
                if(a[i]) continue;
                int cnt=1,t=i;
                while(b[t]!=i){
                    cnt++;
                    t=b[t];
                    a[t]=1;
                }
                ans=lcm(ans,cnt);
            }
            printf("%I64d\n",ans);
        }
    return 0;
}