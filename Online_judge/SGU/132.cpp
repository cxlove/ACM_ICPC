#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define ff (*it).first.first
#define fs (*it).first.second
#define sf (*it).second.first
#define ss (*it).second.second
using namespace std;
int n,m,a[75]={0};
char str[75][10];
int dp[2][1<<7][1<<7];
bool one[1<<7],two[1<<7][1<<7];
set<pair<pair<int,int>,pair<int,int> > >s[2];
void dfs(int row,int col,int now,int next,int num,int p1,int p2){
    if(row>n) return;
    if(col>=m){
        if(!one[p1]) return ;
        if(!two[p1][now]) return ;
        if(row==n&&!one[now]) return ;
        dp[row&1][now][next]=min(dp[row&1][now][next],dp[(row+1)&1][p1][p2]+num);
        s[(row+1)&1].insert(mp(mp(next,a[row+2]),mp(now,next)));
        return ;
    }
    if(now&(1<<col)){
        dfs(row,col+1,now,next,num,p1,p2);
        return ;
    }
    dfs(row,col+1,now,next,num,p1,p2);
    if(col<m-1&&!(now&(1<<(col+1))))
        dfs(row,col+2,now+(1<<col)+(1<<(col+1)),next,num+1,p1,p2);
    if(row<n&&!(next&(1<<col)))
        dfs(row,col+1,now+(1<<col),next+(1<<col),num+1,p1,p2);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<m);i++){
        bool flag=true;
        for(int j=0;j<m-1&&flag;j++)
            if(!(i&(1<<j))&&!(i&(1<<(j+1))))
                flag=false;
        one[i]=flag;
        for(int j=0;j<(1<<m);j++){
            if((i|j)!=(1<<m)-1)
                two[i][j]=false;
            else two[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]);
        for(int j=0;j<m;j++)
            if(str[i][j]=='*')
                a[i]+=1<<j;
    }
    memset(dp[0],0x11,sizeof(dp[0]));
    dp[0][(1<<m)-1][a[1]]=0;
    s[1].insert(mp(mp(a[1],a[2]),mp((1<<m)-1,a[1])));
    for(int i=1;i<=n;i++){
        memset(dp[i&1],0x11,sizeof(dp[i&1]));
        set<pair<pair<int,int>,pair<int,int> > >::iterator it;
        //cout<<i<<" "<<s[i&1].size()<<endl;
        for(it=s[i&1].begin();it!=s[i&1].end();it++)
            dfs(i,0,ff,fs,0,sf,ss);
        s[i&1].clear();
    }
    int ans=0x11111111;
    for(int i=0;i<(1<<m);i++){
        ans=min(ans,dp[n&1][i][0]);
    }
    printf("%d\n",ans);
    return 0;
}
