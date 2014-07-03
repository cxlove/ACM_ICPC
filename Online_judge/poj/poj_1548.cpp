#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
#define pi acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 25;
int mat[N*N][N*N],n=24,m=24;
int match[N*N],vis[N*N];
int a[N][N];
int dfs(int u){
    for(int i=0;i<n*m;i++){
        if(mat[u][i]&&!vis[i]){
            vis[i]=1;
            if(match[i]==-1||dfs(match[i])){
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int hungry(){
    int ans=0;
    mem(match,-1);
    for(int i=0;i<n*m;i++){
        mem(vis,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x==-1&&y==-1) break;
        mem(mat,0);
        mem(a,0);
        a[x][y]=1;
        while(scanf("%d%d",&x,&y)!=EOF&&x+y)
            a[x][y]=1;
        int tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==0) continue;
                tot++;
                for(int u=1;u<=n;u++){
                    for(int v=1;v<=m;v++){
                        if(u==i&&v==j) continue;
                        if(a[u][v]==0) continue;
                        if(u<=i&&v<=j)
                            mat[(u-1)*m+v-1][(i-1)*m+j-1]=1;
                    }
                }
            }
        }
        printf("%d\n",tot-hungry());
    }
    return 0;
}