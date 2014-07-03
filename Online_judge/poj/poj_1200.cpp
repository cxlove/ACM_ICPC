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
#define N 16000006
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
#define MOD 1599997
#define sqr(a) ((a)*(a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n,m;
char str[N];
LL hash[N],fac[N]={1},val[N]={0};
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%s",str);int l=strlen(str);
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*73471;
        for(int i=1;i<=l;i++) val[i]=val[i-1]*73471+str[i-1]-'a';
        int cnt=0;
        for(int i=n;i<=l;i++) hash[cnt++]=val[i]-val[i-n]*fac[n];
        sort(hash,hash+cnt);
        int ans=1;
        for(int i=1;i<cnt;i++) if(hash[i]!=hash[i-1]) ans++;
        printf("%d\n",n>l?0:ans);
    }
    return 0;
}






