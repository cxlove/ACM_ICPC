#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1000000000
#define inf 1<<29
#define MOD 9973
#define LL long long
using namespace std;
struct Matrix{
    int m[15][15];
}init;
int s,c,k;
bool flag[40000]={0};
int prime[40000],cnt=0;
Matrix operator*(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<c;i++)
        for(int j=0;j<c;j++){
            ans.m[i][j]=0;
            for(int k=0;k<c;k++)
                ans.m[i][j]=(ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
        }
    return ans;
}
Matrix operator^(Matrix m1,int b){
    Matrix ans;
    for(int i=0;i<c;i++)
        for(int j=0;j<c;j++)
            ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
            ans=ans*m1;
        m1=m1*m1;
        b>>=1;
    }
    return ans;
}
void Prime(){
    for(int i=2;i<=sqrt(N+1.0);i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(N+1.0);j++)
            flag[i*j]=true;
    }
}
int PowMod(int a,int b){
    a%=MOD;
    int ret=1;
    while(b){
        if(b&1)  ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int Eular(int n){
    int ret=1;
    for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            n/=prime[i];ret*=prime[i]-1;
            while(n%prime[i]==0){n/=prime[i];ret=(ret*prime[i])%MOD;}
        }
    }
    if(n>1) ret*=n-1;
    return ret%MOD;
}
void debug(Matrix t){
    for(int i=0;i<c;i++){
        for(int j=0;j<c-1;j++)
            printf("%d ",t.m[i][j]);
        printf("%d\n",t.m[i][c-1]);
    }
}
int slove(int n){
  //  debug(init);
    Matrix temp=init^n;
  //  debug(temp);
    int ans=0;
    for(int i=0;i<c;i++)
        ans=(ans+temp.m[i][i])%MOD;
    return ans;
}
int Polya(){
    int i,ans=0;
    for(i=1;i*i<s;i++)
        if(s%i==0)
           ans=(ans+Eular(i)*slove(s/i)+Eular(s/i)*slove(i))%MOD;
    if(i*i==s) ans=(ans+Eular(i)*slove(i))%MOD;
    return (ans*PowMod(s%MOD,MOD-2))%MOD;
}

int main(){
    int t;
    Prime();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&s,&c,&k);
        for(int i=0;i<c;i++)
            for(int j=0;j<c;j++)
                init.m[i][j]=1;
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            init.m[a][b]=init.m[b][a]=0;
        }
        printf("%d\n",Polya());
    }
    return 0;
}






