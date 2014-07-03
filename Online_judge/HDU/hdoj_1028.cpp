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
int n,c1[200],c2[200];
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=n;i++)
            c1[i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n&&j+k<=n;k+=i)
                    c2[j+k]+=c1[j];
            for(int j=0;j<=n;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}