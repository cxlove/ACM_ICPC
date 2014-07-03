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
#define N 500001
#define maxn 300005  
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
using namespace std;  
struct Node{
    int x,y,id;
    bool operator<(const Node n)const{
        return x<n.x;
    }
}p[N],q[N];
int n,m;
int l[N+5],r[N+5];
int ans[N];
void Update(int *s,int x,int val){
    for(int i=x;i<=N;i+=lowbit(i))
        s[i]+=val;
}
int sum(int *s,int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&q[i].x,&q[i].y);
            q[i].id=i;
        }
        sort(p,p+n);
        sort(q,q+m);
        mem(l,0);mem(r,0);
        for(int i=0;i<n;i++)
            Update(r,p[i].y+1,1);
        int st=0,ed;
        for(int i=0;i<m;i++){
            for(ed=st;ed<n;ed++)
                if(p[ed].x>q[i].x)
                    break;
            for(int j=st;j<ed;j++){
                Update(l,p[j].y+1,1);
                Update(r,p[j].y+1,-1);
            }
            int a=sum(r,N)-sum(r,q[i].y+1)+sum(l,q[i].y+1);
            int b=sum(l,N)-sum(l,q[i].y+1)+sum(r,q[i].y+1);
            ans[q[i].id]=abs(a-b);
            st=ed;
        }
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
        if(t) puts("");
    } 
    return 0;
}