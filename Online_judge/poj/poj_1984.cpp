#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40005;
int way[4][2]={0,1,0,-1,1,0,-1,0};
struct Query{
    int u,v,idx,id;
    void input(int k){
        id=k;
        scanf("%d%d%d",&u,&v,&idx);
    }
    bool operator<(const Query q)const{
        return idx<q.idx;
    }
}q[N];
struct Edge{
    int u,v,w,dir;
    void input(){
        char str[5];
        scanf("%d%d%d%s",&u,&v,&w,str);
        if(str[0]=='E') dir=0;
        else if(str[0]=='W') dir=1;
        else if(str[0]=='S') dir=2;
        else dir=3;
    }
}e[N];
int n,m,k,ans[N],pre[N],x[N],y[N];
int find(int r){
    if(pre[r]!=r){
        int f=pre[r];
        pre[r]=find(pre[r]);
        x[r]+=x[f];
        y[r]+=y[f];
    }
    return pre[r];
}
void update(int u,int v,int xx,int yy){
   // if(u>v) swap(u,v),xx=-xx,yy=-yy;
    int ra=find(u),rb=find(v);
    if(ra!=rb){
        pre[ra]=rb;
        x[ra]=xx+x[v]-x[u];
        y[ra]=yy+y[v]-y[u];
    }
}
int query(int u,int v){
    int ra=find(u),rb=find(v);
    if(ra!=rb) return -1;
    return abs(x[u]-x[v])+abs(y[u]-y[v]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        pre[i]=i,x[i]=0,y[i]=0;
    for(int i=1;i<=m;i++)
        e[i].input();
    scanf("%d",&k);
    for(int i=0;i<k;i++)
        q[i].input(i);
    sort(q,q+k);
    for(int i=0,j=0;i<k;i++){
        while(j<q[i].idx){
            j++;
            update(e[j].u,e[j].v,way[e[j].dir][0]*e[j].w,way[e[j].dir][1]*e[j].w);
        }
        ans[q[i].id]=query(q[i].u,q[i].v);
    }
    for(int i=0;i<k;i++)
        printf("%d\n",ans[i]);
    /*for(int i=1;i<=7;i++){
        find(i);
        cout<<x[i]<<" "<<y[i]<<endl;
    }
    */
    return 0;
}