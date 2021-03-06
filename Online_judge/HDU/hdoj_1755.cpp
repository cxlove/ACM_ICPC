/*
ID:cxlove
PROB:hdu 1755 A Number Puzzle
DATA:2012.1.12
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 100000000
using namespace std;
int a[10];
int n,m;
bool vis[10];
int dp[101][101];
void dfs(int idx,int num){
    if(idx==n){
        for(int i=1;i<100;i++)
                dp[i][num%i]=min(dp[i][num%i],num);
        return;
    }
    for(int i=0;i<n;i++)
        if(!vis[i]&&(a[i]!=0||idx!=0)){
            vis[i]=true;
            dfs(idx+1,num*10+a[i]);
            vis[i]=false;
        }
}
int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                dp[i][j]=inf;
        memset(vis,false,sizeof(vis));
        dfs(0,0);
        while(m--){
            int x,k;
            cin>>x>>k;
            if(dp[k][(k-x%k)%k]!=inf)
                cout<<dp[k][(k-x%k)%k]<<endl;
            else
                cout<<"None"<<endl;
        }
    }
    return 0;
}

                
