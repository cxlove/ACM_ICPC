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
#include<stack>
#define inf 1<<30
#define M 1000005
#define N 50005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1,l,m
#define rson step<<1|1,m+1,r
#define MOD 1073741824
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
using namespace std;
int a[80005],n;
stack<int>s;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        while(!s.empty()) s.pop();
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            if(s.empty()||a[i]<a[s.top()])
                s.push(i);
            else
            {
                while(1)
                {
                    if(s.empty()||a[i]<a[s.top()])
                    {
                        s.push(i);
                        break;
                    }
                    ans+=(i-s.top())-1;
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            ans+=(n-s.top())-1;
            s.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}


