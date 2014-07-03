
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
#define M 600005
#define N 10005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Trie
{
    Trie *next[26];
    Trie *fail;
    int isword,kind;
};
Trie *que[M],s[M];
int dp[55][N],idx;
int n,m,h[105];
char str[105][105];
string path[55][N];
Trie *NewNode()
{
    Trie *tmp=&s[idx];
    mem(tmp->next,NULL);
    tmp->isword=0;
    tmp->fail=NULL;
    tmp->kind=idx++;
    return tmp;
}
void Insert(Trie *root,char *s,int len,int k)
{
    Trie *p=root;
    for(int i=0; i<len; i++)
    {
        if(p->next[s[i]-'a']==NULL) p->next[s[i]-'a']=NewNode();
        p=p->next[s[i]-'a'];
    }
    p->isword=h[k];
}
void Bulid_fail(Trie *root)
{
    int head=0,tail=0;
    que[tail++]=root;
    root->fail=NULL;
    while(head<tail)
    {
        Trie *tmp=que[head++];
        for(int i=0; i<26; i++)
        {
            if(tmp->next[i])
            {
                if(tmp==root) tmp->next[i]->fail=root;
                else
                {
                    Trie *p=tmp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i])
                        {
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) tmp->next[i]->fail=root;
                }
                if(tmp->next[i]->fail->isword) tmp->next[i]->isword+=tmp->next[i]->fail->isword;
                que[tail++]=tmp->next[i];
            }
            else if(tmp==root) tmp->next[i]=root;
            else tmp->next[i]=tmp->fail->next[i];
        }
    }
}
void slove()
{
    int ans=0;
    mem(dp,-1);
    dp[0][0]=0;
    for(int i=0;i<=n;i++) for(int j=0;j<idx;j++) path[i][j].clear();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<idx;j++)
        {
            if(dp[i][j]==-1) continue;
            for(int k=0;k<26;k++)
            {
                int cur=s[j].next[k]->kind;
                if(dp[i][j]+s[cur].isword>dp[i+1][cur])
                {
                    dp[i+1][cur]=dp[i][j]+s[cur].isword;
                    path[i+1][cur]=path[i][j]+(char)(k+'a');
                }
                else if(dp[i][j]+s[cur].isword==dp[i+1][cur]&&path[i][j]+(char)(k+'a')<path[i+1][cur])
                {
                    path[i+1][cur]=path[i][j]+(char)(k+'a');
                }
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<idx;j++) ans=max(ans,dp[i][j]);
    if(ans==0) {puts("");return;}
    string str=" ";
    for(int i=1;i<=n;i++) for(int j=0;j<idx;j++) if(dp[i][j]==ans&&(str==" "||(path[i][j].size()<str.size()||(path[i][j].size()==str.size()&&path[i][j]<str)))) str=path[i][j];
    cout<<str<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        idx=0;
        Trie *root=NewNode();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
            scanf("%s",str[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&h[i]);
            Insert(root,str[i],strlen(str[i]),i);
        }
        Bulid_fail(root);
        slove();
    }
    return 0;
}







