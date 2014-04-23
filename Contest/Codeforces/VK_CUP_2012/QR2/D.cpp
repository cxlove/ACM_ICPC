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
#include<bitset>
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
char str[2005];
int l[2005],r[2005];
int main(){
    while(cin>>str){
        int L=strlen(str);
        mem(l,0);mem(r,0);
        for(int i=0;i<L;i++){
            for(int j=i,k=i;j>=0&&k<L&&str[j]==str[k];j--,k++)
                l[j]++,r[k]++;
            for(int j=i,k=i+1;j>=0&&k<L&&str[j]==str[k];j--,k++)
                l[j]++,r[k]++;
        }
        for(int i=1;i<L;i++)
            r[i]+=r[i-1];
        LL ans=0;
        for(int i=1;i<L;i++)
            ans+=(LL)r[i-1]*l[i];
        printf("%I64d\n",ans);
    }
    return 0;
}
