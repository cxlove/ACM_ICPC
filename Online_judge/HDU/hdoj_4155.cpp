#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int dp[5][5][5][5][5][5];
int slove(int a,int b,int c,int d,int e,int f){
    if(dp[a][b][c][d][e][f]!=-1)
        return dp[a][b][c][d][e][f];
    int now=1*(4-a)+2*(4-b)+3*(4-c)+4*(4-d)+5*(4-e)+6*(4-f);
    if(now==31)
        return dp[a][b][c][d][e][f]=0;
    else if(now>31)
        return dp[a][b][c][d][e][f]=1;
    int tmp=0;
    if(a&&!slove(a-1,b,c,d,e,f))
        tmp=1;
    else if(b&&!slove(a,b-1,c,d,e,f))
        tmp=1;
    else if(c&&!slove(a,b,c-1,d,e,f))
        tmp=1;
    else if(d&&!slove(a,b,c,d-1,e,f))
        tmp=1;
    else if(e&&!slove(a,b,c,d,e-1,f))
        tmp=1;
    else if(f&&!slove(a,b,c,d,e,f-1))
        tmp=1;
    return dp[a][b][c][d][e][f]=tmp;
}
char str[20];
int main(){
    int cnt[6];
    memset(dp,-1,sizeof(dp));
    while(scanf("%s",str)!=EOF){
        memset(cnt,0,sizeof(cnt));
        int l=strlen(str);
        for(int i=0;i<l;i++)
            cnt[str[i]-'1']++;
        printf("%s ",str);
        int flag=slove(4-cnt[0],4-cnt[1],4-cnt[2],4-cnt[3],4-cnt[4],4-cnt[5]);
        if((flag&&(l%2==0))||(!flag&&(l%2==1)))
            puts("A");
        else
            puts("B");
    }
    return 0;
}
