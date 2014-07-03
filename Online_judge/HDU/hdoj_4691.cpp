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
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MAGIC 11117
#define eps 1e-8
#define LL long long
#define Test puts("END")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 200100;
const int M = 2000100;

char s[N],p[N];
int wa[N],wb[N],wv[N],wc[N],rank[N],height[N],sa[N];

void calheight(char *r,int *sa,int n)
{
    int i,j,k = 0;
    for(i = 1;i <= n;i ++) rank[sa[i]] = i;
    for(i = 0;i < n;height[rank[i ++ ]] = k)
        for(k ? k -- : 0,j = sa[rank[i] - 1];r[i + k] == r[j + k];k ++);
    return ;
}

int cmp(int *r,int a,int b,int l){
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(char *r,int *sa,int n,int m){
    int i,j,p,*x = wa,*y = wb,*t;
    for(i = 0;i < m;i ++) wc[i] = 0;
    for(i = 0;i < n;i ++) wc[x[i] = r[i]] ++;
    for(i = 1;i < m;i ++) wc[i] += wc[i - 1];
    for(i = n - 1;i >= 0;i --) sa[-- wc[x[i]]] = i;
    for(j = 1,p = 1;p < n;j *= 2,m = p){
        for(p = 0,i = n - j;i < n;i ++) y[p ++] = i;
        for(i = 0;i < n;i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0;i < n;i ++) wv[i] = x[y[i]];
        for(i = 0;i < m;i ++) wc[i] = 0;
        for(i = 0;i < n;i ++) wc[wv[i]] ++;
        for(i = 1;i < m;i ++) wc[i] += wc[i - 1];
        for(i = n - 1;i >= 0;i --) sa[-- wc[wv[i]]] = y[i];
        for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1;i < n;i ++)
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p ++;
    }
    return ;
}

int dp[N][18],n,num,l[N],r[N],len[N],LOG[N];

void rmq(){
    int i,j;
    for(i=1;i<=n;i++)
        dp[i][0]=height[i];
    for(j=1;(1<<j)<=n;j++)
        for(i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int query(int s,int v){
    s = rank[s] , v = rank[v];
    if(s == v) return int(1e9);
    if(s > v) swap(s,v);
    s ++;
    // printf("s:%d  v:%d  %d,%d\n",s,v,rank[s],rank[v]);
    int k = LOG[v - s + 1];
    return min(dp[s][k],dp[v - (1 << k) + 1][k]);
}

int cal(int x){
    if(x == 0) return 1;
    int ret = 0;
    while(x) x /= 10,ret ++;
    return ret;
}

int main(){
    // freopen("input.txt","r",stdin);
    LOG[1] = 0;
    for(int i = 2;i < N;i ++) LOG[i] = LOG[i >> 1] + 1;
    while(scanf("%s",s) != EOF){
        scanf("%d",&num);
        LL ans1 = 0 ,ans2 = 0;
        n = strlen(s);
        da(s,sa,n + 1,128);
        calheight(s,sa,n);
        // for(int i = 1;i <= n;i ++)
            // printf("i:%d  s:%s   height:%d\n",i,s + sa[i],height[i]);
        rmq();
        for(int i = 0;i < num;i ++){
            scanf("%d%d",&l[i],&r[i]);
            ans1 += r[i] - l[i] + 1;
            len[i] = r[i] - l[i];
            if(i){
                int ret = query(l[i],l[i - 1]);
                int lcp = min(ret,min(len[i],len[i - 1]));
                // printf("i:%d ret:%d  lcp:%d\n",i,ret,lcp);
                ans2 += (len[i] - lcp) + 2 + cal(lcp);
            }
            else ans2 += 3 + (r[i] - l[i]);
        }
        printf("%I64d %I64d\n",ans1,ans2);
    }
    return 0;
}
