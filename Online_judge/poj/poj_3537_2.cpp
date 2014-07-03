#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int sg[2005];
int get_sg(int n){
    if(sg[n]!=-1)
       return sg[n];
    if(n<0) return 0;
    int vis[2005];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        vis[get_sg(i-3)^get_sg(n-i-2)]=1;
    for(int i=0;;i++)
        if(vis[i]==0)
            return sg[n]=i;
}
int main(){
    int n;
    memset(sg,-1,sizeof(sg));
    sg[0]=0;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",get_sg(n)?1:2);
    return 0;
}



