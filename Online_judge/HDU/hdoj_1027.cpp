#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<string>
#define LL  long long
#define MOD 1000000007
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int main(){
    int n,m,a[1005];
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            a[i]=i+1;
        m--;
        while(m--)
            next_permutation(a,a+n);
        printf("%d",a[0]);
        for(int i=1;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}