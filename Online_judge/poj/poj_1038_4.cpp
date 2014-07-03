#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,k;
int bad[155][15];//存放坏点
int fac[11];    //存放3幂数
int dp[2][60000];//滚动数组，求本行的数量，只需知道前一行的各个状态下的数量就可以了
int InfoA[11],InfoB[11];//InfoA存放前两行的状态，InfoB存放本行和前一行的状态
//0表示前两行空闲，1表示前一行的前一行被占据，2表示前一行被占据
//dp[i&1][state]表示前i行在state状态下放的最多的数量
//所以转移方程只需要在本行搜索结束在计算就可以
void init()   // 把三的幂数打出来
{
int i;
for(i=1,fac[0]=1; i<11;i++)
fac[i] = fac[i-1]*3;
}
inline void Code(int s,int *a) // 把十进制的状态转化成为3进制的表示
{
for( int i = 0;i<m;i++)
{
a[i] = s%3;
s /= 3;
}
}
inline int hash(int a[])   // 把3进制转化成为状态十进制表示并存储；
{
int ans = 0;
for(int i = 0;i<11;i++)
ans += fac[i]*a[i];
return ans;
}
void dfs(int x,int y,int status,int cnt)//第x行第y列本status，数量为cnt
{
if(y>=m-1)
{
dp[x&1][status] = max(dp[x&1][status],cnt);
return ;
}
if(InfoA[y]==0&&InfoA[y+1]==0&&InfoB[y]==0&&InfoB[y+1]==0)
{
InfoB[y]=InfoB[y+1]=2;
int nows=hash(InfoB);
dfs(x,y+2,nows,cnt+1);
InfoB[y]=InfoB[y+1]=0;
}
if(y<m-2&&InfoB[y]==0&&InfoB[y+1]==0&&InfoB[y+2]==0)
{
InfoB[y]=InfoB[y+1]=InfoB[y+2]=2;
int nows=hash(InfoB);
dfs(x,y+3,nows,cnt+1);
InfoB[y]=InfoB[y+1]=InfoB[y+2]=0;
}
dfs(x,y+1,status,cnt);
}
int main()
{
int i,j,T,x,y;
scanf("%d",&T);
while(T--&&scanf("%d%d%d",&n,&m,&k))
{
init();
memset(bad,0,sizeof(bad));
for(i=1;i<=k;i++)
{
scanf("%d%d",&x,&y);
bad[x-1][y-1]=1;
}
if(n<2){printf("0\n");continue;}
memset(dp[1],-1,sizeof(dp[1]));
memset(InfoA,0,sizeof(InfoA));
for(i=0;i<m;i++)InfoA[i]=bad[0][i]+1;
int state=hash(InfoA);
dp[1][state]=0;//初始化，state表示的是第一行坏点的状况
for(i=2;i<=n;i++)
{
int now=i&1,pre=now^1;
memset(dp[now],-1,sizeof(dp[now]));
memset(InfoB,0,sizeof(InfoB));
for(j=0;j<fac[m];j++)//j表示前两行的状态
{
if(dp[pre][j]<0)continue;
Code(j,InfoA);
for(int l=0;l<m;l++)
{
if(bad[i-1][l]==1)InfoB[l]=2;
else InfoB[l]=InfoA[l]-1;
if(InfoB[l]<0)InfoB[l]=0;
}
dfs(i,0,hash(InfoB),dp[pre][j]);
}
}
int ans=0,t=n&1;
for(i=0;i<fac[m];i++)
ans=ans>dp[t][i]?ans:dp[t][i];
printf("%d\n",ans);
}
}
