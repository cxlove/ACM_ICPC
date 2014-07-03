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
int val[5]={1,5,10,25,50};
int c1[255][105]={0},c2[255][105]={0};
int cnt[30];
int main(){
    for(int i=0;i<=100;i++)
        c1[i][i]=1;
    for(int i=1;i<5;i++){
        for(int j=0;j<=250;j++)
            for(int k=0;k+j<=250;k+=val[i])
                for(int r=0;r+k/val[i]<=100;r++)
                    c2[j+k][r+k/val[i]]+=c1[j][r];
        for(int j=0;j<=250;j++)
            for(int k=0;k<=100;k++){
                c1[j][k]=c2[j][k];
                c2[j][k]=0;
            }
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=0;i<=100;i++)
            ans+=c1[n][i];
        printf("%d\n",ans);
    }
    return 0;
}