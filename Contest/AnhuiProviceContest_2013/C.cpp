#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#define Hash1 (LL)11111
#define Hash2 (LL)13337
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
#define eps 1e-8
#define ft first
#define sd second
#define LL long long
#define Test puts("END")
#define pi acos(-1.0)
#define clr(a,b) memset(a,b,sizeof(a));
#define zero(x) (((x)>0?(x):-(x))<eps)
#pragma comment(linker, "/STACK:32000000")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 120000;
const int M = 1000;

int n;
pair<int,int> arr[N];

int main()
{
    // freopen("input.txt","r",stdin);
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i ++)
            scanf("%d%d",&arr[i].ft,&arr[i].sd);
        sort(arr,arr + n);
        double ans = 0;
        double cur = 0;
        for(int i = 0;i < n;i ++){
            ans += max(0.0,cur - arr[i].ft);
            cur += max(0.0,arr[i].ft - cur);
            cur += arr[i].sd;
            ans += arr[i].sd;
        }
        printf("%.4f\n",ans / n);
    }
    return 0;
}