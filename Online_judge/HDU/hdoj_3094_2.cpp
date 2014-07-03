#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
vector<int>v[100005];
int sg[100005];
int get_sg(int u,int pre){
//if(sg[u]!=-1)
 //       return sg[u];
    int ret=0;
    for(int i=0;i<v[u].size();i++){
        if(v[u][i]!=pre){
           // sg[v[u][i]]=;
            ret^=(1+get_sg(v[u][i],u));
        }
    }
    return ret;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            v[i].clear();
        memset(sg,-1,sizeof(sg));
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(get_sg(1,-1))
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
