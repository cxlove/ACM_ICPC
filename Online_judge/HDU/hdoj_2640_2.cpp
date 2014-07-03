/*
ID:cxlove
PROB:hdu 2640 Toy bricks
DATA;2012.1.10
HINT:状态压缩DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[101][15][15];
int pre[15][15][15];
int a[15],b[15],count;
char str[101][10];
int mmap[101];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        memset(mmap,0,sizeof(mmap));
        count=0;
        for(int i=1;i<=n;i++){
            cin>>str[i];
            for(int j=0;j<m;j++)
                if(str[i][j]=='#')
                    mmap[i]+=1<<j;
        }
        for(int i=0;i<(1<<m);i++)
            if((i&1)==0&&(i&(1<<(m-1)))==0&&(i<<1&i)==0&&(i<<2&i)==0){
                int temp=i;
                a[++count]=i;
                b[count]=temp%2;
                while(temp=temp>>1)
                    b[count]+=temp%2;
            }
    //    cout<<count<<endl;
    //    for(int i=1;i<=count;i++)
    //        cout<<a[i]<<" "<<b[i]<<endl;    
        for(int j=1;j<=count;j++)
            if((a[j]&mmap[1])==0&&(a[j]&mmap[2])==0&&(a[j]<<1&mmap[2])==0&&(a[j]>>1&mmap[2])==0&&(a[j]&mmap[3])==0)
                dp[2][1][j]=b[j];
        for(int i=3;i<=n-1;i++){
            for(int j=1;j<=count;j++){
                for(int k=1;k<=count;k++){
                    if((a[j]<<1&a[k])||a[j]&a[k]||a[j]>>1&a[k])
                        continue;
                    if(a[k]&mmap[i]||a[k]&mmap[i-1]||a[k]&mmap[i+1]||a[k]<<1&mmap[i]||a[k]>>1&mmap[i])
                        continue;
                    if(a[j]&mmap[i-1]||a[j]&mmap[i-2]||a[j]&mmap[i]||a[j]<<1&mmap[i-1]||a[j]>>1&mmap[i-1])
                        continue;
                    for(int r=1;r<=count;r++)
                        if((a[r]&a[k])==0&&(a[r]&a[j])==0&&(a[r]<<1&a[j])==0&&(a[r]>>1&a[j])==0&&(a[r]&mmap[i-2])==0)
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][r][j]+b[k]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=count;i++)
            for(int j=1;j<=count;j++)
                ans=max(ans,dp[n-1][i][j]);
        cout<<ans<<endl;
    }
    return 0;
}


