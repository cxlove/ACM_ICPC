#include<cstdio>
 #include<cstring>
 using namespace std;
 
 int maze[10][10],n;
 int vis[10][10];
 int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
 void fill(int x,int y,int c){
     vis[x][y]=1;
     for(int i=0;i<4;i++){
         int tx=x+dir[i][0];
         int ty=y+dir[i][1];
         if(tx<0||ty<0||tx>=n||ty>=n) continue;
         if(vis[tx][ty]==1) continue;
         vis[tx][ty]=2;
         if(maze[tx][ty]==c) fill(tx,ty,c);
     }
 }
 
 int exp(int col){
     int cnt=0;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(maze[i][j]!=col) continue;
             if(vis[i][j]==2){
                 cnt++;
                 fill(i,j,col);
             }
         }
     }
     return cnt;
 }
 
 int h(){
     int col=0;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(vis[i][j]==1) continue;
             col|=1<<maze[i][j];
         }
     }
     int cnt=0;
     while(col){
         col&=(col-1);
         cnt++;
     }
     return cnt;
 }
 
 int dep;
 bool dfs(int d){
     if(d==dep) return h()==0;
     if(h()+d>dep) return false;
     
     for(int i=0;i<=5;i++){
         int tvis[10][10];
         memcpy(tvis,vis,sizeof(vis));
         if(exp(i)==0) continue;
         if(dfs(d+1)) return true;
         memcpy(vis,tvis,sizeof(vis));
     }
     return false;
 }
 
 int main(){
     while(scanf("%d",&n),n){
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 scanf("%d",&maze[i][j]);
             }
         }
         memset(vis,0,sizeof(vis));
         fill(0,0,maze[0][0]);
         
         dep=0;
         while(true){
             if(dfs(0)) break;
             dep++;
         }
         printf("%d\n",dep);
     }
 }