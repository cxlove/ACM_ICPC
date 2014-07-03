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
const int N = 55;
char str[N][N];
int way[4][2]={0,1,0,-1,1,0,-1,0};
int mat[N*N][N*N],n,m;
int match[N*N],vis[N*N];
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
    int t;
    scanf("%d",&t);
    while(t--){
        mem(mat,0);
        scanf("%d%d",&n,&m);
        int tot=0;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='*')
                    tot++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(str[i][j]!='*') continue;
                for(int k=0;k<4;k++){
                    int x=i+way[k][0],y=j+way[k][1];
                    if(x>=0&&y>=0&&x<n&&y<m&&str[x][y]=='*'){
                        mat[i*m+j][x*m+y]=1;
                    }
                }
            }
        }
        printf("%d\n",tot-hungry()/2);
    }
    return 0;
}