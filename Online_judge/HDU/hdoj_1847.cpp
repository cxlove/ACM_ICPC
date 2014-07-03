#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#define LL long long
#define N 1000000
#define inf 1<<20
using namespace std;
int s[10]={1,2,4,8,16,32,64,128,256,512};
int sg[1005];
int get_sg(int n){
    if(sg[n]!=-1)
        return sg[n];
    int flag[100];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<10&&s[i]<=n;i++){
        sg[n-s[i]]=get_sg(n-s[i]);
        flag[sg[n-s[i]]]=1;
    }
    for(int i=0;i<100;i++)
        if(flag[i]==0)
            return i;
}
int main(){
    memset(sg,-1,sizeof(sg));
    sg[0]=0;
    int n;
    while(scanf("%d",&n)!=EOF){
        if(sg[n]==-1)
            sg[n]=get_sg(n);
        if(sg[n])
            puts("Kiki");
        else
            puts("Cici");
    }
    return 0;
}
