#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
vector<int>a[10000],v;
int main(){
    int t,n,l,r,cas=0;
    scanf("%d",&t);
    while(t--){
        a[0].clear();
        for(int i=0;i<52;i++){
            int k;
            scanf("%d",&k);
            a[0].push_back(k);
        }
        scanf("%d%d%d",&n,&l,&r);
        int flag;
        for(int i=1;;i++){
            a[i].clear();
            for(int j=l-1;j<r;j++)
                a[i].push_back(a[i-1][j]);
            for(int j=0;j<l-1;j++)
                a[i].push_back(a[i-1][j]);
            for(int j=r;j<52;j++)
                a[i].push_back(a[i-1][j]);
            flag=i;
            for(int j=0;j<52;j++)
                if(a[i][j]!=a[0][j]){
                    flag=-1;
                    break;
                }
            if(flag!=-1)
                break;
        }
        printf("Case #%d: ",++cas);
        for(int j=0;j<51;j++)
            printf("%d ",a[n%flag][j]);
        printf("%d\n",a[n%flag][51]);
    }
    return 0;
}