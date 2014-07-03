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
int n,m,row,col;
int mat[N][N];
int match[N],used[N];
pii a[N][N];
char str[N][N];
bool dfs(int u){
    for(int i=1;i<=col;i++){
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
    for(int i=1;i<=row;i++){
        mem(used,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        row=0,col=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(str[i][j]=='.') continue;
                if(j&&str[i][j-1]=='*')
                    a[i][j].first=row;
                else a[i][j].first=++row;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(str[i][j]=='.') continue;
                if(i&&str[i-1][j]=='*')
                    a[i][j].second=col;
                else a[i][j].second=++col;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(str[i][j]=='*'){
                    mat[a[i][j].first][a[i][j].second]=1;
                }
            }
        }
        printf("%d\n",hungry());
    }
    return 0;
}