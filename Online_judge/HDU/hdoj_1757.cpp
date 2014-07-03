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
Matrix Mult(Matrix m1,Matrix m2,int n=10){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=((LL)ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
        }
    return ans;
}
Matrix Pow(Matrix m1,int b,int n=10){
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
Matrix Add(Matrix m1,Matrix m2,int n=10){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=((LL)m1.m[i][j]+m2.m[i][j])%MOD;
    return ans;
}
Matrix slove(Matrix init,int k,int n=10){
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
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            printf("%d ",m1.m[i][j]);
        printf("\n");
    }
}
int main(){
    int k,b,n;
    int a[10];
    while(scanf("%d%d",&k,&MOD)!=EOF){
        for(int i=0;i<10;i++)
            scanf("%d",&a[i]);
        if(k<10)
            printf("%d\n",k);
        else{
            memset(init.m,0,sizeof(init.m));
            for(int i=0;i<10;i++)
                init.m[i][0]=a[i];
            for(int i=1;i<10;i++)
                init.m[i-1][i]=1;
            init=Pow(init,k-9);
            LL ans=0;
            for(int i=0;i<10;i++)
                ans=(ans+(9-i)*init.m[i][0])%MOD;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}