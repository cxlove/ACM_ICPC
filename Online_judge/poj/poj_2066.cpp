#include<ctime>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
struct Point {
    int x,y;
}p[50];
int n,dp[50][50];
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int area(int i,int j,int k){
    return abs(xmul(p[i],p[j],p[k]));
}
bool check(int i,int j,int k){
    int s=area(i,j,k);
    for(int r=0;r<n;r++){
        if(r==i||r==j||r==k) continue;
        if(s==area(i,j,r)+area(i,k,r)+area(j,k,r))
            return false;
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=0;i<n;i++)
            dp[i][i+2]=area(i,i+1,i+2);
        for(int i=3;i<n;i++){
            for(int l=0;l+i<n;l++){
                int r=l+i;
                if(check(l,l+1,r))
                    dp[l][r]=min(dp[l][r],max(dp[l+1][r],area(l,l+1,r)));
                if(check(l,r-1,r))
                    dp[l][r]=min(dp[l][r],max(dp[l][r-1],area(l,r-1,r)));
                for(int k=l+2;k<=r-2;k++){
                    if(!check(l,r,k))
                        continue;
                    dp[l][r]=min(dp[l][r],max(dp[l][k],max(dp[k][r],area(l,k,r))));
                }
            }
        }
        printf("%.1f\n",dp[0][n-1]/2.0);
    }
    return 0;
}