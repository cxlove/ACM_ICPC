#include <iostream>
#include <cstdio>
using namespace std;
int n,a[20][20];
int b[20],c[20],ans=0;
void dfs(int idx,int l,int r,int sum){
    if(idx==n){
        ans=max(ans,sum);
        return ;
    }
    int tmp=sum;
    for(int i=0;i<l;i++)
        tmp+=a[b[i]][idx];
    c[r]=idx;
    dfs(idx+1,l,r+1,tmp);
    tmp=sum;
    for(int i=0;i<r;i++)
        tmp+=a[idx][c[i]];
    b[l]=idx;
    dfs(idx+1,l+1,r,tmp);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        dfs(0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}