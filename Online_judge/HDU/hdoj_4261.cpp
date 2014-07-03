#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<29
using namespace std;
int n,k,a[2005];
int b[2005][2005];   //存放i到j的最小差值
int dp[2005][26]={0};   //dp[i][j]表示前i个数，分为j段的最优解
//以下两个优先队列，记录中位数
//如果为奇数个元素，中位数便是大的里面的最小值
//如果为偶数则为小的最大值与大的最小值之间的任意数

int main(){
    while(scanf("%d%d",&n,&k)!=EOF&&n+k){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=inf;
        for(int i=1;i<=n;i++){
       //     while(!lower.empty()) lower.pop();
         //   while(!upper.empty()) upper.pop();
            priority_queue<int>lower;
priority_queue<int,vector<int>,greater<int> >upper;
            int sum=0; //sum表示大堆和与小堆和的差
            for(int j=i;j<=n;j++){
                //判断是加入小的，还是大的
                if(lower.empty()||a[j]<=lower.top()){
                    lower.push(a[j]);
                    sum-=a[j];
                }
                else{
                    upper.push(a[j]);
                    sum+=a[j];
                }
                //计算小堆里面的数量，大堆里面的数量
                int low=(j-i+1)/2,high=(j-i+1)-low;
                //作一次调整，使得数量保持一致
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
                //前面的调整可能使顺序错乱，将小的里面的最大值和大的里面的最大值比较
                //作交换调整
                while(lower.size()&&upper.size()&&lower.top()>upper.top()){
                    int u=lower.top(),v=upper.top();
                    lower.pop();upper.pop();
                    sum=sum+2*u-2*v;
                    lower.push(v);upper.push(u);
                }
                int ans=sum;
                //如果个数为奇数，说明中位数为大的里面的最小值，要减掉
                if(high>low) ans-=upper.top();
                b[i][j]=ans;
            }
        }
        //n^2*k的DP
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
