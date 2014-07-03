#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 5
#define inf 1<<29
#define MOD 10007
#define Max 301    
#define LL __int64
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct Matrix{
    int m[N][N];
}init,unit;
int n=4;
Matrix Mult(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=(ans.m[i][j]+(m1.m[i][k]*m2.m[k][j]))%MOD;
        }
    return ans;
}
Matrix Pow(Matrix m1,int b){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
            ans=Mult(ans,m1);
        m1=Mult(m1,m1);
        b>>=1;
    }
    return ans;
}
Matrix Add(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=(m1.m[i][j]+m2.m[i][j])%MOD;
    return ans;
}
Matrix slove(Matrix init,int k){
    if(k==1)
        return init;
    Matrix temp=slove(init,k>>1);
    temp=Add(temp,Mult(temp,Pow(init,k>>1)));
    if(k&1)
        return Add(temp,Pow(init,k));
    else
        return temp;
}
void debug(Matrix m1){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",m1.m[i][j]);
        printf("\n");
    }
}
int main(){
    int x,y,k;
    while(scanf("%d%d%d",&k,&x,&y)!=EOF){
        x%=MOD;y%=MOD;
        memset(init.m,0,sizeof(init.m));
        init.m[0][0]=1;init.m[1][0]=1;
        init.m[1][1]=(x*x)%MOD;init.m[2][1]=(2*x*y)%MOD;
        init.m[3][1]=(y*y)%MOD;
        init.m[1][2]=x;init.m[2][2]=y;
        init.m[1][3]=1;
        init=Pow(init,k);
        printf("%d\n",(init.m[0][0]+init.m[1][0]+init.m[2][0]+init.m[3][0])%MOD);
    }
    return 0;
}