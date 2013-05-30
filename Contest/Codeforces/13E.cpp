#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 100005;
int n,m,a[N];
int cnt[N],end[N],next[N];
int BLOCK;
void add(int i,int j){
    if(j>n){
        cnt[i]=1;
        end[i]=i;
        next[i]=n+1;
    }
    else{
        if(i/BLOCK==j/BLOCK){
            cnt[i]=cnt[j]+1;
            end[i]=end[j];
            next[i]=next[j];
        }
        else{
            next[i]=j;
            end[i]=i;
            cnt[i]=1;
        }
    }
}
void ask(int u){
    int c=cnt[u],e=end[u];
    while(true){
        u=next[u];
        if(u>n) break;
        c+=cnt[u];
        e=end[u];
    }
    printf("%d %d\n",e,c);
}
int main(){
    scanf("%d%d",&n,&m);
    BLOCK=ceil(sqrt(n*1.0));
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
        add(i,i+a[i]);
    while(m--){
        int k,u,v;
        scanf("%d",&k);
        if(k){
            scanf("%d",&u);
            ask(u);
        }
        else{
            scanf("%d%d",&u,&v);
            add(u,u+v);
            for(int i=u-1;i>=u/BLOCK*BLOCK;i--)
                add(i,i+a[i]);
            a[u]=v;
        }
    }
    return 0;
}
