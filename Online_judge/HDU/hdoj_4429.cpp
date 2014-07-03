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
#define M 2005
#define N 200005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int ts,cas=0;

int n,m;
int xl,yl,xr,yr;

struct pot{
    int x,y;
    pot(){}
    pot(int _x,int _y): x(_x),y(_y){}
    void read(){scanf("%d%d",&x,&y);}
};

struct mtx{
    pot a,b;
    int l,r;
    void insert(pot _a,pot _b){a=_a,b=_b;}
    void read(){a.read(),b.read();}
    bool inner(mtx t){
        return (a.x<=t.a.x && t.b.x<=b.x && a.y<=t.a.y && t.b.y<=b.y);
    }
};

mtx val[M],c;
int cnt[M],l[M],r[M],tot;

void update(int rt){
    cnt[rt]++;
    if(l[rt]==-1){
        val[l[rt]=++tot].insert(val[rt].a,c.b);
        val[r[rt]=++tot].insert(c.a,val[rt].b);
        return;
    }
    if(val[l[rt]].inner(c)) update(l[rt]);
    else if(val[r[rt]].inner(c)) update(r[rt]);
}

int query(int rt){
    if(l[rt]==-1) return cnt[rt];
    if(val[l[rt]].inner(c)) return query(l[rt]);
    if(val[r[rt]].inner(c)) return query(r[rt]);
    return cnt[rt];
}

void run(){
    int i,j;
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    val[tot=1].insert(pot(xl,yl),pot(xr,yr));
    for(i=1;i<=n;i++){
        c.read();
        if(c.a.x>c.b.x) swap(c.a.x,c.b.x);
        if(c.a.y>c.b.y) swap(c.a.y,c.b.y);
        update(1);
    }
    while(m--){
        c.read();
        if(c.a.x>c.b.x) swap(c.a.x,c.b.x);
        if(c.a.y>c.b.y) swap(c.a.y,c.b.y);
        printf("%d\n",n-query(1)+1);
    }
}
int main(){
    while(~scanf("%d%d%d%d",&xl,&yl,&xr,&yr)) run();
    return 0;
}
