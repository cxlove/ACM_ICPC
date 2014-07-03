#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 2
using namespace std;
struct Matrix{
    int m[N][N];
}init,unit;
int n=2;
int MOD;
Matrix Mult(Matrix m1,Matrix m2){
    Matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++){
            if(m1.m[i][k])
                for(int j=0;j<n;j++)                             
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
int main(){
    int t,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&MOD);
        if(k==0){
            printf("0\n");
            continue;
        }
        init.m[0][0]=init.m[0][1]=init.m[1][0]=1;
        init.m[1][1]=0;
        init=Pow(init,2*k-1);
        printf("%d\n",init.m[0][0]);
    }
    return 0;
}