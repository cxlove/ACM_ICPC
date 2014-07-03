#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 105
#define inf 1<<29
#define MOD 9973
#define Max 301    
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct Matrix{
    int m[N][N];
}init,unit;
int n,k;
Matrix Mult(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=(ans.m[i][j]^(m1.m[i][k]*m2.m[k][j]));
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
void debug(Matrix m1){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",m1.m[i][j]);
        printf("\n");
    }
}
char str[N];
int main(){
    while(scanf("%d",&k)!=EOF){
        scanf("%s",str);
        n=strlen(str);
        memset(init.m,0,sizeof(init.m));
        for(int i=0;i<n;i++)
            init.m[i][i]=init.m[(i-1+n)%n][i]=1;
        init=Pow(init,k);
        //debug(init);
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<n;j++)
                t=t^((str[j]-'0')*init.m[j][i]);
            printf("%d",t);
        }
        puts("");
    }
    return 0;
}