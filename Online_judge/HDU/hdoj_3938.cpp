#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<stack>
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 10005
#define maxn 2000005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 777777777
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
struct Node{
    int u,v,val;
    bool operator<(const Node n) const{
        return val<n.val;
    }
}e[N*5];
struct Que{
    int id,val;
    bool operator<(const Que q)const{
        return val<q.val;
    }
}q[N];
int pre[N],cnt[N];
int n,m,Q;
int ans[N];
int find(int x){
    return pre[x]=pre[x]==x?x:find(pre[x]);
}
int main(){
    while(scanf("%d%d%d",&n,&m,&Q)!=EOF){
        for(int i=1;i<=n;i++) pre[i]=i,cnt[i]=1;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&e[i].v,&e[i].u,&e[i].val);
        }
        sort(e,e+m);
        for(int i=0;i<Q;i++){
            scanf("%d",&q[i].val);
            q[i].id=i;
        }
        sort(q,q+Q);
        int ret=0,idx=0;
        for(int i=0;i<Q;i++){
            while(idx<m&&e[idx].val<=q[i].val){
                int u=e[idx].u,v=e[idx].v;
                int ra=find(u),rb=find(v);
                if(ra!=rb){
                    ret+=cnt[ra]*cnt[rb];
                    cnt[ra]+=cnt[rb];
                    pre[rb]=ra;
                }
                idx++;
            }
            ans[q[i].id]=ret;
        }
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}