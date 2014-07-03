#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<29
using namespace std;
int n,k,a[2005];
int b[2005][2005];
int dp[2005][26]={0};
priority_queue<int>lower;
priority_queue<int,vector<int>,greater<int> >upper;
int main(){
    while(scanf("%d%d",&n,&k)!=EOF&&n+k){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=inf;
        for(int i=1;i<=n;i++){
            while(!lower.empty()) lower.pop();
            while(!upper.empty()) upper.pop();
            int sum=0;
            for(int j=i;j<=n;j++){
                if(lower.empty()||a[j]<=lower.top()){
                    lower.push(a[j]);
                    sum-=a[j];
                }
                else{
                    upper.push(a[j]);
                    sum+=a[j];
                }
                int low=(j-i+1)/2,high=(j-i+1)-low;
                if(lower.size()>low){
                    upper.push(lower.top());
                    sum+=lower.top()*2;
                    lower.pop();
                }
                if(upper.size()>high){
                    lower.push(upper.top());
                    sum-=upper.top()*2;
                    upper.pop();
                }
                while(lower.size()&&upper.size()&&lower.top()>upper.top()){
                    int u=lower.top(),v=upper.top();
                    lower.pop();upper.pop();
                    sum=sum+2*u-2*v;
                    lower.push(v);upper.push(u);
                }
                int ans=sum;
                if(high>low) ans-=upper.top();
                b[i][j]=ans;
          //      cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int r=0;r<i;r++)
                   dp[i][j]=(dp[r][j-1]+b[r+1][i])<dp[i][j]?(dp[r][j-1]+b[r+1][i]):dp[i][j];
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
