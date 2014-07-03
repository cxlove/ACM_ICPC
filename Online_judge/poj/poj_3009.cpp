#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <climits>
#define H 1000000007
#define MOD 1217767
using namespace std;
int n,m,a[25][25];
int ans;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int xx,yy;
bool gao(int x,int y,int dir){
    if(a[x+way[dir][0]][y+way[dir][1]]==1) return false;
    while(true){
        if(x<1||y<1||x>n||y>m) break;
        if(a[x][y]==3){
            xx=x;
            yy=y;
            return true;
        }
        int xxx=x+way[dir][0],yyy=y+way[dir][1];
        if(a[xxx][yyy]==1){
            xx=x;
            yy=y;
            return true;
        }
        x=xxx;y=yyy;
    }
    return false;
}
void dfs(int x,int y,int c){
    if(c>=10) return;
    for(int i=0;i<4;i++){
        if(gao(x,y,i)){
            if(a[xx][yy]==3){
                ans=min(ans,c+1);
                return ;
            }
            int xxx=xx+way[i][0],yyy=yy+way[i][1];
            a[xxx][yyy]=0;
            dfs(xx,yy,c+1);
            a[xxx][yyy]=1;
        }
    }
}
int main(){
    while(scanf("%d%d",&m,&n)!=EOF&&n+m){
        int x,y;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                if(a[i][j]==2) x=i,y=j;
            }
        ans=11;
        dfs(x,y,0);
        printf("%d\n",ans>10?-1:ans);
    }
    return 0;
}