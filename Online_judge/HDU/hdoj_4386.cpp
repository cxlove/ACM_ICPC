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
double l[4];
double slove()
{
    if(l[0]+l[1]+l[2]<=l[3]) return -1;
    double s=(l[0]+l[1]+l[2]+l[3])/2;
    return sqrt((s-l[0])*(s-l[1])*(s-l[2])*(s-l[3]));
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<4;i++) scanf("%lf",&l[i]);
        sort(l,l+4);
        double area=slove();
        printf("Case %d: ",++cas);
        if(area<0) printf("-1\n");
        else printf("%.6f\n",area);
    }
    return 0;
}



