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
#define inf 1000000005    
#define M 40    
#define N 10005  
#define maxn 300005    
#define eps 1e-8  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000009  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((-(x))&(x))  
#define HASH1 1331  
#define HASH2 10001  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std; 
struct Node{
    int t,c;
}a[1000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].t>>a[i].c;
    int ans=0,size=0,now=1,cnt=0;
    for(int i=0;i<n;i++){
        cnt=max(0,cnt-(a[i].t-now));
        cnt+=a[i].c;
        ans=max(ans,cnt);
        now=a[i].t;
    }
    cout<<now+cnt<<" "<<ans<<endl;
    return 0;
}