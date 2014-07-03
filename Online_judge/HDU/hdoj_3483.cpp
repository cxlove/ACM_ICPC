#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 55
#define inf 1<<29
//#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct Matrix{
    LL m[N][N];
}init,unit;
int MOD;
Matrix Mult(Matrix m1,Matrix m2,int n){
    Matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            if(m1.m[i][k])
                for(int j=0;j<n;j++){
                    ans.m[i][j]+=m1.m[i][k]*m2.m[k][j];
                    if(ans.m[i][j]>=MOD)ans.m[i][j]%=MOD;
                }
    /*for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=(ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
        }*/
    return ans;
}
Matrix Pow(Matrix m1,int b,int n){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
            ans=Mult(ans,m1,n);
        m1=Mult(m1,m1,n);
        b>>=1;
    }
    return ans;
}
Matrix Add(Matrix m1,Matrix m2,int n){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=(m1.m[i][j]+m2.m[i][j])%MOD;
    return ans;
}
Matrix slove(Matrix init,int k,int n){
    if(k==1)
        return init;
    Matrix temp=slove(init,k>>1,n);
    temp=Add(temp,Mult(temp,Pow(init,k>>1,n),n),n);
    if(k&1)
        return Add(temp,Pow(init,k,n),n);
    else
        return temp;
}
void debug(Matrix m1,int n){
    for(int i=0;i<n;i++){
        printf("%d",m1.m[i][0]);
        for(int j=1;j<n;j++)
            printf(" %d",m1.m[i][j]);
        printf("\n");
    }
}    
int n,x;
LL c[N][N];    
int main(){
    while(scanf("%d%d%d",&n,&x,&MOD)!=EOF){
        if(n==-1&&x==-1&&MOD==-1) break;
        memset(init.m,0,sizeof(init.m));
        for(int i=0;i<=x;i++){
            c[i][0]=1;c[i][i]=1;
            for(int j=1;j<i;j++){
                c[i][j]=(c[i-1][j]+c[i-1][j-1]);
                if(c[i][j]>=MOD)
                    c[i][j]-=MOD;
            }
        }
        for(int j=0;j<=x;j++)
            for(int i=0;i<=j;i++)
                init.m[i][j]=(c[j][i]*x)%MOD;
        for(int i=0;i<=x;i++)
            init.m[i][x+1]=(x*c[x][i])%MOD;
        init.m[x+1][x+1]=1;
        init=Pow(init,n-1,x+2);        
        LL ans=0;
        for(int i=0;i<=x+1;i++)
            ans=(ans+x*init.m[i][x+1])%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}