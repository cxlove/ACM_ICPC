#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[105][105];
int l1,l2;
char s1[105],s2[105];
int way[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-10000}}; 
int id(char ch){
    if(ch=='A') return 0;
    if(ch=='C') return 1;
    if(ch=='G') return 2;
    return 3;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s%d%s",&l1,s1,&l2,s2);
        for(int i=0;i<l1;i++)
            dp[i+1][0]=dp[i][0]+way[id(s1[i])][4];
        for(int j=0;j<l2;j++)
            dp[0][j+1]=dp[0][j]+way[4][id(s2[j])];
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++)
                dp[i][j]=max(dp[i-1][j-1]+way[id(s1[i-1])][id(s2[j-1])],max(dp[i][j-1]+way[4][id(s2[j-1])],dp[i-1][j]+way[id(s1[i-1])][4]));
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}