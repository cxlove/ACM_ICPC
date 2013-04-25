#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#define pb(a) push_back(a)
#define f(x,y) (x)*(y)
#define LL long long
#define test puts("OK");
using namespace std;
const int N =1005;
int n,m,k;
char a[N][N],b[N][N];
int ans[1005][1005];
int e=0;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
        for(int j=0;j<m-1;j++)
            e+=a[i][j]=='E';
        if(i<n-1){
            scanf("%s",b[i]);
            for(int j=0;j<m;j++)
                e+=b[i][j]=='E';
        }
    }
    if(k==1){
        if(4*e>=3*(n*(m-1)+m*(n-1))){
            puts("YES");
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    printf("1%c",j==m-1?'\n':' ');
            }
        }
        else puts("NO");
        return 0;
    }
    if(m>=n){
        ans[0][0]=0;
        for(int j=0;j<m-1;j++)
            ans[0][j+1]=ans[0][j]^(a[0][j]=='N');
        for(int i=1;i<n;i++){
            ans[i][0]=0;
            for(int j=0;j<m-1;j++)
                ans[i][j+1]=ans[i][j]^(a[i][j]=='N');
            int t=0;
            for(int j=0;j<m;j++)
                t+=(ans[i][j]==ans[i-1][j])^(b[i-1][j]=='E');
            if(t*2>m){
                for(int j=0;j<m;j++)
                    ans[i][j]=1-ans[i][j];
            }
        }
    }
    else{
        ans[0][0]=0;
        for(int i=0;i<n-1;i++)
            ans[i+1][0]=ans[i][0]^(b[i][0]=='N');
        for(int j=1;j<m;j++){
            ans[0][j]=0;
            for(int i=0;i<n-1;i++)
                ans[i+1][j]=ans[i][j]^(b[i][j]=='N');
            int t=0;
            for(int i=0;i<n;i++)
                t+=(ans[i][j]==ans[i][j-1])^(a[i][j-1]=='E');
            if(t*2>n){
                for(int i=0;i<n;i++)
                    ans[i][j]=1-ans[i][j];
            }
        }
    }
    puts("YES");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d%c",ans[i][j]+1,j==m-1?'\n':' ');
    }
    return 0;
}