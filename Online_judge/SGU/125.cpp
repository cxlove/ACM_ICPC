#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
int n;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int b[5][5],a[5][5];
bool ans=false;
void dfs(int row,int col){
    if(ans )return;
    if(row>n){
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<4;j++){
                int x=n+way[j][0];
                int y=i+way[j][1];
                if(a[x][y]>a[n][i])
                cnt++;
            }
            if(cnt!=b[n][i]) return ;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cout<<a[i][j]<<(j<n?" ":"\n");
        ans=true;
        return ;
    }
    if(col>n){
        dfs(row+1,1);
        return ;
    }
    for(int i=0;i<=9;i++){
        a[row][col]=i;
        if(row>1){
            int cnt=0;
            for(int j=0;j<4;j++){
                int x=row-1+way[j][0];
                int y=col+way[j][1];
                if(a[x][y]>a[row-1][col])
                cnt++;
            }
            if(cnt==b[row-1][col]){
                dfs(row,col+1);
            } 
        }
        else dfs(row,col+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    memset(a,-1,sizeof(a));
    dfs(1,1);
    if(!ans) puts("NO SOLUTION");
}