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
int mmap[1005][1005];
int n,k;
bool flag[1005];
int ret;
int slove(int m){
    for(int i=1;i<=n;i++)
        if(mmap[m][i]&&!flag[i]){
            flag[m]=true;
            if(!slove(i)){
                flag[m]=false;
                ret=i;
                return true;
            }
            flag[m]=false;
        }
    return false;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(mmap,0,sizeof(mmap));
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            mmap[u][v]=mmap[v][u]=1;
        }
        memset(flag,false,sizeof(flag));
        int ans=slove(k);
        if(ans==0)
            puts("First player loses");
        else
            printf("First player wins flying to airport %d\n",ret);
    }
    return 0;
}
