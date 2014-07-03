#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
int a[1005],n,m,k,cas=0;
bool flag[1005];
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        memset(flag,false,sizeof(flag));
        for(int i=0;i<m;i++){
            scanf("%d",&k);
            flag[k]=true;
        }
        int ans=0,tmp=0;
        for(int i=n*m;i>0;i--)
            if(flag[i]){
                tmp++;
                ans=max(ans,tmp);
            }
            else
                tmp--;
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}