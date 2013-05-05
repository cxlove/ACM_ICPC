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
#include<cassert>    
#define inf 0x11111111  
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
#pragma comment(linker, "/STACK:1024000000,1024000000")      
using namespace std; 
int n,x,y;
double fac[5005];
double a[5005][5005]; //a(i,j) = c(i,j) * 0.5 ^ i
double solve(){
    int level=1,remain=n;
    int query=(abs(x)+abs(y))/2+1;
    while(remain>(4*level-3)){
        remain-=4*level-3;
        level++;
    }
    if(query>level) return 0.0;
    if(query<level) return 1.0;
    if(remain==(4*level-3)&&query==level) return 1.0;
    double ans=0;
    for(int i=abs(y)+1;i<=remain&&i<=(4*level-3)/2;i++){
        if(remain-i<=(4*level-3)/2)
            ans+=a[remain][i];
    }
    double all=0;
    for(int i=0;i<=remain&&i<=(4*level-3)/2;i++){
        if(remain-i<=(4*level-3)/2)
            all+=a[remain][i];
    }
    return ans/all;
}
void Init(){
    a[0][0]=1.0;
    a[1][0]=a[1][1]=0.5;
    for(int i=2;i<=5000;i++){
        a[i][0]=a[i][i]=a[i-1][0]/2.0;
        for(int j=1;j<i;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j])/2.0;
    }
}
int main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    Init();
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        printf("Case #%d: %.10f\n",++cas,solve());
    }
    return 0;
}