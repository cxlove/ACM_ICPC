#include <iostream>
#include <cstdio>
#include <algorithm>
#define lowbit(x) (x&(-x))
using namespace std;
const int N = 100005;
struct Point{
    int x,y,id;
    bool operator<(const Point p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}p[N];
struct BIT{
    int min_val,pos;
    void init(){
        min_val=(1<<30);
        pos=-1;
    }
}bit[N];
struct Edge{
    int u,v,d;
    bool operator<(const Edge e)const{
        return d<e.d;
    }
}e[N<<2];
int n,tot,pre[N];
int find(int x){
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int dist(int i,int j){
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
}
void addedge(int u,int v,int d){
    e[tot].u=u;
    e[tot].v=v;
    e[tot++].d=d;
}
void update(int x,int val,int pos){
    for(int i=x;i>=1;i-=lowbit(i))
        if(val<bit[i].min_val)
            bit[i].min_val=val,bit[i].pos=pos;
}
int ask(int x,int m){
    int min_val=(1<<30),pos=-1;
    for(int i=x;i<=m;i+=lowbit(i))
        if(bit[i].min_val<min_val)
            min_val=bit[i].min_val,pos=bit[i].pos;
    return pos;
}
int k;
int Manhattan_minimum_spanning_tree(int n,Point *p){
    int a[N],b[N];
    for(int dir=0;dir<4;dir++){
        //4种坐标变换
        if(dir==1||dir==3){
            for(int i=0;i<n;i++)
                swap(p[i].x,p[i].y);
        }
        else if(dir==2){
            for(int i=0;i<n;i++){
                p[i].x=-p[i].x;
            }
        }
        sort(p,p+n);
        for(int i=0;i<n;i++){
            a[i]=b[i]=p[i].y-p[i].x;
        }
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        for(int i=1;i<=m;i++)
            bit[i].init();
        for(int i=n-1;i>=0;i--){
            int pos=lower_bound(b,b+m,a[i])-b+1;   //BIT中从1开始
            int ans=ask(pos,m);
            if(ans!=-1)
                addedge(p[i].id,p[ans].id,dist(i,ans));
            update(pos,p[i].x+p[i].y,i);
        }
    }
    sort(e,e+tot);
    int cnt=n-k;
    for(int i=0;i<n;i++)
        pre[i]=i;
    for(int i=0;i<tot;i++){
        int u=e[i].u,v=e[i].v;
        int fa=find(u),fb=find(v);
        if(fa!=fb){
            cnt--;
            pre[fa]=fb;
            if(cnt==0)
                return e[i].d;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //int cas=0;
    while(scanf("%d%d",&n,&k)!=EOF&&n){
        tot=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        printf("%d\n",Manhattan_minimum_spanning_tree(n,p));
        //printf("Case %d: Total Weight = %d\n",++cas,Manhattan_minimum_spanning_tree(n,p));
    }
    return 0;
}