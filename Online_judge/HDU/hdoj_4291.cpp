#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 2
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;
struct Matrix{
    LL m[N][N];
}init,unit;
Matrix Mult(Matrix m1,Matrix m2,int MOD,int n=2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            for(int k=0;k<n;k++)
                ans.m[i][j]=((LL)ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
        }
    return ans;
}
Matrix Pow(Matrix m1,LL b,int MOD,int n=2){
    Matrix ans;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
            ans=Mult(ans,m1,MOD,n);
        m1=Mult(m1,m1,MOD,n);
        b>>=1;
    }
    return ans;
}
LL slove(LL n,int MOD){
    if(n==0) return 0;
    if(n==1) return 1;
    unit=Pow(init,n-1,MOD);
    return unit.m[0][0];
}
int main(){
    LL n;
    while(scanf("%I64d",&n)!=EOF){
        init.m[0][0]=3;init.m[0][1]=1;
        init.m[1][0]=1;init.m[1][1]=0;
        int s0=1000000007,s1=222222224,s2=183120,s3=240;
        n=n%s3;
        n=slove(n,s2);
    //    cout<<n<<endl;
        n=n%s2;
        n=slove(n,s1);
        n=n%s1;
        n=slove(n,s0);
        printf("%I64d\n",n);
    }
    return 0;
}