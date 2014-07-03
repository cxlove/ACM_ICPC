#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<29
using namespace std;
struct Node{
    int cost,val;
}tmp;
vector<Node>a[105];
int n,t,m,kind[105];
int dp[105][105];
bool cmp(Node n1,Node n2){
    return n1.cost!=n2.cost?n1.cost<n2.cost:n1.val>n2.val;
}
int main(){
    while(scanf("%d%d",&n,&t)!=EOF){
        for(int i=1;i<=n;i++){
            a[i].clear();
            scanf("%d%d",&m,&kind[i]);
            for(int j=0;j<m;j++){
                scanf("%d%d",&tmp.cost,&tmp.val);
                a[i].push_back(tmp);
            }
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=t;j++)
                dp[i][j]=-inf;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            if(kind[i]==0){
                for(int k=0;k<a[i].size();k++)    
                    for(int j=t;j>=0;j--)            
                        if(j-a[i][k].cost>=0)
                            dp[i][j]=max(dp[i][j],max(dp[i-1][j-a[i][k].cost]+a[i][k].val,dp[i][j-a[i][k].cost]+a[i][k].val));
            }
            else if(kind[i]==1){
                for(int j=0;j<=t;j++)
                    dp[i][j]=dp[i-1][j];
                sort(a[i].begin(),a[i].end(),cmp);
                for(int j=t;j>=0;j--)        
                    for(int k=0;k<a[i].size();k++)    
                        if(k!=0&&a[i][k].cost==0)
                            continue;
                        else if(j-a[i][k].cost>=0)
                            dp[i][j]=max(dp[i][j],dp[i-1][j-a[i][k].cost]+a[i][k].val);
            }
            else{
                for(int j=0;j<=t;j++)
                    dp[i][j]=dp[i-1][j];
                for(int k=0;k<a[i].size();k++)    
                    for(int j=t;j>=0;j--)            
                        if(j-a[i][k].cost>=0)
                            dp[i][j]=max(dp[i][j],dp[i][j-a[i][k].cost]+a[i][k].val);
            }
        }
        int ans=-1;
        for(int i=0;i<=t;i++)
            ans=max(ans,dp[n][i]);
        if(ans<0)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
/*
3 3
2 1
2 5
3 8
2 0
1 0
2 1
3 2
4 3
2 1
1 1
3 4
2 1
2 5
3 8
2 0
1 1
2 8
3 2
4 4
2 1
1 1
1 1
1 0
2 1
5 3
2 0
1 0
2 1
2 0
2 2
1 1
2 0
3 2
2 1
2 1
1 5
2 8
3 2
3 8
4 9
5 10
*/