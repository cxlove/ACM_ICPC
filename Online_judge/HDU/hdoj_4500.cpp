#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#define LL long long
using namespace std;
int n,m,a[25][25];
int way[4][2]={0,1,0,-1,1,0,-1,0};
int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        int x=1,y=1,ans=-(1<<20);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int sum=0;
                for(int k=0;k<4;k++){
                    int xx=i+way[k][0];
                    int yy=j+way[k][1];
                    if(a[i][j]*a[xx][yy]<0) sum+=abs(a[xx][yy]);
                    else sum-=abs(a[xx][yy]);
                }
                if(sum>ans) ans=sum,x=i,y=j;
            }
        }
        cout<<x<<" "<<y<<" "<<ans<<endl;
    }
}