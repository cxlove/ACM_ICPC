
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define N 1000000000
#define inf 1<<29
#define LL long long
#define eps 1e-7
#define pb(a) push_back(a)
#define ub(v,a) upper_bound(v.begin(),v.end(),a)
using namespace std;
struct Matrix{
    LL m[2][2];
}init;
LL n,MOD;
bool flag[40000]={0};
int prime[40000],cnt=0;
LL MultMod(LL a,LL b){
    a%=MOD;
    b%=MOD;
    if(b<0) b+=MOD;
    if(a<0) a+=MOD;
    LL ret=0;
    while(b){
        if(b&1){
            ret+=a;
            if(ret>=MOD) ret-=MOD;
        }
        a=a<<1;
        if(a>=MOD) a-=MOD;
        b=b>>1;
     //   cout<<b<<endl;
    }
    return ret;
}
Matrix operator*(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            ans.m[i][j]=0;
            for(int k=0;k<2;k++)
                ans.m[i][j]=(ans.m[i][j]+MultMod(m1.m[i][k],m2.m[k][j]))%MOD;
        }
    return ans;
}
Matrix operator^(Matrix m1,int b){
    Matrix ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
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
LL extend_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0){x=1;y=0;return a;}
    LL gcd=extend_gcd(b,a%b,x,y);
    LL t=x;x=y;
    y=t-a/b*y;
    return gcd;
}
LL Get_inverse(int num){
    LL x,y;
    LL gcd=extend_gcd(num,MOD,x,y);
    return (x%MOD+MOD)%MOD;
}
LL Get_T(int k){
    if(k==1)  return 1;
    else if(k==2) return 5;
    Matrix temp=init^(k-2);
    LL f=3*temp.m[0][0]+temp.m[1][0];
    LL g=2*(f-(3*temp.m[0][1]+temp.m[1][1])-1);
    return (g+f)%MOD;
}
LL Polya(){
    LL sum=0;
    int i;
    for(i=1;i*i<n;i++)
        if(n%i==0){
            sum=(sum+MultMod(Eular(i),Get_T(n/i)))%MOD;
            sum=(sum+MultMod(Eular(n/i),Get_T(i)))%MOD;
        }
    if(i*i==n) sum=(sum+MultMod(Get_T(i),Eular(i)))%MOD;
    return (sum/n);
}
int main(){
    Prime();
    init.m[0][0]=3;init.m[0][1]=1;init.m[1][0]=-1;init.m[1][1]=0;
    while(scanf("%I64d%I64d",&n,&MOD)!=EOF){
     //   cout<<n<<" "<<MOD<<endl;
                MOD=(LL)n*MOD;
      //  cout<<MOD<<endl;
        printf("%I64d\n",Polya()%(MOD/n));
    }
    return 0;
}
/*


#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
const int maxn=6;
typedef __int64 lld;
lld mod;
lld mul(lld a,lld b,lld c)
{
         lld ret=0,tmp=a;
         if(b<0)b+=c;
         if(tmp<0)tmp+=c;
         while(b)
         {
                   if(b&0x1)if((ret+=tmp)>=c)ret-=c;
                   if((tmp<<=1)>=c)tmp-=c;
                   b>>=1;
         }
         return ret%c;
}//抄AC大神的模拟高精度

struct Matrix
{
         lld mat[maxn][maxn];
         Matrix(){memset(mat,0,sizeof(mat));}
         lld * operator [](int k){return mat[k];}
};
Matrix operator *(Matrix &a, Matrix &b)
{
         Matrix c;
         for (int i=0;i<6;i++)
                   for (int j=0;j<6;j++)
                   {
                            if (a.mat[i][j]==0) continue;
                            for (int k=0;k<6;k++)
                                     c[i][k]=(c[i][k]+mul(a[i][j],b[j][k],mod))%mod;
                   }
         return c;
}
Matrix operator ^(Matrix &a,int m)
{
         int j;
         Matrix b,c=a;
         for (j=0;j<6;j++)
                   b[j][j]=1;
         while (m)
         {
                   if (m & 1 ) b=b*c;
                   if (m>>=1) c=c*c;
         }
         return b;
}//以上矩阵乘法
const int maxP=400001;
bool IsPrime[maxP];
int Prime[maxP];
int num;
void Eratosthenes(int n=maxP)
{
         num=0;
         memset(Prime,0,sizeof(Prime));
         memset(IsPrime,1,sizeof(IsPrime));
         for (int i=2;i<n;i++)
         {
                   if (IsPrime[i])
                            Prime[num++]=i;
                   for (int j=0;j<num && i*Prime[j]<n;j++)
                   {
                            IsPrime[i*Prime[j]] = 0;
                            if (i%Prime[j] == 0 ) break;
                   }

         }
}//以上筛素数
int p[maxP];
int pp;
lld n;
lld setF[6]={8,3,5,2,5,1};
lld countT(int n)
{
         if (n==1)
                   return 1;
         if (n==2)
                   return 5;
         Matrix a;
         a[0][0]=3;
         a[0][1]=-1;
         a[1][0]=1;
         a[2][0]=a[2][2]=1;
         a[3][2]=1;
         a[4][2]=a[4][3]=1;a[4][4]=2;a[4][5]=-1;
         a[5][4]=1;
         a=a^(n-2);
         lld tot=0;
         for (int i=0;i<6;i++)
         {
                   tot=tot+mul(a[4][i],setF[i],mod);
                   tot%=mod;
         }
         return tot;
}//以上计算T[n]
lld oula(lld a)
{
         for (int i=0;i<pp;i++)
                   if (a%p[i]==0)
                            a=(a/p[i])*(p[i]-1);
         return a;
}//计算欧拉函数
lld work(lld a)
{
         lld resi;
         resi=countT(a);
         lld ts=oula(n/a);
         return mul(resi,ts,mod);
}
int main()
{

         Eratosthenes();
         while (scanf("%I64d%I64d",&n,&mod)!=EOF)
         {
                   int i,j,k;
                   pp=0;
                   k=n;
                   for (i=0;Prime[i]*Prime[i]<=k;i++)
                            if (k%Prime[i] ==0 )
                            {
                                     while (k%Prime[i] ==0)
                                               k/=Prime[i];
                                     p[pp++]=Prime[i];
                            }
                   if (k>1)
                            p[pp++]=k;
                   mod*=n;

                   lld tot=0;
                   for (i=1;i*i<=n;i++)
                            if (n%i==0)
                            {
                                     tot=(tot+work(i))%mod;
                                     if (i*i==n)
                                               break;
                                     tot=(tot+work(n/i))%mod;
                            }
                   tot/=n;
                   mod/=n;
                   printf("%I64d\n",tot%mod);
         }
         return 0;
}
*/
