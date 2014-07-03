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
#define M 40
#define N 210005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL unsigned long long
#define MOD 10000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((double)(a)*(a))
#define Key_value ch[ch[root][1]][0]
#define test puts("OK");
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
char str[10005];
int main()
{
    int cas=0;
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='-') break;
        int ans=0;
        int left=0,right=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='{') left++;
            else
            {
                if(!left) {ans++;left++;}
                else left--;
            }
        }
        if(left) ans+=left/2;
        printf("%d. %d\n",++cas,ans);
    }
    return 0;
}


