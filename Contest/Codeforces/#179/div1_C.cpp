#include<iostream>      
#include<cstdio>      
#include<map>      
#include<cstring>      
#include<cmath>      
#include<vector>      
#include<algorithm>      
#include<set>      
#include<stack>    
#include<string>      
#include<ctime>    
#include<queue>      
#define inf 0x3f3f3f3f   
#define maxn 210005      
#define eps 1e-8    
#define zero(a) fabs(a)<eps      
#define Min(a,b) ((a)<(b)?(a):(b))      
#define Max(a,b) ((a)>(b)?(a):(b))      
#define pb(a) push_back(a)      
#define mp(a,b) make_pair(a,b)      
#define mem(a,b) memset(a,b,sizeof(a))      
#define LL long long      
#define MOD 1000000007    
#define sqr(a) ((a)*(a))      
#define Key_value ch[ch[root][1]][0]      
#define test puts("OK");      
#define pi acos(-1.0)    
#define lowbit(x) ((-(x))&(x))    
#define HASH1 1331    
#define HASH2 10001 
#define lson step<<1
#define rson step<<1|1   
#define C   240      
#define vi vector<int>    
#define TIME 10      
//#pragma comment(linker, "/STACK:1024000000,1024000000")      
using namespace std;
int n,lim;
int one=0,two=0,a[55];
LL dp[505][51][51][2];
LL c[55][55];
queue<pair<int,int> >que[2];
int main(){
    //freopen("input.txt","r",stdin);
    mem(dp,-1);
    for(int i=0;i<=50;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
    scanf("%d%d",&n,&lim);lim/=50;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]/=50;
        if(a[i]==1) one++;
        else two++;
    }
    if(lim==0||(lim==1&&(two||one>1))||(lim==2&&one<2&&two)||(lim==3&&one==0&&two>1)){
        if(lim==2&&one==0&&two==1) ;
        else{
            //puts("-1\n0");
            //return 0;
        }
    }
    que[0].push(mp(one,two));
    dp[0][one][two][0]=1;
    for(int i=1;i<=500;i++){
        pair<int,int>u,v;
        while(!que[(i+1)&1].empty()){
            u=que[(i+1)&1].front();
            que[(i+1)&1].pop();
            if(i&1){
                for(int j=0;j<=u.first;j++){
                    for(int k=0;k<=u.second;k++){
                        if(j+k==0) continue;
                        if(j+2*k>lim) break;
                        if(dp[i][u.first-j][u.second-k][i&1]==-1){
                            dp[i][u.first-j][u.second-k][i&1]=0;
                            que[i&1].push(mp(u.first-j,u.second-k));
                        }
                        dp[i][u.first-j][u.second-k][i&1]=(dp[i][u.first-j][u.second-k][i&1]
                            +((LL)dp[i-1][u.first][u.second][(i+1)&1]*c[u.first][j]%MOD)*c[u.second][k]%MOD)%MOD;
                    }
                }
            }
            else{
                for(int j=0;j<=one-u.first;j++){
                    for(int k=0;k<=two-u.second;k++){
                        if(j+k==0) continue;
                        if(j+2*k>lim) break;
                        if(dp[i][u.first+j][u.second+k][i&1]==-1){
                            dp[i][u.first+j][u.second+k][i&1]=0;
                            que[i&1].push(mp(u.first+j,u.second+k));
                        }
                        dp[i][u.first+j][u.second+k][i&1]=(dp[i][u.first+j][u.second+k][i&1]
                            +((LL)dp[i-1][u.first][u.second][(i+1)&1]*c[one-u.first][j]%MOD)*c[two-u.second][k]%MOD)%MOD;
                    }
                }
            }
        }
        if(i&1&&dp[i][0][0][1]!=-1){
            printf("%d\n%I64d\n",i,dp[i][0][0][1]);
            return 0;
        }
    }
    puts("-1\n0");
    return 0;
}