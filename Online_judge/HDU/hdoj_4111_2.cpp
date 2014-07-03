#include <iostream>
 #include <cstring>
 using namespace std;

 int dp[55][60000];

 int DP(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j==1)
         return dp[i][j]=DP(i+1,0);
    dp[i][j]=0;
     if(i>=1 && !DP(i-1,j))  //擦掉一个1
        dp[i][j]=1;
     else if(j>=1 && !DP(i,j-1)) //将大于1的数减1
        dp[i][j]=1;
     else if(i>=1&&j>0&&!DP(i-1,j+1)) //将一个1加到大于1的数上
         dp[i][j]=1;
     else if(i>=2&& ((j>=1&&!DP(i-2,j+3))||(j==0&& !DP(i-2,2))))  //将两个1相加
         dp[i][j]=1;

     return dp[i][j];
 }

 int main()
 {
     int icase,i,j,k,n,t;
     cin>>icase;
     memset(dp,-1,sizeof(dp));
     for(i=1;i<=icase;i++)
    {
         j=0;
         k=0;
         cin>>n;
         while (n--)
         {
             cin>>t;
             if(t==1)
                 j++;
             else
                 k+=(t+1);
        }
        if(k)
             k--;
         cout<<"Case #"<<i<<": ";
         if(DP(j,k))
             cout<<"Alice"<<endl;
         else
             cout<<"Bob"<<endl;
     }
}