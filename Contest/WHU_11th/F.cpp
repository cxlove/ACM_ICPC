#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int sg[1000],n;
int a[1000][1000];
int get_sg(int m){
    if(sg[m]!=-1) return sg[m];
    bool vis[105];
    memset(vis,false,sizeof(vis));
    for(int i=1;i<m;i++)
        vis[get_sg(i-1)^get_sg(m-i-1)]=true;
    for(int i=0;;i++)
        if(vis[i]==false)
            return sg[m]=i;
}
int main(){
    int t,cas=0;
    memset(sg,-1,sizeof(sg));
    for(int i=0;i<1000;i++)
        sg[i]=get_sg(i);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int ret=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    int cnt=0;
                    for(int k=j;k<n;k+=2)
                        if(a[i][k]==0)
                            cnt++,a[i][k]=1;
                        else break;
                    ret^=sg[cnt];
                }
            }
        }
        printf("Case %d: %s\n",++cas,ret?"Alice":"Bob");
    }
    return 0;
}