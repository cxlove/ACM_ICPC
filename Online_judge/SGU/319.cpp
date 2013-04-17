#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N=60005;
struct Frames{
    int x1,y1,x2,y2;
    Frames(){}
    Frames(int _x1,int _y1,int _x2,int _y2){
        x1=_x1,y1=_y1,x2=_x2,y2=_y2;
    }
}frames[N];
struct Scanning_line{
    int y,x1,x2,id;
    Scanning_line(){}
    Scanning_line(int _y,int _x1,int _x2,int _i){
        y=_y,x1=_x1,x2=_x2,id=_i;
    }
    bool operator<(const Scanning_line s)const{
        return y<s.y;
    }
}line[N<<1];
struct Segment_tree{
    int left,right;
    int cover;
}L[N<<3];
int n,w,h,x[N<<1],tot=0;
vector<int>edge[N];
int pre[N];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].cover=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void push_down(int step){
    if(L[step].cover!=-1){
        L[lson].cover=L[rson].cover=L[step].cover;
        L[step].cover=-1;
    }
}
int query(int step,int l,int r){
    if(L[step].cover!=-1)
        return L[step].cover;
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else return query(lson,l,m);
}
void update(int step,int l,int r,int id){
    if(L[step].left==l&&L[step].right==r){
        if(id<0){
            L[step].cover=pre[abs(id)];
        }
        else{
            L[step].cover=id;
        }
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,id);
    else if(l>m) update(rson,l,r,id);
    else{
        update(lson,l,m,id);
        update(rson,m+1,r,id);
    }
}
LL area[N];
void dfs(int u){
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        area[u]-=area[v];
        dfs(v);
    }
}
int main(){
    scanf("%d%d%d",&n,&w,&h);
    frames[0]=Frames(0,0,w,h);
    area[0]=(LL)w*h;
    for(int i=0;i<n;i++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        line[i*2]=Scanning_line(y1,x1,x2,i+1);
        line[i*2+1]=Scanning_line(y2,x1,x2,-(i+1));
        x[tot++]=x1;
        x[tot++]=x2;
        frames[i+1]=Frames(x1,y1,x2,y2);
        area[i+1]=(LL)(x2-x1)*(y2-y1);
    }
    x[tot++]=0;x[tot++]=w;
    sort(x,x+tot);
    tot=unique(x,x+tot)-x;
    bulid(1,0,tot-1);
    sort(line,line+2*n);
    for(int i=0;i<2*n;i++){
        line[i].x1=lower_bound(x,x+tot,line[i].x1)-x;
        line[i].x2=lower_bound(x,x+tot,line[i].x2)-x;
        if(line[i].id>0){
            pre[line[i].id]=query(1,line[i].x1,line[i].x2);
            edge[pre[line[i].id]].push_back(line[i].id);
        }
        update(1,line[i].x1,line[i].x2,line[i].id);
    }
    dfs(0);
    sort(area,area+n+1);
    for(int i=0;i<=n;i++)
        printf("%lld%c",area[i],i==n?'\n':' ');
    return 0;
}
