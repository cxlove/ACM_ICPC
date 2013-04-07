double dp[1000005][2];
class TheSwapsDivOne
{
    public:
    double find(vector <string> s, int k)
    {
        string str="";
        for(int i=0;i<s.size();i++)
            str+=s[i];
        int n=str.size();
        dp[0][1]=0.0;
        dp[0][0]=1.0;
        for(int i=1;i<=k;i++){
            dp[i][0]=dp[i-1][1]*1.0/(n*(n-1)/2.0)+dp[i-1][0]*((n-1)*(n-2)/2.0)/(n*(n-1)/2.0);
            dp[i][1]=dp[i-1][0]*(n-1)/(n*(n-1)/2.0)+dp[i-1][1]*(n*(n-1)/2.0-1)/(n*(n-1)/2.0);
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double tmp,cnt=(j+1.0)*(n-j);
                if(i!=j) tmp=dp[k][1]/(n-1.0);
                else tmp=dp[k][0];
                ans+=tmp*cnt*(str[i]-'0');
            }
        }
        return ans/(n*(n+1)/2.0);
    }
};