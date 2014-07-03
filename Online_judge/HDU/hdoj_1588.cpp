#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 10
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
Matrix Mult(Matrix m1,Matrix m2,int n=2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=((LL)ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
        }
    return ans;
}
Matrix Pow(Matrix m1,int b,int n=2){
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
Matrix Add(Matrix m1,Matrix m2,int n=2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=((LL)m1.m[i][j]+m2.m[i][j])%MOD;
    return ans;
}
Matrix slove(Matrix init,int k,int n=2){
    if(k==1)
        return init;
    Matrix temp=slove(init,k>>1,n);
    temp=Add(temp,Mult(temp,Pow(init,k>>1)));
    if(k&1)
        return Add(temp,Pow(init,k));
    else
        return temp;
}
void debug(Matrix m1){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",m1.m[i][j]);
        printf("\n");
    }
}
int main(){
    int k,b,n;
    while(scanf("%d%d%d%d",&k,&b,&n,&MOD)!=EOF){
        init.m[0][0]=init.m[0][1]=init.m[1][0]=1;
        init.m[1][1]=0;
        unit.m[0][0]=unit.m[1][1]=1;
        unit.m[1][0]=unit.m[0][1]=0;
        Matrix t;
        t=Pow(init,b);
        init=Pow(init,k);
    //    debug(init);
        //init.m[0][1]即第k项fib，为A^k
        init=Add(unit,slove(init,n-1)); //B=A^k,   B^0+B^1+B^2……+B^n-1    
    //    debug(init);
        init=Mult(init,t);
        printf("%I64d\n",init.m[0][1]);
    }
    return 0;
}
