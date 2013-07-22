#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 100;
int t,m;
int b[N];
int a[N][N+1]={0};
int prime[N],flag[N*11]={0},cnt=0;
void Init(){
    for(int i=2;i<=1000;i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        if(cnt==t) return ;
        for(int j=2;j*i<=1000;j++)
            flag[i*j]=1;
    }
}
int gauss(int n,int m){
    int i,j;
    for(i=0,j=0;i<n&&j<m;j++){
        int k;
        for(k=i;k<n;k++)
            if(a[k][j])
                break;
        if(k<n){
            for(int r=j;r<=m;r++)
                swap(a[i][r],a[k][r]);
            for(int r=0;r<n;r++){
                if(r!=i&&a[r][j]){
                    for(int t=j;t<=m;t++)
                        a[r][t]^=a[i][t];
                }
            }
            i++;
        }
    }
    return m-i;
}
int ans[N];
void out(){
    for(int i=ans[0];i>=1;i--)
        printf("%d",ans[i]);
    if(ans[0]==0) printf("0");
    printf("\n");
}
void gao(){
    for(int i=1;i<=ans[0];i++){
        ans[i]*=2;
    }
    for(int p=1;p<=ans[0];p++){
        if(ans[p]>=10){
            ans[p]%=10;
            ans[p+1]++;
        }
    }
    if(ans[ans[0]+1]>0) ans[0]++;
}
void fuck(){
    ans[1]--;
    int p=1;
    while(ans[p]<0){
        ans[p]+=10;
        ans[++p]--;
    }
    if(ans[ans[0]]==0) ans[0]--;
}
int main(){
    scanf("%d%d",&t,&m);
    Init();
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        for(int j=0;j<t;j++){
            while(b[i]%prime[j]==0){
                a[j][i]^=1;
                b[i]/=prime[j];
            }
        }
    }
    int p=gauss(t,m);
    ans[0]=ans[1]=1;
    for(int i=1;i<=p;i++)
        gao();
    fuck();
    out();
    return 0;
}
