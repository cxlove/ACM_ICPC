//dp[i]£ºthe length of string is i
class TheLargestString
{
    public:
    string find(string s, string t)
    {
    	pair<string,string>dp[50];
    	dp[0]=mp("","");
    	for(int i=1;i<=s.size();i++){
    		for(int j=i-1;j>=0;j--){
    			if(dp[j].first+(char)s[i-1]+dp[j].second+(char)t[i-1]>dp[j+1].first+dp[j+1].second)
    				dp[j+1]=mp(dp[j].first+(char)s[i-1],dp[j].second+(char)t[i-1]);
    		}
    	}
    	string ans="";
    	for(int i=1;i<=s.size();i++)
    		ans=max(ans,dp[i].first+dp[i].second);
    	return ans;
    }
}