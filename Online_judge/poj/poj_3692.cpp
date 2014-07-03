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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2505;
int n,m,w;
int mat[N][N];
int match[N],used[N];
bool dfs(int u){
    for(int i=1;i<=m;i++){
        if(mat[u][i]&&!used[i]){
            used[i]=1;
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
    for(int i=1;i<=n;i++){
        mem(used,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    int cas=0;
    while(scanf("%d%d%d",&n,&m,&w)!=EOF){
        if(n==0&&m==0&&w==0) break;
        mem(mat,1);
        for(int i=0;i<w;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            mat[u][v]=0;
        }
        printf("Case %d: %d\n",++cas,n+m-hungry());
    }
    return 0;
}