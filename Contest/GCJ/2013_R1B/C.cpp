C-large-practice.in#include<iostream>      
#include<cstdio>      
#include<map>      
#include<cstring>      
#include<cmath>      
#include<vector>      
#include<algorithm>      
#include<set>      
#include<stack>    
#include<string>      
#include<ctime>    
#include<queue>      
#include<cassert>    
#define inf 0x11111111  
#define maxn 210005      
#define eps 1e-8    
#define zero(a) fabs(a)<eps      
#define Min(a,b) ((a)<(b)?(a):(b))      
#define Max(a,b) ((a)>(b)?(a):(b))      
#define pb(a) push_back(a)      
#define mp(a,b) make_pair(a,b)      
#define mem(a,b) memset(a,b,sizeof(a))      
#define LL long long      
#define MOD 1000000007    
#define sqr(a) ((a)*(a))      
#define Key_value ch[ch[root][1]][0]      
#define test puts("OK");      
#define pi acos(-1.0)    
#define lowbit(x) ((-(x))&(x))    
#pragma comment(linker, "/STACK:1024000000,1024000000")      
using namespace std; 
const int M = 3900000;
struct Trie  {    
    Trie *next[26];    
    Trie *fail; 
    bool word;
};    
Trie *que[M],s[M],*root;    
int idx=0;  
Trie *NewNode()  {    
    Trie *tmp=&s[idx++];    
    mem(tmp->next,NULL);   
    tmp->fail=NULL;
    tmp->word=false;
    return tmp;    
}    
void Insert(Trie *root,char *s,int len)  {    
    Trie *p=root;    
    for(int i=0; i<len; i++){    
        if(p->next[s[i]-'a']==NULL) p->next[s[i]-'a']=NewNode();    
        p=p->next[s[i]-'a'];    
    }  
    p->word=true;  
}  
char str[4005];
int dp[4005][6],l;
void dfs(int idx,int i,int d,int ans){
    if(s[idx].word){
        dp[i][d]=min(dp[i][d],ans);
    }
    if(i==l) return ;
    //¿ÉÒÔÐÞ¸Ä
    if(d==5){
        for(int j=0;j<26;j++){
            if(s[idx].next[j]){
                if(j==str[i]-'a')
                    dfs(s[idx].next[j]-s,i+1,5,ans);
                else 
                    dfs(s[idx].next[j]-s,i+1,1,ans+1);
            }
        }
    }
    else if(s[idx].next[str[i]-'a'])
        dfs(s[idx].next[str[i]-'a']-s,i+1,d+1,ans);
}
int solve(){
    mem(dp,0x11);
    dp[0][5]=0;
    l=strlen(str);
    for(int i=0;i<l;i++){
        for(int j=1;j<=5;j++){
            if(dp[i][j]==inf)
                continue;
            dfs(0,i,j,dp[i][j]);
        }
    }
    int ans=inf;
    for(int i=1;i<=5;i++)
        ans=min(ans,dp[l][i]);
    return ans;
}  
int main(){
    int t,cas=0;
    freopen("garbled_email_dictionary.txt","r",stdin);
    idx=0;
    root=NewNode();  
    while(scanf("%s",str)!=EOF){
        Insert(root,str,strlen(str));
    }
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        printf("Case #%d: %d\n",++cas,solve());
    }
    return 0;
}