#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 400005
#define maxn 300005  
#define eps 1e-12
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
char str[N];
int next[N];
void get_next(char *s,int l){
    next[0]=-1;
    int i=0,j=-1;
    while(i<l){
        if(j==-1||s[i]==s[j]){
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int main(){
    while(scanf("%s",str)!=EOF){
        int l=strlen(str);
        vector<int>ans;
        ans.pb(l);
        get_next(str,l+1);
        int k=next[l];
        while(k){
            ans.pb(k);
            k=next[k];
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[ans.size()-1]);
    }
    return 0;
}