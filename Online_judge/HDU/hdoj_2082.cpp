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
LL c1[100],c2[100];
int cnt[30];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=26;i++)
            scanf("%d",&cnt[i]);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=cnt[1];i++)
            c1[i]=1;
        for(int i=2;i<=26;i++){
            for(int j=0;j<=50;j++)
                for(int k=0;k<=i*cnt[i]&&j+k<=50;k+=i)
                    c2[j+k]+=c1[j];
            for(int j=0;j<=50;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        LL ans=0;
        for(int i=1;i<=50;i++)
            ans+=c1[i];
        printf("%I64d\n",ans);
    }
    return 0;
}
