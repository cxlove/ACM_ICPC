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
#define N 405
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct Node
{
    int a,b;
    Node(){}
    Node(int _a,int _b):a(_a),b(_b){}
};
bool cmp1(Node n1,Node n2){return n1.a<n2.a;}
bool cmp2(Node n1,Node n2){return n1.a>n2.a;}
vector<Node>l,r;
int n,m;
int dpl[1005]={0},dpr[1005]={0};
void Init()
{
    for(int i=1;i<=n;i++) dpl[i]=dpr[i]=inf;
    dpl[0]=dpr[n+1]=0;
    sort(l.begin(),l.end(),cmp1);
    sort(r.begin(),r.end(),cmp2);
    for(int i=0;i<l.size();i++)
    {
        for(int j=l[i].a;j>=l[i].b;j--)
        {
            dpl[j]=min(dpl[j],dpl[j-l[i].b]+1);
        }
    }
    for(int i=0;i<r.size();i++)
    {
        for(int j=r[i].a;j<=n-r[i].b+1;j++)
        {
            dpr[j]=min(dpr[j],dpr[j+r[i].b]+1);
        }
    }
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        l.clear();r.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int k,a,b;
            scanf("%d%d%d",&k,&a,&b);
            if(k==1) l.pb(Node(a,b));
            else r.pb(Node(a,b));
        }
        Init();
        int a1=0,a2=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n+1;j++)
            {
                if(dpl[i]==inf||dpr[j]==inf) continue;
                if(i+n+1-j>a1){a1=i+n+1-j;a2=dpl[i]+dpr[j];}
                else if(i+n+1-j==a1&&dpl[i]+dpr[j]<a2){a1=i+n+1-j;a2=dpl[i]+dpr[j];}
            }
        }
        printf("Case %d: %d %d\n",++cas,a1,a2);
    }
    return 0;
}
