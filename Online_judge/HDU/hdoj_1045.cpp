#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct row{
    int x;
    int ly,ry;
}a[16];
struct col{
    int y;
    int lx,rx;
}b[16];
char str[5][5];
int ca,cb;
int mat[16][16];
int vis[20];
int match[20];
bool dfs(int u){
    for(int i=0;i<=cb;i++)
        if(vis[i]==0&&mat[u][i]){
            vis[i]=1;
            if(match[i]==-1||dfs(match[i])){
                match[i]=u;
                return true;
            }
        }
        return false;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        ca=-1;cb=-1;
        bool flag=false;
        for(int i=0;i<n;i++){
            flag=false;
            for(int j=0;j<n;j++){
                if(str[i][j]=='X')
                    flag=false;
                else{
                    if(flag==false){
                        ca++;
                        a[ca].x=i;
                        a[ca].ly=j;
                        flag=true;
                    }
                    a[ca].ry=j;
                }
            }
        }
        flag=false;
        for(int i=0;i<n;i++){
            flag=false;
            for(int j=0;j<n;j++){
                if(str[j][i]=='X')
                    flag=false;
                else{
                    if(flag==false){
                        cb++;
                        b[cb].y=i;
                        b[cb].lx=j;
                        flag=true;
                    }
                    b[cb].rx=j;
                }
            }
        }
        memset(mat,0,sizeof(mat));
        for(int i=0;i<=ca;i++)
            for(int j=0;j<=cb;j++)
                if(a[i].x>=b[j].lx&&a[i].x<=b[j].rx)
                    if(b[j].y>=a[i].ly&&b[j].y<=a[i].ry)
                        mat[i][j]=1;
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int i=0;i<=ca;i++){
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                 ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}