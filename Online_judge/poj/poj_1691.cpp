#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 15;
struct Rect{
    int x1,x2,y1,y2,c;
    void input(){
        scanf("%d%d%d%d%d",&y1,&x1,&y2,&x2,&c);
    }
}rec[N];
int up[N],dp[1<<N][25],n;
bool check(int i,int j){
    if(rec[j].y2!=rec[i].y1) return false;
    if(rec[j].x2<=rec[i].x1) return false;
    if(rec[j].x1>=rec[i].x2) return false;
    return true;
}
void dfs(int s,int c){
    if(s==(1<<n)-1) return ;
    for(int i=0;i<n;i++){
        if(s&(1<<i)) continue;
        if((up[i]&s)!=up[i]) continue;
        int news=s|(1<<i);
        int newc=rec[i].c;
        int cnt=(newc!=c);
        if(dp[news][newc]>dp[s][c]+cnt){
            dp[news][newc]=dp[s][c]+cnt;
            dfs(news,newc);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            rec[i].input();
        }
        for(int i=0;i<n;i++){
            up[i]=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(check(i,j)) up[i]|=1<<j;
            }
        }
        memset(dp,0x11,sizeof(dp));
        dp[0][0]=0;
        dfs(0,0);
        int ans=n;
        for(int i=0;i<=20;i++)
            ans=min(ans,dp[(1<<n)-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}