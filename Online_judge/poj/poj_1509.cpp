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
#define N 200015
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL unsigned long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((double)(a)*(a))
#define Key_value ch[ch[root][1]][0]
#define test puts("OK");
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct SAM
{
    SAM *pre,*son[26];
    int len,idx;
}*root,*tail,que[N];
char str[N/2];
int tot=0;
void add(int c,int l)
{
    SAM *p=tail,*np=&que[tot++];
    np->len=l;np->idx=l;
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else
    {
        SAM *q=p->son[c];
        if(p->len+1==q->len) np->pre=q;
        else
        {
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->idx=q->len;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
    tail=np;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        tot=0;
        root=tail=&que[tot++];
        for(int i=0;str[i];i++) add(str[i]-'a',i+1);
        for(int i=0,l=strlen(str);str[i];i++) add(str[i]-'a',l+i+1);
        for(int i=0;str[i];i++)
        {
            for(int j=0;j<26;j++)
            {
                if(root->son[j]){root=root->son[j];break;}
            }
        }
        printf("%d\n",root->idx-strlen(str)+1);
        for(int i=0;i<tot;i++) que[i].pre=NULL,mem(que[i].son,NULL);
    }
    return 0;
}
