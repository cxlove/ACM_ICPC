/*
ID:cxlove
PROB:hdu 2280 Tetris Comes Back
DATA:2012.1.10
HINT:状态压缩DP+dfs
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,c;
char str[1001][6];
int dp[1001][1<<5];
int mmap[1001];
void dfs(int i,int j,int temp,int idx,int num){
    if(idx>=5){
        dp[i+1][temp]=min(dp[i][j]+num,dp[i+1][temp]);
        return ;
    }
    if((1<<idx&mmap[i+1])==0){        
        if((1<<idx&j)==0){
            if(i+2<=n&&((1<<idx)&mmap[i+2])==0){
                if(idx-1>=0&&(1<<(idx-1)&mmap[i+2])==0&&(1<<(idx-1)&temp)==0)
                    dfs(i,j,(temp+(1<<idx))|1<<(idx-1),idx+1,num);        // 6号方块 
                if(idx+1<5&&(1<<(idx+1)&mmap[i+2])==0)
                     dfs(i,j,temp+(1<<(idx+1))+(1<<idx),idx+1,num);          //2号方块 
                   dfs(i,j,temp+(1<<idx),idx+1,num);                       // 5号方块 
                if(idx+1<5&&(1<<(idx+1)&mmap[i+1])==0&&(1<<(idx+1)&j)==0) 
                    dfs(i,j,temp+(1<<idx),idx+2,num);      // 7号方块                     
            }        
             dfs(i,j,temp,idx+1,num+1);           //1号方块 
            if(idx+1<5&&(1<<(idx+1)&j)==0&&(1<<(idx+1)&mmap[i+1])==0&&(1<<(idx+1)&mmap[i+2])==0)
                dfs(i,j,temp+(1<<(idx+1)),idx+2,num);                //8号方块 
            if(idx+1<5&&(1<<(idx+1)&mmap[i+1])==0&&(1<<(idx+1)&j)==0)
                dfs(i,j,temp,idx+2,num);       //4号方块 
        }
        else
            dfs(i,j,temp,idx+1,num);            //此位置已经放 
    }
    else
        dfs(i,j,temp,idx+1,num);    //此位置不可放 
}
int main(){
    while(scanf("%d%d",&n,&c)!=EOF){
        memset(mmap,0,sizeof(mmap));
        for(int i=0;i<=n;i++)
            for(int j=0;j<(1<<5);j++)
                dp[i][j]=99999;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){        
            scanf("%s",str[i]);
            for(int j=0;j<5;j++)
                if(str[i][j]=='1')
                    mmap[i]+=1<<(4-j);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<(1<<5);j++)
                dfs(i,j,0,0,0);
        int ans1=dp[n][0];
    int ans2=99999;
        for(int i=0;i<(1<<5);i++)
            ans2=min(ans2,dp[n][i]);
        if(ans2<=c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
1 1
00000
1 1
00100
1 1
01010
4 1
10000
00101
10010
00000
3 1
00010
00100
01010
*/
