#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 105;
const int M = 210;
const int MOD = 1000000007;

struct Trie
{
    int status;
    Trie * next[2],*fail;
    inline void init(){
        status = 0;
        next[0] = next[1] = fail = NULL;
    }
}*q[M],node[M],*root;

int dp[N][N][M][4],n,m,tot;
char s[N],p[N];

void init(){
    tot = 0;
    node[tot].init();
    root = &node[tot ++];
}

void insert(char *s,int which){
    for(int i = 0;s[i];i ++)
        if(s[i] == 'D') s[i] = '0';
        else s[i] = '1';
    Trie *cur = root;
    for(int i = 0;s[i];i ++){
        int id = s[i] - '0';
        if(cur -> next[id] == NULL){
            node[tot].init();
            cur -> next[id] = &node[tot ++];
        }
        cur = cur -> next[id];
    }
    cur -> status |= 1 << which;
}

void build(){
    int head,tail;
    head = tail = 0;
    root -> fail = NULL;
    q[0] = root;
    while(head <= tail){
        Trie * cur = q[head ++];
        for(int i = 0;i < 2;i ++){
            if(cur -> next[i]){
                if(cur == root) cur -> next[i] -> fail = root;
                else{
                    Trie *p = cur -> fail;
                    while(p){
                        if(p -> next[i]){
                            cur -> next[i] -> fail = p -> next[i];
                            break;
                        }
                        p = p -> fail;
                    }
                    if(p == NULL) cur -> next[i] -> fail = root;
                    cur -> next[i] -> status |= cur -> next[i] -> fail -> status;
                }
                q[++ tail] = cur -> next[i];
            }
            else cur -> next[i] = (cur == root) ? root  : cur -> fail -> next[i];
        }
    }
}

inline void update(int &a,int b){
    a += b;
    if(a >= MOD) a -= MOD;
}

int main(){
    // freopen("input.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    while(cas --){
        scanf("%d%d",&n,&m);
        swap(n,m);
        scanf("%s%s",s,p);
        init();
        insert(s,0);
        insert(p,1);
        build();
        for(int i =0;i <= n;i ++)
            for(int j = 0;j <= m;j ++)
                for(int pos = 0;pos < tot;pos ++)
                    for(int s = 0;s < 4;s ++)
                        dp[i][j][pos][s] = 0;
        dp[0][0][0][0] = 1;
        for(int i = 0;i <= n;i ++)
            for(int j = 0;j <= m;j ++){
                for(int pos = 0;pos < tot;pos ++){
                    for(int status = 0;status < 4;status ++){
                        for(int k = 0;k < 2;k ++){
                            int id = node[pos].next[k] - node;
                            int s = status | node[id].status;
                            if(k == 0) update(dp[i + 1][j][id][s],dp[i][j][pos][status]);
                            else update(dp[i][j + 1][id][s],dp[i][j][pos][status]);
                        }
                    }
                }
            }
        int ans = 0;
        for(int i = 0;i < tot;i ++)
            update(ans,dp[n][m][i][3]);
        printf("%d\n",ans);
    }
    return 0;
}