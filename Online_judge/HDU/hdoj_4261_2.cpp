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
void scanf_(int &num){
    char in;
    bool neg=false;
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;
    if(in=='-'){
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(neg)
        num=0-num;
}
void printf_(int num){
    bool flag=false;
    if(num<0){
        putchar('-');
        num=-num;
    }
    int ans[10],top=0;
    while(num!=0){
        ans[top++]=num%10;
        num/=10;
    }
    if(top==0)
        putchar('0');
    for(int i=top-1;i>=0;i--){
        char ch=ans[i]+'0';
        putchar(ch);
    }
}
int main(){
    while(1){
        scanf_(n);scanf_(k);if(n==0&&k==0) break;
        for(int i=1;i<=n;i++) scanf_(a[i]);
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
        printf_(dp[n][k]);putchar('\n');
    }
    return 0;
}
