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
int sg[55][60005];
int get_sg(int i,int j){
    if(sg[i][j]!=-1)
        return sg[i][j];
    if(j==1)
        return sg[i][j]=get_sg(i+1,0);
    sg[i][j]=0;
    if(i>=1&&!get_sg(i-1,j))
        sg[i][j]=1;
    else if(j>=1&&!get_sg(i,j-1))
        sg[i][j]=1;
    else if(i>=1&&j>0&&!get_sg(i-1,j+1))
        sg[i][j]=1;
    else if(i>=2&&((j==0&&!get_sg(i-2,j+2))||(j&&!get_sg(i-2,j+3))))
        sg[i][j]=1;
    return sg[i][j];
}
int main(){
    int n,t,cas=0,k;
    scanf("%d",&t);
    memset(sg,-1,sizeof(sg));
    while(t--){
        scanf("%d",&n);
        int one=0,sum=0;
        while(n--){
            scanf("%d",&k);
            if(k==1)
                one++;
            else
                sum+=(k+1);
        }
        if(sum)
            sum--;
        printf("Case #%d: ",++cas);
        if(get_sg(one,sum))
             puts("Alice");
        else
             puts("Bob");
    }
    return 0;
}
