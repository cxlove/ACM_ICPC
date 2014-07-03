/*
ID:cxlove
PROB:zipper
DATA:2012.3.9
HINT:DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[205],s2[205],s[405];
int dp[205][205];
int main(){
    int t;
    scanf("%d",&t);
    s1[0]=s2[0]='3';
    for(int tt=1;tt<=t;tt++){
        scanf("%s%s%s",s1+1,s2+1,s+1);
        int l1=strlen(s1);
        int l2=strlen(s2);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<l2;i++)
            if(s2[i]==s[i])
                dp[0][i]=i;
            else
                break;
        for(int i=1;i<l1;i++)
            if(s1[i]==s[i])
                dp[i][0]=i;
            else
                break;
        for(int i=1;i<l1;i++)
            for(int j=1;j<l2;j++){
                if(s1[i]==s[i+j]&&dp[i-1][j]!=0)
                    dp[i][j]=i+j;
                else if(s2[j]==s[i+j]&&dp[i][j-1]!=0)
                    dp[i][j]=i+j;
            }
        printf("Data set %d: ",tt);
        if(dp[l1-1][l2-1]==l1+l2-2)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}