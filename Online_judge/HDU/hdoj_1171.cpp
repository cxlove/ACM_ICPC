#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 29
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int c1[250005],c2[250005];
int val[55],cnt[55],n;
int main(){
    while(scanf("%d",&n)!=EOF&&n>=0){
        int mmax=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&val[i],&cnt[i]);
            mmax+=val[i]*cnt[i];
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=val[0]*cnt[0];i+=val[0])
            c1[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=mmax;j++)
                for(int k=0;k<=val[i]*cnt[i]&&j+k<=mmax;k+=val[i])
                    c2[j+k]+=c1[j];
            for(int j=0;j<=mmax;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        int i;
        for(i=mmax/2;;i--)
            if(c1[i])
                break;
        printf("%d %d\n",mmax-i,i);
    }
    return 0;
}
    