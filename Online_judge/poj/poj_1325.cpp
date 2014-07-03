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
const int N = 1005;
int mat[N][N],vis[N],match[N];
int n,m,k;
int dfs(int u){
    for(int i=0;i<m;i++){
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
    for(int i=0;i<n;i++){
        mem(vis,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        mem(mat,0);
        scanf("%d%d",&m,&k);
        for(int i=0;i<k;i++){
            int id,x,y;
            scanf("%d%d%d",&id,&x,&y);
            if(x&&y){
                mat[x][y]=1;
            }
        }
        printf("%d\n",hungry());
    }
    return 0;
}