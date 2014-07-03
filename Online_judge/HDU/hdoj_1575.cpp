#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 10
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct Matrix{
    int m[N][N];
}init;
int n,k;
Matrix Mult(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=(ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&init.m[i][j]);
        init=Pow(init,k);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=(ans+init.m[i][i])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}