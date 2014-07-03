#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000
#define M 10005
#define N 200005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
using namespace std;
int n,path[105][105];
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&path[i][j]);
        printf("Case %d: ",++cas);
        bool flag=true;
        for(int k=0;k<n&&flag;k++)
            for(int i=0;i<n&&flag;i++)
                for(int j=0;j<n&flag;j++)
                    if(i!=j&&i!=k&&j!=k)
                        if(path[i][j]>path[i][k]+path[k][j])
                            flag=false;
        if(!flag){puts("impossible");continue;}
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i==j) continue;
                bool mark=true;
                for(int k=0;k<n;k++)
                    if(j!=k&&i!=k&&path[i][j]==path[i][k]+path[k][j]){
                        mark=false;
                        break;
                    }
                if(mark) ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
