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
#define inf 1<<30
#define M 2005
#define N 100005
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct HashBlock
{
    int size,col;
    map<int,int>m;
}a[400];
int n,q,c[N];
int len,cnt;
void Init()
{
    len=(int)sqrt(n+1e-8);
    cnt=(n-1)/len+1;
    for(int i=0;i<cnt;i++)
    {
        a[i].size=min(n,(i+1)*len)-i*len;
        a[i].col=-1;
        a[i].m.clear();
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        a[i/len].m[c[i]]++;
    }
}
void Push_Down(int step)
{
    if(a[step].col!=-1)
    {
        a[step].m.clear();
        for(int i=step*len;i<min((step+1)*len,n);i++)
        {
            c[i]=a[step].col;
            a[step].m[c[i]]++;
        }
        a[step].col=-1;
    }
}
void Update(int l,int r,int col)
{
    int la=l/len,ra=r/len;
    for(int i=la+1;i<ra;i++) a[i].col=col;
    if(la!=ra)
    {
        Push_Down(la);Push_Down(ra);
        for(int i=l;i<len*(1+la);i++)
        {
            a[la].m[c[i]]--;a[la].m[col]++;c[i]=col;
        }
        for(int i=ra*len;i<=r;i++)
        {
            a[ra].m[c[i]]--;a[ra].m[col]++;c[i]=col;
        }
    }
    else
    {
        Push_Down(la);
        for(int i=l;i<=r;i++)
        {
            a[la].m[c[i]]--;a[la].m[col]++;c[i]=col;
        }
    }
}
int Query(int l,int r,int col)
{
    int la=l/len,ra=r/len,ans=0;
    for(int i=la+1;i<ra;i++)
    {
        if(a[i].col==col) ans+=a[i].size;
        else if(a[i].col==-1&&a[i].m.find(col)!=a[i].m.end()) ans+=a[i].m[col];
    }
    if(la!=ra)
    {
        Push_Down(la);Push_Down(ra);
        for(int i=l;i<len*(la+1);i++)
        {
            ans+=c[i]==col;
        }
        for(int i=ra*len;i<=r;i++)
        {
            ans+=c[i]==col;
        }
    }
    else
    {
        Push_Down(la);
        for(int i=l;i<=r;i++) ans+=c[i]==col;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        Init();
        while(q--)
        {
            int k,l,r,c;
            scanf("%d%d%d%d",&k,&l,&r,&c);
            if(k==1) Update(l,r,c);
            else printf("%d\n",Query(l,r,c));
        }
    }
    return 0;
}

