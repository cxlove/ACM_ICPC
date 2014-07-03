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
#define Hash1 (LL)11111
#define Hash2 (LL)13337 
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define LL long long
#define Test puts("END")
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:32000000")
using namespace std;
const int MOD = 1000000007;
const int N = 1710;
const int M = 260;
const int INF = 0x11111111 ;
struct trie
{
    bool cannot;
    int must;
    int marks;
    trie *next[26],*fail;
}node[N],*q[N],*root;
char s[N];
int dp[2][N][1 << 8],n,m;
int se[2][N][1 << 8],tot;
void init();
void solve(int cas);
void build();
void insert(char *,int );
inline void update(int &a,int &b,const int c,const int d);
int main()
{
    // freopen("input.txt","r",stdin);
    int cas,a,t = 1;
    scanf("%d",&cas);
    while(cas --){
        scanf("%d",&n);
        init();
        for(int i = 0;i < n;i ++){
            scanf("%s%d",s,&a);
            insert(s,a);
            if(a == 999) m ++;
        }
        scanf("%s",s + 1);
        solve(t ++);
    }
    return 0;
}
void init()
{
    tot = m = 0;
    memset(dp,0x3f,sizeof(dp));
    root = &node[tot];
    memset(node[tot].next,NULL,sizeof(node[tot].next));
    node[tot].cannot = node[tot].marks = 0;
    node[tot ++].must = 0;
}
void insert(char *str,int num)
{
    trie *p = root;
    for(int i = 0;str[i];i ++){
        int idx = str[i] - 'a';
        if(p -> next[idx] == NULL){
            p -> next[idx] = &node[tot];
            memset(node[tot].next,NULL,sizeof(node[tot].next));
            node[tot].cannot = node[tot].marks = 0;
            node[tot ++].must = 0;
        }
        p = p -> next[idx];
    }
    if(num == -999){
        p -> cannot = true;
    }
    else if(num == 999){
        p -> must = (1 << m);
    }
    else {
        p -> marks += num;
    }
}
void build()
{
    int head,tail;
    head = tail = 0;
    q[tail] = root;
    root -> fail = NULL;
    while(head <= tail){
        trie *cur = q[head ++];
        for(int i = 0;i < 26;i ++){
            if(cur -> next[i] != NULL){
                if(cur == root)
                    cur -> next[i] -> fail = root;
                else{
                    trie *p = cur -> fail;
                    while(p != NULL){
                        if(p -> next[i]){
                            cur -> next[i] -> fail = p -> next[i];
                            break;
                        }
                        p = p -> fail;
                    }
                    if(p == NULL)
                        cur -> next[i] -> fail = root;
                    if(cur -> next[i] -> fail -> cannot)
                        cur -> next[i] -> cannot = true;
                    cur -> next[i] -> marks += cur -> next[i] -> fail -> marks;
                    cur -> next[i] -> must = (cur -> next[i] -> must | cur -> next[i] -> fail -> must);
                }
                q[++ tail] = cur -> next[i];
            }
            else{
                cur -> next[i] = (cur == root) ? root : cur -> fail -> next[i];
            }
        }
    }
}
void solve(int cas)
{
    build();
    memset(dp[0],0x11,sizeof(dp[0]));
    memset(se[0],0x8f,sizeof(se[0]));
    dp[0][0][0] = 0;
    se[0][0][0] = 0;
    int len = strlen(s + 1);
    for(int i = 0;i < len;i ++){
        memset(dp[(i + 1) & 1],0x11,sizeof(dp[(i + 1) & 1]));
        memset(se[(i + 1) & 1],0x8f,sizeof(se[(i + 1) & 1]));
        for(int j = 0;j < tot;j ++){
            for(int k = 0;k < 1 << m;k ++){
                if(dp[i & 1][j][k] >= INF) continue;
                int idx = s[i + 1] - 'a';
                update(dp[(i + 1) & 1][j][k],se[(i + 1) & 1][j][k],dp[i & 1][j][k] + 1,se[i & 1][j][k]);
                if(node[j].next[idx] -> cannot == true) continue;
                int next_j = node[j].next[idx] - node , next_k = k;
                if(node[j].next[idx] -> must != 0)
                    next_k = k | node[j].next[idx] -> must;
                update(dp[(i + 1) & 1][next_j][next_k],se[(i + 1) & 1][next_j][next_k],dp[i & 1][j][k],se[i & 1][j][k] + node[j].next[idx] -> marks);
            }
        }
    }
    int ans1 = INF,ans2 = 0x8f;
    for(int i = 0;i < tot;i ++){
        update(ans1,ans2,dp[len & 1][i][(1 << m) - 1],se[len & 1][i][(1 << m) - 1]);
    }
    if(ans1 == INF){
        printf("Case %d: Banned\n",cas);
    }
    else printf("Case %d: %d %d\n",cas,ans1,ans2);
}
inline void update(int &a,int &b,const int c,const int d)
{
    if(a > c){
        a = c;
        b = d;
    }
    else if(a == c){
        b = max(b,d);
    }
}