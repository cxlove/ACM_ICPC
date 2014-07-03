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
const int N = 505;
int n,k;
int mat[N][N];
int match[N],used[N];
bool dfs(int u){
    for(int i=0;i<n;i++){
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
    for(int i=0;i<n;i++){
        mem(used,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
char str[100];
int main(){
    while(scanf("%d",&n)!=EOF){
        mem(mat,0);
        for(int i=0;i<n;i++){
            scanf("%s",str);
            int k,id;
            sscanf(str,"%d:",&id);
            scanf("%s",str);
            sscanf(str,"(%d)",&k);
            for(int j=0;j<k;j++){
                int v;
                scanf("%d",&v);
                mat[id][v]=1;
            }
        }
        printf("%d\n",n-hungry()/2);
    }
    return 0;
}