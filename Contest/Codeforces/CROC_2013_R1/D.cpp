#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N = 505;
const int M = 10005;
int n,m;
struct dsu{
    int pre[N];
    void Init(){
        for(int i=1;i<=n;i++)
            pre[i]=i;
    }
    int Find(int x){
        return pre[x]=(pre[x]==x?x:Find(pre[x]));
    }
    void Union(int a,int b){
        int fa=Find(a),fb=Find(b);
        if(fa!=fb) pre[fa]=fb;
    }
}s[M],e[M];
int u[M],v[M];
int solve(dsu l,dsu r){
    for(int i=1;i<=n;i++)
        l.Union(i,r.Find(i));
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=i==l.Find(i);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    s[0].Init();
    e[m+1].Init();
    for(int i=1;i<=m;i++){
        s[i]=s[i-1];
        s[i].Union(u[i],v[i]);
    }
    for(int i=m;i;i--){
        e[i]=e[i+1];
        e[i].Union(u[i],v[i]);
    }
    int q,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",solve(s[l-1],e[r+1]));
    }
    return 0;
}