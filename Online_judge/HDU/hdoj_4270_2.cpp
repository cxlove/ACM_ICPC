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
#define N 510001
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
    int len,id,suf;
    bool *del;
    void Init(){
        pre=NULL;
        id=len=suf=0;
        mem(son,NULL);
    }
}*root,*tail,que[N];
int tot,D;
char str[N/2];
int q,l;
int pos[N/2];
bool del[N/2]={false};
void add(int c,int l){
    SAM *np=&que[tot++],*p=tail;
    np->Init();
    np->del=&del[D++];
    *np->del=false;
    pos[l]=tot-1;
    np->len=np->id=l;
    while(p&&(p->son[c]==NULL||(*p->son[c]->del))) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else{
        SAM *q=p->son[c];
        if(p->len+1==q->len)np->pre=q;
        else{
            SAM *nq=&que[tot++];   
            *nq=*q;
           // nq->id=q->len;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&(p->son[c]==q)) p->son[c]=nq,p=p->pre;
        }
    }
    tail=np;
}
void Delete(int len){
    for(int i=l-len+1;i<=l;i++) *(que[pos[i]].del)=true;
    l-=len;
    tail=&que[pos[l]];
}
int cnt,len,k;
int dfs(SAM *p,int idx){
    if(idx==len)
        return p->id-idx+1;
    if(p->suf==cnt)
        return l-idx+1;
    for(int i=0;i<26;i++)
        if(p->son[i]!=NULL&&!(*p->son[i]->del))
            return dfs(p->son[i],idx+1);
    return p->len-idx+1;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s",str)!=EOF){
        tot=0;l=0;cnt=0;D=0;
        root=tail=&que[tot++];
        root->Init();
        root->del=&del[D++];*root->del=false;
        scanf("%d",&q);
        for(int i=0;str[i];i++) add(str[i]-'a',++l);
        while(q--){
            scanf("%d",&k);
            //cout<<k<<" TTTTTTTT"<<endl;
            if(k==1){
                scanf("%s",str);
                for(int i=0;str[i];i++){
                    add(str[i]-'a',++l);
                }
            }
            else{
                scanf("%d",&len);
                if(k==3) Delete(len);
                else{
                    cnt++;
                    SAM *p=tail;
                    while(p!=NULL&&p!=root) p->suf=cnt,p=p->pre;
                    root->suf=0;
                    printf("%d\n",dfs(root,0));
                }
            }
        }
    }
    return 0;
}