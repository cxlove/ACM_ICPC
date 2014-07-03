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
#define inf 1600005  
#define M 40  
#define N 210001
#define maxn 2000005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
#define vi vector<int> 
using namespace std;  
struct SAM{
    SAM *pre,*son[26];
    int len,ml;
}*root,*tail,que[N],*b[N];
int tot;
char str[N/2];
void add(int c,int l){
    SAM *np=&que[tot++],*p=tail;
    np->len=l;tail=np;
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else{
        SAM *q=p->son[c];
        if(p->len+1==q->len) np->pre=q;
        else{
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
}
bool vis[N];
void Update(SAM *p){
    if(p==NULL||vis[p-que]) return;
    p->ml=p->len;
    vis[p-que]=true;
    Update(p->pre);
}
int main(){
    //freopen("input.txt","r",stdin);
    int t,cas=0,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,str);
        tot=0;mem(vis,false);
        root=tail=&que[tot++];
        for(int i=0;str[i];i++) 
            add(str[i]-'a',i+1);
        for(int i=0;i<tot;i++) if(que[i].pre) que[i].ml=que[i].pre->len;
        while(n--){
            scanf("%s",str);
            SAM *p=root;
            int len=0;
            for(int i=0;str[i];i++){
                int c=str[i]-'a';
                if(p->son[c]!=NULL) len++,p=p->son[c],Update(p->pre);
                else{
                    while(p&&p->son[c]==NULL) p=p->pre;
                    if(p==NULL) len=0,p=root;
                    else len=p->len+1,p=p->son[c],Update(p->pre);
                }
                p->ml=Max(len,p->ml);
            }
        }
        LL ans=0;
        for(int i=0;i<tot;i++){
           // printf("%d %d\n",que[i].len,que[i].ml);
            ans+=que[i].len-que[i].ml;
        }
        printf("Case %d: %I64d\n",++cas,ans);
        for(int i=0;i<tot;i++){
            que[i].ml=0;
            que[i].pre=NULL;
            mem(que[i].son,NULL);
        }
    }
    return 0;
}